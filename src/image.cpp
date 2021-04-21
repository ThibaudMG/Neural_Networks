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
    ifstream label_file(image_path + "train-label.idx1-ubyte");
    
    if (label_file.is_open())
    {
        string input_label;
        label_file.read((char *) &input_label, 8 + image_index); // ifstream& read(const char*, int);
        cout << input_label << endl;
        Image:label = input_label[-1];
        label_file.close();
    }

    else
        cout << "Unable to open label_file" << endl;
}

double Image::operator[](int pixel_index)
{
    return (double) (Image::pixels[pixel_index]/255.); // return [0. ; 1.]
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