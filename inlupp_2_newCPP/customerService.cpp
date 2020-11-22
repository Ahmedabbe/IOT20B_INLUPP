#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include "customer.h"



using namespace std;

void addCustomerToDB(ServingEngine* ENGINE, Customer* CUST, string name)
{
	CUST->CreateCustomer(ENGINE, name);
	cout << "db -> " << name << endl;
}

bool hasCustomer(ServingEngine* ENGINE, Customer* CUST, string name)
{
	if (CUST->checkCustomer(ENGINE, name) == true) {
		return true;
	}
	else
		return false;
}

void addCustomer(ServingEngine* ENGINE, Customer* CUST)
{
	string indata = "";
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		cin >> indata;
		if (!hasCustomer(ENGINE, CUST, indata) || indata == "#") break;
		cout << "Customer is already found !" << endl;
	}
	if (indata == "#") return;
	addCustomerToDB(ENGINE, CUST, indata);
}

void readCustomer(ServingEngine* ENGINE, Customer* CUST)
{
	string indata = "";
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		cin >> indata;
		if (hasCustomer(ENGINE, CUST, indata) || indata == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (indata == "#") return;
	cout << endl;
	CUST->PrintCustomers(ENGINE, indata);
}

void updateCustomer(ServingEngine* ENGINE, Customer* CUST)
{
	string oldname = "";
	string newname = "";
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		cin >> oldname;
		if (hasCustomer(ENGINE, CUST, oldname) || oldname == "#") break;
		cout << "Customer not found !" << endl;
	}
	while (true) {
		cout << "Customer new name (# -> go back) -> ";
		cin >> newname;
		if (!hasCustomer(ENGINE, CUST, newname) || newname == "#") break;
		cout << "Customer is already found !" << endl;
	}
	if (oldname == "#" || newname == "#") return;
	CUST->RenameCustomer(ENGINE, oldname, newname);
}
//void deleteCustomer()
//{
//	string indata = "";
//	while (true) {
//		cout << "Customer name (# -> go back) -> ";
//		cin >> indata;
//		if (hasCustomer(indata) || indata == "#") break;
//		cout << "Customer not found !" << endl;
//	}
//	if (indata == "#") return;
//	//deleteCustomerFromDB(indata);
//}