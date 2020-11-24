#ifndef _ADSERVINGENGINE_H
#define _ADSERVINGENGINE_H
#include "customer.h"
#include "campaign.h"
#include<vector>
using namespace std;

class AdServingEngine {
	vector<Customer>customerList;
public:
	AdServingEngine();
	int createCustomerId();
	void addCustomer(Customer cust);
	Customer getCustomerbyIndex(int index);
	void deleteCustomer(Customer cust);
	AD* getNextAd();
};
#endif
