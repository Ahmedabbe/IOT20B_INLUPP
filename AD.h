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
	AD(std::string adName, int adID, std::string adText, AdType adType);
	void setAdText(std::string adText);
	void setAdType(AdType adType);
	std::string getAdContent();
	~AD();
};
#endif
