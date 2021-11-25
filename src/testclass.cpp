#include <string>
#include <cmath>
#include <boost/date_time/gregorian/gregorian_types.hpp>

using namespace boost::gregorian;

namespace testpkg
{
    TestClass::TestClass(date const& refdate, int const& n, double const& x)
        : refdate(refdate), n(n), x(x)
    {}

    const date& get_refdate() const
    {
        return refdate;
    }

    const int get_n() const
    {
        return n;
    };

    const double get_x() const
    {
        return x;
    };

    int func1(int m) const
    {
        return n * m;
    }

    double func2(double y) const
    {
        return x * y;
    }

    double bigfunc(
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

}
