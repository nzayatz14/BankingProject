//============================================================================
// Name        : BankingProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "InternalAccount.h"
#include "Person.h"
#include "Admin.h"
#include "Client.h"
#include "ExternalAccount.h"
#include "Bank.h"
#include "AccountAccessor.h"
using namespace std;

int main() {
	Person *person;
	ExternalAccount account;
	AccountAccessor a;
	InternalAccount temp[2];

	account.setAccountNumber(-1);

	person = a.login(person, account);
	cout<<person->getAddress()<<endl;
	person->printOptions();

	free (person);
	person = NULL;
	return 0;
}
