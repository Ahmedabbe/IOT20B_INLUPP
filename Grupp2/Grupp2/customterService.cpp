#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include "Customer.h"

using namespace std;

void addCustomerToDB(string name, vector<Customer>* kundlist)
{
	Customer kund (name);
	kundlist->push_back(kund);
	cout << "add new kund success !" << endl;
}

Customer getCustomerFromDB(string name, vector<Customer>* kundlist) {
	for (auto kund : *kundlist) {
		if (kund.getName() == name) return kund;
	}
}

void updateCustomerToDB(string oldname, string newname, vector<Customer>* kundlist) {
	for (auto kund = kundlist->begin(); kund != kundlist->end(); ++kund) {
		if (kund->getName() == oldname) {
			kund->setName(newname);
			cout << "Update success for Customer: " << kund->getName() << endl;
			break;
		}
	}
}

void deleteCustomerFromDB(string name, vector<Customer>* kundlist) {
	for (auto kund = kundlist->begin(); kund != kundlist->end(); ++kund) {
		if (kund->getName() == name) {
			kundlist->erase(kund);
			cout << "Delete success ! "<< endl;
			break;
		}
	}
}

bool hasCustomer(string name, vector<Customer>* kundlist)
{
	if (!kundlist->size()) return false;
	for (auto kund : *kundlist) {
		if (kund.getName() == name) return true;
	}	
	return false;
}

void addCustomer(vector<Customer>* kundlist)
{
	string indata = "";
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		cin >> indata;
		if (!hasCustomer(indata, kundlist) || indata == "#") break;
		cout << "Customer is already found !" << endl;
	}
	if (indata == "#") return;
	addCustomerToDB(indata, kundlist);
}

void readCustomer(vector<Customer>* kundlist)
{
	string indata = "";
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		cin >> indata;
		if (hasCustomer(indata, kundlist) || indata == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (indata == "#") return;
	Customer found = getCustomerFromDB(indata, kundlist);
	cout << "Found Customer name: " << found.getName() << endl;
}

void updateCustomer(vector<Customer>* kundlist)
{
	string oldname = "";
	string newname = "";
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		cin >> oldname;
		if (hasCustomer(oldname, kundlist) || oldname == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (oldname == "#") return;
	while (true) {
		cout << "Customer new name (# -> go back) -> ";
		cin >> newname;
		if (!hasCustomer(newname, kundlist) || newname == "#") break;
		cout << "Customer is already found !" << endl;
	}
	if (newname == "#") return;
	updateCustomerToDB(oldname, newname, kundlist);
}
void deleteCustomer(vector<Customer>* kundlist)
{
	string indata = "";
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		cin >> indata;
		if (hasCustomer(indata, kundlist) || indata == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (indata == "#") return;
	deleteCustomerFromDB(indata, kundlist);
}

