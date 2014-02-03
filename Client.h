/*
 * Client.h
 *
 *  Created on: Feb 1, 2014
 *      Author: Junjieliao
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "ExternalAccount.h"

using namespace std;

class Client {
public:
	Client();//constructor
	virtual ~Client();//destructor
	void copyClient(const Client&);//function copies information from another client
	void viewExternalAccount();//function calls displayExternalAccount()
	void withdraw();
	//ask the user what account they wish to withdraw from and how much
	//check to see that money is less than the total amount of money
	//in the account.If it is, subtract that money from the account,
	//or else print an error message and call printOptions()

	void deposit();
	//ask the user what account they wish to deposit form and how much
	//add that money to the account
	//call printOptions()

	void transfer();
	//ask the user what account they wish to transfer from and how
	//much money, check to see that money is less than the total
	//amount of money in the account.If it is, ask which account they
	//want to transfer this money into and make the transfer, or else
	//print an error message and call printOptions()

	void printOptions();
	//print and number the capabilities of the client(make a
	//withdrawal, deposit of transfer)
	//ask the option which the user wants to do(by number)and call
	//the respective function

protected:
	ExternalAccount heldAccount;
};


#endif /* CLIENT_H_ */

