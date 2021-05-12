#ifndef SIGMOIDE
#define SIGMOIDE

/*** Description ***
La classe Sigmoide descend de la classe Fonction_activation et correspond tout simplement à la fonction sigmoïde
Cette classe surdéfinie naturellement l’opérateur () et la fonction membre prim.
*/

#include "fonction_activation.h"

class Sigmoide : public Fonction_activation
{
public:
    Sigmoide(); // Constructeur, prenant en parametre un entier correspondant à l’indice de la fleur (entier entre 0 et 149)
    ~Sigmoide();

    double operator()(double x) override;

    double prim(double x) override;

    const char* get_label() override;

private :

};

#endif