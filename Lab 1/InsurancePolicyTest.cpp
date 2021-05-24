// InsurancePolicyTest.cpp

#include <iostream>
#include "InsurancePolicy.h"

using namespace std;

int main (int argc, char** agrv){
	InsurancePolicy myPolicy; // stack-based insurancepolicy
	myPolicy.setPolicyNumber(12324);
	myPolicy.setIfWasPaid(false);
	myPolicy.checkIfWasPayed();
	myPolicy.displayData();	
	
	cout << "" << endl;
	
	InsurancePolicy* myPolicy2; // heap-based policy
	myPolicy2 = new InsurancePolicy();
	myPolicy2->setPolicyNumber(12346);
	myPolicy2->setPrice(125);
	myPolicy2->setPaymentAmount(25);
	myPolicy2->setIfWasPaid(true);
	myPolicy2->displayData();
	cout << "Wait..." << endl;
	myPolicy2->checkIfWasPayed();
	
	delete myPolicy2;
	return 0;
}
