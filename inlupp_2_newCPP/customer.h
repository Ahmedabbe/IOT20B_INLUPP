
//HEADER

#ifndef CUSTOMER_H
#define CUSTOMER_H

class ServingEngine;

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

public:

	//Default Constructor
	Customer();

	//Overload Constructors *CREATE*
	Customer(string, int);

	//Deconstructor *DELETE* ?
	~Customer();

	string getName() const;
	// getName
	// @return string - name of Customer

	int getID() const;
	// getID
	// @return int - ID of Customer

	void setName(string);
	// setName
	// @param string - name of Customer

	void setID(int);
	// setID
	// @param int - ID of Customer



// Customer CRUD functions
	void CreateCustomer(ServingEngine* ENGINE, string name);
	void PrintCustomers(ServingEngine* ENGINE, string name);
	void PrintCust(ServingEngine* ENGINE, int index);
	void RenameCustomer(ServingEngine* ENGINE, string currentName, string newName);
	bool checkCustomer(ServingEngine* ENGINE, string name);
	void PrintAllCustomers(ServingEngine* ENGINE);

// Functions for Campaign
	int NumberOfCampaigns();
	Campaign& GetCampaignByIndex(int index);
	void AddCampaign(Campaign c);

};

#endif