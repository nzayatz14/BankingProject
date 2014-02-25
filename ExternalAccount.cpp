/*
 * ExternalAccount.cpp
 *
 *  Created on: Feb 1, 2014
 *      Author: nzayatz14
 */

#include "ExternalAccount.h"

namespace std {

ExternalAccount::ExternalAccount() {
	password = "password";
	createInternalAccounts();
	accountNumber = 0;

}

void ExternalAccount::createInternalAccounts(){
		internalAccounts[0].setAccountType("Checking");
		internalAccounts[0].setMoney(0);
		internalAccounts[1].setMoney(0);
		internalAccounts[1].setAccountType("Savings");
}

void ExternalAccount::displayExternalAccount(){
	cout<<accountHolder.getUserName()<<"\t"<<password<<"\t"<<accountNumber<<endl;
}

string ExternalAccount::getPassword(){
	return password;
}

void ExternalAccount::getAccountHolder(Client *c){
	accountHolder.copyClient(*c);
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
	a.copyInternalAccount(internalAccounts[0]);
	b.copyInternalAccount(internalAccounts[1]);
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

int ExternalAccount::getAccountNumber(){
	return accountNumber;
}

ExternalAccount::~ExternalAccount() {
}

}
