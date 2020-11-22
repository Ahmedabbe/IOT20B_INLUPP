
#include "customer.h"
#include "adservingengine.h"

Customer::Customer() {
	newName = "";
	newID = 1337;
}

Customer::Customer(string name, int ID = 1337) {
	newName = name;
	newID = ID;
}

Customer::~Customer() {


}

string Customer::getName() const {
	return newName;
}

int Customer::getID() const {
	return newID;
}


void Customer::setName(string name) {
	this->newName = name;
}

void Customer::setID(int ID) {
	newID = ID;
}


// Creating customer name and ID
void Customer::CreateCustomer(ServingEngine* ENGINE, string name) {

	Customer newCustomer(name, ENGINE->NumberOfCustomers() + 1); // "ENGINE->NumberOfCustomers() + 1" only works with no delete function

	ENGINE->AddCustomer(newCustomer);
}

// Printing all customers in certain vector
void Customer::PrintCustomers(ServingEngine* ENGINE, string name) {

	for (int i = 0; i < ENGINE->NumberOfCustomers(); i++) {

		if (name == ENGINE->GetCustomerByIndex(i).getName()) {


			PrintCust(ENGINE, i);

		}
	}

}

// Printing specific Customer attributes
void Customer::PrintCust(ServingEngine* ENGINE, int index) {
	cout << "Name: " << ENGINE->GetCustomerByIndex(index).getName() << endl;
	cout << "ID: " << ENGINE->GetCustomerByIndex(index).getID() << endl;
	cout << endl;

}

// Changing customer name as part of CRUD
void Customer::RenameCustomer(ServingEngine* ENGINE, string currentName, string newName) {

	for (int i = 0; i < ENGINE->NumberOfCustomers(); i++) {

		if (currentName == ENGINE->GetCustomerByIndex(i).getName()) {


			ENGINE->GetCustomerByIndex(i).setName(newName);

		}
	}
}



bool Customer::checkCustomer(ServingEngine* ENGINE, string name) {

	for (int i = 0; i < ENGINE->NumberOfCustomers(); i++) {

		if (name == ENGINE->GetCustomerByIndex(i).getName()) {

			return true;

		}
	}
	return false;
}



void Customer::PrintAllCustomers(ServingEngine* ENGINE) {

	for (int i = 0; i < ENGINE->NumberOfCustomers(); i++) {


		PrintCust(ENGINE, i);

	}
}


int Customer::NumberOfCampaigns() {

	return Campaigns.size();

}

Campaign& Customer::GetCampaignByIndex(int index) {

	return Campaigns[index];
}

void Customer::AddCampaign(Campaign c) {

	return Campaigns.push_back(c);
}

