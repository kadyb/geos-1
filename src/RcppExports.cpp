// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// geos_version_impl
std::string geos_version_impl();
RcppExport SEXP _geom_geos_version_impl() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(geos_version_impl());
    return rcpp_result_gen;
END_RCPP
}
// geos_test_throw_error
void geos_test_throw_error();
RcppExport SEXP _geom_geos_test_throw_error() {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    geos_test_throw_error();
    return R_NilValue;
END_RCPP
}
// geomcpp_buffer
SEXP geomcpp_buffer(SEXP data, SEXP ptype, double width, int quadSegs, int endCapStyle, int joinStyle, double mitreLimit, int singleSided);
RcppExport SEXP _geom_geomcpp_buffer(SEXP dataSEXP, SEXP ptypeSEXP, SEXP widthSEXP, SEXP quadSegsSEXP, SEXP endCapStyleSEXP, SEXP joinStyleSEXP, SEXP mitreLimitSEXP, SEXP singleSidedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type data(dataSEXP);
    Rcpp::traits::input_parameter< SEXP >::type ptype(ptypeSEXP);
    Rcpp::traits::input_parameter< double >::type width(widthSEXP);
    Rcpp::traits::input_parameter< int >::type quadSegs(quadSegsSEXP);
    Rcpp::traits::input_parameter< int >::type endCapStyle(endCapStyleSEXP);
    Rcpp::traits::input_parameter< int >::type joinStyle(joinStyleSEXP);
    Rcpp::traits::input_parameter< double >::type mitreLimit(mitreLimitSEXP);
    Rcpp::traits::input_parameter< int >::type singleSided(singleSidedSEXP);
    rcpp_result_gen = Rcpp::wrap(geomcpp_buffer(data, ptype, width, quadSegs, endCapStyle, joinStyle, mitreLimit, singleSided));
    return rcpp_result_gen;
END_RCPP
}
// geomcpp_convert
SEXP geomcpp_convert(SEXP data, SEXP ptype);
RcppExport SEXP _geom_geomcpp_convert(SEXP dataSEXP, SEXP ptypeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type data(dataSEXP);
    Rcpp::traits::input_parameter< SEXP >::type ptype(ptypeSEXP);
    rcpp_result_gen = Rcpp::wrap(geomcpp_convert(data, ptype));
    return rcpp_result_gen;
END_RCPP
}
// geomcpp_validate_provider
LogicalVector geomcpp_validate_provider(SEXP data);
RcppExport SEXP _geom_geomcpp_validate_provider(SEXP dataSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type data(dataSEXP);
    rcpp_result_gen = Rcpp::wrap(geomcpp_validate_provider(data));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_geom_geos_version_impl", (DL_FUNC) &_geom_geos_version_impl, 0},
    {"_geom_geos_test_throw_error", (DL_FUNC) &_geom_geos_test_throw_error, 0},
    {"_geom_geomcpp_buffer", (DL_FUNC) &_geom_geomcpp_buffer, 8},
    {"_geom_geomcpp_convert", (DL_FUNC) &_geom_geomcpp_convert, 2},
    {"_geom_geomcpp_validate_provider", (DL_FUNC) &_geom_geomcpp_validate_provider, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_geom(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
