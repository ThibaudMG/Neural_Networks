#include <iostream>
#include <fstream>
#include <string>
#include <thread> //sleep 
#include <chrono>  

#include "iris.h"
#include "image.h"
#include "nn1.h"
#include "sigmoide.h"
#include "tanh.h"

using namespace std;

int main(int argc, char *argv[])
{
  // Choix fonction activation
  //int act = stoi(argv[1]);

  int res;
  Nn1* network = new Nn1(4,3, new Tanh());
  Apprenstissage<Iris,150> apprentissage(network);

  apprentissage.apprendre_base(10000, 0.1);
  cout << "Learning done." << endl;
  
  cout << "Program is paused !\n" <<
        "Press Enter to continue\n";

    // pause the program until user input
    getc(stdin);

  
  res = apprentissage.evaluer();
  cout << "\n--- Good classifications: " << res << " ---" << endl;

  return 0;
}
/*
Perceptron 1
poids[0] = 5.270532; poids[1] = 25.504809; poids[2] = 8.436754; poids[3] = 20.274894; poids[4] = 5.424423;
Perceptron 2
poids[0] = 1.708656; poids[1] = 4.826744; poids[2] = 1.763760; poids[3] = -0.078747; poids[4] = 1.283463; 
Perceptron 3
poids[0] = -0.934030; poids[1] = 1.365229; poids[2] = 1.168292; poids[3] = -0.729139; poids[4] = 1.084977; */