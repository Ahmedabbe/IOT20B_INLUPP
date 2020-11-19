
//HEADER

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
	
	string newName;
	int newID;
	vector<Campaign> Campaigns;
	bool hasActiveCampaigns;

public:

	//Default Constructor
	Customer();

	//Overload Constructors *CREATE*
	Customer(string, int, bool);

	//Deconstructor *DELETE* ?
	~Customer();

	string getName() const;
		// getName
		// @return string - name of Customer

	int getID() const;
		// getID
		// @return int - ID of Customer

	bool getActiveCampaign() const;
		// getActiveCampaign
		// @return boolean - status of active campaign

	void setName(string);
		// setName
		// @param string - name of Customer

	void setID(int);
		// setID
		// @param int - ID of Customer

	void setActiveCampaign(bool);
		// setActiveCampaign
		// @param bool - status of active campaign



	// Customer CRUD functions
	void CreateCustomer(STATE* SYSTEM_STATE);
	void PrintCustomers(STATE* SYSTEM_STATE);
	void PrintCust(Customer* CUST);
	void RenameCustomer(STATE* SYSTEM_STATE, string currentName);
};

#endif