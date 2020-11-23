#include "adServingEngine.h"
#include "customer.h"
#include "campaign.h"
#include "AD.h"
#include<vector>
using namespace std;

AdServingEngine::AdServingEngine() {
	vector<Customer>customerList;
}

int AdServingEngine::getCustomerId() {
	return this->customerList.size();
}
void AdServingEngine::addCustomer(Customer cust) {
	/*for (int i=0;i< customerList.size();i++){
		if (cust.getName() == customerList[i].getName()) {
			exception thrown:
		}*/
	this->customerList.push_back(cust);
}

Customer AdServingEngine::getCustomerbyIndex(int index) {
	return customerList[index];
}

void AdServingEngine::deleteCustomer(Customer cust) {
	for (int i = 0; i < customerList.size(); i++) {
		if (cust.getName() == customerList[i].getName())
			customerList.erase(customerList.begin() + i);
	}
}

AD AdServingEngine::getNextAd() {
	if (!customerList.empty()) {
		vector<Customer>activeCustomerList;
		double totalSlot = 0;
		for (int i = 0; i < customerList.size(); i++) {
			if (customerList[i]->hasActiveCampaigns()) {
				activeCustomerList.push_back(customerList[i]);
				totalSlot += customerList[i].getActiveCampaign().getCampaignCost();
			}
			do {
				double slotSelection=rand() % totalSlot;
				
			} while (nextCustomer == currentCustomer);
	