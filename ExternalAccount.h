/*
 * ExternalAccount.h
 *
 *  Created on: Feb 1, 2014
 *      Author: nzayatz14
 */

#ifndef EXTERNALACCOUNT_H_
#define EXTERNALACCOUNT_H_

namespace std {

class ExternalAccount {
private:
	int accountNumber;
	Client accountHolder;
	InternalAccount internalAccounts[2];
	string password;
public:
	int getAccountNumber();
	string getPassword();
	void getAccountHolder(Client &c);
	void getInternalAccounts(InternalAccount &d[]);

	void setPassword(string s);
	void setAccountHolder(Client &c);
	void setInternalAccounts(InternalAccount &a[]);
	void setAccountNumber(int g);

	void createInternalAccount(string name);
	void displayExternalAccount();
	void copyExternalAccount(ExternalAccount &e);

	ExternalAccount();
	virtual ~ExternalAccount();
};

template<>
class hash<ExternalAccount>{
	typedef size_t result_type;

	result_type operator()(const ExternalAccount &c) const{
		size_t value{0};
		boost::hash_combine(value, c.accountNumber);
		boost::hash_combine(value, c.password);

		return value;
	}
}
}

#endif /* EXTERNALACCOUNT_H_ */
