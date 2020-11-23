#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include <vector>
#include "AD.h"
#include "Customer.h"

using namespace std;

void addAD(vector<Customer*> &kundlist);
void addADToDB(string name, string text, AdType type, Campaign* camp);
bool isType(string typtstr, AdType* type);
bool hasAD(string name, Campaign* camp);
void readAD(vector<Customer*> &kundlist);
void updateAD(vector<Customer*> &kundlist);
void deleteAD(vector<Customer*> &kundlist);
AD* getADFromDB(string name, Campaign* camp);
void updateADToDB(string newname, AD* ad);
void deleteADFromDB(AD* ad, Campaign* camp);
void showADs(vector<Customer*> &kundlist);
void showAD(string campname, string kundname, AD* ad);
void showAD(string campname, string kundname, AD ad);
