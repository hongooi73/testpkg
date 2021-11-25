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

class RTestClass : public TestClass
{
public:

    RTestClass(SEXP in_date, int const& in_n, double const& in_x)
        : TestClass(as_boost_date(in_date), in_n, in_x)
    {}

    // double do_bigfunc(Argset1 argset1, Argset2 argset2, Argset3 argset3)
    // {
    //     return bigfunc(
    //         argset1.a1,
    //         argset1.a2,
    //         argset1.a3,
    //         argset1.a4,
    //         argset1.a5,
    //         argset1.a6,
    //         argset1.a7,
    //         argset1.a8,
    //         argset1.a9,
    //         argset1.a10,
    //         argset2.a11,
    //         argset2.a12,
    //         argset2.a13,
    //         argset2.a14,
    //         argset2.a15,
    //         argset2.a16,
    //         argset2.a17,
    //         argset2.a18,
    //         argset2.a19,
    //         argset2.a20,
    //         argset3.a21,
    //         argset3.a22,
    //         argset3.a23,
    //         argset3.a24,
    //         argset3.a25
    //     );
    // }

};

RCPP_MODULE(RTestClassModule)
{
    class_<RTestClass>("RTestClass")

    .constructor<SEXP, int, double>()
    
    .method("get_x", &TestClass::get_x);
}

}
