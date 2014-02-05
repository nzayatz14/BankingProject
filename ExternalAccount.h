/*
 * ExternalAccount.h
 *
 *  Created on: Feb 1, 2014
 *      Author: nzayatz14
 */


#include <iostream>
#ifndef EXTERNALACCOUNT_H_
#define EXTERNALACCOUNT_H_

class Bank;
class Client;
class InternalAccount;

namespace std {


class ExternalAccount {
private:
	Bank* b;
	int accountNumber;
	Client* accountHolder;
	InternalAccount* internalAccounts[2];
	string password;
public:
	int getAccountNumber();
	string getPassword();
	void getAccountHolder(Client &c);
	void getInternalAccounts(InternalAccount &d, InternalAccount &e);

	void setPassword(string s);
	void setAccountHolder(Client &c);
	void setInternalAccounts(InternalAccount &a, InternalAccount &b);
	void setAccountNumber(int g);

	void createInternalAccounts();
	void displayExternalAccount();
	void copyExternalAccount(ExternalAccount &e);

	void login();
	void logout();

	ExternalAccount();
	virtual ~ExternalAccount();
};
}

#endif /* EXTERNALACCOUNT_H_ */
