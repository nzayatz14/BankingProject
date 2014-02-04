/*
 * InternalAccount.h
 *
 *  Created on: Feb 1, 2014
 *      Author: Junjieliao
 */

#ifndef INTERNALACCOUNT_H_
#define INTERNALACCOUNT_H_

#include <string>
#include "ExternalAccount.h"

using namespace std;

class InternalAccount {
public:
	InternalAccount();	//constructor
	virtual ~InternalAccount();	//destructor
	void copyInternalAccount(InternalAccount& other);//function copies the information from an InternalAccount
	void setAccountType(string);	//function sets the account type
	void setMoney(double m);	//function sets the money
	void setExternalAccount(ExternalAccount&);	//function sets the corresponding external account
	string getAccountType();	//function gets the type of the account
	double getMoney();	//function gets the money in the account
	ExternalAccount getExternalAccount();	//function gets the corresponding external account
	void displayInternalAccount();	//function prints all information of the internal account

private:
	string accountType; //variable holds the type of the account
	double money;		//variable holds the money in the account
	ExternalAccount externalAccount;	//variable holds the corresponding external account
};




#endif /* INTERNALACCOUNT_H_ */
