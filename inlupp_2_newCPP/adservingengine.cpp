
#include "customer.h"
#include "adservingengine.h"


ServingEngine::ServingEngine(void) {


}

int ServingEngine::NumberOfCustomers() {

	return customer_list.size();

}

Customer& ServingEngine::GetCustomerByIndex(int index) {

	return customer_list[index];
}

void ServingEngine::AddCustomer(Customer c) {

	return customer_list.push_back(c);
}