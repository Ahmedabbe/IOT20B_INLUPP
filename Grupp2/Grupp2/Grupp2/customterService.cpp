#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>

using namespace std;

void addCustomerToDB(string name)
{
	cout << "db -> " << name << endl;
}

bool hasCustomer(string name)
{
	bool found = false;
	return found;
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

void readCustomer()
{
	string indata = "";
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		cin >> indata;
		if (hasCustomer(indata) || indata == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (indata == "#") return;
	//getCustomerFromDB(indata);
}

void updateCustomer()
{
	string oldname = "";
	string newname = "";
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		cin >> oldname;
		if (hasCustomer(oldname) || oldname == "#") break;
		cout << "Customer not found !" << endl;
	}
	while (true) {
		cout << "Customer new name (# -> go back) -> ";
		cin >> newname;
		if (!hasCustomer(newname) || newname == "#") break;
		cout << "Customer is already found !" << endl;
	}
	if (oldname == "#" || newname == "#") return;
	//updateCustomerToDB(oldname, newname);
}
void deleteCustomer()
{
	string indata = "";
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		cin >> indata;
		if (hasCustomer(indata) || indata == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (indata == "#") return;
	//deleteCustomerFromDB(indata);
}

