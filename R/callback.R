#' Test calling R from Rcpp
#'
#' Function to call an R function from Rcpp to test the behavior
#' of compiling with `-DRCPP_USE_UNWIND_PROTECT`.
#'
#' @export
#' @useDynLib uptest
#' @importFrom Rcpp sourceCpp
uptest <- function(){
  call_r_from_rcpp()
}

callback <- function() {
  stop("Ouch from R")
}
