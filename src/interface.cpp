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
    ITestClass(List args)
    {
        SEXP in_date = args[0];
        int in_n = args[1];
        double in_x = args[2];
        impl = std::make_shared<TestClass>(as_boost_date(in_date), in_n, in_x);
    }

    // not exposed to R, for internal communication only
    ITestClass(std::shared_ptr<TestClass> impl)
        : impl(impl)
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

    // taking another object as an argument
    double combine(Environment obj)
    {
        SEXP objptr = obj.find(".pointer");
        ITestClass* ptr = (ITestClass*) R_ExternalPtrAddr(objptr);
        return impl->combine(ptr->get_implementation());
    }

    // in-place updating
    void merge(Environment other)
    {
        SEXP objptr = other.find(".pointer");
        ITestClass* ptr = (ITestClass*) R_ExternalPtrAddr(objptr);
        impl->merge(ptr->get_implementation());
    }

    // returning a new object from a static function
    ITestClass make_obj(int new_n, double new_x)
    {
        std::shared_ptr<TestClass> new_impl(TestClass::make_obj(new_n, new_x));
        ITestClass new_obj(new_impl);
        return new_obj;
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
    class_<ITestClass>("ITestClass")
        .constructor<List>()
        .method("get_refdate", &ITestClass::get_refdate, "get_refdate")
        .method("get_n", &ITestClass::get_n, "get_n")
        .method("get_x", &ITestClass::get_x, "get_x")
        .method("func1", &ITestClass::func1, "func1")
        .method("vec_func1", &ITestClass::vec_func1, "vec_func1")
        .method("bigfunc", &ITestClass::bigfunc, "bigfunc")
        .method("combine", &ITestClass::combine, "combine")
        .method("merge", &ITestClass::merge, "merge")
        .method("make_obj", &ITestClass::make_obj, "make_obj")
    ;
}

}

RCPP_EXPOSED_CLASS_NODECL(testpkg::ITestClass)
