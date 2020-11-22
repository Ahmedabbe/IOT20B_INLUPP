#include <iostream>
#include <sstream>
#include <string>
#include<locale.h>
#include <vector>
#include "AD.h"
#include "Customer.h"

using namespace std;

void addAD(vector<Customer> &kundlist);
void addADToDB(string name, string text, AdType type, string campname, string kundname, vector<Customer> &kundlist);
bool isType(string typtstr, AdType* type);
bool hasAD(string name, string campaignName, string kundname, vector<Customer> &kundlist);
void readAD(vector<Customer> &kundlist);
void updateAD(vector<Customer> &kundlist);
void deleteAD(vector<Customer> &kundlist);
AD getADFromDB(string name, string campname, string kundname, vector<Customer>& kundlist);
void updateADToDB(string oldname, string newname, string campname, string kundname, vector<Customer>& kundlist);
void deleteADFromDB(string name, string campname, string kundname, vector<Customer>& kundlist);
void showADs(vector<Customer> &kundlist);
void showAD(string campname, string kundname, AD ad);