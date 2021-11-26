loadModule("RTestClassModule2", TRUE)

suppressMessages(setMethod("show", "Rcpp_ITestClass2", function(object)
{
    cat("An object of class 'TestClass' with shared pointer interface\n")
    invisible(object)
}))
