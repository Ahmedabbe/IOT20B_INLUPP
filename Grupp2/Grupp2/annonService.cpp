#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include <vector>
#include "AD.h"
#include "Campaign.h"

using namespace std;

void addADToDB(string name, string text, AdType type, string campname, vector<Campaign>* camplist)
{
	AD ad(name, text,  type);
	for (auto camp = camplist->begin(); camp != camplist->end(); ++camp) {
		if (camp->getName() == campname) {
			vector<AD> templist = camp->getAds();
			templist.push_back(ad);
			camp->setAds(templist);
			cout << "Add success " << camp->getAds().size() << endl;
			break;
		}
	}
}

AD getADFromDB(string name, vector<AD>* ADlist) {
	/*for (auto kund : *kundlist) {
		if (kund.getName() == name) return kund;
	}*/
	string named="te", text="tt";
	AdType type = AdType::blink;
	AD ad(named, text, type);
	return ad;
}

void updateADToDB(string oldname, string newname, vector<AD>* ADlist) {
	/*for (auto kund = kundlist->begin(); kund != kundlist->end(); ++kund) {
		if (kund->getName() == oldname) {
			kund->setName(newname);
			cout << "Update success for Customer: " << kund->getName() << endl;
			break;
		}
	}*/
}

void deleteADFromDB(string name, vector<AD>* ADlist) {
	/*for (auto kund = kundlist->begin(); kund != kundlist->end(); ++kund) {
		if (kund->getName() == name) {
			kundlist->erase(kund);
			cout << "Delete success ! " << endl;
			break;
		}
	}*/
}

bool hasAD(string name, string campaignName, vector<Campaign> campaignlist)
{
	for (auto camp : campaignlist) {
		for (auto ad : camp.getAds()) {
			if (ad.getName() == name) return true;
		}
	}
	return false;
}

bool hasCamp(string campname, vector<Campaign> campaignlist) {
	for (auto camp : campaignlist) {
		if (camp.getName() == campname) return true;
	}
	return false;
}

bool isType(string typestr, AdType* type) {
	if (typestr == "scroll") *type = AdType::scroll;
	else if (typestr == "blink") *type = AdType::blink;
	else if (typestr == "plainText") *type = AdType::plainText;
	else return false;
	return true;
}

void addAD(vector<Campaign>* camplist)
{
	string indata = "";
	string text = "";
	string typestr = "";
	string campname = "";
	AdType type;
	cin.ignore();
	while (true) {		
		cout << "Campaign name (# -> go back) -> ";
		getline(cin, campname);
		if (hasCamp(campname, *camplist) || campname == "#") break;
		cout << "Campaign not found !" << endl;
	}
	if (campname == "#") return;
	while (true) {
		cout << "AD name (# -> go back) -> ";
		getline(cin, indata);
		if (!hasAD(indata, campname, *camplist) || indata == "#") break;
		cout << "AD name is already found !" << endl;
	}
	if (indata == "#") return;
	while (true) {
		cout << "AD text (# -> go back) -> ";
		getline(cin, text);
		if (text.length()>0 || text == "#") break;
		cout << "Write something !" << endl;
	}
	if (text == "#") return;
	while (true) {
		cout << "AD type: scroll, blink or plainText. (# -> go back) -> ";
		getline(cin, typestr);
		if (isType(typestr, &type) || typestr == "#") break;
		cout << "Wrong type !" << endl;
	}
	if (typestr == "#") return;
	addADToDB(indata, text, type, campname, camplist);
}

void readAD(vector<AD>* ADlist)
{
	/*string indata = "";
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		cin >> indata;
		if (hasCustomer(indata, kundlist) || indata == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (indata == "#") return;
	Customer found = getCustomerFromDB(indata, kundlist);
	cout << "Found Customer name: " << found.getName() << endl;*/
}

void updateAD(vector<AD>* ADlist)
{
	/*string oldname = "";
	string newname = "";
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		cin >> oldname;
		if (hasCustomer(oldname, kundlist) || oldname == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (oldname == "#") return;
	while (true) {
		cout << "Customer new name (# -> go back) -> ";
		cin >> newname;
		if (!hasCustomer(newname, kundlist) || newname == "#") break;
		cout << "Customer is already found !" << endl;
	}
	if (newname == "#") return;
	updateCustomerToDB(oldname, newname, kundlist);*/
}
void deleteAD(vector<AD>* ADlist)
{
	/*string indata = "";
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		cin >> indata;
		if (hasCustomer(indata, kundlist) || indata == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (indata == "#") return;
	deleteCustomerFromDB(indata, kundlist);*/
}
