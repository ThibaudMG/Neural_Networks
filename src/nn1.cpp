#include <iostream>
#include <fstream>
#include <string>
#include "nn1.h"

Nn1::Nn1(int input_size, int nb_labels)
{
    // Choix fonction d'activation
    Fonction_activation* activation = new Tanh();

    // Initialisation du NN
    for(int i=0; i<nb_labels; i++){
        Nn1::network.push_back(new Perceptron(input_size, activation, i));
    }

}

char Nn1::evaluation( pair<vector<double>, int> &input){
    char label = 0;
    double best_match = network[0]->forward(input);
    
    for(int i=1; i<network.size(); i++){
        Perceptron* perceptron = network[i];
        if(perceptron->forward(input) > best_match) label = i;
        delete perceptron;
    }
    
    return label;
}

void Nn1::apprentissage ( pair<vector<double>, int> &input, double mu){
    for(int i=1; i<network.size(); i++){
        Perceptron* perceptron = network[i];
        perceptron->backprop(input,mu);
        delete perceptron;
    }
}

Nn1::~Nn1()
{
    delete &network;
}
