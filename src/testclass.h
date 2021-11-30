#include <cmath>
#include <memory>
#include <boost/date_time/gregorian/gregorian_types.hpp>

using namespace boost::gregorian;

namespace testpkg
{

class TestClass
{
public:
    TestClass(date const& refdate, int const& n, double const& x);

    // getters
    const date& get_refdate() const;
    const int get_n() const;
    const double get_x() const;

    int func1(int m) const;

    double func2(double y) const;

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
    ) const;

    double combine(std::shared_ptr<TestClass> obj) const;

    void merge(std::shared_ptr<TestClass> other);

    std::shared_ptr<TestClass> make_obj(int new_n, double new_x);

protected:
    date refdate;
    int n;
    double x;
};

}

