#ifndef SIGMOIDE
#define SIGMOIDE

/*** Description ***
La classe Sigmoide descend de la classe Fonction_activation et correspond tout simplement à la fonction sigmoïde
Cette classe surdéfinie naturellement l’opérateur () et la fonction membre prim.
*/

#include <math.h>
#include "fonction_activation.h"

class Sigmoide : public Fonction_activation
{
public:
    Sigmoide(); // Constructeur, prenant en parametre un entier correspondant à l’indice de la fleur (entier entre 0 et 149)
    ~Sigmoide();

    double operator()(double x) override{
        return 1 / (1 + exp(-x)) ;
    }

    double prim(double x) override{
        return 1 - operator()(x);
    }

    const char* get_label() override{
        return "sigmoide";
    }

private :

};

#endif