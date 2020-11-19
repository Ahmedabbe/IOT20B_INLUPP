#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include "CustomerService.h"

using namespace std;

void addCampaign();
bool hasCampaign(string name);
void addCampaignToDB(string name, float cost);