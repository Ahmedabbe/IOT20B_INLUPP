#ifndef CUSTOMER_H
#define CUSTOMER_H

class STATE;

#include <iostream>
#include <string>
#include <vector>
#include "Campaign.h"

using namespace std;

class Customer {
private:
	static int staticID;
	string newName;
	int newID;
	vector<Campaign*> Campaigns;
	//bool hasActiveCampaigns;

public:

	//Default Constructor
	Customer();
	Customer(string newName);
	//Overload Constructors *CREATE*
	Customer(string newName, int newID);

	//Deconstructor *DELETE* ?
	~Customer();

	string getName() const;
	// getName
	// @return string - name of Customer

	int getID() const;
	// getID
	// @return int - ID of Customer

	vector<Campaign*> getCampaigns();
	// getActiveCampaign
	// @return boolean - status of active campaign

	void setCampaigns(vector<Campaign*> campaign);
	// setActiveCampaign
	// @param bool - status of active campaign

	void setName(string name);
	// setName
	// @param string - name of Customer

	void setID(int id);
	// setID
	// @param int - ID of Customer

	bool hasActiveCampaign();

	



// Customer CRUD functions
	/*void CreateCustomer(STATE* SYSTEM_STATE);
	void PrintCustomers(STATE* SYSTEM_STATE);
	void PrintCust(Customer* CUST);
	void RenameCustomer(STATE* SYSTEM_STATE, string currentName);*/
};

#endif
