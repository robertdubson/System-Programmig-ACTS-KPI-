//InsurancePolicy.h
#include <string>
using namespace std;

class InsurancePolicy{

public:
	InsurancePolicy(); //constructor 
	~InsurancePolicy(); //destructor

void displayData();
void checkIfWasExpired();
void checkIfWasPayed();

//methods to get access to data
int getPolicyNumber();
void setPolicyNumber(int inPolicyNumber);

std::string getDateOfTheContractBeginning();
void setDateOfTheContractBeginning(std::string inDateOfTheContractBeginning);

std::string getDateOfContractExpiry();
void setDateOfContractExpiry(std::string inDateOfContractExpiry);

int getPrice();
void setPrice(int inPrice);

int getPaymentAmount();
void setPaymentAmount(int inPaymentAmount);

int getPocicySortCode();
void setPocicySortCode(int inPocicySortCode);

bool getIfWasPaid();
void setIfWasPaid(bool inWasPaid);

bool getIsExpired();
void setIsExpired(bool inIsExpired);

int getClientCode();
void setClientCode(int inClientCode);

int getCoworkerCode();
void setCoworkerCode(int inCoworkerCode);

private:
int PolicyNumber; 
std::string DateOfTheContractBeginning;
std::string DateOfContractExpiry;
int Price;
int PaymentAmount;
int PolicySortCode;
bool wasPayed;
bool isExpired;
int ClientCode;
int CoworkerCode;
};
