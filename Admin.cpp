/*
 * Admin.cpp
 *
 *  Created on: Feb 1, 2014
 *      Author: nzayatz14
 */

#include "Admin.h"

using namespace std;

Admin::Admin() {
	// TODO Auto-generated constructor stub

}

Admin::~Admin() {
	// TODO Auto-generated destructor stub
}

void Admin::viewBank()
{
	bank.printBank();
}

void Admin::viewAccounts()
{
	cout<<bank.getTotalAccounts()<<endl;
}

void Admin::viewAccountInDetail()
{
	// ask for the account number of the account that the user wishes to view
	//if it is a valid account number, open<accountNumber.txt> read in all of
	//the information and print it all. If its not print error and call printOptions

}
void Admin::createAccount()
{
	//ask for general information
	//create client object from entered info
	//call bank.create ExternalAccount(client,password) function for bank class
	//call print options
}

void Admin::changePassword()
{
	//ask for the userName of the account (check to make sure it exists and is the //correct account)
	//ask for new password and re-entry
	//if both entries match, find the externalAccount in the bank and set password in
	//the temporary account to the new password
	//set the externalAccount in the Bank equal to the temporary
	//call printOptions()
}

void Admin::printOptions()
{
	//print and number the capabilities of the administrator (create an account, delete
	//an account, view a specific account, or change the password to an account)
	//ask the option which the user wants to do (by number) and call the respective
	//function
}
