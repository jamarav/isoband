// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// isobands_impl
List isobands_impl(const NumericVector& x, const NumericVector& y, const NumericMatrix& z, const NumericVector& value_low, const NumericVector& value_high);
RcppExport SEXP _isoband_isobands_impl(SEXP xSEXP, SEXP ySEXP, SEXP zSEXP, SEXP value_lowSEXP, SEXP value_highSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type y(ySEXP);
    Rcpp::traits::input_parameter< const NumericMatrix& >::type z(zSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type value_low(value_lowSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type value_high(value_highSEXP);
    rcpp_result_gen = Rcpp::wrap(isobands_impl(x, y, z, value_low, value_high));
    return rcpp_result_gen;
END_RCPP
}
// isolines_impl
List isolines_impl(const NumericVector& x, const NumericVector& y, const NumericMatrix& z, const NumericVector& value);
RcppExport SEXP _isoband_isolines_impl(SEXP xSEXP, SEXP ySEXP, SEXP zSEXP, SEXP valueSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type y(ySEXP);
    Rcpp::traits::input_parameter< const NumericMatrix& >::type z(zSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type value(valueSEXP);
    rcpp_result_gen = Rcpp::wrap(isolines_impl(x, y, z, value));
    return rcpp_result_gen;
END_RCPP
}
// test
void test(const NumericVector& pll, const NumericVector& plr, const NumericVector& pul, const NumericVector& p);
RcppExport SEXP _isoband_test(SEXP pllSEXP, SEXP plrSEXP, SEXP pulSEXP, SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericVector& >::type pll(pllSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type plr(plrSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type pul(pulSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type p(pSEXP);
    test(pll, plr, pul, p);
    return R_NilValue;
END_RCPP
}
// separate_polygons
List separate_polygons(const NumericVector& x, const NumericVector& y, const IntegerVector& id);
RcppExport SEXP _isoband_separate_polygons(SEXP xSEXP, SEXP ySEXP, SEXP idSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type y(ySEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type id(idSEXP);
    rcpp_result_gen = Rcpp::wrap(separate_polygons(x, y, id));
    return rcpp_result_gen;
END_RCPP
}

RcppExport SEXP run_testthat_tests();

static const R_CallMethodDef CallEntries[] = {
    {"_isoband_isobands_impl", (DL_FUNC) &_isoband_isobands_impl, 5},
    {"_isoband_isolines_impl", (DL_FUNC) &_isoband_isolines_impl, 4},
    {"_isoband_test", (DL_FUNC) &_isoband_test, 4},
    {"_isoband_separate_polygons", (DL_FUNC) &_isoband_separate_polygons, 3},
    {"run_testthat_tests",         (DL_FUNC) &run_testthat_tests,         0},
    {NULL, NULL, 0}
};

RcppExport void R_init_isoband(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
