loadModule("RTestClassModule2", TRUE)

#' @export
test_class <- function(date, n, x)
{
    date <- as.Date(date)
    n <- as.integer(n)
    x <- as.double(x)
    ITestClass$new(list(date, n, x))
}

suppressMessages(setMethod("show", "Rcpp_ITestClass", function(object)
{
    cat("An object of class 'TestClass' with shared pointer interface\n")
    invisible(object)
}))
