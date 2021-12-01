#include <memory>
#include <Rcpp.h>

using namespace Rcpp;

namespace testpkg
{

template<typename T>
static T* get_interface_pointer(RObject obj, const char* target_class)
{
    if(!obj.inherits(target_class))
    {
        stop(std::string("expecting an object of class ") + target_class);
    }
    Environment env = as<Environment>(obj);
    SEXP objptr = env[".pointer"];
    if(objptr == R_NilValue)
    {
        stop("invalid object supplied");
    }
    return (T*) R_ExternalPtrAddr(objptr);
}

}
