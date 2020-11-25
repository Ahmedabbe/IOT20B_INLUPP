#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <sstream>
#include <string>
#include<locale.h>
#include <vector>
#include <windows.h>
#include "CustomerService.h"
#include "CampaignService.h"
#include "Customer.h"
#include "AnnonService.h"
#include "Campaign.h"
#include "AdServingEngine.h"

using namespace std;

void adminMeny(string* chosenNum);
//void visaAds(AdEngine* engine, vector<Customer*>& kundlist);
void fakeDisplay(AdEngine* engine, vector<Customer*>& kundlist);

void customer(vector<Customer*> &kundlist);
void customerMeny(string* chosenNum);

void campaign(vector<Customer*> &kundlist);
void campaignMeny(string* chosenNum);

void annons(vector<Customer*> &kundlist);
void annonsMeny(string* chosenNum);

int main() 
{
	setlocale(LC_ALL, "sv_SE.utf8");
	setlocale(LC_NUMERIC, "en_US.utf8");

	AdEngine* engine = new AdEngine();
	vector<Customer*> kundlist = engine->getKundlist();

	string chosenNum = "6";
	while (true) {
		adminMeny(&chosenNum);
		if (chosenNum == "1") customer(kundlist);
		else if (chosenNum == "2") campaign(kundlist);
		else if (chosenNum == "3") annons(kundlist);
		else if (chosenNum == "4") fakeDisplay(engine, kundlist);
		else if (chosenNum == "9") break;
		else cout << "Fel nummer!" << endl;
	}
	return 0;
}

void adminMeny(string* chosenNum)
{
	cout << "******** Admin Meny ********" << endl;
	cout << "1-> CRUD för Customer" << endl;
	cout << "2-> CRUD för Kampanj" << endl;
	cout << "3-> CRUD för Annons" << endl;
	cout << "4-> Visa Annons" << endl;
	cout << "9-> Exit" << endl;
	cout << "****************************" << endl;
	cout << "Vilken nummer -> ";
	cin >> *chosenNum;
}
void fakeDisplay(AdEngine* engine, vector<Customer*>& kundlist) {
	engine->setKundlist(kundlist);
	char inChar;
	do
	{
		std::cout << "display ads";
		std::cout << engine->getNextAd()->getAdContent() << "\n";
		Sleep(2000);
		cout << "Enter X to go back to Menu :";
		cin >> inChar;
	} while (inChar != 'X');
	return;
}


//void visaAds(AdEngine* engine, vector<Customer*>& kundlist)
//{
//	engine->setKundlist(kundlist);
//	cout << engine->getKundlist().size() << " visas " << endl;
//	cout << "visa next ads ..." << endl;
//}

void customer(vector<Customer*> &kundlist)
{
	string chosenNum = "7";
	while (true) {
		customerMeny(&chosenNum);
		if (chosenNum == "1") addCustomer(kundlist);
		else if (chosenNum == "2") readCustomer(kundlist);
		else if (chosenNum == "3") updateCustomer(kundlist);
		else if (chosenNum == "4") deleteCustomer(kundlist);
		else if (chosenNum == "5") showCustomers(kundlist);
		else if (chosenNum == "9") break;
		else cout << "Fel nummer!" << endl;
		//cout << kundlist->size() << endl;
	}
}

void customerMeny(string* chosenNum)
{	
	cout << "******** Customer Meny ********" << endl;
	cout << "1-> Create Customer" << endl;
	cout << "2-> Read from Customer" << endl;
	cout << "3-> Uppdate Customer" << endl;
	cout << "4-> Delete Customer" << endl;
	cout << "5-> Show Customers" << endl;
	cout << "9-> Go back" << endl;
	cout << "****************************" << endl;
	cout << "Vilken nummer -> ";
	cin >> *chosenNum;
}

void campaign(vector<Customer*> &kundlist)
{
	string chosenNum = "7";
	while (true) {
		campaignMeny(&chosenNum);
		if (chosenNum == "1") addCampaign(kundlist);
		else if (chosenNum == "2") readCampaign(kundlist);
		else if (chosenNum == "3") updateCampaign(kundlist);
		else if (chosenNum == "4") deleteCampaign(kundlist);
		else if (chosenNum == "5") showCampaigns(kundlist);
		else if (chosenNum == "9") break;
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
	cout << "5-> Show Campaigns" << endl;
	cout << "9-> Go back" << endl;
	cout << "****************************" << endl;
	cout << "Vilken nummer -> ";
	cin >> *chosenNum;
}

void annons(vector<Customer*> &kundlist)
{
	string chosenNum = "7";
	while (true) {
		annonsMeny(&chosenNum);
		if (chosenNum == "1") addAD(kundlist);
		else if (chosenNum == "2") readAD(kundlist);
		else if (chosenNum == "3") updateAD(kundlist);
		else if (chosenNum == "4") deleteAD(kundlist);
		else if (chosenNum == "5") showADs(kundlist);
		else if (chosenNum == "9") break;
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
	cout << "5-> Show Annons" << endl;
	cout << "9-> Go back" << endl;
	cout << "****************************" << endl;
	cout << "Vilken nummer -> ";
	cin >> *chosenNum;
}
