#include <math.h>
#include "tanh.h"

Tanh::Tanh(){}

double Tanh::operator()(double x)
{
    return (exp(x) - exp(-x)) / (exp(x) + exp (-x));
}

double Tanh::prim(double x)
{
    return 1. - pow((operator()(x)),2) ;
}

const char* Tanh::get_label(){
        return "tanh";
    }

Tanh::~Tanh()
{
    
}
