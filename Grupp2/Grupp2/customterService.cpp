#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include "Customer.h"

using namespace std;

void addCustomerToDB(string name, vector<Customer> &kundlist)
{
	
	cout << "add new kund success !" << endl;
}

Customer getCustomerFromDB(string name, vector<Customer> &kundlist) {
	Customer k = Customer();
	
	return k;
}

void updateCustomerToDB(string oldname, string newname, vector<Customer> &kundlist) {
	
			cout << "Update success for Customer: " << endl;
		
}

void deleteCustomerFromDB(string name, vector<Customer> &kundlist) {
	
			cout << "Delete success ! "<< endl;
	
}

bool hasCustomer(string name, vector<Customer> &kundlist)
{
	
	return false;
}

void addCustomer(vector<Customer> &kundlist)
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

void showCustomer(Customer kund) {
	cout << "show customer" << endl;
}

void readCustomer(vector<Customer> &kundlist)
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
	Customer found = getCustomerFromDB(indata, kundlist);
	showCustomer(found);	
}

void updateCustomer(vector<Customer> &kundlist)
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
void deleteCustomer(vector<Customer> &kundlist)
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

void showCustomers(vector<Customer> &kundlist) {
	for (auto kund : kundlist) {
		showCustomer(kund);
	}
}