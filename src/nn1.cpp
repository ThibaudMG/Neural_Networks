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
    srand(time(NULL)); // Initialize seed
    for(int i=0; i<nb_labels; i++){
        Nn1::perceptrons.push_back(new Perceptron(input_size, activation, '0'+i));
    }

}

void Nn1::apprentissage ( pair<vector<double>, char>* input, double mu){
    for(int i=0; i<perceptrons.size(); i++){
        Perceptron* perceptron = perceptrons[i];
        //cout << "\nPerceptron " << perceptron->get_label() << endl;
        perceptron->backprop(input,mu);
        delete &perceptron;
    }
}

char Nn1::evaluation( pair<vector<double>, char>* input){
    char label = '0';
    double best_match = perceptrons[0]->forward(input);
    double A;
    cout << "Perceptron 0: " << to_string(best_match) << endl; 
    for(int i=1; i<perceptrons.size(); i++){
        Perceptron* perceptron = perceptrons[i];
        A = perceptron->forward(input);
        cout << "Perceptron " << i << ": " << to_string(A) << endl;
        if(A > best_match){
            label = '0'+ i;
            best_match = A;
        }

        delete &perceptron;
    }
    cout << "label = " << label << endl;
    return label;
}

Perceptron* Nn1::get_perceptron(int index){
    return Nn1::perceptrons[index];
}

Nn1::~Nn1()
{
    delete &perceptrons;
}
