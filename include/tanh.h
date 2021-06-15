#ifndef TANH
#define TANH

/*** Description ***
La classe Tanh descend de la classe Fonction_activation et correspond tout simplement à la tangente hyperbolique.
Cette classe surdéfinie naturellement l’opérateur () et la fonction membre prim.
*/

#include "fonction_activation.h"

class Tanh : public Fonction_activation
{
public:
    Tanh();
    ~Tanh();

    double operator()(double x) override;

    double prim(double x) override;

    const char *get_label() override;

private:
};

#endif