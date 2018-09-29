#include "parameter.h"
#include "fa_algo.h"

int main(int argc, char** argv) {

    const int RUN_TIME = atoi(argv[1]);

    const int ITERATION = atoi(argv[2]);

    Parameter parameter;
    
    parameter.setITERATION(atoi(argv[2]));
    
    parameter.setPopultion(atoi(argv[3]));
    
    parameter.setFuncNum(atoi(argv[4]));
    
    parameter.setLAC(atof(argv[5]));

    int run = 0;

    while(run < RUN_TIME) {
    
        int itr = 0;
        
        fa_algo fa(parameter);
        
        fa.setBF();
        
        fa.initial();
        
        fa.checkInit();
    
        while(itr < ITERATION) {
                              
            fa.candidate(itr);
                
            ++itr;
        
            cout << setprecision(16) << itr << " " << fa.bestSol.fitness << endl;
        
        }
        //cout << fa.candidateSol[0].velocity[0] << endl;
        cout << setprecision(16) << fa.bestSol.fitness << endl;
        fa.bestSol.printData();
    
        ++run;
    
    }
    
}
