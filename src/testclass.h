#include <string>
#include <cmath>
#include <boost/date_time/gregorian/gregorian_types.hpp>

using namespace boost::gregorian;

namespace testpkg
{

class TestClass
{
public:
    TestClass(date const& refdate, int const& n, double const& x);

    const date& get_refdate() const;
    const int get_n() const;
    const double get_x() const;

    double func1(int m) const;
    double func2(double y) const;

protected:
    date refdate;
    int n;
    double x;
};

}

