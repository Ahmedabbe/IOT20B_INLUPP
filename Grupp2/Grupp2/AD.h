#ifndef _AD_H
#define _AD_H
#include<iostream>
using namespace std;

enum AdType { scroll, blink, plainText };

class AD {
	std::string adName;
	int adID;
	std::string adText;
	AdType adType;
public:
	AD();
	AD(std::string adName, int adID, std::string adText, AdType adType);
	AD(std::string adName, std::string adText, AdType adType);
	void setAdText(std::string adText);	
	void setAdType(AdType adType);
	void setName(std::string name);
	std::string getName();
	std::string getAdText();
	std::string getAdContent();
	AdType getAdType();
	~AD();
};
#endif
