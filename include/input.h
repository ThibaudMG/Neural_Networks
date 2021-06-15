#ifndef INPUT
#define INPUT

/*** Description ***
Dans ce projet, nous allons considérer deux types d’inputs: des images et des vecteurs décrivant des fleurs.
Ces deux types de données ont en commun d’être représentables sous la forme d’un «tableau», dont la taille va dépendre du type de données contenues(28×28pour les imageset 4 pour les fleurs).
Nous reviendrons en détails sur ces deux types d’inputs plus tard.
Afin d’homogénéiser le traitement sur ces deux types d’inputs, vous allez créer une classe abstraite, \
nommée Input, qui aura pour rôle de décrire l’ensemble des méthodes nécessaires pour accéder aux informations d’un input.

Le label d’un input indique à quelle famille il appartient. C’est cette famille que devra reconnaitre plus tard le réseau de neurones.
Cette classeabstraite possède un unique attribut (privé) qui stocke le label de l’input.
*/

#include <stdlib.h>

// Abstract class (with "virtual" methods)
class Input
{
public:
    virtual double &operator[](int) = 0; // Permet d’acceder à une valeur(double) du «tableau» en fonction de son indice (int)
    virtual char getLabel() = 0;         // Renvoie un char representant le label de l’input

private:
    char label;
};

#endif