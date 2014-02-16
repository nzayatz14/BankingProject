/*
 * InternalAccount.cpp
 *
 *  Created on: Feb 1, 2014
 *      Author: Junjieliao
 */

#include<iostream>
#include "InternalAccount.h"

using namespace std;

InternalAccount::InternalAccount() {
	// TODO Auto-generated constructor stub
	accountType= "Checking";
	money=0;
	username="user";
}//end InternalAccount

//InternalAccount::~InternalAccount() {
//	// TODO Auto-generated destructor stub
//	delete [] externalAccount;
//}//end ~InternalAccount

void InternalAccount::copyInternalAccount(InternalAccount& into){
	into.setMoney(money);
	into.setAccountType(accountType);
	into.setUsername(username);
}

void InternalAccount::setAccountType(string acct){
	accountType=acct;
}//end setAccountType

void InternalAccount::setMoney(double m){
	money=m;
}//end setMoney

void InternalAccount::setUsername(string nam){
	username=nam;
}//end setExternalAccount

string InternalAccount::getAccountType(){
	return accountType;
}//end getAccountType

double InternalAccount::getMoney(){
	return money;
}//end getMoney

string InternalAccount::getUsername(){
	return username;
}//end username

void InternalAccount::displayInternalAccount(){
	cout<<accountType<<":"<<endl<<"$"<<money<<endl;
}//end displayInteralAccount
