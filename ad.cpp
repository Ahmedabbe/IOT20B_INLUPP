//#include<iostream>
#include "AD.h"

AD::AD(std::string adName, int adID, std::string adText, AdType adType) {
	this->adName = adName;
	this->adID = adID;
	this->adText = adText;
	this->adType = adType;
}

void AD::setAdText(std::string adText) {
	this->adText = adText;
}

void AD::setAdType(AdType adType) {
	this->adType = adType;
}

std::string AD::getAdContent() {
	switch (this->adType) {
	case 0: return "Scroll: " + this->adText;
	case 1:	return "Blink: " + this->adText;
	case 2: return "Plain Text: " + this->adText;
	}
}

AD::~AD() {
	std::cout << "Deleting instance";
}


