
#ifndef GEOS_COMMON_H
#define GEOS_COMMON_H

#include <string.h>
#include "Rinternals.h"
#include "libgeos.h"

// this leaves 200 characters of space for the prepending
// text for the error (which is always hard-coded)
#define GEOS_ERROR_MESSAGE_BUFFER_SIZE 1024
#define GEOS_ACTUAL_ERROR_MESSAGE_BUFFER_SIZE 1224

// error handler that writes message to the char[1024] at userdata
void geos_common_handle_error(const char *message, void* userdata);

// a handle, initialized on package load, for destroying geometries
// much faster than creating a new handle for each geometry to be destroyed
// (possibly millions)
extern GEOSContextHandle_t geos_gc_handle;

// creates an externalptr with the appropriate finisher for a GEOSGeometry*
// and calls GEOSGeom_destory_r(), finishing an externalptr
void geos_common_release_geometry(SEXP externalPtr);
SEXP geos_common_geometry_xptr(GEOSGeometry* geometry);

// when referencing child geometries, we can avoid cloning by protecting
// the parent from garbage collection but not registering a finalizer
// (these geometries must not be finalized, as they are owned by
// the GEOSGeometry* that will be finalized by parent)
SEXP geos_common_child_geometry_xptr(const GEOSGeometry* geometry, SEXP parent);

// creates an externalptr with the appropriate finish for a GEOSSTRTree*
// making sure to also protect the list() of GEOSGeometry* XPtrs from which
// the tree was created (which recursively protects the GEOSGeometry* objects
// from garbage collection), and a list of indices, whose memory is referenced
// from the GEOSSTRTree itself
void geos_common_release_tree(SEXP externalPtr);
SEXP geos_common_tree_xptr(GEOSSTRtree* geometry, SEXP geom, SEXP indices);

// macros to set up and tear down the GEOS error handling code
// hardcodes 'handle' as the GEOS handle type
#define GEOS_INIT()  \
  GEOSContextHandle_t handle = GEOS_init_r();  \
  char lastGEOSErrorMessage[GEOS_ERROR_MESSAGE_BUFFER_SIZE];  \
  strcpy(lastGEOSErrorMessage, "Unknown error");  \
  GEOSContext_setErrorMessageHandler_r(handle, &geos_common_handle_error, lastGEOSErrorMessage)\

// the error macro wraps Rf_error() but adds the error message at the end
// works for the frequent usage with exactly one arg to Rf_error()
// only works in the same function where GEOS_INIT() was used
#define GEOS_ERROR(msg, arg) GEOS_FINISH();  \
  char actualErrorMessage[GEOS_ACTUAL_ERROR_MESSAGE_BUFFER_SIZE];     \
  strcpy(actualErrorMessage, msg); \
  memcpy(&actualErrorMessage[strlen(msg)], lastGEOSErrorMessage, strlen(lastGEOSErrorMessage)); \
  actualErrorMessage[strlen(msg) + strlen(lastGEOSErrorMessage)] = '\0'; \
  Rf_error(actualErrorMessage, arg)

// finishes handle
#define GEOS_FINISH() GEOS_finish_r(handle)

// check geometry coming out of an externalptr
#define GEOS_CHECK_GEOMETRY(geometry, i)  \
  if (geometry == NULL) {   \
    Rf_error("External pointer is not valid [i=%d]", i + 1);  \
  }

#endif
