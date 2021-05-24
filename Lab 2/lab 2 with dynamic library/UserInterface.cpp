#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <stdio.h>
#include "DataBase.h"
//#include <ofstream>
//#include <ifstream>
using namespace std;

int displayMenu();
void deletePolicy(DataBase &inDB);
void createNewPolicy(DataBase &inDB);
void payThePolicy(DataBase &inDB);
void writeToFile(DataBase &inDB);
void readFromFile(DataBase &inDB);
void getPolicyInfo(DataBase &inDB);

int main(int argc, char** argv){

//File fp;

//DataBase *policyDB;

//policyDB = new DataBase();

DataBase policyDB;


bool done = false;

while(!done){

int selection = displayMenu();

switch(selection){

	case 1:
		createNewPolicy(policyDB);
		break;
	case 2:
		deletePolicy(policyDB);
		break;
	case 3: 
		policyDB.displayAll();
		break;
	case 4:
		policyDB.displayCurrent();
		break;
	case 5:
		payThePolicy(policyDB);
		break;
	case 6:
		writeToFile(policyDB);
		break;
	case 7:
		readFromFile(policyDB);
		break;
	case 8:
		getPolicyInfo(policyDB);
		break;
	case 0:
		done = true;
		break;
	default:
		cout<<"Unkown command. Please, try again,"<< endl; 
}

}


}


void getPolicyInfo(DataBase &inDB){

	int inPolicyNumber;
	cout<< "Please, enter the number of the policy." << "\n";
	cin >> inPolicyNumber;
	inDB.getByNumber(inPolicyNumber).displayTheData();

}



void writeToFile(DataBase &inDB){


	inDB.writeToFile();



}


void readFromFile(DataBase &inDB){

	inDB.readFromFile();

}

int displayMenu(){

int selection;

cout<<endl;
cout<<"InsurancePolicyDataBase" << endl;
cout<<"-----------------------" << endl;
cout<<"1) Create new policy" << endl;
cout<<"2) Delete the policy" << endl;
cout<<"3) List all policies" << endl;
cout<<"4) List all current policies " << endl;
cout<<"5) Pay the policy." << endl;
cout<<"6) Write to the file" << endl;
cout<<"7) Read from the file" << endl;
cout<< "8) Display Info of a policy" << endl;
cout<<"0) EXIT" << endl;
cout<< endl;
cout<<"--->";
cin >> selection;

return selection;

}

void createNewPolicy(DataBase &inDB){

	int inPolicyNumber;
	cout << "Please, enter the number of your policy.";
	cin >> inPolicyNumber;
	//try{

		inDB.addPolicy(inPolicyNumber);

	//}catch(std::exception ex){
	//	cout<<"Unable to add new policy;" << endl;
//	}

}

void deletePolicy(DataBase &inDB){

	int inPolicyNumber;
	cout<<"You are going to delete the policy."<<endl;
	cout<< "Please, enter the number or the policy.";
	cin>> inPolicyNumber;
//	try{
	
		inDB.removePolicy(inPolicyNumber);

//	}
//	catch(std::exception ex){
//	cout<<"Unable to remove the policy."<< endl;
//	}

}

void payThePolicy(DataBase &inDB){

	int inMoney;
	int inPolicyNumber;
	cout<< "Please, enter the policy number you want to pay.";
	cin >> inPolicyNumber;
	cout << "Howmuch money do you want to pay?";
	cin>> inMoney;

	//try{
	
		inDB.payThePolicy(inPolicyNumber, inMoney);

	//}
	//catch(std::exception ex){

	//	cout<< "Unable to pay the policy:("<< endl;

	//}

}


