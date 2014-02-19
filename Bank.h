/*
 * Bank.h
 *
 *  Created on: Feb 1, 2014
 *      Author: nzayatz14
 */



#ifndef BANK_H_
#define BANK_H_
#include<iostream>
#include<unordered_map>
#include "ExternalAccount.h"
#include "Person.h"
#include "Client.h"
#include "InternalAccount.h"

using namespace std;

class Bank {
private:
	unordered_map<string ,ExternalAccount> bank;
	int totalAccounts;
public:
	Bank();
	virtual ~Bank();

	int getTotalAccounts();
	void setTotalAccounts(int g);

	void printBank();
	void createExternalAccount(Client &a, string pass);
	void deleteExternalAccount(string user);
	void find(string user, ExternalAccount &a);
	void updateAccount(string user, ExternalAccount &a);
	void logout();
};

#endif /* BANK_H_ */
