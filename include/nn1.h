#ifndef NN1
#define NN1

/*** Description ***
La classe NN1 sert à représenter un réseau de neurones. 
Cette classe a pour membre l’ensemble des perceptrons qui constituent le réseau de neurones.
*/

#include <vector>
#include "perceptron.h"
#include "tanh.h"
#include "sigmoide.h"

class Nn1
{
public:
    Nn1(int input_size, int nb_labels); 
    ~Nn1();

    char evaluation ( pair<vector<double>, int> &input);
    void apprentissage ( pair<vector<double>, int> &input, double mu);

private :
    vector<Perceptron*> network;
    
};

#endif