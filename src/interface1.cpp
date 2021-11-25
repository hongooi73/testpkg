#include <Rcpp.h>
#include <boost/date_time/gregorian/gregorian_types.hpp>

// [[Rcpp::depends(BH)]]

using namespace Rcpp;

SEXP as_rcpp_date(const boost::gregorian::date &d)
{
    boost::gregorian::date::ymd_type ymd = d.year_month_day();     // convert to y/m/d struct
    return Rcpp::wrap(Rcpp::Date(ymd.year, ymd.month, ymd.day));
}

boost::gregorian::date as_boost_date(SEXP dtsexp)
{
    Rcpp::Date dt(dtsexp);
    return boost::gregorian::date(dt.getYear(), dt.getMonth(), dt.getDay());
}


// [[Rcpp::export]]
Rcpp::Date convdate(SEXP indate)
{
    boost::gregorian::date bdate = as_boost_date(indate);
    Rcpp::Date outdate = as_rcpp_date(bdate);
    return outdate;
}

