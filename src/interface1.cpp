#include <Rcpp.h>
#include "testclass.h"
#include "dateconv.h"

// [[Rcpp::depends(BH)]]

using namespace Rcpp;

namespace testpkg
{

class ITestClass
{
public:
    ITestClass(SEXP in_date, int const& in_n, double const& in_x)
        : impl(as_boost_date(in_date), in_n, in_x)
    {}

    Date get_refdate()
    {
        return as_rcpp_date(impl.get_refdate());
    }

    int get_n()
    {
        return impl.get_n();
    }

    double get_x()
    {
        return impl.get_x();
    }

    int func1(int m)
    {
        return impl.func1(m);
    }

    double func2(double y)
    {
        return impl.func2(y);
    }

    // we don't have to implement any interfaces that shouldn't be exposed
    // double bigfunc() {}

private:
    TestClass impl;
};

RCPP_MODULE(RTestClassModule)
{
    class_<ITestClass>("ITestClass")
        .constructor<SEXP, int, double>()
        .method("func1", &ITestClass::func1, "func1")
        .method("func2", &ITestClass::func2, "func2");
}

}
