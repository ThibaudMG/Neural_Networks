#include <iostream>
#include <fstream>
#include <string>
#include "iris.h"
#include "image.h"
using namespace std;

int main(int argc, char *argv[])
{
  int index = stoi(argv[1]);
  
  Iris iris = Iris(index);
  cout << "label of iris n." << to_string(index) << ": "<< to_string(iris.getLabel()) << endl;
  
  Image image = Image(index);
  cout << "label of image n." << to_string(index) << ": "<< to_string(image.getLabel()) << endl;
  return 0;
}