#include "image.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Image::Image(int image_index)
{
    string substr;
    string image_path = "../files/MNIST_training/";

    // Load label
    ifstream label_file(image_path + "train-labels.idx1-ubyte", ios::in | ios::binary);
    if (label_file.is_open())
    {
        // Get file length
        label_file.seekg(0, label_file.end);
        const int length = label_file.tellg();
        label_file.seekg(0, label_file.beg);

        // Read label file
        char *input_labels = new char[length];
        label_file.read(input_labels, length); // ifstream& read(const char*, int);
        Image::label = input_labels[image_index + 7]; // (char) to_string() ?

        // Close file
        label_file.close();
    }
    else
        cout << "Unable to open label_file" << endl;

    // Load pixels
    ifstream image_file(image_path + "training" + to_string(image_index), ios::in | ios::binary);
    if (image_file.is_open())
    {
        // Get file length
        image_file.seekg(0, image_file.end);
        const int length = image_file.tellg();
        image_file.seekg(0, image_file.beg);

        // Read image file
        char *input_label = new char[length];
        image_file.read(input_label, length); // ifstream& read(const char*, int);
        image_file.close();

        ofstream myfile;
        myfile.open("../files/image_output.txt");

        for (int i = 0; i < 28; i++)
        {
            for (int j = 0; j < 28; j++)
            {
                myfile << to_string(abs((int)input_label[j + i * 28 + 1078])) << " | ";
                Image::pixels[j + i * 28] = (char)abs((int)input_label[j + i * 28 + 1078]);
                if (j == 27)
                    myfile << endl;
            }
        }

        // Close files
        myfile.close();
        image_file.close();
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