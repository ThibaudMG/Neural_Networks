#include <iostream>
#include <fstream>
#include <string>
#include "input_intermediaire.h"

Input_intermediaire::Input_intermediaire(char label)
{
    Input_intermediaire::label = label;
}

void Input_intermediaire::add(double value){
    values.push_back(value);
}

double& Input_intermediaire::operator[](int index){
    return values[index];
}

char Input_intermediaire::getLabel()
{
    return label;
}

Input_intermediaire::~Input_intermediaire()
{
    delete &label;
    values.clear();
    vector<double>().swap(values); // free memory
}