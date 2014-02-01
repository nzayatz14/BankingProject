/*
 * Bank.h
 *
 *  Created on: Feb 1, 2014
 *      Author: nzayatz14
 */

#include<iostream>
#include<unordered_set>

#ifndef BANK_H_
#define BANK_H_

using namespace std;
typedef unordered_set<ExternalAccount> Accounts;

class Bank {
private:
	Accounts bank;
public:
	Bank();
	virtual ~Bank();
};

#endif /* BANK_H_ */
