#include <iostream>
#include <fstream>
#include <string>
#include "image.h"

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
        Image::label = to_string(input_labels[image_index + 8])[0]; // (char) to_string() ?
        //Image::label = (input_labels[image_index + 8]);

        // Close file
        delete input_labels;
        label_file.close();
    }
    else
        cout << "Unable to open label_file" << endl;

    
    // Load pixels
    Image::pixels = (double*) malloc (784* sizeof(double)); // 28*28 = 784 pixels

    ifstream image_file(image_path + "training" + to_string(image_index), ios::in | ios::binary);
    if (image_file.is_open())
    {
        // Get file length
        image_file.seekg(0, image_file.end);
        const int length = image_file.tellg();
        image_file.seekg(0, image_file.beg);

        // Read image file
        char *input_pixels = new char[length];
        image_file.read(input_pixels, length); // ifstream& read(const char*, int);
        image_file.close();

        ofstream myfile;
        myfile.open("../files/image_output.txt");

        for (int i = 0; i < 28; i++)
        {
            for (int j = 0; j < 28; j++)
            {
                //myfile << to_string(abs((int)input_label[j + i * 28 + 1078])) << " | ";
                Image::pixels[j + i * 28] = (double) abs((int)input_pixels[j + i * 28 + 1078])/255; // [0. ; 1.]
                //if (j == 27)
                    //myfile << endl;
            }
        }

        // Close files
        //myfile.close();
        delete input_pixels;
        image_file.close();
    }
    else
        cout << "Unable to open label_file" << endl;
}

double &Image::operator[](int pixel_index)
{
    return  Image::pixels[pixel_index];
}

char Image::getLabel()
{
    return Image::label;
}

Image::~Image()
{
    delete &label;
    free(pixels);
}