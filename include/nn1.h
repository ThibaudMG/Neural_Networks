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

    char evaluation(Input &input);
    void apprentissage(Input &input, double learning_rate);
    Perceptron *get_perceptron(int index);

private:
    vector<Perceptron *> perceptrons;
};

#endif