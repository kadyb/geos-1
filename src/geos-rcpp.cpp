
// this is intended to do all the 'hard' GEOS memory management so that other files
// can focus on geom operations

#include "geos-rcpp.h"
#include <Rcpp.h>

using namespace Rcpp;

static void __errorHandler(const char *fmt, ...) { // #nocov start

  char buf[BUFSIZ], *p;
  va_list ap;
  va_start(ap, fmt);
  vsprintf(buf, fmt, ap);
  va_end(ap);
  p = buf + strlen(buf) - 1;
  if(strlen(buf) > 0 && *p == '\n') *p = '\0';

  Rcpp::Function error(".stop_geos", Rcpp::Environment::namespace_env("geom"));
  error(buf);

  return; // #nocov end
}

static void __warningHandler(const char *fmt, ...) {

  char buf[BUFSIZ], *p;
  va_list ap;
  va_start(ap, fmt);
  vsprintf(buf, fmt, ap);
  va_end(ap);
  p = buf + strlen(buf) - 1;
  if(strlen(buf) > 0 && *p == '\n') *p = '\0';

  Rcpp::Function warning("warning");
  warning(buf);

  return;
}

// #nocov start
static void __countErrorHandler(const char *fmt, void *userdata) {
  int *i = (int *) userdata;
  *i = *i + 1;
}

static void __emptyNoticeHandler(const char *fmt, void *userdata) { }
// #nocov end

GEOSContextHandle_t geos_init(void) {
#ifdef HAVE350
  GEOSContextHandle_t ctxt = GEOS_init_r();
  GEOSContext_setNoticeHandler_r(ctxt, __warningHandler);
  GEOSContext_setErrorHandler_r(ctxt, __errorHandler);
  return ctxt;
#else
  return initGEOS_r((GEOSMessageHandler) __warningHandler, (GEOSMessageHandler) __errorHandler);
#endif
}

void geos_finish(GEOSContextHandle_t ctxt) {
#ifdef HAVE350
  GEOS_finish_r(ctxt);
#else
  finishGEOS_r(ctxt);
#endif
}

using GeomPtr = std::unique_ptr<GEOSGeometry, std::function<void(GEOSGeometry*)>>;

static GeomPtr geos_ptr(GEOSGeometry* g, GEOSContextHandle_t hGEOSctxt) {
  auto deleter = std::bind(GEOSGeom_destroy_r, hGEOSctxt, std::placeholders::_1);
  return GeomPtr(g, deleter);
}
