/*
 * Client.h
 *
 *  Created on: Feb 1, 2014
 *      Author: Junjieliao
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Person.h"
#include "InternalAccount.h"

using namespace std;

class Client:public Person {
public:
	Client();//constructor
	virtual ~Client();//destructor
	InternalAccount getHeldAccount();//function returns heldAccount
	void setHeldAccount(InternalAccount &a[]);//function sets the held account
	void copyClient(Client &into);//function copies information from another client
	void viewInternalAccount();//function calls displayExternalAccount()
	void withdraw();
	//ask the user what account they wish to withdraw from and how much
	//check to see that money is less than the total amount of money
	//in the account.If it is, subtract that money from the account,
	//or else print an error message

	void deposit();
	//ask the user what account they wish to deposit form and how much
	//add that money to the account

	void transfer();
	//ask the user what account they wish to transfer from and how
	//much money, check to see that money is less than the total
	//amount of money in the account.If it is, ask which account they
	//want to transfer this money into and make the transfer, or else
	//print an error message

	void printOptions();
	//print and number the capabilities of the client(make a
	//withdrawal, deposit of transfer)
	//ask the option which the user wants to do(by number)and call
	//the respective function

	void logout();
	//save all the changes about the information and overwrite it
	//back into the text file

protected:
	InternalAccount heldAccount[];
};


#endif /* CLIENT_H_ */
