

#ifndef ENGINE_H
#define ENGINE_H
#include <vector>
#include "customer.h"

using namespace std;

class ServingEngine {
private:

	vector<Customer> customer_list;

public:

	ServingEngine();
	int NumberOfCustomers();
	Customer& GetCustomerByIndex(int index);
	void AddCustomer(Customer c);

};

#endif ENGINE_H