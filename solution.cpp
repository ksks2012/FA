#include "solution.h"

Solution::Solution() {


}

Solution::Solution(Parameter parameter) {

    this->parameter = parameter;
    this->localFitness = INT_MAX;

}

Solution::~Solution() {


}

void Solution::setDimension(int D) {
    
    dimension = D;
    location = vector<double>(dimension, 0.0);

}

void Solution::setRange(vector<double> &UL, vector<double> &LL) {

    this->UL = UL;
    this->LL = LL;
    
    
    //TODO 
    this->range = UL[0] - LL[0];

}

void Solution::initLocation() {


    for(int i = 0; i < dimension; ++i) {
    
        genLocation(i);
    
    }

}

void Solution::genLocation(int idx) {

    double r =  (double) rand() / RAND_MAX;
    
    location[idx] = r * range + LL[0];

}

void Solution::feasible() {

    for (int i = 0; i < dimension; ++i) {
		
        if(checkLocation(i)) {
        
            location[i] = max(location[i], LL[i]);
            location[i] = min(location[i], UL[i]);  
        
        }
		
	}

}

double Solution::RAND() {

    return (double) rand() / RAND_MAX;

}

double Solution::RAND(double lowwer, double upper) {
	
	return lowwer + (upper - lowwer) * rand() / (RAND_MAX + 1.0);

}

bool Solution::checkLocation(int idx) {

    if(location[idx] > UL[idx] || location[idx] < LL[idx])
        return true;
        
    return false;

}

void Solution::printData() {

    for(int i = 0; i < dimension; ++i) {
    
        cout << location[i] << " " ; 
    
    }
    
    cout << endl;

}

void Solution::calFitness() {

    fitness = 0;
    
    switch(parameter.FUNC_NUM) {
        
        case 0:
            
            //fitness += 25;
            
            for(int i = 0; i < dimension; ++i)
                fitness += location[i] * location[i];
            
            //fitness = abs(fitness);
            break;
            
        case 1:
            
            fitness += 25;
            
            for(int i = 0; i < dimension; ++i)
                fitness += ceil(location[i]);
            
            //fitness = abs(fitness);
            break;
        case 2:
            
            //fitness += 25;
            
            for(int i = 0; i < dimension; ++i)
                fitness += pow(floor(location[i] + 0.5), 2);
            
            fitness = abs(fitness);
            break;
        case 16:         
            
            for(int i = 0; i < dimension - 1; ++i)
                fitness += 100 * pow(location[i + 1] - pow(location[i], 2), 2) + pow(location[i] - 1, 2);
            
            break;
        case 22:
            fitness += 10 * dimension;
            
            for(int i = 0; i < dimension; ++i)
                fitness +=  pow(location[i], 2) - 10 * cos(2 * M_PI * location[i]);// + 10;
            
            break;
        case 23:
            fitness += 418.9829 * dimension;
            
            for(int i = 0; i < dimension; ++i)
                fitness -= (location[i] * sin(pow(abs(location[i]), 0.5)));
            
            break;
            
        case 28:
         
            fitness = 4 * pow(location[0], 2) - 2.1 * pow(location[0], 4) + (1.0 / 3.0) * pow(location[0], 6) + location[0] * location[1] - 4 * pow(location[1], 2) + 4 * pow(location[1], 4);
            
            //fitness = abs(1.03163 + fitness);
            break;
        case 41:
        {
            fitness += 1;
            
            double sum = 0;
            
            for(int i = 1; i < dimension + 1; ++i)
                sum += pow(location[i - 1], 2);
        
            sum = sum / 4000;
        
            double product = 1;
            
            for(int i = 1; i < dimension + 1; ++i)
                product *= cos(location[i - 1] / pow(i, 0.5));
        
            fitness += sum - product;

            break;
        }
        case 101:
         
            fitness += 0;
            
            for(int i = 0; i < dimension; ++i)
                fitness += pow(location[i], 2) ;
            
            //fitness = abs(1.03163 + fitness);
            break;
        default:
            cout << "unknown function" << endl;
            break;
    }

}

