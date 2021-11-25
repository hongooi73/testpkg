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

    double func1(int m) const
    {
        return n * m;
    }

    double func2(double y) const
    {
        return x * y;
    }
}
