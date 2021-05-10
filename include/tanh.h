#ifndef TANH
#define TANH

/*** Description ***
La classe Tanh descend de la classe Fonction_activation et correspond tout simplement à la tangente hyperbolique.
Cette classe surdéfinie naturellement l’opérateur () et la fonction membre prim.
*/

#include <math.h>
#include "fonction_activation.h"

class Tanh : public Fonction_activation
{
public:
    Tanh();
    ~Tanh();

    double operator()(double x) override{
        return (exp(x) - exp(-x)) / (exp(x) + exp (-x));
    }

    double prim(double x) override{
        return 1 - pow((operator()(x)),2) ;
    }

const char* get_label() override{
        return "tanh";
    }

private :
    
};

#endif