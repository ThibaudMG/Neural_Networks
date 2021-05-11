#include <iostream>
#include <fstream>
#include <string>
#include "nn1.h"
#include "tanh.h"
#include "sigmoide.h"

Nn1::Nn1(int input_size, int nb_labels)
{
    // Choix fonction d'activation
    Fonction_activation* activation = new Tanh();

    // Initialisation du NN
    for(int i=0; i<nb_labels; i++){
        Nn1::perceptrons.push_back(new Perceptron(input_size, activation, i));
    }

}

char Nn1::evaluation( pair<vector<double>, int> &input){
    char label = 0;
    double best_match = perceptrons[0]->forward(input);
    
    for(int i=1; i<perceptrons.size(); i++){
        Perceptron* perceptron = perceptrons[i];
        if(perceptron->forward(input) > best_match) label = i;
        delete perceptron;
    }
    
    return label;
}

void Nn1::apprentissage ( pair<vector<double>, int> &input, double mu){
    for(int i=1; i<perceptrons.size(); i++){
        Perceptron* perceptron = perceptrons[i];
        perceptron->backprop(input,mu);
        delete perceptron;
    }
}

Nn1::~Nn1()
{
    delete &perceptrons;
}
