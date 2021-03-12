// basic file operations
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (int argc, char *argv[]) {
  string line;
  ifstream myfile ("../files/iris_training/iris0");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n'; // 5.1,3.5,1.4,0.2,Iris-setosa
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}