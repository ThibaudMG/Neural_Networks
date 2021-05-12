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
  // Choix fonction activation
  //int act = stoi(argv[1]);
  
  int res;
  Nn1* network = new Nn1(4,3);
  Apprenstissage<Iris,4,Tanh> apprentissage(network);

  apprentissage.apprendre_base(10, 0.1);
  cout << "app ok" << endl;
  res = apprentissage.evaluer();
  cout << "res sur 150:" << res << endl;

  return 0;
}