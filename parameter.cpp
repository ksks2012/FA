#include "parameter.h"
#include <cmath>

Parameter::Parameter() {

}

Parameter::~Parameter() {

}

void Parameter::setITERATION(int ITERATION) {

    this->ITERATION = ITERATION;

}

void Parameter::setPopultion(int POPULATION) {

    this->POPULATION = POPULATION;

}

void Parameter::setFuncNum(int FUNC_NUM) {

    this->FUNC_NUM = FUNC_NUM;

}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Parameter::setLAC(double LAC) {

    this->LAC = LAC;

} 
