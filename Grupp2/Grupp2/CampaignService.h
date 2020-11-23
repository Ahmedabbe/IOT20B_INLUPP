#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include "CustomerService.h"
#include "Campaign.h"

using namespace std;

void addCampaign(vector<Customer*> &kundlist);
bool hasCampaign(string name, Customer* kund);
void addCampaignToDB(string name, float cost, tm fromdate, tm todate, Customer* kund);
bool checkDate(string* campaigndate, tm* from);
bool validDate(int yearnum, int monnum, int daynum);
bool isLeapYear(int year);
Campaign* getCampaignFromDB(string name, Customer* kund);
void readCampaign(vector<Customer*> &kundlist);
void updateCampaign(vector<Customer*> &kundlist); 
void updateCampaignToDB(string newname, Campaign* camp);
void deleteCampaign(vector<Customer*> &kundlist);
void deleteCampaignFromDB(Campaign* camp, Customer* kund);
void showCampaigns(vector<Customer*> &kundlist);
void showCampaign(Campaign* camp, string kundname);
