#include <memory>
#include <Rcpp.h>
#include "testclass.h"
#include "dateconv.h"
#include "extpointer.h"

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
    double bigfunc(List arglist)
    {
        if(arglist.length() != 25)
        {
            stop("incorrect number of arguments");
        }
        // TODO: check all arg types
        return impl->bigfunc(
            arglist[0],
            arglist[1],
            arglist[2],
            arglist[3],
            arglist[4],
            arglist[5],
            arglist[6],
            arglist[7],
            arglist[8],
            arglist[9],
            arglist[10],
            arglist[11],
            arglist[12],
            arglist[13],
            arglist[14],
            arglist[15],
            arglist[16],
            arglist[17],
            arglist[18],
            arglist[19],
            arglist[20],
            arglist[21],
            arglist[22],
            arglist[23],
            arglist[24]
        );
    }

    // taking another object as an argument
    double combine(RObject obj)
    {
        ITestClass* ptr = get_interface_pointer<ITestClass>(obj, "Rcpp_ITestClass");
        return impl->combine(ptr->get_implementation());
    }

    // in-place updating
    void merge(RObject other)
    {
        ITestClass* ptr = get_interface_pointer<ITestClass>(other, "Rcpp_ITestClass");
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
