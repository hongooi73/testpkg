#include <Rcpp.h>
#include <boost/date_time/gregorian/gregorian_types.hpp>

using namespace Rcpp;

inline SEXP as_rcpp_date(const boost::gregorian::date &d)
{
    boost::gregorian::date::ymd_type ymd = d.year_month_day();     // convert to y/m/d struct
    return Rcpp::wrap(Rcpp::Date(ymd.year, ymd.month, ymd.day));
}

inline boost::gregorian::date as_boost_date(RObject obj)
{
    if(!obj.inherits("Date"))
    {
        stop(std::string("not a Date object"));
    }

    Rcpp::Date dt(obj);
    return boost::gregorian::date(dt.getYear(), dt.getMonth(), dt.getDay());
}
