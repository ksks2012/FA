#ifndef __SOLUTION_H__
#define __SOLUTION_H__

#include <vector>
#include <climits>
#include <cmath>
#include "parameter.h"
#include <cstdlib>

using namespace std;

class Solution {

public:

    Parameter parameter;

    vector<double> location;    
    
    vector<double> UL;
    vector<double> LL;
    
    double range;
    
    double fitness;
    
    double localFitness;
    
    int dimension;

public:

    Solution();
    Solution(Parameter);
    ~Solution();
    
    void setDimension(int);
    void setRange(vector<double> &, vector<double> &);
    
    void initLocation();
    void genLocation(int);
    
    void feasible();
    
    void calFitness();
    
    static double RAND();
    static double RAND(double, double);
    
    bool checkLocation(int);
    
    void printData();

};

#endif
