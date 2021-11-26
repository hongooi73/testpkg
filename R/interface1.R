loadModule("RTestClassModule", TRUE)

suppressMessages(setMethod("show", "Rcpp_ITestClass", function(object)
{
    cat("An object of class 'TestClass'\n")
    invisible(object)
}))
