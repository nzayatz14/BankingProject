/*
 * Admin.h
 *
 *  Created on: Feb 1, 2014
 *      Author: nzayatz14
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
	Admin();
	virtual ~Admin();
	void viewBank();
	void viewAccounts();
	void viewAccountInDetail();
	void createAccount();
	void deleteAccount();
	void changePassword();
	void printOptions();
	void logout();
	void setBank(Bank &b);

private:
	Bank bank;
};

#endif /* ADMIN_H_ */
