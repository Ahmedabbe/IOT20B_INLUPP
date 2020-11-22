#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include "CustomerService.h"

using namespace std;

void addCampaign();
bool hasCampaign(string name);
void addCampaignToDB(string name, float cost, tm fromdate, tm todate);
bool checkDate(string* campaigndate, tm* from);
bool validDate(int yearnum, int monnum, int daynum);
bool isLeapYear(int year);