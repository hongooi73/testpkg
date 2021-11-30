#include <memory>
#include <Rcpp.h>

using namespace Rcpp;

namespace testpkg
{

template<typename T>
static T* get_interface_pointer(Environment env)
{
    SEXP objptr = env[".pointer"];
    if(objptr == R_NilValue)
    {
        stop("invalid object supplied");
    }
    return (T*) R_ExternalPtrAddr(objptr);
}

}
