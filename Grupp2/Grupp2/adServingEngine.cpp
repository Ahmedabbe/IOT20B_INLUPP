#include "AdServingEngine.h"

AdEngine::AdEngine() {};
void AdEngine::setKundlist(vector<Customer> kundlist) {
	this->kundlist = kundlist;
}
vector<Customer> AdEngine::getKundlist() {
	return this->kundlist;
}
AD AdEngine::getNextAd() {
	AD ad = AD();
	return ad;
}

AdEngine::~AdEngine() {};