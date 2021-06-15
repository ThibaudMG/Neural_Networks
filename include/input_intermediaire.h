#ifndef INPUT_INTERMEDIAIRE
#define INPUT_INTERMEDIAIRE

/*** Description ***
La classe Input_intermediaire va servir à stocker les valeurs intermédiaires 𝒂(𝟏)=(𝑎1(1),…,𝑎𝑡(1)) à la sortie des perceptrons de la couche cachée. \
Elle descend de la classe Input. Elle possède un champ qui va contenir des valeurs réelles (double), qui sera de préférence un vecteur (vector).
*/
#include <vector>
#include "input.h"

using namespace std;

class Input_intermediaire : public Input
{
public:
    Input_intermediaire(char label);
    ~Input_intermediaire();
    
    void add(double value);
    double &operator[](int index);
    char getLabel();

private :
    vector<double> values;
    char label;
};

#endif