#include <iostream>
#include <fstream>
#include <string>

#include "nn1.h"
#include "nn2.h"
//#include "apprentissage.h"
#include "iris.h"
#include "image.h"
#include "sigmoide.h"
#include "tanh.h"

using namespace std;

int main(int argc, char *argv[])
{
    int res;

    // Nn2(int input_size, int nb_labels, int nb_perceptrons_cachee, Fonction_activation *activation)
    Nn2 *network = new Nn2(784, 9, 9, new Sigmoide());

    // Apprentissage<class input_type_class, int nb_input> Apprenstissage(Nn *network)
    Apprenstissage<Nn2, Image, 60000> apprentissage(network);

    apprentissage.apprendre_base(100000, 0.1);
    cout << "Learning done." << endl;

    // Pause the program
    cout << "Press Enter to continue" << endl;
    getc(stdin);


    res = apprentissage.evaluer();
    cout << "\n--- Taux de classification: " << to_string(100 * res / 60000.) << "% ---" << endl;

    delete network;

    return 0;
}