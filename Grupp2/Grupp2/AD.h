#ifndef _AD_H
#define _AD_H
#include<iostream>
using namespace std;

enum AdType { scroll, blink, plainText };

class AD {
	static int staticID;
	std::string adName;
	int adID;
	int kundID;
	int campID;
	std::string adText;
	AdType adType;
public:
	AD();
	AD(std::string adName, int adID, std::string adText, AdType adType);
	AD(std::string adName, std::string adText, AdType adType, int kundID, int campID);
	void setAdText(std::string adText);	
	void setAdType(AdType adType);
	void setName(std::string name);
	int getID();
	int getKundID();
	int getCampID();
	std::string getName();
	std::string getAdText();
	std::string getAdContent();
	AdType getAdType();
	~AD();
};
#endif
