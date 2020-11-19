
#include "Customer.h"
#include "STATE.h"

Customer::Customer() {
	newName = "";
	newID = 0;
	hasActiveCampaigns = false;
	
}

Customer::Customer(string name, int ID, bool status) {
	newName = name;
	newID = ID;
	hasActiveCampaigns = status;
}

Customer::~Customer() {


}

string Customer::getName() const {
	return newName;
}

int Customer::getID() const {
	return newID;
}

bool Customer::getActiveCampaign() const {
	return hasActiveCampaigns;
}

void Customer::setName(string name) {
	newName = name;
}

void Customer::setID(int ID) {
	newID = ID;
}

void Customer::setActiveCampaign(bool status) {
	hasActiveCampaigns = status;
}

// Creating customer name and ID and setting "ActiveCampaigns" as false as standard for new customers
void Customer::CreateCustomer(STATE* SYSTEM_STATE) {

	string name;
	int ID;

	cout << "Customer name: ";
	cin >> name;

	cout << "Customer ID: ";
	cin >> ID;

	Customer newCustomer(name, ID, false);

	SYSTEM_STATE->customer_list.push_back(newCustomer);
	cout << endl;
}

// Printing all customers in certain vector
void Customer::PrintCustomers(STATE* SYSTEM_STATE) {

	for (Customer& CUST : SYSTEM_STATE->customer_list) {

		PrintCust(&CUST);

	}

}

// Printing specific Customer attributes
void Customer::PrintCust(Customer* CUST) {
	cout << "Name: " << CUST->getName() << endl;
	cout << "ID: " << CUST->getID() << endl;
	cout << (CUST->getActiveCampaign() ? "Has current Campaigns" : "Has no current Campaigns") << endl;
	cout << endl;

}

// Changing customer name as part of CRUD
void Customer::RenameCustomer(STATE* SYSTEM_STATE, string currentName) {

	string newName;


	for (Customer& CUST : SYSTEM_STATE->customer_list) {

		if (currentName == CUST.getName()) {

			cout << "Enter new customer name: ";
			cin >> newName;
			CUST.setName(newName);

		}
	}
}