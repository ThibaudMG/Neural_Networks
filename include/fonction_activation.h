#ifndef FONCTIONS_ACTIVATION
#define FONCTIONS_ACTIVATION

/*** Description ***
La classe Fonction_activation est une classe abstraite dont les classes héritées représenterons les différentes fonctions d’activation possibles.
Cette classe possède les méthodes nécessaires à toute fonction d’activation pour être utilisée par l’algorithme du perceptron.
*/

// Abstract class (with "virtual" methods)
class Fonction_activation
{
public:  
    virtual double operator()(double parametre) = 0; // L’opérateur () qui prend en paramètre une valeur réelle (double) et \
    qui renvoie une valeur réelle (double) correspondant à l’application de la fonction d’activation au paramètre
    
    virtual double prim(double parametre) = 0; // Une fonction membre prim qui prend en paramètre une valeur réelle (double) et qui renvoie une valeur réelle (double) \
    correspondant à l’application de la dérivée de la fonction d’activation au paramètre.

    virtual const char* get_label() = 0;

private:

};

#endif