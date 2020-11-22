#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include <ctime>
#include "CustomerService.h"

using namespace std;

void addCampaignToDB(string name, float cost, tm fromdate, tm todate, string kundname, vector<Customer> &kundlist)
{
	
			cout << "Add new campaign success !" << endl;
	
}

Campaign getCampaignFromDB(string name, string kundname, vector<Customer> &kundlist) {
	Campaign camp = Campaign();
	return camp;
}

void deleteCamp(string name, vector<Campaign>& templist) {
	
			cout << "Delete camp " << endl;
	
}

void deleteCampaignFromDB(string name, string kundname, vector<Customer> &kundlist) {
	
			cout << "Success !" << endl;			
	
}

bool hasCampaign(string name, string kundname, vector<Customer> &kundlist)
{
	
	return false;
}

bool isLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0) {
		return true;
	}
	else if (year % 100 == 0 && year % 400 == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool validDate(int yearnum, int monnum, int daynum) 
{
	if (yearnum < 2020) return false;
	if (monnum < 1 || monnum>12) return false;
	if (isLeapYear(yearnum) && monnum == 2) {
		if (daynum >= 1 && daynum <= 29) return true;
	}
	else if (!isLeapYear(yearnum) && monnum == 2) {
		if (daynum >= 1 && daynum <= 28) return true;
	}
	else if (monnum == 1 || monnum == 3 || monnum == 5 ||
		monnum == 7 || monnum == 8 || monnum == 10 || monnum == 12) {
		if (daynum >= 1 && daynum <= 31) return true;
	}
	else {
		if (daynum >= 1 && daynum <= 30) return true;
	}
	return false;
}

bool checkDate(string* campaigndate, tm* fromto)
{
	string tempstr = *campaigndate;  
	if (tempstr.length() < 10) return false;
	string year = tempstr.substr(0, 4);
	string mon = tempstr.substr(5, 2);
	string day = tempstr.substr(8, 2);
	int yearnum=0, monnum=0, daynum=0;
	try {
		yearnum = stoi(year);
		monnum = stoi(mon);
		daynum = stoi(day);
	}
	catch (exception e) {
		return false;
	}
	if(!validDate(yearnum, monnum, daynum)) return false;
	fromto->tm_year = yearnum - 1900;
	fromto->tm_mon = monnum - 1;
	fromto->tm_mday = daynum;
	fromto->tm_hour = 0;
	fromto->tm_min = 0;
	fromto->tm_sec = 0;
	return true;
}

void addCampaign(vector<Customer> &kundlist)
{
	string kundname = "";
	string name = "";
	string coststr = "";
	string fromdate = "";
	string todate = "";
	time_t today = time(NULL);
	

	struct tm from = * localtime(&today);
	struct tm to = *localtime(&today);
	float cost = 0;
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		cin >> kundname;
		if (hasCustomer(kundname, kundlist) || kundname == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (kundname == "#") return;
	Customer foundKund = getCustomerFromDB(kundname, kundlist);
	while (true) {
		cout << "Campaign name (# -> go back) -> ";
		cin >> name;
		if (!hasCampaign(name, kundname, kundlist) || name == "#") break;
		cout << "Campaign is already found !" << endl;
	}
	if (name == "#") return;
	while (true) {
		cout << "Campaign cost (# -> go back) -> ";
		cin >> coststr;
		stringstream s(coststr);
		if (!(s >> cost) || !s.eof()) {
			if (coststr == "#") break;
			cout << "fel nummer för cost !" << endl;
		}
		else {
			s >> cost;
			break;
		}
	}
	if (coststr == "#") return;
	while (true) {
		cout << "From date YYYY-MM-DD (# -> go back) -> ";
		cin >> fromdate;
		if (checkDate(&fromdate, &from) || fromdate == "#") break;
		cout << "fel datumn !" << endl;
	}
	if (fromdate == "#") return;
	while (true) {
		cout << "To date YYYY-MM-DD (# -> go back) -> ";
		cin >> todate;
		if ((checkDate(&todate, &to) && difftime(mktime(&to), mktime(&from)) >= 0) 
			|| todate == "#") break;
		cout << "fel datumn !" << endl;
	}
	if (todate == "#") return;
	to.tm_hour = 23;
	to.tm_min=59;
	addCampaignToDB(name, cost, from, to, kundname, kundlist);
}

void showCampaign(Campaign camp, string kundname) {
	cout << "show Camp" << endl;
}

void readCampaign(vector<Customer> &kundlist) {
	string indata = "";
	string kundname = "";
	cin.ignore();
	while (true) {
		cout << "Campaign name (# -> go back) -> ";
		getline(cin, indata);
		if(indata == "#") break;
		cout << "Customer name (# -> go back) -> ";
		getline(cin, kundname);
		if (hasCampaign(indata, kundname, kundlist) || kundname == "#") break;
		cout << "Not found !" << endl;
	}
	if (indata == "#" || kundname == "#") return;
	Campaign found = getCampaignFromDB(indata, kundname, kundlist);
	showCampaign(found, kundname);
}

void updateCampaignToDB(string oldname, string newname, string kundnamen, vector<Customer> &kundlist) {
	
			cout << "Success !" << endl;
	
}

void updateCampaign(vector<Customer> &kundlist) {
	string kundname = "";
	string oldname = "";
	string newname = "";
	cin.ignore();
	while (true) {
		cout << "Customer name (# -> go back) -> ";
		getline(cin, kundname);
		if (hasCustomer(kundname, kundlist) || kundname == "#") break;
		cout << "Customer not found !" << endl;
	}
	if (kundname == "#") return;
	while (true) {
		cout << "Campaign old name (# -> go back) -> ";
		getline(cin, oldname);
		if (hasCampaign(oldname, kundname, kundlist) || oldname == "#") break;
		cout << "Campaign not found !" << endl;
	}
	if (oldname == "#") return;
	while (true) {
		cout << "Campaign new name (# -> go back) -> ";
		getline(cin, newname);
		if (!hasCampaign(newname, kundname, kundlist) || newname == "#") break;
		cout << "Campaign is already found !" << endl;
	}
	if (newname == "#") return;
	updateCampaignToDB(oldname, newname, kundname, kundlist);
}

void deleteCampaign(vector<Customer> &kundlist) {
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
	deleteCampaignFromDB(campname, indata, kundlist);
}

void showCampaigns(vector<Customer> &kundlist) {
	cout << "show camp list" << endl;
}