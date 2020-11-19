#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include <vector>
#include "AD.h"
#include "Campaign.h"

using namespace std;

void addAD(vector<Campaign>* camplist);
void addADToDB(string name, string text, AdType type, string campname, vector<Campaign>* camplist);
bool isType(string typtstr, AdType* type);
bool hasCamp(string campname, vector<Campaign> campaignlist);
bool hasAD(string name, string campaignName, vector<Campaign> campaignlist);

void readAD(vector<AD>* adlist);
void updateAD(vector<AD>* adlist);
void deleteAD(vector<AD>* adlist);
AD getADFromDB(string name, vector<AD>* adlist);
void updateADToDB(string oldname, string newname, vector<AD>* adlist);
void deleteADFromDB(string name, vector<AD>* adlist);
