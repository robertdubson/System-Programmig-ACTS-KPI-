// InsurancePolicy.h
#include <string>
using namespace std;

class InsurancePolicy{

public:

 InsurancePolicy(); // конструктор
~InsurancePolicy(); // деструктор

void payThePolicy(int inMoney);
void displayTheData();
void checkIfWasExpired();
void checkIfWasPayed();

// методи доступу до даних
int  getPolicyNumber();
void setPolicyNumber (int  inPolicyNumber);
std::string getDateOfTheContract();
void setDateOfTheContract(std::string inDateOfTheContract);
std::string getDateOfExpiry();
void setDateOfExpiry(std::string inDateOfExpiry);
int getPrice();
void setPrice(int inPrice);
int getPaymentAmount();
void setPaymentAmount(int inPaymentAmount);
int getPolicySortCode();
void setPolicySortCode(int inPolicySortCode);
bool getIfWasPaid();
void setIfWasPayed(bool inWasPayed);
bool getIsExpired();
void setIsExpired(bool inIsExpired);
int getClientCode();
void setClientCode(int inClientCode);
int getCoworkerCode();
void setCoworkerCode(int inCoworkerCode);

private:
int policyNumber; // номер полісу
std::string  dateOfTheContract; // дата початку
std::string dateOfExpiry; // дата завершення
int Price; // вартість
int paymentAmount; // сума виплати
int policySortCode; // код виду полісу
bool wasPayed; // відмітка про виплату
bool isExpired; // відмітка про закінчення
int clientCode; // код клієнта
int coworkerCode; // код співробітника


};
