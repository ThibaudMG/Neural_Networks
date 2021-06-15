#include <iostream>
#include <fstream>
#include <string>

#include "nn1.h"
#include "nn2.h"
#include "iris.h"
#include "image.h"
#include "sigmoide.h"
#include "tanh.h"

using namespace std;

int main(int argc, char *argv[])
{
    string nn;
    string in;

    // Get arguments
    if (argc != 3)
    {
        cout << "Please provide a neural network type [nn1/nn2] then an input class [iris/image]" << endl;
        return 0;
    }
    else
    {
        cout << argv[0] << ";" << argv[1] << ";" << argv[2] << endl;
        nn = argv[1];
        in = argv[2];
        cout << argv[0] << ";" << nn << ";" << in << endl;
    }
    int res;

    // Use the wright network/input
    if (nn == "nn1")
    {
        cout << "NN1, ";
        if (in == "image")
        {
            cout << "Image" << endl;
            Nn1 *network = new Nn1(789, 9, new Sigmoide());           //Nn1(int input_size, int nb_labels, Fonction_activation* activation)
            Apprenstissage<Nn1, Image, 60000> apprentissage(network); //Apprentissage<class network, class input_type_class, int nb_input> Apprenstissage(Nn1 *network)
            apprentissage.apprendre_base(100000, 0.1);
            cout << "Learning done." << endl;
            // Pause the program
            cout << "Press Enter to continue..." << endl;
            getc(stdin);
            // Results
            res = apprentissage.evaluer();
            cout << "\n--- Taux de classification: " << to_string(100 * res / 60000.) << "% ---" << endl;
            delete network;
        }
        else
        {                                                          // Iris input by default
            cout << "Iris" << endl;
            Nn1 *network = new Nn1(4, 3, new Sigmoide());          //Nn1(int input_size, int nb_labels, Fonction_activation* activation)
            Apprenstissage<Nn1, Iris, 150> apprentissage(network); //Apprentissage<class network, class input_type_class, int nb_input> Apprenstissage(Nn1 *network)
            apprentissage.apprendre_base(10000, 0.01);
            cout << "Learning done." << endl;
            // Pause the program
            cout << "Press Enter to continue..." << endl;
            getc(stdin);
            // Results
            res = apprentissage.evaluer();
            cout << "\n--- Taux de classification: " << to_string(100 * res / 150.) << "% ---" << endl;
            delete network;
        }
    }
    else if (nn == "nn2")
    {
        cout << "NN2, ";
        if (in == "image")
        {
            cout << "Image" << endl;
            Nn2 *network = new Nn2(789, 9, 9, new Sigmoide());        //Nn1(int input_size, int nb_labels, Fonction_activation* activation)
            Apprenstissage<Nn2, Image, 60000> apprentissage(network); //Apprentissage<class network, class input_type_class, int nb_input> Apprenstissage(Nn1 *network)
            apprentissage.apprendre_base(100000, 0.1);
            cout << "Learning done." << endl;
            // Pause the program
            cout << "Press Enter to continue..." << endl;
            getc(stdin);
            // Results
            res = apprentissage.evaluer();
            cout << "\n--- Taux de classification: " << to_string(100 * res / 60000.) << "% ---" << endl;
            delete network;
        }
        else
        {                                                          // Iris input by default
            cout << "Iris" << endl;
            Nn2 *network = new Nn2(4, 3, 3, new Sigmoide());       //Nn1(int input_size, int nb_labels, Fonction_activation* activation)
            Apprenstissage<Nn2, Iris, 150> apprentissage(network); //Apprentissage<class network, class input_type_class, int nb_input> Apprenstissage(Nn1 *network)
            apprentissage.apprendre_base(10000, 0.01);
            cout << "Learning done." << endl;
            // Pause the program
            cout << "Press Enter to continue..." << endl;
            getc(stdin);
            // Results
            res = apprentissage.evaluer();
            cout << "\n--- Taux de classification: " << to_string(100 * res / 150.) << "% ---" << endl;
            delete network;
        }
    }
    else
    {
        cout << "Wrong network type provided, please choose \"nn2\" or \"nn1\"" << endl;
        return 0;
    }

    return 0;
}