#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include <vector>
#include "AD.h"
#include "Customer.h"
#include "CustomerService.h"
#include "CampaignService.h"

using namespace std;

//enum AdType { scroll, blink, plainText };

void addADToDB(string name, string text, AdType type, Campaign* camp)
{
	AD* ad = new AD(name, text, type);
	vector<AD*> templist = camp->getAds();
	templist.push_back(ad);
	camp->setAds(templist);
	cout << "Success !" << endl;
}


AD* getADFromDB(string name, Campaign* camp) {
	for (auto ad : camp->getAds()) {
		if (ad->getName() == name) return ad;
	}
}

void updateADToDB(string newname, AD* ad) {
	ad->setName(newname);
	cout << "Success !" << endl;
}

void deleteADFromDB(AD* ad, Campaign* camp) {
	int index = -1;
	vector<AD*> templist = camp->getAds();
	for (auto tempad : templist) {
		index++;
		if (tempad->getName() == ad->getName()) {
			templist.erase(templist.begin() + index);
			cout << "Delete success ! " << endl;
			break;
		}
	}
	camp->setAds(templist);
}

bool hasAD(string name, Campaign* camp)
{
	for (auto ad : camp->getAds()) {
		if (ad->getName() == name) return true;
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

void addAD(vector<Customer*> &kundlist)
{
	string indata = "";
	string text = "";
	string typestr = "";
	string campname = "";
	string kundname = "";
	AdType type;
	cin.ignore();
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		getline(cin, kundname);
		if (hasCustomer(kundname, kundlist) || kundname == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (kundname == "#") return;
	Customer* foundKund = getCustomerFromDB(kundname, kundlist);
	while (true) {		
		cout << "Campaign name (# -> go back) -> ";
		getline(cin, campname);
		if (hasCampaign(campname, foundKund) || campname == "#") break;
		cout << "Campaign not found !" << endl;
	}
	if (campname == "#") return;
	Campaign* foundCamp = getCampaignFromDB(campname, foundKund);
	while (true) {
		cout << "AD name (# -> go back) -> ";
		getline(cin, indata);
		if (!hasAD(indata, foundCamp) || indata == "#") break;
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
	addADToDB(indata, text, type, foundCamp);
}
void showAD(string campname, string kundname, AD ad) {
	cout << "****************************" << endl;
	cout << "Customer: " << kundname << endl;
	cout << "Campaign: " << campname << endl;
	cout << "AD name: " << ad.getName() << endl;
	cout << "AD content: " << ad.getAdContent() << endl;
}
void showAD(string campname, string kundname, AD* ad) {
	cout << "****************************" << endl;
	cout << "Customer: " << kundname << endl;
	cout << "Campaign: " << campname << endl;
	cout << "AD name: " << ad->getName() << endl;
	cout << "AD content: " << ad->getAdContent() << endl;
}
void readAD(vector<Customer*> &kundlist)
{
	string indata = "";
	string campname = "";
	string adname = "";
	cin.ignore();
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		getline(cin, indata);
		if (hasCustomer(indata, kundlist) || indata == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (indata == "#") return;
	Customer* foundKund = getCustomerFromDB(indata, kundlist);
	while (true) {
		cout << "Campaign name (# -> go back) -> ";
		getline(cin, campname);
		if (hasCampaign(campname, foundKund) || campname == "#") break;
		cout << "Campaign not found !" << endl;
	}
	if (campname == "#") return;
	Campaign* foundCamp = getCampaignFromDB(campname, foundKund);
	while (true) {
		cout << "Ad name (# -> go back) -> ";
		getline(cin, adname);
		if (hasAD(adname, foundCamp) || adname == "#") break;
		cout << "Ad not found !" << endl;
	}
	if (adname == "#") return;
	AD* found = getADFromDB(adname, foundCamp);
	showAD(campname, indata, found);
}

void updateAD(vector<Customer*> &kundlist)
{
	string oldname = "";
	string newname = "";
	string indata = "";
	string campname = "";
	cin.ignore();
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		getline(cin, indata);
		if (hasCustomer(indata, kundlist) || indata == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (indata == "#") return;
	Customer* foundKund = getCustomerFromDB(indata, kundlist);
	while (true) {
		cout << "Campaign name (# -> go back) -> ";
		getline(cin, campname);
		if (hasCampaign(campname, foundKund) || campname == "#") break;
		cout << "Campaign not found !" << endl;
	}
	if (campname == "#") return;
	Campaign* foundCamp = getCampaignFromDB(campname, foundKund);
	while (true) {
		cout << "AD old name (# -> go back) -> ";
		getline(cin, oldname);
		if (hasAD(oldname, foundCamp) || oldname == "#") break;
		cout << "AD not found !" << endl;
	}
	if (oldname == "#") return;
	AD* found = getADFromDB(oldname, foundCamp);
	while (true) {
		cout << "AD new name (# -> go back) -> ";
		getline(cin, newname);
		if (!hasAD(newname, foundCamp) || oldname == "#") break;
		cout << "AD new name is already found !" << endl;
	}
	if (newname == "#") return;
	updateADToDB(newname, found);
}
void deleteAD(vector<Customer*> &kundlist)
{
	string indata = "";
	string campname = "";
	string adname = "";
	cin.ignore();
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		getline(cin, indata);
		if (hasCustomer(indata, kundlist) || indata == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (indata == "#") return;
	Customer* foundKund = getCustomerFromDB(indata, kundlist);
	while (true) {
		cout << "Campaign name (# -> go back) -> ";
		getline(cin, campname);
		if (hasCampaign(campname, foundKund) || campname == "#") break;
		cout << "Campaign not found !" << endl;
	}
	if (campname == "#") return;
	Campaign* foundCamp = getCampaignFromDB(campname, foundKund);
	while (true) {
		cout << "Ad name (# -> go back) -> ";
		getline(cin, adname);
		if (hasAD(adname, foundCamp) || adname == "#") break;
		cout << "Ad not found !" << endl;
	}
	if (adname == "#") return;
	AD* found = getADFromDB(adname, foundCamp);
	deleteADFromDB(found, foundCamp);
}

void showADs(vector<Customer*> &kundlist) {
	for (auto kund : kundlist) {
		for (auto camp : kund->getCampaigns()) {
			for (auto ad : camp->getAds()) {
				showAD(camp->getName(), kund->getName(), ad);
			}			
		}
	}
}