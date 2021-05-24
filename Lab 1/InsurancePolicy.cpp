// InsurancePolicy.cpp
#include "InsurancePolicy.h"
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

// initialization object fields
InsurancePolicy::InsurancePolicy(){
PolicyNumber=00000; 
DateOfTheContractBeginning="01.01.1999";
DateOfContractExpiry="01.01.2019";
Price=0;
PaymentAmount=0;
PolicySortCode=000000000;
wasPayed=false;
isExpired=false;
ClientCode=0000;
CoworkerCode=0000;
}
//clean-up memory
InsurancePolicy::~InsurancePolicy(){}

//class behavior 
//display data
void InsurancePolicy::displayData(){
	
	cout << "Date of the contract beginning is " << DateOfTheContractBeginning << endl;
	cout << "Date of expiry is " << DateOfContractExpiry << endl;
	cout << "Price is $" << Price << endl;
	cout << "Payment amount is $" << PaymentAmount << endl;
	cout << "Policy Sort Code is " << PolicySortCode << endl;
	cout << "Code of the Client is " << ClientCode << endl;
	cout << "Code of the Coworker is " << CoworkerCode << endl;
}
void InsurancePolicy::checkIfWasPayed(){
	if (wasPayed){
		cout << "The policy is paid" << endl;
		}
	else {
		cout << "The policy wasn't paid. Wainting for youe check..." << endl;
		}
}

//access methods
int InsurancePolicy::getPolicyNumber(){
	return PolicyNumber;
}
void InsurancePolicy::setPolicyNumber(int inPolicyNumber){
	PolicyNumber = inPolicyNumber;
}	
std::string InsurancePolicy::getDateOfTheContractBeginning(){
	return DateOfTheContractBeginning;
}
void InsurancePolicy::setDateOfTheContractBeginning(std::string inDateOfTheContractBeginning){
	DateOfTheContractBeginning = inDateOfTheContractBeginning;
}
std::string InsurancePolicy::getDateOfContractExpiry(){
	return DateOfContractExpiry;
}
void InsurancePolicy::setDateOfContractExpiry(std::string inDateOfContractExpiry){
	DateOfContractExpiry = inDateOfContractExpiry;
}

int InsurancePolicy::getPrice(){
	return Price;
}
void InsurancePolicy::setPrice(int inPrice){
	Price = inPrice;
}
int InsurancePolicy::getPaymentAmount(){
	return PaymentAmount;
}
void InsurancePolicy::setPaymentAmount(int inPaymentAmount){
	PaymentAmount = inPaymentAmount;
}
int InsurancePolicy::getPocicySortCode(){
	return PolicySortCode;
}
void InsurancePolicy::setPocicySortCode(int inPocicySortCode){
	PolicySortCode = inPocicySortCode;
}

bool InsurancePolicy::getIfWasPaid(){
	return wasPayed;
}
void InsurancePolicy::setIfWasPaid(bool inWasPaid){
	wasPayed = inWasPaid;
}
bool InsurancePolicy::getIsExpired(){
	return isExpired;
}
void InsurancePolicy::setIsExpired(bool inIsExpired){
	isExpired = inIsExpired;
}
int InsurancePolicy::getClientCode(){
	return ClientCode;
}
void InsurancePolicy::setClientCode(int inClientCode){
	ClientCode = inClientCode;
}

int InsurancePolicy::getCoworkerCode(){
	return CoworkerCode;
}
void InsurancePolicy::setCoworkerCode(int inCoworkerCode){
	CoworkerCode = inCoworkerCode;
}






