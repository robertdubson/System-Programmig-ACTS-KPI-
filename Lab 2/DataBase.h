#include <iostream>
#include "InsurancePolicy.h"
#include <vector>
class DataBase{

public:
	DataBase();
	~DataBase();

	void displayAll();
	void displayCurrent();
	
	void addPolicy(int inPolicyNumber);
	void removePolicy(int inPolicyNumber);
	InsurancePolicy& getByNumber(int inPolicyNumber);
	void payThePolicy(int inPolicyNumber, int inMoney);
	void writeToFile();
	void readFromFile();
protected:
	std::vector<InsurancePolicy> policies;


};

