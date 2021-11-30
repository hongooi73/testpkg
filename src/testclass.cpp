#include "testclass.h"

using namespace boost::gregorian;

namespace testpkg
{

TestClass::TestClass(date const& refdate, int const& n, double const& x)
    : refdate(refdate), n(n), x(x)
{}

const date& TestClass::get_refdate() const
{
    return refdate;
}

const int TestClass::get_n() const
{
    return n;
}

const double TestClass::get_x() const
{
    return x;
}

int TestClass::func1(int m) const
{
    return n * m;
}

double TestClass::func2(double y) const
{
    return x * y;
}

double TestClass::bigfunc(
    double a1,
    double a2,
    double a3,
    double a4,
    double a5,
    double a6,
    double a7,
    double a8,
    double a9,
    double a10,
    double a11,
    double a12,
    double a13,
    double a14,
    double a15,
    double a16,
    double a17,
    double a18,
    double a19,
    double a20,
    double a21,
    double a22,
    double a23,
    double a24,
    double a25
) const
{
    return a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 +
           a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 +
           a21 + a22 + a23 + a24 + a25;
}


double TestClass::combine(std::shared_ptr<TestClass> obj) const
{
    return x + obj->get_x();
}

void TestClass::merge(std::shared_ptr<TestClass> other)
{
    if(refdate < other->get_refdate())
    {
        refdate = other->get_refdate();
    }
    n = n + other->get_n();
    x = x * other->get_x();
}

std::shared_ptr<TestClass> TestClass::make_obj(int new_n, double new_x)
{
    date refdate(1970, 1, 1);
    return std::make_shared<TestClass>(refdate, new_n, new_x);
}

}
