#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
  string line;
  string iris_path = "../files/iris_training/";
  string image_path = "../files/MNIST_training/";
  
  int image_index = 1;
  char label;
  //ifstream image_file(image_path + "training" + to_string(image_index));
  ifstream label_file(image_path + "train-label.idx1-ubyte");

  if (label_file.is_open())
  {
    string input_label;
    label_file.read((char *)&input_label, 8 + image_index); // ifstream& read(const char*, int);
    cout << input_label << endl;
    label = input_label[-1];
    label_file.close();
  }

  else
    cout << "Unable to open label_file" << endl;

  cout << label << endl;
  /*ifstream myfile (iris_path + "iris0");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n'; // 5.1,3.5,1.4,0.2,Iris-setosa
    }
    myfile.close();
  }
  else cout << "Unable to open file"; 
  */

  return 0;
}