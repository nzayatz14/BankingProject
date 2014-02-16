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

void Admin::viewAccountInDetail(){
	// ask for the account number of the account that the user wishes to view
	//if it is a valid account number, open<accountNumber.txt> read in all of
	//the information and print it all. If its not print error and call printOptions
	ifstream in;
	int accountNumber;
	ostringstream ss;

	cout << "Enter account number:"<<endl;
	cin>>accountNumber;
	ss<<accountNumber;
	String acct = ss.str();
	acct = acct + ".txt";

	in.open(acct.c_str());
	string temp;
	while(!in.eof()){
		getline(temp,in);
		cout<<temp<<endl;
	}
	in.close(acct.c_str());

}
void Admin::createAccount(){
	//ask for general information
	//create client object from entered info
	//call bank.create ExternalAccount(client,password) function for bank class

	Client clie;

	string firstName;
	string lastName;
	string b;
	char g;
	string p;
	string a;
	string e;
	string un;
	string pass;

	cout<<"Please enter first name of client."<< endl;
	cin>>firstName;


	cout<<"Please enter last name of client."<< endl;
	cin>>lastName;

	string n = firstName + lastName;

	cout<<"Please enter birthday of client."<< endl;
	cin>>b;

	cout<<"Please enter gender of client."<< endl;
	cin>>g;

	cout<<"Please enter in phone number of client"<< endl;
	cin>>p;

	cout<<"Please enter in address of client"<< endl;
	cin>>a;

	cout<<"Please enter in email of client"<< endl;
	cin>>e;

	cout<<"Please enter in username of client"<< endl;
	cin>>un;

	cout<<"Please enter in a password"<< endl;
	cin>>pass;

	clie.setPerson(n,b,g,p,a,e,un);

	Bank.createExternalAccount(clie, pass);
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
		cout<<"Here you can do: 1. View bank 2. View number of accounts  3. View account in detail 4. Create an account 5. Delete an account 6. Change password of account 0. Exit"<<
			"Enter the number you wish to choose: ";
	int n;
	while(n!=0){
		cin>>n;
		switch(n){
			case 1:
				viewBank();
				break;
			case 2:
				viewAccounts();
				break;
			case 3:
				viewAccountInDetail();
				break;
			case 4:
				createAccount();
				break;
			case 5:
				deleteAccount();
				break;
			case 6:
				changePassword();
				break;
			default:
				cout<<"Please enter a valid number."<<endl;
				printOptions();
		}
		cout<<"Here you can do: 1. View bank 2. View number of accounts  3. View account in detail 4. Create an account 5. Delete an account 6. Change password of account 0. Exit"<<
					"Enter the number you wish to choose: ";
	}
	logout();
}
}
