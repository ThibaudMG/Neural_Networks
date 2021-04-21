#ifndef IMAGE
#define IMAGE

/*** Description ***
La classe Image a pour but de stocker des images en noir et blanc, comprenant 28×28 pixels.
Chaque pixel est décrit par son niveau de gris, qui est une valeur entre 0 et 255 (qui pourra être stockée dans un char). 
Les images considérées proviennent de la base de données MNIST et représentent des chiffres dessinés à la main.
Il y a 10 chiffres différents (0, 1, ..., 9). Le label d’un chiffre correspond à sa valeur.
Ces images sont stockées dans MNIST_training.tar.gz sous la forme de fichiers bmp. 
Il y a 60000 images, chacune contenue dans un fichier d’extension bmp dont le nom debute par «training» et finit par l’indice de l’image (training0, ..., training59999).
Le fichier contenant les labels de ces images est train-labels-idx1-ubyte.gz. Les images, ainsi que les labels, sont contenus dans des fichiers binaires. 
Chaque valeur de ces fichiers est codée sous la forme d’un octet (dont la valeur pourra être stockée dans un char).
Pour les images, les octets correspondant aux pixels de l’images se trouvent à partir de l’octet 1078 du fichier d’extension bmp correspondant (et donc jusqu’à l’octet 1078+28²).
Pour les labels, les octets correspondant au tableau de labels se trouvent à partir de l’octet 8 dans le fichier de labels (le label de l’image d’indice i se trouve donc à l’octet 8+i).

Le constructeur devra charger l’image à partir du fichier bmp correspondant, ainsi quecharger le label de l’image dans le champ label hérité de la classe Input.
*/

#include "input.h"

class Image : public Input
{
public:
    Image(int image_index); // Un constructeur prenant en paramètre un entier correspondant à l’indice de l’image (entier entre 0 et 59999)
    ~Image();
    double operator[](int pixel_index); // L’operateur [] qui prend en parametre un entier correspondant à l’indice du pixel et qui renvoie son niveau de gris sous la forme d’un double
    char getLabel();

private:
    char label;
    char pixels[784]; // Chaque pixel est décrit par son niveau de gris, qui est une valeur entre 0 et 255
};

#endif