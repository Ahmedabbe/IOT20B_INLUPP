#include<ctime>
#include "AdServingEngine.h"

AdEngine::AdEngine() {};
void AdEngine::setKundlist(vector<Customer*> kundlist) {
	this->kundlist = kundlist;
}
vector<Customer*> AdEngine::getKundlist() {
	return this->kundlist;
}
AD* AdEngine::getNextAd() {
	if (!kundlist.empty()) {
		vector<Campaign*>activeCampaignsList;
		float totalVisibility = 0, min = 0;
		Campaign* nextCampaign, * currentCampaign;
		nextCampaign = NULL;
		for (int i = 0; i < kundlist.size(); i++) {
			if (kundlist[i]->hasActiveCampaign()) {
				for (auto camp : kundlist[i]->getCampaigns()) {
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

//AD AdEngine::getNextAd() {
//	AD ad = AD();
//	return ad;
//}

AdEngine::~AdEngine() {};