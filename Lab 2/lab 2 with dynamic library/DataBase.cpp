#include <iostream>
#include <fstream>

#include "DataBase.h"
//#include "InsurancePolicy.h"
//#include "InsurancePolicy.cpp"
#include <vector>

using namespace std;

DataBase::DataBase(){

	vector<InsurancePolicy> policies;	

}

DataBase::~DataBase(){



}


void DataBase::writeToFile(){

	ofstream myfile;
	myfile.open("test.txt");
	for(int i =0; i<policies.size(); i++){

		myfile << "Policy Number:" << policies[i].getPolicyNumber() << "\n";
		myfile << "Balance:"  << policies[i].getPrice() << "\n";
		myfile <<"Payment amount:  " << policies[i].getPaymentAmount() << "\n";
		myfile << "----------------------" << "\n";

	}
	myfile.close();

}

void DataBase::readFromFile(){
	string line;
	ifstream myfile("test.txt");
	if(myfile.is_open()){
		while(getline(myfile, line)){
		
		cout << line  << "\n";

		}
		myfile.close();
	}
	else{

		cout << "Unable to open the file :(" <<endl;

	}	

}

void DataBase::payThePolicy(int inPolicyNumber, int inMoney){
	
	for(int i = 0; i<policies.size(); i++){

		if(policies[i].getPolicyNumber()==inPolicyNumber){
			
			policies[i].payThePolicy(inMoney);

		}

	}

}

void DataBase::displayAll(){

	if(policies.empty()){

		cout << "The List is empty." << endl;

	}
	
	else {

	for(int i=0; i<policies.size(); i++){

                policies[i].displayTheData();

        }

	}

	
}

void DataBase::displayCurrent(){

	if(policies.empty()){
	
		cout << "Sorry, the list is empty." << endl;

	}
	else{

		policies[policies.size()].displayTheData();
		

	}	

}

void DataBase::addPolicy(int inPolicyNumber){

	InsurancePolicy *new_policy;
	new_policy = new InsurancePolicy();
	new_policy->setPolicyNumber(inPolicyNumber);
	policies.push_back(*new_policy);

}

void DataBase::removePolicy(int inPolicyNumber){

	auto iter = policies.cbegin();
	for(int i=0; i<policies.size(); i++){
		
		if(policies[i].getPolicyNumber()==inPolicyNumber){

			policies.erase(iter+i);

		}

	}

}

InsurancePolicy& DataBase::getByNumber(int inPolicyNumber){

	//InsurancePolicy* hbPolicy;
	//hbPolicy = new InsurancePolicy();
	//return hbPolicy;
	
        for (int i=0; i<policies.size(); i++){

		if(policies[i].getPolicyNumber()==inPolicyNumber){
			
			return policies[i];			

		}

	}
	
}
