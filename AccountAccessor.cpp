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
	bool success = false;

	while(!success){
		cout<<"Username: ";
		cin>>name;
		cout<<"Password: ";
		cin>>pass;

		InternalAccount temp[2];
		bank.find(name, e);

		if(e.getAccountNumber() != -1){
			e.getInternalAccounts(temp[0],temp[1]);
			if (pass.compare(e.getPassword()) == 0){
				success = true;
				if(name.compare("admin") != 0){
					per = new Client();
					e.getAccountHolder(static_cast<Client*>(per));
				}else{
					per = new Admin();
				}

			}else{
				cout<<"Password is incorrect."<<endl;
			}
		}else{
			cout<<"User name does not exist."<<endl;
		}
	}

	return per;
}

}
