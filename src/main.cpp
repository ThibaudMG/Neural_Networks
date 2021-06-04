#include <iostream>
#include <fstream>
#include <string>

#include "iris.h"
#include "image.h"
#include "nn1.h"
#include "sigmoide.h"
#include "tanh.h"

using namespace std;

int main(int argc, char *argv[])
{ 
  // Choix classe input
  //string class_ = argv[1];
  int res;
  
  /*------ Iris ------*//*
  //
  // Nn1(int input_size, int nb_labels, Fonction_activation* activation)
  Nn1 *network = new Nn1(4, 3, new Sigmoide());
  // Apprentissage<class input_type_class, int nb_input> Apprenstissage(Nn1 *network)
  Apprenstissage<Image, 150> apprentissage(network);

  apprentissage.apprendre_base(10000, 0.1);
  cout << "Learning done." << endl;

  // Pause the program
  cout << "Press Enter to continue" << endl;
  getc(stdin);

  res = apprentissage.evaluer();
  cout << "\n--- Taux de classification: " << to_string(100*res/150.) << "% ---" << endl;
  *//*------------*/
  //
  //
  //
  /*------ Image ------*/
  //
  // Nn1(int input_size, int nb_labels, Fonction_activation* activation)
  Nn1 *network = new Nn1(784, 10, new Sigmoide());
  // Apprentissage<class input_type_class, int nb_input> Apprenstissage(Nn1 *network)
  Apprenstissage<Image, 60000> apprentissage(network);

  apprentissage.apprendre_base(50000, 1);
  cout << "Learning done." << endl;

  // Pause the program
  cout << "Press Enter to continue" << endl;
  getc(stdin);

  res = apprentissage.evaluer();
  cout << "\n--- Taux de classification: " << to_string(100*res/60000.) << "% ---" << endl;
  /*------------*/

  delete network;

  return 0;
}