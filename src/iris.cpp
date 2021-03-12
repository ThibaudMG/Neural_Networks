#include "..\include\iris.h"
#include <iostream>
using namespace std;

Iris::Iris(int flower_index){
    // file = open "iris" + flower_index
    // description = file.get 4 premier truc
    // label = file.getlast
}

double Iris::operator[](int case_index){
    return 0.0;
}

char Iris::getLabel(){
    return Iris::label;
}

Iris::~Iris(){
    delete &label;
}