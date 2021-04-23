#include "..\include\image.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Image::Image(int image_index)
{
    string substr;
    string image_path = "../files/MNIST_training/";

    //ifstream image_file(image_path + "training" + to_string(image_index));
    ifstream label_file(image_path + "train-labels.idx1-ubyte");

    if (label_file.is_open())
    {
        // Get number of characters
        label_file.seekg(0, label_file.end);
        const int length = label_file.tellg();
        label_file.seekg(0, label_file.beg);
        cout << "length: " << length << endl;
        
        // Read label file
        char *input_labels = new char[length];
        label_file.read(input_labels, length); // ifstream& read(const char*, int);
        Image:label = input_labels[image_index + 7]; // (char) to_string() ?
        
    }
    else
        cout << "Unable to open label_file" << endl;
}

double Image::operator[](int pixel_index)
{
    return (double)(Image::pixels[pixel_index] / 255.); // return [0. ; 1.]
}

char Image::getLabel()
{
    return Image::label;
}

Image::~Image()
{
    delete &label;
    delete &pixels;
}