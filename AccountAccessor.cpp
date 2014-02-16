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

Person* AccountAccessor::login(Person *per, ExternalAccount &e){
	string name, pass;
		cout<<"Username: ";
		cin>>name;
		cout<<"Password: ";
		cin>>pass;

		InternalAccount temp[2];
		bank.find(name, e);

		e.getInternalAccounts(temp[0],temp[1]);

		//temp[0].displayInternalAccount();
		//temp[1].displayInternalAccount();

		if (pass.compare(e.getPassword()) == 0){

			if(name.compare("admin") != 0){
				per = new Client(temp[0],temp[1]);
				e.getAccountHolder(static_cast<Client*>(per));
			}else{
				per = new Admin();
			}

		}

		return per;
}

}
