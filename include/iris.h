#ifndef IRIS
#define IRIS

/*** Description ***
La classe Iris a pour but de stocker la (courte) description de fleurs sous la forme d’un tableau de 4 réels.
Il existe 3 types de fleurs: Iris setosa(label 0), Iris virginica(label 1)and Iris versicolor(label 2).
Les descriptions de ces fleurs se trouvent dans iris_training.tar.gz.
Il y a 150 descriptions de fleurs, chacune contenue dans un fichier dont le nom débute par «Iris» et finit par l’indice de la fleur (Iris0, ..., Iris149).
Chaque description contient 4 réels, séparés par des points-virgules, ainsi qu’une chaine de caractères indiquant le type de la fleur.

Le constructeur va charger la description de la fleur (ainsi que son label) à partir du fichier correspondant.
*/

#include "input.h"

class Iris : public Input
{
public:
    Iris(int flower_index); // Constructeur, prenant en parametre un entier correspondant à l’indice de la fleur (entier entre 0 et 149)
    ~Iris();
    double operator[](int case_index); // L’operateur [] qui prend en parametre un entier correspondant à l’indice de la case et qui renvoie le double correspondant
    char getLabel();

private :
    char label;
    float description[4]; //  Chaque description contient 4 réels, séparés par des points-virgules, ainsi qu’une chaine de caractères indiquant le type de la fleur
    // Il y a 150 descriptions de fleurs. Il existe 3 types de fleurs: Iris setosa(label 0), Iris virginica(label 1)and Iris versicolor(label 2)
};

#endif