#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::NumericVector call_r_from_rcpp() {
  Rcpp::Function callback = Rcpp::Environment::namespace_env("uptest")["callback"];
  try {
    callback();
  } catch( const std::exception& e ) {
    // Handle R errors in C++ application
    std::cerr << "[Appplication handling R exception] " << e.what() << std::endl;
  }
  return Rcpp::NumericVector::create(42);
}
