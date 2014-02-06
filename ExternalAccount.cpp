/*
 * ExternalAccount.cpp
 *
 *  Created on: Feb 1, 2014
 *      Author: nzayatz14
 */

#include "ExternalAccount.h"

namespace std {

ExternalAccount::ExternalAccount() {
	accountNumber = bank.getTotalAccounts()+1;
	accountHolder = (new Client());
	password = "password";
	createInternalAccounts();
	b = new Bank();

}

void ExternalAccount::createInternalAccounts(){
		internalAccounts[0].setAccountType("Checking");
		internalAccounts[0].setExternalAccount(this);
		internalAccounts[0].setMoney(0);
		internalAccounts[1].setMoney(0);
		internalAccounts[1].setAccountType("Savings");
		internalAccounts[1].setExternalAccount(this);
}

void ExternalAccount::displayExternalAccount(){
	cout<<accountHolder.getUserName()<<" "<<password<<" "<<accountNumber<<endl;
}

int ExternalAccount::getPassword(){
	return password;
}

void ExternalAccount::getAccountHolder(Client &c){
	accountHolder.copyClient(c);
}

void ExternalAccount::getInternalAccounts(InternalAccount &d, InternalAccount &e){
	internalAccounts[0].copyInternalAccount(d);
	internalAccounts[1].copyInternalAccount(e);
}

void ExternalAccount::setPassword(string s){
	password = s;
}

void ExternalAccount::setAccountNumber(int g){
	accountNumber = g;
}

void ExternalAccount::setInternalAccounts(InternalAccount &a, InternalAccount &b){
	a.copyInternalAccount(internalAccount[0]);
	b.copyInternalAccount(internalAccount[1]);
}

void ExternalAccount::setAccountHolder(Client &c){
	c.copyClient(accountHolder);
}

void ExternalAccount::copyExternalAccount(ExternalAccount &e){
	e.setAccountNumber(accountNumber);
	e.setAccountHolder(accountHolder);
	e.setInternalAccounts(internalAccounts[0], internalAccounts[1]);
	e.setPassword(password);
}

ExternalAccount::~ExternalAccount() {
	delete [] accountNumber;
}

}
