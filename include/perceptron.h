#ifndef PERCEPTRON
#define PERCEPTRON

/*** Description ***
La classe Tanh descend de la classe Fonction_activation et correspond tout simplement à la tangente hyperbolique.
Cette classe surdéfinie naturellement l’opérateur () et la fonction membre prim.
*/

#include <vector>
#include "fonction_activation.h"

using namespace std;

class Perceptron
{
public:
    Perceptron(int input_size, Fonction_activation* activation, char label); // Un constructeur qui prend en paramètre un entier correspondant à la taille de l’input (par exemple, 4 pour les fleurs et 784 pour les images), une fonction d’activation (de préférence un pointeur pour avoir une même fonction d’activation commune à tous les perceptrons), ainsi qu’un char correspondant au label du perceptron. Le constructeur va initialiser les poids du perceptron de manière aléatoire (par exemple en choisissant des valeurs entières entre -1 et 1 aléatoirement).
    ~Perceptron();

    double forward (pair<vector<double>, int>* input); // Une fonction membre forward qui prend en paramètre un Input (de préférence par référence), et qui renvoie une valeur réelle (double) correspondant à l’application de l’algorithme du perceptron à l’input en paramètre (correspond au calcul de 𝒜(𝒙)).
    double calcul_delta (pair<vector<double>, int>* input);
    void backprop (pair<vector<double>, int>* input, double mu); // Une fonction membre backprop qui prend en paramètre un Input (de préférence par référence), ainsi qu’une valeur réelle (double) correspondant au pas de gradient 𝜇, et qui ne renvoie rien. Cette fonction va apprendre les poids à partir de l’input en paramètre en utilisant la formule \
    w(i,k) = w(i,k-1) - mu*delta(k-1) si i = 0 \
             w(i,k-1) - mu*x(i)*delta(k-1) sinon
    
    double get_poids (int index); // Une fonction membre get_poids qui prend en paramètre un indice (int) et renvoie une valeur réelle (double) correspondant à la valeur du poids correspondant à l’indice en paramètre.
    double get_delta();

private :
    vector<double> poids;
    Fonction_activation* activation;
    float facteur_gradient; // le facteur commun à toutes les coordonnées du gradient
    char label;
    double delta; // pour la fonction calcul_delta
    int input_size;
    
};

#endif