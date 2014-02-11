/*
 * AccountAccessor.cpp
 *
 *  Created on: Feb 5, 2014
 *      Author: nzayatz14
 */

#include "AccountAccessor.h"
#include <fstream>
#include <sstream>
namespace std {

AccountAccessor::AccountAccessor() {
	// TODO Auto-generated constructor stub

}

AccountAccessor::~AccountAccessor() {
	// TODO Auto-generated destructor stub
}

void AccountAccessor::login(Person *per){
	string name, pass;
	cout<<"Username: ";
	cin>>name;
	cout<<"Password: ";
	cin>>pass;

	ExternalAccount temp;

	bank.find(name, temp);

	if (pass.compare(temp.getPassword()) == 0){

		if(name.compare("admin") != 0){
			per = new Client();
			temp.getAccountHolder(static_cast<Client*>(per));
		}else{
			per = new Admin();
		}

		per->printOptions();
	}
}

}
