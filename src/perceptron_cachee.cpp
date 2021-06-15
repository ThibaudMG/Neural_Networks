#include <iostream>
#include <fstream>

#include "perceptron_cachee.h"
#include "perceptron.h"

Perceptron_cachee::Perceptron_cachee(int input_size, Fonction_activation *activation, char label, const vector<Perceptron*> &perceptrons)
{
    Perceptron_cachee::input_size = input_size;

    // Initialisation perceptrons
    Perceptron_cachee::perceptrons = perceptrons;
 
    // Initialisation poids
    for (int i = 0; i < input_size + 1; i++)
    {
        int ran = rand() % 2; // Random int between 0 and 1
        if (ran > 0)
            Perceptron_cachee::poids.push_back(1.);
        else
            Perceptron_cachee::poids.push_back(0.);
    }

    // Initialisation fonction d'activation
    Perceptron_cachee::activation = activation;

    // Initialisation label
    Perceptron_cachee::label = label;
}

double Perceptron_cachee::calcul_input_inter(Input &input)
{
    double somme = 0.;
    for (int i = 0; i < input_size; i++){
        somme += get_poids(i + 1) * input[i];
    } 
    
    //cout << endl << "arg= " << to_string(get_poids(0) + somme) << endl;
    return activation->operator()(get_poids(0) + somme);
}

double Perceptron_cachee::calcul_delta(Input &input)
{
    double somme1 = 0., somme2 = 0.;
    // Calcul somme 1
    for (int i = 0; i < input_size; i++)
        somme1 += get_poids(i + 1) * input[i];

    // Calcul somme 2, en selectionnant le perceptron de meme label que l'input
    for (std::vector<Perceptron *>::iterator perceptron = perceptrons.begin(); perceptron != perceptrons.end(); ++perceptron)
    {
        if ((*perceptron)->get_label() == input.getLabel())
        {
            for (int i = 0; i < input_size; i++)
                somme2 += (*perceptron)->get_poids(i + 1) * (*perceptron)->get_delta();
        }
    }

    delta = activation->prim(get_poids(0) + somme1) * somme2;
    return delta;
}

void Perceptron_cachee::backprop(Input &input, double learning_rate)
{
    poids[0] = get_poids(0) - learning_rate * calcul_delta(input);

    for (int i = 0; i < input_size; i++)
    {
        poids[i + 1] = get_poids(i + 1) - learning_rate * input[i] * get_delta();
    }
}

double Perceptron_cachee::get_delta()
{
    return Perceptron_cachee::delta;
}

char Perceptron_cachee::get_label()
{
    return Perceptron_cachee::label;
}

double Perceptron_cachee::get_poids(int index)
{
    return Perceptron_cachee::poids[index];
}

Fonction_activation *Perceptron_cachee::get_activation()
{
    return Perceptron_cachee::activation;
}

Perceptron_cachee::~Perceptron_cachee()
{
    delete &label;
    delete &poids;
    delete &facteur_gradient;
    delete &delta;
    delete &input_size;
    perceptrons.clear();
    vector<Perceptron *>().swap(perceptrons); // free memory
}
