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

void AccountAccessor::login(Person &per){
	string name, pass;
	cout<<"Username: ";
	cin>>name;
	cout<<"Password: ";
	cin>>pass;

	ExternalAccount temp;

	bank.find(name, temp);

	if (pass.compare(temp.getPassword()) == 0){
		int account = temp.getAccountNumber();

		ifstream in;
		ostringstream ss;
		string accountNumb;
		ss<<account;
		accountNumb = ss.str();
		accountNumb = accountNumb + ".txt";
		in.open(accountNumb.c_str());

		//read in data and set it to person

		in.close();
	}
}

void AccountAccessor::logout(){

}
}
