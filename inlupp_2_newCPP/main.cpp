#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include "CustomerService.h"
#include "CampaignService.h"
#include "adservingengine.h"


using namespace std;


void adminMeny(string* chosenNum);
void visaAds();

void customer(ServingEngine* ENGINE, Customer* CUST);
void customerMeny(string* chosenNum);

void campaign();
void campaignMeny(string* chosenNum);

void annons();
void annonsMeny(string* chosenNum);


int main()
{
	setlocale(LC_ALL, "sv_SE.utf8");
	setlocale(LC_NUMERIC, "en_US.utf8");

	ServingEngine* ENGINE = new ServingEngine; // on the heap now????
	Customer* CUST = new Customer();

	string chosenNum = "6";
	while (true) {
		adminMeny(&chosenNum);
		if (chosenNum == "1") customer(ENGINE, CUST);
		else if (chosenNum == "2") campaign();
		else if (chosenNum == "3") annons();
		else if (chosenNum == "4") visaAds();
		else if (chosenNum == "5") break;
		else cout << "Fel nummer!" << endl;
	}
	return 0;
}

void adminMeny(string* chosenNum)
{
	cout << "******** Admin Meny ********" << endl;
	cout << "1-> CRUD for Customer" << endl;
	cout << "2-> CRUD for Campaign" << endl;
	cout << "3-> CRUD for Ad" << endl;
	cout << "4-> Show ads" << endl;
	cout << "5-> Exit" << endl;
	cout << "****************************" << endl;
	cout << "Vilken nummer -> ";
	cin >> *chosenNum;
}

void visaAds()
{
	cout << "visa ads ..." << endl;
}

void customer(ServingEngine* ENGINE, Customer* CUST)
{
	string chosenNum = "6";
	while (true) {
		customerMeny(&chosenNum);
		if (chosenNum == "1") addCustomer(ENGINE, CUST);
		else if (chosenNum == "2") readCustomer(ENGINE, CUST);
		else if (chosenNum == "3") updateCustomer(ENGINE, CUST);
		//else if (chosenNum == "4") deleteCustomer();
		else if (chosenNum == "6") CUST->PrintAllCustomers(ENGINE);
		else if (chosenNum == "5") break;
		else cout << "Fel nummer!" << endl;
	}
}

void customerMeny(string* chosenNum)
{
	cout << "******** Customer Meny ********" << endl;
	cout << "1-> Create Customer" << endl;
	cout << "2-> Read from Customer" << endl;
	cout << "3-> Uppdate Customer" << endl;
	cout << "4-> Delete Customer" << endl;
	cout << "5-> Go back" << endl;
	cout << "6-> List Customers" << endl;
	cout << "****************************" << endl;
	cout << "Vilken nummer -> ";
	cin >> *chosenNum;
}

void campaign()
{
	string chosenNum = "6";
	while (true) {
		campaignMeny(&chosenNum);
		if (chosenNum == "1") addCampaign();
		else if (chosenNum == "2") cout << "read campaign " << chosenNum << endl;
		else if (chosenNum == "3") cout << "update campaign " << chosenNum << endl;
		else if (chosenNum == "4") cout << "delete campaign " << chosenNum << endl;
		else if (chosenNum == "5") break;
		else cout << "Fel nummer!" << endl;
	}
}

void campaignMeny(string* chosenNum)
{
	cout << "******** Campaign Meny ********" << endl;
	cout << "1-> Create Campaign" << endl;
	cout << "2-> Read from Campaign" << endl;
	cout << "3-> Uppdate Campaign" << endl;
	cout << "4-> Delete Campaign" << endl;
	cout << "5-> Go back" << endl;
	cout << "****************************" << endl;
	cout << "Vilken nummer -> ";
	cin >> *chosenNum;
}

void annons()
{
	string chosenNum = "6";
	while (true) {
		annonsMeny(&chosenNum);
		if (chosenNum == "1") cout << "add annons " << chosenNum << endl;
		else if (chosenNum == "2") cout << "read annons " << chosenNum << endl;
		else if (chosenNum == "3") cout << "update annons " << chosenNum << endl;
		else if (chosenNum == "4") cout << "delete annons " << chosenNum << endl;
		else if (chosenNum == "5") break;
		else cout << "Fel nummer!" << endl;
	}
}

void annonsMeny(string* chosenNum)
{
	cout << "******** Annons Meny ********" << endl;
	cout << "1-> Create Annons" << endl;
	cout << "2-> Read from Annons" << endl;
	cout << "3-> Uppdate Annons" << endl;
	cout << "4-> Delete Annons" << endl;
	cout << "5-> Go back" << endl;
	cout << "****************************" << endl;
	cout << "Vilken nummer -> ";
	cin >> *chosenNum;
}