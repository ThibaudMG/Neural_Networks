#ifndef PERCEPTRON_CACHEE
#define PERCEPTRON_CACHEE

/*** Description ***
La classe Perceptron_cachee sert à représenter un perceptron de la couche cachée et descend de la classe Perceptron. \
Il hérite donc des champs correspondant au vecteur de poids et au label de la classe Perceptron. \
La différence avec un perceptron classique se trouve essentiellement au niveau du calcul de 𝛿𝑠(1) qui dépend des valeurs 𝛿𝑙(2) des perceptrons de la couche cachée.
*/

#include <utility>
#include "perceptron.h"

class Perceptron_cachee : public Perceptron
{
public:
    Perceptron_cachee(int input_size, Fonction_activation *activation, char label, const vector<Perceptron *> &perceptrons);
    ~Perceptron_cachee();

    double calcul_input_inter(Input &input);
    double calcul_delta(Input &input);
    void backprop(Input &input, double learning_rate);

    double get_poids(int index);
    double get_delta();
    char get_label();
    Fonction_activation *get_activation();
    int input_size;

private:
    vector<double> poids;
    Fonction_activation *activation;
    float facteur_gradient; // le facteur commun à toutes les coordonnées du gradient
    char label;             // le label (qui n’aura pas vraiment le sens de catégorie) correspondra à l’indice du perceptron dans le vecteur
    double delta;
    vector<Perceptron *> perceptrons;
};

#endif