#include <memory>
#include <Rcpp.h>
#include "testclass.h"
#include "dateconv.h"

// [[Rcpp::depends(BH)]]

using namespace Rcpp;

// static void null_finalizer(SEXP x)
// {
//     return;
// }

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

    // customising the inputs for a problematic method (too many args for Rcpp to handle)
    double bigfunc(List argset1, List argset2, double a21, double a22, double a23, double a24, double a25)
    {
        return impl->bigfunc(
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

    double combine(Environment obj)
    {
        SEXP objptr = obj[".pointer"];
        ITestClass2* ptr = (ITestClass2*) R_ExternalPtrAddr(objptr);
        return impl->combine(ptr->get_implementation());
    }

    // SEXP get_object()
    // {
    //     SEXP val = PROTECT(R_MakeExternalPtr(&impl, R_NilValue, R_NilValue));
    //     R_RegisterCFinalizerEx(val, null_finalizer, TRUE);
    //     UNPROTECT(1);

    //     return val;
    // }

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
        .constructor<SEXP, int, double>()
        .method("get_refdate", &ITestClass2::get_refdate, "get_refdate")
        .method("get_n", &ITestClass2::get_n, "get_n")
        .method("get_x", &ITestClass2::get_x, "get_x")
        .method("func1", &ITestClass2::func1, "func1")
        .method("vec_func1", &ITestClass2::vec_func1, "vec_func1")
        .method("bigfunc", &ITestClass2::bigfunc, "bigfunc")
        .method("combine", &ITestClass2::combine, "combine")
        // .method("get_object", &ITestClass2::get_object, "get_object")
    ;
}

}
