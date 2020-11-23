#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include "Customer.h"

//Customer::Customer() {
//	newName = "";
//	newID = 0;
//	hasActiveCampaigns = false;
//
//}
Customer::Customer(){}

Customer::Customer(string name) {
	this->newName = name;
	//hasActiveCampaigns = status;
}

Customer::Customer(string name, int ID) {
	this->newName = name;
	this->newID = ID;
	//hasActiveCampaigns = status;
}

Customer::~Customer() {


}

string Customer::getName() const {
	return this->newName;
}

int Customer::getID() const {
	return this->newID;
}

//bool Customer::getActiveCampaign() const {
//	return hasActiveCampaigns;
//}

void Customer::setName(string name) {
	this->newName = name;
}

void Customer::setID(int ID) {
	this->newID = ID;
}

vector<Campaign*> Customer::getCampaigns() {
	return this->Campaigns;
}

void Customer::setCampaigns(vector<Campaign*> campaigns) {
	this->Campaigns = campaigns;
}

bool Customer::hasActiveCampaign() {
	vector<Campaign*> camps;

	time_t today = time(NULL);
	struct tm todaydate = *localtime(&today);
	todaydate.tm_hour = 1;
	todaydate.tm_min = 0;
	todaydate.tm_sec = 0;	
	for (auto camp : this->Campaigns) {
		struct tm from = camp->getFrom();
		struct tm to = camp->getTo();
		if (difftime(mktime(&todaydate), mktime(&from)) >= 0
			&& difftime(mktime(&to), mktime(&todaydate)) >= 0) camps.push_back(camp);
	}
	this->setCampaigns(camps);
	return camps.size();
}

//void Customer::setActiveCampaign(bool status) {
//	hasActiveCampaigns = status;
//}

// Creating customer name and ID and setting "ActiveCampaigns" as false as standard for new customers
//void Customer::CreateCustomer(STATE* SYSTEM_STATE) {
//
//	string name;
//	int ID;
//
//	cout << "Customer name: ";
//	cin >> name;
//
//	cout << "Customer ID: ";
//	cin >> ID;
//
//	Customer newCustomer(name, ID, false);
//
//	SYSTEM_STATE->customer_list.push_back(newCustomer);
//	cout << endl;
//}
//
//// Printing all customers in certain vector
//void Customer::PrintCustomers(STATE* SYSTEM_STATE) {
//
//	for (Customer& CUST : SYSTEM_STATE->customer_list) {
//
//		PrintCust(&CUST);
//
//	}
//
//}
//
//// Printing specific Customer attributes
//void Customer::PrintCust(Customer* CUST) {
//	cout << "Name: " << CUST->getName() << endl;
//	cout << "ID: " << CUST->getID() << endl;
//	cout << (CUST->getActiveCampaign() ? "Has current Campaigns" : "Has no current Campaigns") << endl;
//	cout << endl;
//
//}
//
//// Changing customer name as part of CRUD
//void Customer::RenameCustomer(STATE* SYSTEM_STATE, string currentName) {
//
//	string newName;
//
//
//	for (Customer& CUST : SYSTEM_STATE->customer_list) {
//
//		if (currentName == CUST.getName()) {
//
//			cout << "Enter new customer name: ";
//			cin >> newName;
//			CUST.setName(newName);
//
//		}
//	}
//}
