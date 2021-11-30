loadModule("RTestClassModule2", TRUE)

test_class2 <- function(date, n, x)
{
    date <- as.Date(date)
    n <- as.integer(n)
    x <- as.double(x)
    ITestClass2$new(list(date, n, x))
}

suppressMessages(setMethod("show", "Rcpp_ITestClass2", function(object)
{
    cat("An object of class 'TestClass' with shared pointer interface\n")
    invisible(object)
}))
