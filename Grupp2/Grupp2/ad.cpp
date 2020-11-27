#include "AD.h"
int AD::staticID = 0;
AD::AD(){}

AD::AD(std::string adName, int adID, std::string adText, AdType adType) {
	this->adName = adName;
	this->adID = adID;
	this->adText = adText;
	this->adType = adType;
}

AD::AD(std::string adName, std::string adText, AdType adType, int kundID, int campID) {
	AD::staticID++;
	this->adID = AD::staticID;
	this->kundID = kundID;
	this->campID = campID;
	this->adName = adName;
	this->adText = adText;
	this->adType = adType;
}

void AD::setAdText(std::string adText) {
	this->adText = adText;
}

void AD::setAdType(AdType adType) {
	this->adType = adType;
}
void AD::setName(std::string name) {
	this->adName = name;
}
int AD::getID() {
	return this->adID;
}
int AD::getKundID() {
	return this->kundID;
}
int AD::getCampID() {
	return this->campID;
}
std::string AD::getName() {
	return this->adName;
}
std::string AD::getAdText() {
	return this->adText;
}
AdType AD::getAdType() {
	return this->adType;
}

std::string AD::getAdContent() {
	switch (this->adType) {
	case 0: return "Scroll: " + this->adText;
	case 1:	return "Blink: " + this->adText;
	case 2: return "Plain Text: " + this->adText;
	}
}

AD::~AD() {
	//std::cout << "Deleting instance";
}

