#include "adServingEngine.h"
#include "customer.h"
#include "campaign.h"
#include "AD.h"
#include<vector>
#include<ctime>
using namespace std;

AdServingEngine::AdServingEngine() {
	vector<Customer>customerList;
}

int AdServingEngine::createCustomerId() {
	return this->customerList.size();
}
void AdServingEngine::addCustomer(Customer cust) {
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

AD* AdServingEngine::getNextAd() {
	if (!customerList.empty()) {
		vector<Campaign*>activeCampaignsList;
		float totalVisibility = 0, min = 0;
		Campaign* nextCampaign, * currentCampaign;
		for (int i = 0; i < customerList.size(); i++) {
			if (customerList[i].hasActiveCampaign()) {
				for (auto camp : customerList[i].getCampaigns()) {
					time_t now = time(NULL);
					if (mktime(&camp->getFrom()) <= now && now < mktime(&camp->getTo()))
					{
						totalVisibility += camp->getCost();
						activeCampaignsList.push_back(camp);
					}
				}
			}
		}
		//do {
		float randomSelection = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / totalVisibility));
		for (int i = 0; i < activeCampaignsList.size(); i++) {
			if (min <= randomSelection && randomSelection < min + activeCampaignsList[i]->getCost())
				nextCampaign = activeCampaignsList[i];
			else
				min += activeCampaignsList[i]->getCost();
		}
		//} while (nextCampaign->getId() == currentCampaign->getId());
		int adIndex = rand() % nextCampaign->getAds().size();
		AD* nextAd = nextCampaign->getAds()[adIndex];
		return nextAd;
	}
}

