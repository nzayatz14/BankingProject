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
		InternalAccount();
		//default constructor that sets
		//accountType="Checking",
		//money=0, and
		//username="user"
		//as default

		void copyInternalAccount(InternalAccount& other);
		//function copies the information from other InternalAccount variable
		//Passes other InternalAccount variable as reference,
		//copy the values of money, account type
		//and username

		void setAccountType(string);
		//function sets the account type
		//Set the value passed into the function
		//into member: accountType

		void setUsername(string);
		//function sets the username
		//Set the value passed into the function
		//into member: username

		void setMoney(double m);
		//function sets the money
		//Set the value passed into the function
		//into member: money

		string getAccountType();
		//function gets the type of the account
		//Return the value of member: accountType
		//as string

		double getMoney();
		//function gets the money in the account
		//Return the value of member: money
		//as double

		string getUsername();
		//function gets the username in the account
		//Return the value of member: username
		//as string

		void displayInternalAccount();
		//function prints all information of the internal account
		//Display the values of accountType and money
		//in the format below:
		//accontType:
		//$money

private:
	string accountType; //variable to holds the type of the account
	double money;		//variable to holds the money in the account
	string username;	//variable to holds the username in the account
};




#endif /* INTERNALACCOUNT_H_ */
