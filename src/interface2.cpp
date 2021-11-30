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
    ITestClass2(List args)
    {
        SEXP in_date = args[0];
        int in_n = args[1];
        double in_x = args[2];
        impl = std::make_shared<TestClass>(as_boost_date(in_date), in_n, in_x);
    }

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

    // we don't have to add any interfaces that shouldn't be exposed
    // double func2(double y) {}

    // adding complexity: vectorising an underlying method
    NumericVector vec_func1(NumericVector m)
    {
        NumericVector out(m.length());

        for(int i = 0; i < m.length(); ++i)
        {
            out[i] = impl->func1(m[i]);
        }
        return out;
    }

    // inputs for a problematic method (too many args for Rcpp to handle)
    double bigfunc(List argset)
    {
        return impl->bigfunc(
            argset["a1"],
            argset["a2"],
            argset["a3"],
            argset["a4"],
            argset["a5"],
            argset["a6"],
            argset["a7"],
            argset["a8"],
            argset["a9"],
            argset["a10"],
            argset["a11"],
            argset["a12"],
            argset["a13"],
            argset["a14"],
            argset["a15"],
            argset["a16"],
            argset["a17"],
            argset["a18"],
            argset["a19"],
            argset["a20"],
            argset["a21"],
            argset["a22"],
            argset["a23"],
            argset["a24"],
            argset["a25"]
        );
    }

    double combine(Environment obj)
    {
        SEXP objptr = obj[".pointer"];
        ITestClass2* ptr = (ITestClass2*) R_ExternalPtrAddr(objptr);
        return impl->combine(ptr->get_implementation());
    }

    void merge(Environment other)
    {
        SEXP objptr = other[".pointer"];
        ITestClass2* ptr = (ITestClass2*) R_ExternalPtrAddr(objptr);
        impl->merge(ptr->get_implementation());
    }

protected:
    std::shared_ptr<TestClass> get_implementation()
    {
        return impl;
    }

private:
    std::shared_ptr<TestClass> impl;
};

RCPP_MODULE(RTestClassModule2)
{
    class_<ITestClass2>("ITestClass2")
        .constructor<List>()
        .method("get_refdate", &ITestClass2::get_refdate, "get_refdate")
        .method("get_n", &ITestClass2::get_n, "get_n")
        .method("get_x", &ITestClass2::get_x, "get_x")
        .method("func1", &ITestClass2::func1, "func1")
        .method("vec_func1", &ITestClass2::vec_func1, "vec_func1")
        .method("bigfunc", &ITestClass2::bigfunc, "bigfunc")
        .method("combine", &ITestClass2::combine, "combine")
        .method("merge", &ITestClass2::merge, "merge")
    ;
}

}
