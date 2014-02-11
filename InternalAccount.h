/*
 * InternalAccount.h
 *
 *  Created on: Feb 1, 2014
 *      Author: Junjieliao
 */

#ifndef INTERNALACCOUNT_H_
#define INTERNALACCOUNT_H_

#include <string>

using namespace std;

class InternalAccount {
public:
	InternalAccount();	//constructor
//	virtual ~InternalAccount();	//destructor
	void copyInternalAccount(InternalAccount& other);//function copies the information from an InternalAccount
	void setAccountType(string);	//function sets the account type
	void setUsername(string);	//function sets the username
	void setMoney(double m);	//function sets the money
	string getAccountType();	//function gets the type of the account
	double getMoney();	//function gets the money in the account
	string getUsername();//function gets the username in the account
	void displayInternalAccount();	//function prints all information of the internal account

private:
	string accountType; //variable to holds the type of the account
	double money;		//variable to holds the money in the account
	string username;	//variable to holds the username in the account
};




#endif /* INTERNALACCOUNT_H_ */
