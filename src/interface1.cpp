#include <memory>
#include <Rcpp.h>
#include "testclass.h"
#include "dateconv.h"

// [[Rcpp::depends(BH)]]

using namespace Rcpp;

namespace testpkg
{

//' @export ITestClass
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

    // we don't have to add any interfaces that shouldn't be exposed
    // double func2(double y) {}

    double bigfunc(List argset1, List argset2, double a21, double a22, double a23, double a24, double a25)
    {
        return impl.bigfunc(
            argset1["a1"],
            argset1["a2"],
            argset1["a3"],
            argset1["a4"],
            argset1["a5"],
            argset1["a6"],
            argset1["a7"],
            argset1["a8"],
            argset1["a9"],
            argset1["a10"],
            argset2["a11"],
            argset2["a12"],
            argset2["a13"],
            argset2["a14"],
            argset2["a15"],
            argset2["a16"],
            argset2["a17"],
            argset2["a18"],
            argset2["a19"],
            argset2["a20"],
            a21,
            a22,
            a23,
            a24,
            a25
        );
    }

    double combine(SEXP obj)
    {
        TestClass* ptr = (TestClass*) R_ExternalPtrAddr(obj);
        std::shared_ptr<TestClass> sptr(ptr);
        return impl.combine(sptr);
    }

    Rcpp::XPtr<TestClass> get_object()
    {
        return Rcpp::XPtr<TestClass>(&impl);
    }

protected:
    // for internal communication in C++
    std::shared_ptr<TestClass> get_object_ptr()
    {
        std::shared_ptr<TestClass> ptr(&impl);
        return ptr;
    }

private:
    TestClass impl;
};

RCPP_MODULE(RTestClassModule)
{
    class_<ITestClass>("ITestClass")
        .constructor<SEXP, int, double>()
        .method("get_refdate", &ITestClass::get_refdate, "get_refdate")
        .method("get_n", &ITestClass::get_n, "get_n")
        .method("get_x", &ITestClass::get_x, "get_x")
        .method("func1", &ITestClass::func1, "func1")
        .method("bigfunc", &ITestClass::bigfunc, "bigfunc")
        .method("combine", &ITestClass::combine, "combine")
        .method("get_object", &ITestClass::get_object, "get_object")
    ;
}

}
