/*
 * Admin.h
 *
 *  Created on: Feb 1, 2014
 *      Author: mac2nd
 */

#ifndef ADMIN_H_
#define ADMIN_H_

#include "Bank.h"
#include "ExternalAccount.h"
#include "Person.h"
#include "Client.h"
#include "InternalAccount.h"

using namespace std;

class Admin: public Person {
public:
	Admin();	// constructor for admin
	virtual ~Admin();	// destructor for admin
	void viewBank();	// views the Bank
	void viewAccounts();	// views the total number of Accounts
	void viewAccountInDetail();	// views a specific account in detail
	void createAccount();	// create an account
	void deleteAccount();	// deletes an account
	void changePassword();	// changes password of a specific account
	void printOptions();	// prints the options to screen
	void logout();	// logouts of admin
	void setBank(Bank &b);	// 

private:
	Bank bank;
};

#endif /* ADMIN_H_ */

