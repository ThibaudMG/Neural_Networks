#ifndef NN1
#define NN1

/*** Description ***
La classe NN1 sert à représenter un réseau de neurones. 
Cette classe a pour membre l’ensemble des perceptrons qui constituent le réseau de neurones.
*/

#include <vector>
#include "perceptron.h"

template<class input_type_class, int nb_input, class fonction_activation>
class Apprenstissage
{
    public:
        Apprenstissage(Nn1* network){
            Apprenstissage::network = network;
        }

        void apprendre_base(int iterations, double mu){
            for(int i=0; i<iterations; i++){
                pair<vector<double>, int> &formated_input;

                // Choix d'un input au hasard
                input_type_class input = new input_type_class(rand() % nb_input);

                // Convertion du format d'input
                if(input_type_class == "iris"){
                    for (auto x : input->description){
                        get<0>(formated_input).push_back(x);
                    }
                    get<1>(formated_input) = input->label;
                }
                else(input_type_class == "image"){
                    for (auto x : input->pixels){
                        get<0>(formated_input).push_back(x);
                    }
                    get<1>(formated_input) = input->label;
                }

                // Apprentissage du NN
                network->apprentissage(formated_input, mu);
            }
        }

        int evaluer(){
            int matched = 0;

            for(int i; i< nb_input, i++){
                pair<vector<double>, int> &formated_input;
                
                // Selection de l'input
                input_type_class input = new input_type_class(i);
                char label = input->label();

                // Convertion du format d'input
                if(input_type_class == "iris"){
                    for (auto x : input->description){
                        get<0>(formated_input).push_back(x);
                    }
                    get<1>(formated_input) = input->label;
                }
                else(input_type_class == "image"){
                    for (auto x : input->pixels){
                        get<0>(formated_input).push_back(x);
                    }
                    get<1>(formated_input) = input->label;
                }

                // Evaluation
                if(label == network->evaluation(formated_input)) matched++;

            }

            return matched;
        }

        

    private:
        Nn1* network;
};

class Nn1
{
public:
    Nn1(int input_size, int nb_labels); 
    ~Nn1();

    char evaluation ( pair<vector<double>, int> &input);
    void apprentissage ( pair<vector<double>, int> &input, double mu);

private :
    vector<Perceptron*> perceptrons;
    
};

#endif