#ifndef _AD_ENGINE
#define _AD_ENGINE
#include<iostream>
#include <vector>
#include "Customer.h"
#include "AD.h"

using namespace std;

class AdEngine {
	vector<Customer*> kundlist;
public:
	AdEngine();
	void setKundlist(vector<Customer*> kundlist);
	vector<Customer*> getKundlist();
	AD getNextAd();
	~AdEngine();
};
#endif // !_AD_ENGINE
