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
  //ifstream image_file(image_path + "training" + to_string(image_index));
  //ifstream label_file(image_path + "train-labels.idx1-ubyte");

  //Calling the open function to read an object from a file
  ifstream image_file(image_path + "training" + to_string(image_index));

  if (image_file.is_open())
  {
    // Get number of characters
    image_file.seekg(0, image_file.end);
    const int length = image_file.tellg();
    image_file.seekg(0, image_file.beg);
    cout << "length: " << length << endl;
    ///////////////////////////

    char *input_label = new char[length];
    image_file.read(input_label, length); // ifstream& read(const char*, int);
    image_file.close();

    ofstream myfile;
    myfile.open("image_output.txt");
    //cout << "input: " << to_string(input_label[image_index + 8]) << endl;
    for (int i = 0; i < 28; i++)
    {
      for (int j = 0; j < 28; j++)
      {
        myfile << to_string(input_label[j + i * 28 + 1078]) << " | ";
        if (j == 27)
          myfile << endl;
      }
    }
    myfile.close();
  }
  else
    cout << "Unable to open label_file" << endl;

 
  return 0;
}