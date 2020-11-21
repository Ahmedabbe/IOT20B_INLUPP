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

void gotoCamp(string adname, string text, AdType type, string campname, vector<Campaign>& templist) {
	AD ad(adname, text, type);
	for (auto camp = templist.begin(); camp != templist.end(); ++camp) {
		if (camp->getName() == campname) {
			vector<AD> adstemplist = camp->getAds();
			adstemplist.push_back(ad);
			camp->setAds(adstemplist);
			cout << "Add ads " << endl;
			break;
		}
	}
}

void addADToDB(string name, string text, AdType type, string campname, string kundname, vector<Customer> &kundlist)
{
	for (auto kund = kundlist.begin(); kund != kundlist.end(); ++kund) {
		if (kund->getName() == kundname) {
			vector<Campaign> templist = kund->getCampaigns();
			gotoCamp(name, text, type, campname, templist);
			kund->setCampaigns(templist);
			cout << "Success !" << endl;
			break;
		}
	}
}

AD getADFromDB(string name, string campname, string kundname, vector<Customer> &kundlist) {
	for (auto kund : kundlist) {
		if (kund.getName() == kundname) {
			for (auto camp : kund.getCampaigns()) {
				if (camp.getName() == campname) {
					for (auto ad : camp.getAds()) {
						if (ad.getName() == name) return ad;
					}
				}
			}
		}
	}
}

void gotoAD(string oldname, string newname, vector<AD>& templist) {
	for (auto ad = templist.begin(); ad != templist.end(); ++ad) {
		if (ad->getName() == oldname) {
			ad->setName(newname);
			cout << "update ads " << endl;
			break;
		}
	}
}
void updateCamp(string oldname, string newname, string campname, vector<Campaign>& templist) {
	for (auto camp = templist.begin(); camp != templist.end(); ++camp) {
		if (camp->getName() == campname) {
			vector<AD> adstemplist = camp->getAds();
			gotoAD(oldname, newname, adstemplist);
			camp->setAds(adstemplist);
			break;
		}
	}
}

void updateADToDB(string oldname, string newname, string campname, string kundname, vector<Customer> &kundlist) {
	for (auto kund = kundlist.begin(); kund != kundlist.end(); ++kund) {
		if (kund->getName() == kundname) {
			vector<Campaign> templist = kund->getCampaigns();
			updateCamp(oldname, newname, campname, templist);
			kund->setCampaigns(templist);
			cout << "Success !" << endl;
			break;
		}
	}
}

void beginToDelete(string name, vector<AD>& templist) {
	for (auto ad = templist.begin(); ad != templist.end(); ++ad) {
		if (ad->getName() == name) {
			templist.erase(ad);
			cout << "Deleted" << endl;
			break;
		}
	}
}
void deleteFromCamp(string name, string campname, vector<Campaign>& templist) {
	for (auto camp = templist.begin(); camp != templist.end(); ++camp) {
		if (camp->getName() == campname) {
			vector<AD> adlist = camp->getAds();
			beginToDelete(name, adlist);
			camp->setAds(adlist);
			break;
		}
	}
}
void deleteADFromDB(string name, string campname, string kundname, vector<Customer>& kundlist) {
	for (auto kund = kundlist.begin(); kund != kundlist.end(); ++kund) {
		if (kund->getName() == kundname) {
			vector<Campaign> templist = kund->getCampaigns();
			deleteFromCamp(name, campname, templist);
			kund->setCampaigns(templist);
			cout << "Success !" << kund->getName() << endl;
			break;
		}
	}
}

bool hasAD(string name, string campaignName, string kundname, vector<Customer> &kundlist)
{
	for (auto kund : kundlist) {
		if (kund.getName() == kundname) {
			for (auto camp : kund.getCampaigns()) {
				if (camp.getName() == campaignName) {
					for (auto ad : camp.getAds()) {
						if (ad.getName() == name) return true;
					}
				}
			}
		}		
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
		//cin >> campname;
		if (hasCustomer(kundname, kundlist) || kundname == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (kundname == "#") return;
	while (true) {		
		cout << "Campaign name (# -> go back) -> ";
		getline(cin, campname);
		//cin >> campname;
		if (hasCampaign(campname, kundname, kundlist) || campname == "#") break;
		cout << "Campaign not found !" << endl;
	}
	if (campname == "#") return;
	while (true) {
		cout << "AD name (# -> go back) -> ";
		getline(cin, indata);
		//cin >> indata;
		if (!hasAD(indata, campname, kundname, kundlist) || indata == "#") break;
		cout << "AD name is already found !" << endl;
	}
	if (indata == "#") return;
	while (true) {
		cout << "AD text (# -> go back) -> ";
		getline(cin, text);
		//cin >> text;
		if (text.length()>0 || text == "#") break;
		cout << "Write something !" << endl;
	}
	if (text == "#") return;
	while (true) {
		cout << "AD type: scroll, blink or plainText. (# -> go back) -> ";
		getline(cin, typestr);
		//cin >> typestr;
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
		//cin >> indata;
		if (hasCustomer(indata, kundlist) || indata == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (indata == "#") return;
	while (true) {
		cout << "Campaign name (# -> go back) -> ";
		getline(cin, campname);
		//cin >> campname;
		if (hasCampaign(campname, indata, kundlist) || campname == "#") break;
		cout << "Campaign not found !" << endl;
	}
	if (campname == "#") return;
	while (true) {
		cout << "Ad name (# -> go back) -> ";
		getline(cin, adname);
		//cin >> adname;
		if (hasAD(adname, campname, indata, kundlist) || adname == "#") break;
		cout << "Ad not found !" << endl;
	}
	if (adname == "#") return;
	AD found = getADFromDB(adname, campname, indata, kundlist);
	showAD(campname, indata, found);
	//cout << "Found AD name: " << found.getName() << endl;
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
		//cin >> indata;
		if (hasCustomer(indata, kundlist) || indata == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (indata == "#") return;
	while (true) {
		cout << "Campaign name (# -> go back) -> ";
		getline(cin, campname);
		//cin >> campname;
		if (hasCampaign(campname, indata, kundlist) || campname == "#") break;
		cout << "Campaign not found !" << endl;
	}
	if (campname == "#") return;
	while (true) {
		cout << "AD old name (# -> go back) -> ";
		getline(cin, oldname);
		//cin >> oldname;
		if (hasAD(oldname, campname, indata, kundlist) || oldname == "#") break;
		cout << "AD not found !" << endl;
	}
	if (oldname == "#") return;
	while (true) {
		cout << "AD new name (# -> go back) -> ";
		getline(cin, newname);
		//cin >> newname;
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
		//cin >> indata;
		if (hasCustomer(indata, kundlist) || indata == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (indata == "#") return;
	while (true) {
		cout << "Campaign name (# -> go back) -> ";
		getline(cin, campname);
		//cin >> campname;
		if (hasCampaign(campname, indata, kundlist) || campname == "#") break;
		cout << "Campaign not found !" << endl;
	}
	if (campname == "#") return;
	while (true) {
		cout << "Ad name (# -> go back) -> ";
		getline(cin, adname);
		//cin >> adname;
		if (hasAD(adname, campname, indata, kundlist) || adname == "#") break;
		cout << "Ad not found !" << endl;
	}
	if (adname == "#") return;
	deleteADFromDB(adname, campname, indata, kundlist);
}

void showADs(vector<Customer> &kundlist) {
	for (auto kund : kundlist) {
		for (auto camp : kund.getCampaigns()) {
			for (auto ad : camp.getAds()) {
				showAD(camp.getName(), kund.getName(), ad);
			}			
		}
	}
}