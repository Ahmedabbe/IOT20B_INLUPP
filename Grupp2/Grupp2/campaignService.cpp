#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include <ctime>
#include "CustomerService.h"

using namespace std;

bool hasCampaign(string name)
{
	bool found = false;
	return found;
}

void addCampaignToDB(string name, float cost, tm fromdate, tm todate)
{
	cout << " namn " << name << " cons " << cost << " fr " << fromdate.tm_mon+1 << " to " << todate.tm_mon+1 << endl;
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

bool validDate(int yearnum, int monnum, int daynum) //test
{
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
	string tempstr = *campaigndate;  //2020-10-09
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
	return true;
}

void addCampaign()
{
	string name = "";
	string coststr = "";
	string fromdate = "";
	string todate = "";
	struct tm from;
	struct tm to;
	float cost = 0;
	while (true) {
		cout << "Campaign name (# -> go back) -> ";
		cin >> name;
		if (!hasCampaign(name) || name == "#") break;
		cout << "Customer is already found !" << endl;
	}
	if (name == "#") return;
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
		if ((checkDate(&todate, &to) && (fromdate <= todate)) || todate == "#") break;
		cout << "fel datumn !" << endl;
	}
	if (todate == "#") return;
	addCampaignToDB(name, cost, from, to);
}
