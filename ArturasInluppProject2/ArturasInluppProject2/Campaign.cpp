#include<iostream>
#include <vector>
#include <string>
#include <cstring>
#include "Campaign.h"
//#include "Ads.h"
#include "State.h"
#include <algorithm>
using namespace std;


class Campaign {
private:
	string name;
	int id;
	//time_t fromDateTime;
	//time_t toDateTime;
	float campaignCost;
	//vector<Ads>adsList;
public:
	Campaign()
	{
		string name = "";
		int id = 0;
		float campaignCost = 0;

	}
	
	Campaign(string Name, int Id, float CampaignCost)
	{
		this->name = Name;
		this->id = Id;
		this->campaignCost = CampaignCost;
	}

	string getName()
	{
		return name;
	}

	int getId()
	{
		return id;
	}
	
	void setName(string newName)
	{
		name = newName;
	}

	void CreateCampaign(SYSTEM_STATE* state) {

		string newName;
		int newId;
		float newCampaignCost;

		cout << "Campaign name: ";
		cin >> newName;

		cout << "Campaign ID: ";
		cin >> newId;

		cout << "Campaign belop: ";
		cin >> newCampaignCost;

		Campaign newCampaign(newName, newId, newCampaignCost);

		state->campaignList.push_back(newCampaign);
		cout << endl;
	}

	void PrintCampaings(SYSTEM_STATE* state) {

		for (Campaign& cam : state->campaignList) {

			PrintCampaign(&cam);

		}

	}

	
	void PrintCampaign(Campaign* cam)
	{
		cout << "Name: " << cam->getName() << endl;
		cout << "ID: " << cam->getId() << endl;
		cout << endl;
	}
	/*void removeCampaign(string ad)
	{
		campaignList.erase(std::remove(campaignList.begin(), campaignList.end(), ad), campaignList.end());
	}*/

	void SetCampaignCost(float newBelopp)
	{
		this->campaignCost = newBelopp;
	}


};

int main()
{
	/*Campaign campaign = Campaign("hej", 232, 343.5);
	cout << campaign.getId();*/

	SYSTEM_STATE state;
	Campaign cam;

	cam.CreateCampaign(&state);

	cam.PrintCampaings(&state);

	return 0;
	
}