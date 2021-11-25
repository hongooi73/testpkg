#include <Rcpp.h>
#include <boost/date_time/gregorian/gregorian_types.hpp>
#include "dateconv.h"

// [[Rcpp::depends(BH)]]

// [[Rcpp::export]]
Rcpp::Date convdate(SEXP indate)
{
    boost::gregorian::date bdate = as_boost_date(indate);
    Rcpp::Date outdate = as_rcpp_date(bdate);
    return outdate;
}

