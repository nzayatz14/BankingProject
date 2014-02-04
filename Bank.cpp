/*
 * Bank.cpp
 *
 *  Created on: Feb 1, 2014
 *      Author: nzayatz14
 */

#include "Bank.h"
#include <fstream>
#include <sstream>
using namespace std;
Bank::Bank() {
	// TODO Auto-generated constructor stub
	ifstream in;
	in.open("bank.txt");
	string user, pass;
	int accountNumber;

	while(!in.eof()){
		in>>user;
		in>>pass;
		in>>accountNumber;

		ifstream acct;
		ostringstream ss;
		string accountNumb;
		ss<<account;
		accountNumb = ss.str();
		accountNumb = accountNumb + ".txt";
		acct.open(accountNumb.c_str());

		//read in data

		acct.close();

		ExternalAccount temp;
		//create externalAccount and Person and internalAccounts based on data

		bank.insert(make_pair<string,ExternalAccount>(user, temp));
	}

	in.close();
}

Bank::~Bank() {
	// TODO Auto-generated destructor stub
}

int Bank::getTotalAccounts(){
	return totalAccounts;
}

void Bank::setTotalAccounts(int g){
	totalAccounts = g;
}

void Bank::printBank(){
	for(auto i = bank.begin(); i!=bank.end();i++){
		ExternalAccount temp = i->second;
		Client c;
		c = temp.getAccountHolder(c);
		string userName = i->first;
		cout<< userName<<" "<< temp.getPassword()<<" "<< temp.getAccountNumber()<<endl;
	}
}

void Bank::createExternalAccount(Client &a, string pass){
	ExternalAccount n;
	n = n.setAccountHolder(a);
	n.setPassword(pass);
	n.createInternalAccounts();
	string user = a.getUserName();
	bank.insert(make_pair<string,ExternalAccount>(user, n));
	totalAccounts++;
}

void Bank::deleteExternalAccount(string user){
	bank.erase(user);
	totalAccounts--;
}

void Bank::find(string user, ExternalAccount &a){
	unordered_map<string,ExternalAccount>::const_iterator found = bank.find (user);
	found->second.copyExternalAccount(a);

}

