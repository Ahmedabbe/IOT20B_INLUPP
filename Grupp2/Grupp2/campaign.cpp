#include "Campaign.h"

int Campaign::staticID = 0;
Campaign::Campaign(){}

Campaign::Campaign(std::string name, struct tm from, struct tm to, float cost, int kundID) {
	Campaign::staticID++;
	this->id = Campaign::staticID;
	this->kundID = kundID;
	this->name = name;
	this->fromDateTime = from;
	this->toDateTime = to;
	this->campaignCost = cost;
}

void Campaign::setName(std::string name) {
	this->name = name;
}
void Campaign::setCost(float cost) {
	this->campaignCost = cost;
}
void Campaign::setAds(vector<AD*> ads) {
	this->adsList = ads;
}
int Campaign::getId() {
	return this->id;
}
int Campaign::getKundID() {
	return this->kundID;
}
std::string Campaign::getName() {
	return this->name;
}
float Campaign::getCost() {
	return this->campaignCost;
}
struct tm Campaign::getFrom() {
	return this->fromDateTime;
}
struct tm Campaign::getTo() {
	return this->toDateTime;
}
vector<AD*> Campaign::getAds() {
	return this->adsList;
}
Campaign::~Campaign() {
	//std::cout << "Deleting instance";
}