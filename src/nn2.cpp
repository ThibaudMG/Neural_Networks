#include <iostream>
#include <fstream>
#include <string>
#include "nn2.h"
#include "input_intermediaire.h"
#include "tanh.h"
#include "sigmoide.h"

Nn2::Nn2(int input_size, int nb_labels, int nb_perceptrons_cachee, Fonction_activation *activation)
{
    // Initialisation du NN2
    srand(time(NULL)); // Initialize seed

    for (int i = 0; i < nb_labels; i++)
    {
        perceptrons.push_back(new Perceptron(input_size, activation, '0' + i));
    }
    for (int i = 0; i < nb_perceptrons_cachee; i++)
    {
        perceptrons_cachee.push_back(new Perceptron_cachee(input_size, activation, '0' + i, perceptrons));
    }
}

void Nn2::apprentissage(Input &input, double learning_rate)
{
    // 0.Creation d'un input intermediaire
    Input_intermediaire input_inter(input.getLabel());
    for (vector<Perceptron_cachee *>::iterator perceptron_it = perceptrons_cachee.begin(); perceptron_it != perceptrons_cachee.end(); ++perceptron_it)
    {  
        input_inter.add((*perceptron_it)->calcul_input_inter(input));
    }
    //for(int i=0; i<perceptrons_cachee.size(); i++) cout << input_inter[i] << "; ";
    //cout << endl;

    // 1.Calcul des delta de la couche de sortie et couche cachée
    for (int i = 0; i < perceptrons.size(); i++)
    {
        perceptrons[i]->calcul_delta(input_inter);
    }
    for (int i = 0; i < perceptrons_cachee.size(); i++)
    {
        perceptrons_cachee[i]->calcul_delta(input);
    }

    // 2.Calcul des delta et des poids de la couche cachee
    for (int i = 0; i < perceptrons_cachee.size(); i++)
    {
        perceptrons_cachee[i]->backprop(input, learning_rate);
    }

    // 3.Calcul des poids de la couche de sortie
    for (int i = 0; i < perceptrons.size(); i++)
    {
        perceptrons[i]->backprop(input_inter, learning_rate);
    }
}

char Nn2::evaluation(Input &input)
{
    // Calcul Input_intermediaire 𝒂(𝟏)=(𝑎1(1),…,𝑎𝑡(1))
    Input_intermediaire input_inter(input.getLabel());
    for (vector<Perceptron_cachee *>::iterator perceptron_it = perceptrons_cachee.begin(); perceptron_it != perceptrons_cachee.end(); ++perceptron_it)
    {
        input_inter.add((*perceptron_it)->calcul_input_inter(input));
    }

    // Calcul sortie en passant l'input intermediaire en entree du perceptron de sortie
    char label = '0';
    double best_match = perceptrons[0]->forward(input_inter);
    double A;
    //cout << "Perceptron 0: " << to_string(best_match) << endl;

    for (int i = 1; i < perceptrons.size(); i++)
    {
        A = perceptrons[i]->forward(input_inter);
        //cout << "Perceptron " << i << ": " << to_string(A) << endl;
        if (A > best_match)
        {
            label = '0' + i;
            best_match = A;
        }
    }
    //cout << "Label found: " << label << endl;
    return label;
}

Perceptron *Nn2::get_perceptron(int index)
{
    return Nn2::perceptrons[index];
}

Nn2::~Nn2()
{
    perceptrons.clear();
    perceptrons_cachee.clear();
    vector<Perceptron *>().swap(perceptrons);               // free memory
    vector<Perceptron_cachee *>().swap(perceptrons_cachee); // free memory
}
