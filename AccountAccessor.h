/*
 * AccountAccessor.h
 *
 *  Created on: Feb 5, 2014
 *      Author: nzayatz14
 */

#include "ExternalAccount.h"
#include "Bank.h"
#include "Person.h"
#include "Client.h"
#include "Admin.h"
#include "InternalAccount.h"

#ifndef ACCOUNTACCESSOR_H_
#define ACCOUNTACCESSOR_H_

namespace std {

class AccountAccessor {
private:
	ExternalAccount externalAccount;
	Bank bank;
public:
	AccountAccessor();
	virtual ~AccountAccessor();

	Person* login(Person* per, ExternalAccount &e);
};

}

#endif /* ACCOUNTACCESSOR_H_ */
