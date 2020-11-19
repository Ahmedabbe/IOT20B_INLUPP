#include <iostream>
#include <vector>
#include "Customer.h"
#include "STATE.h"
#include <string>
#include <algorithm>

using namespace std;



int main()
{
	STATE SYSTEM_STATE;
	Customer CUST;

	string lasse = "lasse";

	CUST.CreateCustomer(&SYSTEM_STATE);
	CUST.CreateCustomer(&SYSTEM_STATE);
	CUST.CreateCustomer(&SYSTEM_STATE);

	CUST.RenameCustomer(&SYSTEM_STATE, lasse);


	CUST.PrintCustomers(&SYSTEM_STATE);


	return 0;
}

