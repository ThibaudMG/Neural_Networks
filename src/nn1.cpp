#include <iostream>
#include <fstream>
#include <string>
#include "nn1.h"
#include "tanh.h"
#include "sigmoide.h"

Nn1::Nn1(int input_size, int nb_labels, Fonction_activation* activation)
{
    // Initialisation du NN
    srand(time(NULL)); // Initialize seed
    for(int i=0; i<nb_labels; i++){
        Nn1::perceptrons.push_back(new Perceptron(input_size, activation, '0'+i));
    }

}

void Nn1::apprentissage (Input* input, double learning_rate){
    //cout << endl;
    for(int i=0; i<perceptrons.size(); i++){
        //cout << "Perceptron:" << perceptrons[i]->get_label() << ", Input label:" << input->getLabel() << endl;
        perceptrons[i]->backprop(input,learning_rate);
    }
}

char Nn1::evaluation(Input* input){
    char label = '0';
    double best_match = perceptrons[0]->forward(input);
    double A;
    //cout << "Perceptron 0: " << to_string(best_match) << endl; 
    
    for(int i=1; i<perceptrons.size(); i++){    
        A = perceptrons[i]->forward(input);
        //cout << "Perceptron " << i << ": " << to_string(A) << endl;
        if(A > best_match){
            label = '0'+ i;
            best_match = A;
        }
    }
    //cout << "Label found: " << label << endl;
    return label;
}

Perceptron* Nn1::get_perceptron(int index){
    return Nn1::perceptrons[index];
}

Nn1::~Nn1()
{
    delete &perceptrons;
}
