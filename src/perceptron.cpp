#include <iostream>
#include <fstream>
#include <string>
#include "perceptron.h"

Perceptron::Perceptron(int input_size, Fonction_activation* activation, char label)
{
    Perceptron::input_size = input_size;
    // Initialisation poids
    for(int i=0; i<Perceptron::input_size + 1; i++){
        Perceptron::poids[i] = rand();
    }
    
    // Initialisation fonction d'activation
    Perceptron::activation = activation;

    // Initialisation label
    Perceptron::label = label;
}

double Perceptron::forward(pair<vector<double>, int>* input)
{
    double res, somme = 0;
    for(int i=0; i<Perceptron::input_size; i++) somme += Perceptron::get_poids(i+1) * input->first[i];
    
    res = activation->operator()(Perceptron::get_poids(0) + somme);
    return res;
}

double Perceptron::calcul_delta(pair<vector<double>, int>* input)
{
    double somme = 0;
    for(int i=0; i<Perceptron::input_size; i++) somme += Perceptron::get_poids(i+1) * input->first[i];

    Perceptron::delta = activation->prim(get_poids(0) + somme) * (forward(input) - input->second);
    return Perceptron::delta;
}

void Perceptron::backprop(pair<vector<double>, int>* input, double mu)
{
    Perceptron::poids[0] = get_poids(0) - mu * get_delta();
    for(int i=0; i<Perceptron::input_size; i++){
        Perceptron::poids[i+1] = get_poids(i+1) - mu * input->first[i] * get_delta();
    }
}

double Perceptron::get_delta()
{
    return Perceptron::delta;
}

double Perceptron::get_poids(int index)
{
    return Perceptron::poids[index];
}

Perceptron::~Perceptron()
{
    delete &label;
    delete &poids;
    delete &facteur_gradient;
    delete &delta;
    delete &input_size;
}
