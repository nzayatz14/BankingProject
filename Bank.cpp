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

	getline(in, user);
	while(!in.eof()){
		in>>user;
		in>>pass;
		in>>accountNumber;

		ExternalAccount temp;
		temp.setAccountNumber(accountNumber);
		temp.setPassword(pass);

		ifstream acct;
		ostringstream ss;
		string accountNumb;
		ss<<accountNumber;
		accountNumb = ss.str();
		accountNumb = accountNumb + ".txt";
		acct.open(accountNumb.c_str());

		string no;
		//read in data
		getline(acct,no);
		getline(acct,no);
		getline(acct,no);
		getline(acct,no);

		if(user.compare("admin") != 0){
			Client person;
			string name,birthday,phone,address,email;
			char gender;
			getline(acct,name);
			getline(acct,birthday);
			in>>gender;
			getline(acct,no);
			getline(acct,phone);
			getline(acct,address);
			getline(acct,email);
			getline(acct,no);
			person.setPerson(name, birthday, gender, phone,address,email,user);

			InternalAccount accounts[2];
			accounts[0].setUsername(user);
			accounts[1].setUsername(user);

			string account1;
			getline(acct,account1);
			accounts[0].setAccountType(account1);

			double money1;
			acct>>money1;
			accounts[0].setMoney(money1);

			getline(acct,no);
			getline(acct,no);

			string account2;
			getline(acct,account2);
			accounts[1].setAccountType(account2);

			double money2;
			acct>>money2;
			accounts[1].setMoney(money2);

			temp.setAccountHolder(person);
			temp.setInternalAccounts(accounts[0],accounts[1]);
		}



		acct.close();

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
		Client *c;
		temp.getAccountHolder(c);
		string userName = i->first;
		cout<< userName<<" "<< temp.getPassword()<<" "<< temp.getAccountNumber()<<endl;
	}
}

void Bank::createExternalAccount(Client &a, string pass){
	ExternalAccount n;
	n.setAccountHolder(a);
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

	if(found != bank.end()){
	ExternalAccount temp = found->second;
	temp.copyExternalAccount(a);
	}

}

