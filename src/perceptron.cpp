#include "perceptron.h"
//#include "..\include\iris.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Perceptron::Perceptron(int input_size, Fonction_activation* activation, char label)
{
    Perceptron::input_size = input_size;
    // Initialisation poids
    for(int i=0; i<Perceptron::input_size; i++){
        Perceptron::poids[i] = rand();
    }
    
    // Initialisation fonction d'activation
    Perceptron::activation = activation;

    // Initialisation label
    Perceptron::label = label;
}

double Perceptron::forward(pair<vector<double>, int> &input)
{
    double res, somme = 0;
    for(int i=0; i<Perceptron::input_size; i++) somme += Perceptron::get_poids(i) * get<0>(input)[i];
    
    res = activation->operator()(Perceptron::get_poids(0) + somme);
    return res;
}

double Perceptron::calcul_delta(pair<vector<double>, int> &input) // 𝛿(𝑘−1)=𝜑′(𝑤(0,𝑘−1)+Σ𝑤(𝑖,𝑘)−1𝑥𝑖𝑛𝑖= 1)×(𝒜(𝒙𝒋)−𝑦𝑗)pour l’input (𝒙𝑗,𝑦𝑗) donné en paramètre
{
    double somme = 0;
    for(int i=0; i<Perceptron::input_size; i++) somme += Perceptron::get_poids(i) * get<0>(input)[i];

    Perceptron::delta = activation->prim(get_poids(0) + somme) * (forward(input) - get<1>(input));
    return Perceptron::delta;
}

void Perceptron::backprop(pair<vector<double>, int> &input, double mu)
{
    Perceptron::poids[0] = get_poids(0) - mu * delta;
    for(int i=1; i<Perceptron::input_size; i++){
        Perceptron::poids[i] = get_poids(i) - mu * get<0>(input)[i] * Perceptron::delta;
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
}


///// TODO
/*
input = pair(vector<double>, int)*/