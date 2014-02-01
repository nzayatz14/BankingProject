/*
 * Bank.h
 *
 *  Created on: Feb 1, 2014
 *      Author: nzayatz14
 */

#include<iostream>
#include<unordered_set>
#include "ExternalAccount.h"

#ifndef BANK_H_
#define BANK_H_

using namespace std;
typedef unordered_set<ExternalAccount> Accounts;

class Bank {
private:
	Accounts bank;
	int totalAccounts;
public:
	Bank();
	virtual ~Bank();

	int getTotalAccounts();
	void setTotalAccounts(int g);

	void printBank();
	void createExternalAccount(Client &a, string pass);
	void deleteExternalAccount(int a);
	void login(ExternalAccount &a);
	void logout(ExternalAccount &a);
};

#endif /* BANK_H_ */
