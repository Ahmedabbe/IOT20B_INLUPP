#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include "customer.h"


using namespace std;

void addCustomer(ServingEngine* ENGINE, Customer* CUST);

void readCustomer(ServingEngine* ENGINE, Customer* CUST);
void updateCustomer(ServingEngine* ENGINE, Customer* CUST);
//void deleteCustomer();
bool hasCustomer(ServingEngine* ENGINE, Customer* CUST, string name);
void addCustomerToDB(ServingEngine* ENGINE, Customer* CUST, string name);