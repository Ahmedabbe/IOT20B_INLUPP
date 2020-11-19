#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include <vector>
#include "Customer.h"

using namespace std;

void addCustomer(vector<Customer>* kundlist);
void readCustomer(vector<Customer>* kundlist);
void updateCustomer(vector<Customer>* kundlist);
void deleteCustomer(vector<Customer>* kundlist);
bool hasCustomer(string name, vector<Customer>* kundlist);
void addCustomerToDB(string name, vector<Customer>* kundlist);
Customer getCustomerFromDB(string name, vector<Customer>* kundlist);
void updateCustomerToDB(string oldname, string newname, vector<Customer>* kundlist);
void deleteCustomerFromDB(string name, vector<Customer>* kundlist);