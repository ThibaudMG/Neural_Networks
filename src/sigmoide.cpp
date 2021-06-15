#include <math.h>
#include "sigmoide.h"

Sigmoide::Sigmoide() {}

double Sigmoide::operator()(double x)
{
    return 1. / (1. + exp(-x));
}

double Sigmoide::prim(double x)
{
    return operator()(x) * (1. - operator()(x));
}

const char *Sigmoide::get_label()
{
    return "sigmoide";
}

Sigmoide::~Sigmoide()
{
}
