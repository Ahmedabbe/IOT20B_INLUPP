#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include "Customer.h"

using namespace std;

void addCustomerToDB(string name, vector<Customer*> &kundlist)
{
	Customer* kund = new Customer(name);
	kundlist.push_back(kund);
	cout << "add new kund success !" << endl;
}

Customer* getCustomerFromDB(string name, vector<Customer*> &kundlist) {
	for (auto kund : kundlist) {
		if (kund->getName() == name) return kund;
	}
}

void updateCustomerToDB(string oldname, string newname, vector<Customer*> &kundlist) {
	for (auto kund : kundlist) {
		if (kund->getName() == oldname) {
			kund->setName(newname);
			cout << "Update success for Customer: " << kund->getName() << endl;
			break;
		}
	}
}

void deleteCustomerFromDB(string name, vector<Customer*> &kundlist) {
	int index = -1;
	for (auto kund : kundlist) {
		index++;
		if (kund->getName() == name) {
			kundlist.erase(kundlist.begin() + index); 
			cout << "Delete success ! " << endl;
			break;
		}
	}
}

bool hasCustomer(string name, vector<Customer*> &kundlist)
{
	if (!kundlist.size()) return false;
	for (auto kund : kundlist) {
		if (kund->getName() == name) return true;
	}	
	return false;
}

void addCustomer(vector<Customer*> &kundlist)
{
	string indata = "";
	cin.ignore();
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		getline(cin, indata);
		if (indata.length() == 0) {
			cout << "Input something" << endl;
			continue;
		}
		if (!hasCustomer(indata, kundlist) || indata == "#") break;
		cout << "Customer is already found !" << endl;
	}
	if (indata == "#") return;
	addCustomerToDB(indata, kundlist);
}

void showCustomer(Customer* kund) {
	cout << "****************************" << endl;
	cout << "Found Customer name: " << kund->getName() << ", id: " << kund->getID() << endl;
	if (kund->getCampaigns().size() > 0) {
		if (kund->hasActiveCampaign()) {
			cout << "--Has " << kund->getCampaigns().size() << " active campaigns" << endl;
			for (auto camp : kund->getCampaigns()) {
				cout << "	Campaign name: " << camp->getName() 
					<< " , id: " << camp->getId() << ", kund id: " << camp->getKundID() << endl;
				if (camp->getAds().size() > 0) {
					cout << "	--This campaign has " << camp->getAds().size() << " ads" << endl;
					for (auto ad : camp->getAds()) {
						cout << "		Ad name: " << ad->getName() 
							<< " , id: " << ad->getID() << ", kund id: " << ad->getKundID() 
							<< ", campaign id: " << ad->getCampID() << endl;
					}
				}
			}
		}
		else cout << "--Has no active campaigns" << endl;
	}
}

void readCustomer(vector<Customer*> &kundlist)
{
	string indata = "";
	cin.ignore();
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		getline(cin, indata);
		if (hasCustomer(indata, kundlist) || indata == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (indata == "#") return;
	Customer* found = getCustomerFromDB(indata, kundlist);
	showCustomer(found);	
}

void updateCustomer(vector<Customer*> &kundlist)
{
	string oldname = "";
	string newname = "";
	cin.ignore();
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		getline(cin, oldname);
		if (hasCustomer(oldname, kundlist) || oldname == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (oldname == "#") return;
	while (true) {
		cout << "Customer new name (# -> go back) -> ";
		getline(cin, newname);
		if (!hasCustomer(newname, kundlist) || newname == "#") break;
		cout << "Customer is already found !" << endl;
	}
	if (newname == "#") return;
	updateCustomerToDB(oldname, newname, kundlist);
}
void deleteCustomer(vector<Customer*> &kundlist)
{
	string indata = "";
	cin.ignore();
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		getline(cin, indata);
		if (hasCustomer(indata, kundlist) || indata == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (indata == "#") return;
	deleteCustomerFromDB(indata, kundlist);
}

void showCustomers(vector<Customer*> &kundlist) {
	for (auto kund : kundlist) {
		showCustomer(kund);
	}
}