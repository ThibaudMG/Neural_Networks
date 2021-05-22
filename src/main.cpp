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
  Nn1* network = new Nn1(4,3);
  Apprenstissage<Iris,150,Tanh> apprentissage(network);


  apprentissage.apprendre_base(10000, 0.1);
  cout << "Learning done." << endl;
  
  cout << "Program is paused !\n" <<
        "Press Enter to continue\n";

    // pause the program until user input
    getc(stdin);

  res = apprentissage.evaluer();
  cout << "Good classifications: " << res << endl;

  return 0;
}