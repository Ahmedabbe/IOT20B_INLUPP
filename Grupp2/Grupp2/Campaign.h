#ifndef CAMPAIGN_H
#define CAMPAIGN_H
#include <string>
#include <vector>
#include <iostream>
#include "AD.h"

using namespace std;


class Campaign {
	static int staticID;
	std::string name;
	int id;
	int kundID;
	struct tm fromDateTime;
	struct tm toDateTime;
	float campaignCost;
	vector<AD*> adsList;

public:
	Campaign();
	Campaign(std::string Name, int Id, float CampaignCost);
	Campaign(std::string name, struct tm from, struct tm to, float cost, int kundID);
	void setName(std::string name);
	void setCost(float cost);
	void setAds(vector<AD*> ads);
	struct tm getFrom();
	struct tm getTo();
	std::string getName();
	float getCost();
	int getId();
	int getKundID();
	vector<AD*> getAds();
	~Campaign();

};




#endif CAMPAIGN_H
