#ifndef NN1
#define NN1

/*** Description ***
La classe NN1 sert à représenter un réseau de neurones. 
Cette classe a pour membre l’ensemble des perceptrons qui constituent le réseau de neurones.
*/

#include <vector>
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

    char evaluation (pair<vector<double>, int>* input);
    void apprentissage (pair<vector<double>, int>* input, double mu);

private :
    vector<Perceptron*> perceptrons;
    
};

template<class input_type_class, int nb_input, class fonction_activation> class Apprenstissage
{
    public:
        Apprenstissage(Nn1* network){
            Apprenstissage::network = network;
        }

        void apprendre_base(int iterations, double mu){
            for(int i=0; i<iterations; i++){
                pair<vector<double>, int>* formated_input;

                // Choix d'un input au hasard
                input_type_class input(rand() % nb_input);

                // Convertion du format d'input
                if(typeid(input).name() == "Iris"){
                    for (int j=0; j<4; j++){
                        formated_input->first.push_back(input[j]);
                    }
                    formated_input->second = input.getLabel();
                    cout << formated_input->second << endl;
                }
                else if(typeid(input).name() == "Image"){
                    for (int j=0; j<784; j++){
                        formated_input->first.push_back(input[j]);
                    }
                    formated_input->second = input.getLabel();
                }

                // Apprentissage du NN
                network->apprentissage(formated_input, mu);
            }
        }

        int evaluer(){
            int matched = 0;

            for(int i; i< nb_input; i++){
                pair<vector<double>, int>* formated_input;
                
                // Selection de l'input
                input_type_class input(i);
                char label = input.getLabel();

                // Convertion du format d'input
                if(typeid(input).name() == "Iris"){
                    for (int j=0; j<4; j++){
                        formated_input->first.push_back(input[j]);
                    }
                    formated_input->second = input.getLabel();
                }
                else if(typeid(input).name() == "Image"){
                    for (int j=0; j<784; j++){
                        formated_input->first.push_back(input[j]);
                    }
                    formated_input->second = input.getLabel();
                }

                // Evaluation
                if(label == network->evaluation(formated_input)) matched++;

            }

            return matched;
        }

        

    private:
        Nn1* network;
};

#endif