#ifndef NN2
#define NN2

/*** Description ***
La classe NN2 sert à représenter un réseau de neurones avec une couche cachée.\
Cette classe a pour membre l’ensemble des perceptrons de la couche caché (chacun de la classe Perceptron_cachee), \
ainsi que l’ensemble des perceptrons de la couche de sortie (chacun de la classe Perceptron) qui constituent le réseau de neurones.
*/

#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <typeinfo>

#include "perceptron_cachee.h"
#include "iris.h"
#include "input.h"
#include "image.h"

using namespace std;

class Nn2
{
public:
    Nn2(int input_size, int nb_labels, int nb_perceptrons_cachee, Fonction_activation *activation);
    ~Nn2();

    char evaluation(Input &input);
    void apprentissage(Input &input, double learning_rate);
    Perceptron *get_perceptron(int index);

private:
    vector<Perceptron *> perceptrons;
    vector<Perceptron_cachee *> perceptrons_cachee;
};

template <class network_type, class input_type_class, int nb_input>
class Apprenstissage
{
public:
    Apprenstissage(network_type *network)
    {
        Apprenstissage::network = network;
    }

    void apprendre_base(int iterations, double learning_rate)
    {
        for (int i = 0; i < iterations; i++)
        {
            // Choix d'un input au hasard
            int index = (rand() % nb_input);
            input_type_class input(index);

            network->apprentissage(input, learning_rate);
            //cout << "iteration: " << i << endl;
        }
    }

    int evaluer()
    {
        int matched = 0;

        for (int i; i < nb_input; i++)
        {
            pair<vector<double>, char> formated_input;

            // Selection de l'input
            input_type_class input(i);

            // Get label to find
            char label = input.getLabel();

            // Evaluation
            //cout << "\nInput label: " << label << endl;
            if (label == network->evaluation(input))
                matched += 1;
        }

        return matched;
    }

private:
    network_type *network;
};

#endif