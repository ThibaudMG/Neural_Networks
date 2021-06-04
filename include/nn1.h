#ifndef NN1
#define NN1

/*** Description ***
La classe NN1 sert à représenter un réseau de neurones. 
Cette classe a pour membre l’ensemble des perceptrons qui constituent le réseau de neurones.
*/

#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <typeinfo>

#include "perceptron.h"
#include "iris.h"
#include "input.h"
#include "image.h"

using namespace std;

class Nn1
{
public:
    Nn1(int input_size, int nb_labels, Fonction_activation *activation);
    ~Nn1();

    char evaluation(Input *input);
    void apprentissage(Input *input, double learning_rate);
    Perceptron *get_perceptron(int index);

private:
    vector<Perceptron *> perceptrons;
};

template <class input_type_class, int nb_input>
class Apprenstissage
{
public:
    Apprenstissage(Nn1 *network)
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

            /*string class_name = typeid(input).name();
            class_name = class_name.substr(1);
            cout << "Input choosed: " << class_name << " " << index<< endl;*/

            // Apprentissage du NN
            /*if (i == 0)
            {
                cout << "Perceptron 1" << endl;
                for (int j = 0; j < network->get_perceptron(0)->input_size + 1; j++)
                {
                    cout << "poids[" << j << "] = " << to_string(network->get_perceptron(0)->get_poids(j)) << "; ";
                }
                cout << endl;

                cout << "Perceptron 2" << endl;
                for (int j = 0; j < network->get_perceptron(1)->input_size + 1; j++)
                {
                    cout << "poids[" << j << "] = " << to_string(network->get_perceptron(1)->get_poids(j)) << "; ";
                }
                cout << endl;

                cout << "Perceptron 3" << endl;
                for (int j = 0; j < network->get_perceptron(2)->input_size + 1; j++)
                {
                    cout << "poids[" << j << "] = " << to_string(network->get_perceptron(2)->get_poids(j)) << "; ";
                }
                cout << "\n"
                     << endl;
            }*/

            network->apprentissage(&input, learning_rate);
            cout << "iteration: " << i << endl;
            /*if (i == iterations - 1)
            {
                cout << "Perceptron 1" << endl;
                for (int j = 0; j < network->get_perceptron(0)->input_size + 1; j++)
                {
                    cout << "poids[" << j << "] = " << to_string(network->get_perceptron(0)->get_poids(j)) << "; ";
                }
                cout << endl;

                cout << "Perceptron 2" << endl;
                for (int j = 0; j < network->get_perceptron(1)->input_size + 1; j++)
                {
                    cout << "poids[" << j << "] = " << to_string(network->get_perceptron(1)->get_poids(j)) << "; ";
                }
                cout << endl;

                cout << "Perceptron 3" << endl;
                for (int j = 0; j < network->get_perceptron(2)->input_size + 1; j++)
                {
                    cout << "poids[" << j << "] = " << to_string(network->get_perceptron(2)->get_poids(j)) << "; ";
                }
                cout << "\n"
                     << endl;
            }*/
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
            if (label == network->evaluation(&input))
                matched += 1;
        }

        return matched;
    }

private:
    Nn1 *network;
};

#endif