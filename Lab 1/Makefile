#Makefile for InsurancePolicy project

all: main 

main: InsurancePolicyTest.o InsurancePolicy.o
	g++ InsurancePolicyTest.o InsurancePolicy.o -o main

InsurancePolicyTest.o: InsurancePolicyTest.cpp
	g++ -c InsurancePolicyTest.cpp

InsurancePolicy.o: InsurancePolicy.cpp
	g++ -c InsurancePolicy.cpp

clean:
	rm -f *.o main
