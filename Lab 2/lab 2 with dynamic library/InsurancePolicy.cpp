// InsurancePolicy.cpp
#include "InsurancePolicy.h"
#include <iostream>
#include<chrono>
#include<ctime>


using namespace std;

// ініціалізація полів об'єкта
InsurancePolicy::InsurancePolicy(){

policyNumber = 00000;
dateOfTheContract="01.01.1999";
dateOfExpiry="01.01.2010";
Price = 0;
paymentAmount = 0;
policySortCode = 000000000;
wasPayed = false;
isExpired = false;
clientCode = 0000;
coworkerCode = 0000;


}

// тут маємо очищати пам'ять
InsurancePolicy::~InsurancePolicy(){


}

//поведінка класу

void InsurancePolicy::payThePolicy(int inMoney){

	paymentAmount = inMoney;
	cout << "You have payed the insurance." << endl;
	cout << "Your balance is $" << paymentAmount << endl; 



}


void InsurancePolicy::displayTheData(){
	
	cout << "-------------------------" << endl;
	cout << "Date of the contract is " << dateOfTheContract<< endl;  
	cout << "Date of expiry is " << dateOfExpiry<< endl;
	cout << "Policy number is " << policyNumber << endl; 
	cout << "Price is " <<  Price << endl;
	cout << "Payment amount is " << paymentAmount << endl;
	cout << "Policy Sort Code is " << policySortCode << endl;
	cout << "Code of the client is "<< clientCode << endl;
	cout << "Code of the coworker is " << coworkerCode << endl; 

}

void InsurancePolicy::checkIfWasExpired(){

	time_t rawtime;
        struct tm * timeinfo;
        char buffer [80];                   //рядок, в якому буде записано теперішній час
 
        time ( &rawtime );                  // дата в секундах
        timeinfo = localtime ( &rawtime );  // 
 
        strftime (buffer,80,"%I:%M%p.",timeinfo); // форматуємо рядок часу
	
       // if(strftime == dateOfExpiry){

       // isExpired = true;
//}
	//else{

		//isExpired = false;

	//}

}

void InsurancePolicy::checkIfWasPayed(){

	if(wasPayed){
	
		cout << "The policy is paid, everithing is ok:)" << endl;

	}	// comment
	else {
		
		cout << "The policy wasnt paid, we are waiting for your check..." << endl;
	}
}






// методи доступу
int InsurancePolicy::getPolicyNumber(){

	return policyNumber;

}

void InsurancePolicy::setPolicyNumber(int inPolicyNumber){

	policyNumber = inPolicyNumber;

}
string InsurancePolicy::getDateOfTheContract(){
	
	return dateOfTheContract;

}

void InsurancePolicy::setDateOfTheContract(string inDateOfTheContract){
	
	dateOfTheContract =inDateOfTheContract;

}

string InsurancePolicy::getDateOfExpiry(){

	return dateOfExpiry;
}

void InsurancePolicy::setDateOfExpiry(string inDateOfExpiry ){

	dateOfExpiry = inDateOfExpiry;

}

int InsurancePolicy::getPrice(){

	return Price;

}

void InsurancePolicy::setPrice(int inPrice){
	
	Price = inPrice;

}

int InsurancePolicy::getPaymentAmount(){

	return paymentAmount;

}

void InsurancePolicy::setPaymentAmount(int inPaymentAmount){

	paymentAmount = inPaymentAmount;

}

int InsurancePolicy::getPolicySortCode(){

	return policySortCode;

}

void InsurancePolicy::setPolicySortCode(int inPolicySortCode){

	policySortCode = inPolicySortCode;

}

bool InsurancePolicy::getIfWasPaid(){

	return wasPayed;

}

void InsurancePolicy::setIfWasPayed(bool inWasPayed){

	wasPayed = inWasPayed;

}

bool InsurancePolicy::getIsExpired(){

	return isExpired;

}

void InsurancePolicy::setIsExpired(bool inIsExpired){

	isExpired = inIsExpired;

}

int InsurancePolicy::getClientCode(){

	return clientCode;

}

void InsurancePolicy::setClientCode(int inClientCode){

	clientCode = inClientCode;

}

int InsurancePolicy::getCoworkerCode(){

	return coworkerCode;

}

void InsurancePolicy::setCoworkerCode(int inCoworkerCode){

	coworkerCode = inCoworkerCode;

}
