#include <math.h>
#include "sigmoide.h"

Sigmoide::Sigmoide(){}

double Sigmoide::operator()(double x)
{
    return (exp(x) - exp(-x)) / (exp(x) + exp (-x));
}

double Sigmoide::prim(double x)
{
    return 1 - pow((operator()(x)),2) ;
}

const char* Sigmoide::get_label(){
        return "sigmoide";
    }

Sigmoide::~Sigmoide()
{
    
}
