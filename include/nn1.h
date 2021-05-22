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
#include "image.h"

using namespace std;

class Nn1
{
public:
    Nn1(int input_size, int nb_labels); 
    ~Nn1();

    char evaluation (pair<vector<double>, char>* input);
    void apprentissage (pair<vector<double>, char>* input, double mu);
    Perceptron* get_perceptron(int index);

private :
    vector<Perceptron*> perceptrons;
    
};

template <class input_type_class, int nb_input, class fonction_activation> class Apprenstissage
{
    public:
        Apprenstissage(Nn1* network){
            Apprenstissage::network = network;
        }

        void apprendre_base(int iterations, double mu){
            for(int i=0; i<iterations; i++){
                pair<vector<double>, char> formated_input; //faut pas mmetre *

                // Choix d'un input au hasard
                int index = (rand() % nb_input);
                input_type_class input(index);
                
                string class_name = typeid(input).name();
                class_name = class_name.substr(1);
                //cout << "Input choosed: " << class_name << " " << index<< endl;

                // Convertion du format d'input
                if(class_name == "Iris"){
                    for (int j=0; j<4; j++){
                        formated_input.first.push_back((double) input[j]);
                    }
                    formated_input.second = input.getLabel();
                }
                else if(class_name == "Image"){
                    for (int j=0; j<784; j++){
                        formated_input.first.push_back((double) input[j]);
                    }
                    formated_input.second = input.getLabel();
                }
                else cout << "Error Input type class";

                // Apprentissage du NN
                if(i==0 || i==iterations-1) {
                    cout << "Perceptron 1" << endl;
                    for(int j=0; j<network->get_perceptron(0)->input_size + 1; j++){
                        cout << "poids[" << j << "] = "<< to_string(network->get_perceptron(0)->get_poids(j)) << "; ";
                    }
                    cout << endl;

                    cout << "Perceptron 2" << endl;
                    for(int j=0; j<network->get_perceptron(1)->input_size + 1; j++){
                        cout << "poids[" << j << "] = "<< to_string(network->get_perceptron(1)->get_poids(j)) << "; ";
                    }
                    cout << endl;

                    cout << "Perceptron 3" << endl;
                    for(int j=0; j<network->get_perceptron(2)->input_size + 1; j++){
                        cout << "poids[" << j << "] = "<< to_string(network->get_perceptron(2)->get_poids(j)) << "; ";
                    }
                    cout << "\n" << endl;
                }
                
                network->apprentissage(&formated_input, mu);
            }
        }

        int evaluer(){
            int matched = 0;

            for(int i; i< nb_input; i++){
                pair<vector<double>, char> formated_input;
                
                // Selection de l'input
                input_type_class input(i);

                // Get input class name
                string class_name = typeid(input).name();
                class_name = class_name.substr(1);

                // Get label to find
                char label = input.getLabel();

                // Convertion du format d'input
                if(class_name == "Iris"){
                    for (int j=0; j<4; j++){
                        formated_input.first.push_back((double) input[j]);
                    }
                    formated_input.second = label;
                }
                else if(class_name == "Image"){
                    for (int j=0; j<784; j++){
                        formated_input.first.push_back((double) input[j]);
                    }
                    formated_input.second = label;
                }
                else cout << "Error Input type class";

                // Evaluation
                cout << "\nInput label: " << label << endl;
                if(label == network->evaluation(&formated_input)) matched+= 1;

            }

            return matched;
        }

        

    private:
        Nn1* network;
};

#endif