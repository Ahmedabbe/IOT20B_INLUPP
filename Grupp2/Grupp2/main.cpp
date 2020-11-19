#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>

using namespace std;

void adminMeny(string* chosenNum);

void customer();
void customerMeny(string* chosenNum);
void addCustomer();
bool hasCustomer(string name);
void addCustomerToDB(string name);

void campaign();
void campaignMeny(string* chosenNum);
void addCampaign();
bool hasCampaign(string name);
void addCampaignToDB(string name, float cost);

void annons();
void annonsMeny(string* chosenNum);

int main() 
{
	setlocale(LC_ALL, "sv_SE.utf8");
	setlocale(LC_NUMERIC, "en_US.utf8");

	string chosenNum = "5";
	while (true) {
		adminMeny(&chosenNum);
		if(chosenNum=="1") customer();
		else if (chosenNum == "2") campaign();
		else if (chosenNum == "3") annons();
		else if (chosenNum == "4") break;
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
	cout << "4-> Quit" << endl;
	cout << "****************************" << endl;
	cout << "Vilken nummer -> ";
	cin >> *chosenNum;
}

void customer()
{
	string chosenNum = "6";
	while (true) {
		customerMeny(&chosenNum);
		if (chosenNum == "1") addCustomer();
		else if (chosenNum == "2") cout << "read customer " << chosenNum << endl;
		else if (chosenNum == "3") cout << "update customer " << chosenNum << endl;
		else if (chosenNum == "4") cout << "delete customer " << chosenNum << endl;
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
	cout << "5-> Quit" << endl;
	cout << "****************************" << endl;
	cout << "Vilken nummer -> ";
	cin >> *chosenNum;
}

void addCustomer()
{
	string indata = "";
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		cin >> indata;
		if (!hasCustomer(indata) || indata == "#") break;
		cout << "Customer is already found !" << endl;
	}
	if (indata == "#") return;
	addCustomerToDB(indata);
}

void addCustomerToDB(string name)  // add name id?? to customer
{
	cout << "db " << name << endl;
}

bool hasCustomer(string name)
{
	bool found = false;
	return found;
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
	cout << "5-> Quit" << endl;
	cout << "****************************" << endl;
	cout << "Vilken nummer -> ";
	cin >> *chosenNum;
}

void addCampaign()
{
	string name = "";
	string coststr = "";
	float cost = 0;
	while (true) {
		cout << "Campaign name (# -> go back) -> ";
		cin >> name;
		if (!hasCampaign(name) || name == "#") break;
		cout << "Customer is already found !" << endl;
	}
	while (true) {
		cout << "Campaign cost (# -> go back) -> ";
		cin >> coststr;
		stringstream s(coststr);
		if (!(s >> cost) || !s.eof() || coststr == "#") {
			cout << "fel nummer för cost !" << endl;
		}
		else {
			s >> cost;
			break;
		}
	}
	if (name == "#" || coststr == "#") return;
	addCampaignToDB(name, cost);
}

bool hasCampaign(string name)
{
	bool found = false;
	return found;
}

void addCampaignToDB(string name, float cost)  //  add name id?? datetime ?? to campaign
{
	cout << "db 2 " << name << " 3 " << cost << endl;
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
	cout << "5-> Quit" << endl;
	cout << "****************************" << endl;
	cout << "Vilken nummer -> ";
	cin >> *chosenNum;
}
