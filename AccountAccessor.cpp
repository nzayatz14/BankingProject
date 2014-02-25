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

//Pre: passes in a person pointer to be returned and an external account by reference to be returned
//Post: set the person equal to the person logging in and the externalAccount equal to the account that
//has been logged in to
Person* AccountAccessor::login(Person *per, ExternalAccount &e){
	string name, pass;
	bool success = false;

	//read in the username and password
	while(!success){
		cout<<"Username: ";
		cin>>name;
		cout<<"Password: ";
		cin>>pass;

		InternalAccount temp[2];

		//try to find the account with the given username
		bank.find(name, e);

		//if the username is found, check if the password matches
		if(e.getAccountNumber() != -1){
			e.getInternalAccounts(temp[0],temp[1]);
			if (pass.compare(e.getPassword()) == 0){
				//if the password matches, set the person equal to whoever logs in
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
			cout<<"Password is incorrect."<<endl;
		}
	}

	//return the person
	return per;
}

}
