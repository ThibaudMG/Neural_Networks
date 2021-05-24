#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "perceptron.h"

Perceptron::Perceptron(int input_size, Fonction_activation* activation, char label)
{
    Perceptron::input_size = input_size;
    
    
    // Initialisation poids
    for(int i=0; i<Perceptron::input_size + 1; i++){
        int ran = rand()%2; // Random int between 0 and 1
        if(ran>0) Perceptron::poids.push_back(1.);
        else Perceptron::poids.push_back(-1.);
        
    }
    
    // Initialisation fonction d'activation
    Perceptron::activation = activation;

    // Initialisation label
    Perceptron::label = label;
}

double Perceptron::forward(Input* input)
{
    //cout << "Forward" << endl;
    double res, somme = 0;
    for(int i=0; i<Perceptron::input_size; i++) somme += Perceptron::get_poids(i+1) * input->operator[](i);
    
    /*cout << "poids= {" << to_string(get_poids(0)) << "; " << to_string(get_poids(1)) << "; " \
    << to_string(get_poids(2)) << "; " << to_string(get_poids(3)) << "; " << to_string(get_poids(4)) << "} "<< endl;
    
    */
    //cout << "arg = " << Perceptron::get_poids(0) + somme << endl;
    res = activation->operator()(Perceptron::get_poids(0) + somme); // arg trop grand -> donne toujours 1 !
    return res;
}

double Perceptron::calcul_delta(Input* input)
{
    //cout << "calcul delta" << endl;
    double somme = 0;
    for(int i=0; i<Perceptron::input_size; i++) somme += Perceptron::get_poids(i+1) * input->operator[](i);
    Perceptron::delta = activation->prim(get_poids(0) + somme) * (forward(input) - input->getLabel());
    return Perceptron::delta;
}

void Perceptron::backprop(Input* input, double mu)
{
    Perceptron::poids[0] = get_poids(0) - mu * Perceptron::calcul_delta(input);

    for(int i=0; i<Perceptron::input_size; i++){
        Perceptron::poids[i+1] = get_poids(i+1) - mu * input->operator[](i) * get_delta();
        //cout << "poid: " << get_poids(i+1) << endl;
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
