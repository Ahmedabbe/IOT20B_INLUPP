#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include "CustomerService.h"

using namespace std;

bool hasCampaign(string name)
{
	bool found = false;
	return found;
}

void addCampaignToDB(string name, float cost)  //  add name id?? datetime ?? to campaign
{
	cout << "db 2 " << name << " 3 " << cost << endl;
}

void addCampaign()
{
	string name = "";
	string coststr = "";
	float cost = 0;
	while (true) {
		cout << "Campaign name (# -> go back) -> ";
		cin >> name;
		if (!hasCampaign(name) || name == "#") break;
		cout << "Customer is already found !" << endl;
	}
	while (true) {
		cout << "Campaign cost (# -> go back) -> ";
		cin >> coststr;
		stringstream s(coststr);
		if (!(s >> cost) || !s.eof() || coststr == "#") {
			cout << "fel nummer för cost !" << endl;
		}
		else {
			s >> cost;
			break;
		}
	}
	if (name == "#" || coststr == "#") return;
	addCampaignToDB(name, cost);
}
