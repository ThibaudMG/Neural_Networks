#include "..\include\iris.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Iris::Iris(int flower_index)
{
    string substr;
    ifstream irisFile("../files/iris_training/iris" + flower_index); // irisFile = 5.1,3.5,1.4,0.2,Iris-setosa
    if (irisFile.is_open())
    {
        int index = 0;
        while (getline(irisFile, substr, ',') && index < 4)
        {
            Iris::description[index] = stof(substr); // stof -> String to Float
            index++;
        }

        // Convert iris type string to label int
        if (substr == "Iris-setosa")
        {
            Iris::label = 0;
        }
        else if (substr == "Iris-virginica")
        {
            Iris::label = 1;
        }
        else if (substr == "Iris-versicolor")
        {
            Iris::label = 2;
        }
        else
        {
            Iris::label = 0;
        }
        irisFile.close();
    }

    else
        cout << "Unable to open file" << endl;
}

double Iris::operator[](int case_index)
{
    return Iris::description[case_index];
}

char Iris::getLabel()
{
    return Iris::label;
}

Iris::~Iris()
{
    delete &label;
    delete &description;
}