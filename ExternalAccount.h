/*
 * ExternalAccount.h
 *
 *  Created on: Feb 1, 2014
 *      Author: nzayatz14
 */

#ifndef EXTERNALACCOUNT_H_
#define EXTERNALACCOUNT_H_

namespace std {

class ExternalAccount;

template<>
class hash<ExternalAccount>{
	
	result_type operator()(const ExternalAccount &c) const{
		size_t value{0};
		boost::hash_combine(value, )
	}
}


class ExternalAccount {
private:
	int accountNumber;
	Client accountHolder;
	InternalAccount internalAccounts[2];
	string password;
public:
	ExternalAccount();
	virtual ~ExternalAccount();
};

}

#endif /* EXTERNALACCOUNT_H_ */
