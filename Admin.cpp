/*
 * Admin.cpp
 *
 *  Created on: Feb 1, 2014
 *      Author: nzayatz14
 */

#include "Admin.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

Admin::Admin() {
	// TODO Auto-generated constructor stub
	userName = "admin";
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
	cout<<"\nTotal number of accounts: "<<bank.getTotalAccounts()<<endl<<endl;
}

void Admin::viewAccountInDetail(){
	// ask for the account number of the account that the user wishes to view
	//if it is a valid account number, open<accountNumber.txt> read in all of
	//the information and print it all. If its not print error and call printOptions

	string user;
	cout<<"Enter User Name: ";
	cin>>user;

	ExternalAccount ext;
	bank.find(user, ext);
	Client c;
	Client *cPtr = &c;
	InternalAccount t[2];

	ext.getAccountHolder(cPtr);

	cout<<endl<<c.getUserName()<<endl;
	cout<<ext.getPassword()<<endl;
	cout<<"Account Number: "<<ext.getAccountNumber()<<endl<<endl;
	c.displayPersonalInformation();
	cout<<endl;

	ext.getInternalAccounts(t[0],t[1]);

	t[0].displayInternalAccount();
	cout<<endl;
	t[1].displayInternalAccount();
	cout<<endl;


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

	string n = firstName + " "+lastName;

	cout<<"Please enter birthday of client."<< endl;
	cin>>b;

	cout<<"Please enter gender of client."<< endl;
	cin>>g;

	cout<<"Please enter in phone number of client"<< endl;
	cin>>p;
	getline(cin, a);

	cout<<"Please enter in address of client:\n";
	getline(cin, a);

	cout<<"Please enter in email of client"<< endl;
	cin>>e;

	cout<<"Please enter in username of client"<< endl;
	cin>>un;

	cout<<"Please enter in a password"<< endl;
	cin>>pass;

	clie.setPerson(n,b,g,p,a,e,un);

	bank.createExternalAccount(clie, pass);
}

void Admin::changePassword()
{
	//ask for the userName of the account (check to make sure it exists and is the //correct account)
	//ask for new password and re-entry
	//if both entries match, find the externalAccount in the bank and set password in
	//the temporary account to the new password
	//set the externalAccount in the Bank equal to the temporary
	//call printOptions()

	ExternalAccount temp;
	temp.setAccountNumber(-1);

	string un;
	string pass;
	string pass2;
	cout<<"Please enter the username of the account that you wish to change the password for:" << endl;
	cin>>un;

	bank.find(un, temp);

	if(temp.getAccountNumber()!=-1){
		cout<<"Please enter the new password of the account:" << endl;
		cin>>pass;

		cout<<"Please enter the password again:" << endl;
		cin>>pass2;

		if(pass.compare(pass2)==0){
			temp.setPassword(pass);
			bank.updateAccount(un, temp);
		}
	}
}

void Admin::deleteAccount(){
	string un;
	cout<<"Please enter the user name of the account you wish to delete:" << endl;
	cin>>un;

	bank.deleteExternalAccount(un);
}

void Admin::printOptions()
{
	//print and number the capabilities of the administrator (create an account, delete
	//an account, view a specific account, or change the password to an account)
	//ask the option which the user wants to do (by number) and call the respective
	//function
	int n = -1;
	do{
		cout<<"Here you can do: \n1. View bank  \n2. View the number of accounts  \n3. View an account in detail \n4. Create an account \n5. Delete an account \n6. Change password of account \n0. Logout"<<
				"\nEnter the number you wish to choose: ";

		try{
			cin>>n;
			if(!cin)
				throw 1;
		}
		catch(int a){
			n=-1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
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
		case 0:
			break;
		default:
			cout<<"Please enter a valid number."<<endl;
		}
	}while (n!=0);

	logout();
}

void Admin::logout(){
	bank.logout();
}
