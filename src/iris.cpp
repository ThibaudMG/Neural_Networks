#include "iris.h"
//#include "..\include\iris.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Iris::Iris(int flower_index)
{
    string substr;
    ifstream irisFile("../files/iris_training/iris" + to_string(flower_index)); // irisFile = 5.1,3.5,1.4,0.2,Iris-setosa

    if (irisFile.is_open())
    {
        Iris::description = (double*) malloc (4* sizeof(double));

        // Load description
        int index = 0;
        while (getline(irisFile, substr, ',') && index < 4)
        {
            Iris::description[index] = stod(substr); // stof -> String to Float
            index++;
        }
        
        // Load label
        if (substr == "Iris-setosa")
        {
            Iris::label = '0';
        }
        else if (substr == "Iris-virginica")
        {
            Iris::label = '1';
        }
        else if (substr == "Iris-versicolor")
        {
            Iris::label = '2';
        }
        else
        {
            Iris::label = 0;
        }
        irisFile.close();
    }

    else
        cout << "Unable to open iris file" << endl;
}

double& Iris::operator[](int case_index)
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
    free(description);
}