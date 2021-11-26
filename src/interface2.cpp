#include <memory>
#include <Rcpp.h>
#include "testclass.h"
#include "dateconv.h"

// [[Rcpp::depends(BH)]]

using namespace Rcpp;

namespace testpkg
{

//' @export ITestClass2
class ITestClass2
{
public:
    ITestClass2(SEXP in_date, int const& in_n, double const& in_x)
        : impl(std::make_shared<TestClass>(as_boost_date(in_date), in_n, in_x))
    {}

    Date get_refdate()
    {
        return as_rcpp_date(impl->get_refdate());
    }

    int get_n()
    {
        return impl->get_n();
    }

    double get_x()
    {
        return impl->get_x();
    }

    int func1(int m)
    {
        return impl->func1(m);
    }

private:
    std::shared_ptr<TestClass> impl;
};

RCPP_MODULE(RTestClassModule2)
{
    class_<ITestClass2>("ITestClass2")
        .constructor<SEXP, int, double>()
        .method("get_refdate", &ITestClass2::get_refdate, "get_refdate")
        .method("get_n", &ITestClass2::get_n, "get_n")
        .method("get_x", &ITestClass2::get_x, "get_x")
        .method("func1", &ITestClass2::func1, "func1");
}

}
