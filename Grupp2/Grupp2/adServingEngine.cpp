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
		for (Customer* kund: kundlist) {
			if (kund->hasActiveCampaign()) {
				for (auto camp : kund->getCampaigns()) {
					time_t now = time(NULL);
					if (mktime(&camp->getFrom()) <= now && now < mktime(&camp->getTo()))
					{
						totalVisibility += camp->getCost();
						activeCampaignsList.push_back(camp);
					}
				}
			}
		}
		if (!activeCampaignsList.empty())
		{
			//do {
			float randomSelection = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / totalVisibility));
			for (Campaign* c : activeCampaignsList) {
				if (min <= randomSelection && randomSelection < min + c->getCost()) {
					nextCampaign = c;
					break;
				}
				else
					min += c->getCost();
			}
			//} while (nextCampaign->getId() == currentCampaign->getId());
			if (nextCampaign->getAds().size())
			{
				int adIndex = rand() % nextCampaign->getAds().size();
				AD* nextAd = nextCampaign->getAds()[adIndex];
				return nextAd;
			}			
		}		
	}
	return NULL;
}

//AD AdEngine::getNextAd() {
//	AD ad = AD();
//	return ad;
//}

AdEngine::~AdEngine() {};