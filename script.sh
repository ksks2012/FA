#!/bin/bash

#	@echo "1  RUN_TIME"
#	@echo "2  ITERATION"
#	@echo "3  POPULATION"
#	@echo "4  FUNC_NUM"
#   @echo "5  light absorption coefficient"
#   @echo "6  "
#   @echo "7  "
#   @echo "8  "

#@@@@@@@@@@@@

#Vortex Search
#function
# 0 for test
# 1 Stepint
# 2 Step

#16 Rosenbrock

#22 Rastrigin
#23 Schwefel 

#41 Griewank

#28 Six Hump Camel Back

#CEC2005 
#101 Shifted Sphere Function

#CEC2013

#202 Rotated High Conditioned Elliptic Function 


make clean all

#gdb --args
./fa.out 1 250 40 0 1.0

