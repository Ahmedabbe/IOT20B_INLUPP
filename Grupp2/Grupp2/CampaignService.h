#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include "CustomerService.h"
#include "Campaign.h"

using namespace std;

void addCampaign(vector<Customer> &kundlist);
bool hasCampaign(string name, string kundname, vector<Customer> &kundlist);
void addCampaignToDB(string name, float cost, tm fromdate, tm todate, string kundname, vector<Customer> &kundlist);
bool checkDate(string* campaigndate, tm* from);
bool validDate(int yearnum, int monnum, int daynum);
bool isLeapYear(int year);
Campaign getCampaignFromDB(string name, string kundname, vector<Customer> &kundlist);
void readCampaign(vector<Customer> &kundlist);
void updateCampaign(vector<Customer> &kundlist); 
void updateCampaignToDB(string oldname, string newname, string kundnamen, vector<Customer> &kundlist);
void deleteCampaign(vector<Customer> &kundlist);
void deleteCampaignFromDB(string name, string kundname, vector<Customer> &kundlist);
void showCampaigns(vector<Customer> &kundlist);
void showCampaign(Campaign camp, string kundname);
void deleteCamp(string name, vector<Campaign>& templist);