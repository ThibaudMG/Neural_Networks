#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <typeinfo>
#include "sigmoide.h"
#include "perceptron.h"

Perceptron::Perceptron(int input_size, Fonction_activation *activation, char label)
{
    Perceptron::input_size = input_size;

    // Initialisation poids
    for (int i = 0; i < Perceptron::input_size + 1; i++)
    {
        int ran = rand() % 2; // Random int between 0 and 1
        if (ran > 0)
            Perceptron::poids.push_back(1.);
        else
            Perceptron::poids.push_back(0.);
    }

    // Initialisation fonction d'activation
    Perceptron::activation = activation;

    // Initialisation label
    Perceptron::label = label;
}

double Perceptron::forward(Input &input)
{
    double res, somme = 0.;
    for (int i = 0; i < Perceptron::input_size; i++)
        somme += Perceptron::get_poids(i + 1) * input[i];

    //res = activation->operator()((Perceptron::get_poids(0) + somme)/10.);
    res = activation->operator()(Perceptron::get_poids(0) + somme); // Too high values (ex:0.99999; 1.0; 1.0)
    //if(res >= 0.5 ) return 1.0;
    //else return 0.;
    return res;
}

double Perceptron::calcul_delta(Input &input)
{
    double somme = 0.;
    for (int i = 0; i < Perceptron::input_size; i++)
        somme += Perceptron::get_poids(i + 1) * input[i];

    if (Perceptron::get_label() == input.getLabel())
    {
        Perceptron::delta = activation->prim(get_poids(0) + somme) * (forward(input) - 1.);
    }
    else
    {
        Perceptron::delta = activation->prim(get_poids(0) + somme) * (forward(input) - 0.);
    }

    //double forwd = forward(input);
    //if (forwd > 0.5) Perceptron::delta = 0;
    //else Perceptron::delta = activation->prim(get_poids(0) + somme) * (forwd - (input->getLabel() - '0') );
    //Perceptron::delta = activation->prim(get_poids(0) + somme) * (forward(input) - (Perceptron::get_label() - '0') );
    return Perceptron::delta;
}

void Perceptron::backprop(Input &input, double learning_rate)
{
    Perceptron::poids[0] = get_poids(0) - learning_rate * Perceptron::calcul_delta(input);
    //cout << get_delta() << endl;
    for (int i = 0; i < Perceptron::input_size; i++)
    {
        Perceptron::poids[i + 1] = get_poids(i + 1) - learning_rate * input[i] * get_delta();
    }
}

double Perceptron::get_delta()
{
    return Perceptron::delta;
}

char Perceptron::get_label()
{
    return Perceptron::label;
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
