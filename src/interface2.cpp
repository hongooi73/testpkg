#include <Rcpp.h>
#include "testclass.h"
#include "dateconv.h"

// [[Rcpp::depends(BH)]]

using namespace Rcpp;

namespace testpkg
{

//structs for organising big argument lists
struct Argset1
{
    double a1;
    double a2;
    double a3;
    double a4;
    double a5;
    double a6;
    double a7;
    double a8;
    double a9;
    double a10;
};

struct Argset2
{
    double a11;
    double a12;
    double a13;
    double a14;
    double a15;
    double a16;
    double a17;
    double a18;
    double a19;
    double a20;
};

struct Argset3
{
    double a21;
    double a22;
    double a23;
    double a24;
    double a25;
};

class ITestClass
{
public:
    ITestClass(SEXP in_date, int const& in_n, double const& in_x)
        : impl(as_boost_date(in_date), in_n, in_x)
    {}

    int func1(int m)
    {
        return impl.func1(m);
    }

    double func2(double y)
    {
        return impl.func2(y);
    }

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
