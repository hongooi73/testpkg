#' @useDynLib testpkg, .registration=TRUE
#' @import Rcpp
NULL

loadModule("RTestClassModule", TRUE)
loadModule("RTestClassModule2", TRUE)
