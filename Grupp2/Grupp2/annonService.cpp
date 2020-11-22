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


void addADToDB(string name, string text, AdType type, string campname, string kundname, vector<Customer> &kundlist)
{	
			cout << "Success !" << endl;
}

AD getADFromDB(string name, string campname, string kundname, vector<Customer> &kundlist) {
	AD ad = AD();
	return ad;
}

void updateADToDB(string oldname, string newname, string campname, string kundname, vector<Customer> &kundlist) {
			cout << "Success !" << endl;
}

void deleteADFromDB(string name, string campname, string kundname, vector<Customer>& kundlist) {
	
			cout << "Success !" << endl;
	
}

bool hasAD(string name, string campaignName, string kundname, vector<Customer> &kundlist)
{
	
	return false;
}

bool isType(string typestr, AdType* type) {
	if (typestr == "scroll") *type = AdType::scroll;
	else if (typestr == "blink") *type = AdType::blink;
	else if (typestr == "plainText") *type = AdType::plainText;
	else return false;
	return true;
}

void addAD(vector<Customer> &kundlist)
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
	while (true) {		
		cout << "Campaign name (# -> go back) -> ";
		getline(cin, campname);
		if (hasCampaign(campname, kundname, kundlist) || campname == "#") break;
		cout << "Campaign not found !" << endl;
	}
	if (campname == "#") return;
	while (true) {
		cout << "AD name (# -> go back) -> ";
		getline(cin, indata);
		if (!hasAD(indata, campname, kundname, kundlist) || indata == "#") break;
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
	addADToDB(indata, text, type, campname, kundname, kundlist);
}
void showAD(string campname, string kundname, AD ad) {
	cout << "****************************" << endl;
	cout << "Customer: " << kundname << endl;
	cout << "Campaign: " << campname << endl;
	cout << "AD name: " << ad.getName() << endl;
	cout << "AD content: " << ad.getAdContent() << endl;
}
void readAD(vector<Customer> &kundlist)
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
	while (true) {
		cout << "Campaign name (# -> go back) -> ";
		getline(cin, campname);
		if (hasCampaign(campname, indata, kundlist) || campname == "#") break;
		cout << "Campaign not found !" << endl;
	}
	if (campname == "#") return;
	while (true) {
		cout << "Ad name (# -> go back) -> ";
		getline(cin, adname);
		if (hasAD(adname, campname, indata, kundlist) || adname == "#") break;
		cout << "Ad not found !" << endl;
	}
	if (adname == "#") return;
	AD found = getADFromDB(adname, campname, indata, kundlist);
	showAD(campname, indata, found);
}

void updateAD(vector<Customer> &kundlist)
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
	while (true) {
		cout << "Campaign name (# -> go back) -> ";
		getline(cin, campname);
		if (hasCampaign(campname, indata, kundlist) || campname == "#") break;
		cout << "Campaign not found !" << endl;
	}
	if (campname == "#") return;
	while (true) {
		cout << "AD old name (# -> go back) -> ";
		getline(cin, oldname);
		if (hasAD(oldname, campname, indata, kundlist) || oldname == "#") break;
		cout << "AD not found !" << endl;
	}
	if (oldname == "#") return;
	while (true) {
		cout << "AD new name (# -> go back) -> ";
		getline(cin, newname);
		if (!hasAD(newname, campname, indata, kundlist) || oldname == "#") break;
		cout << "AD new name is already found !" << endl;
	}
	if (newname == "#") return;
	updateADToDB(oldname, newname, campname, indata, kundlist);
}
void deleteAD(vector<Customer> &kundlist)
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
	while (true) {
		cout << "Campaign name (# -> go back) -> ";
		getline(cin, campname);
		if (hasCampaign(campname, indata, kundlist) || campname == "#") break;
		cout << "Campaign not found !" << endl;
	}
	if (campname == "#") return;
	while (true) {
		cout << "Ad name (# -> go back) -> ";
		getline(cin, adname);
		if (hasAD(adname, campname, indata, kundlist) || adname == "#") break;
		cout << "Ad not found !" << endl;
	}
	if (adname == "#") return;
	deleteADFromDB(adname, campname, indata, kundlist);
}

void showADs(vector<Customer> &kundlist) {
	cout << "show ads " << endl;
}