/*
 * Client.cpp
 *
 *  Created on: Feb 1, 2014
 *      Author: Junjieliao
 */

#include<iostream>
#include "Client.h"

using namespace std;

Client::Client() {
	// TODO Auto-generated constructor stub
	heldAccount=new ExternalAccount;
}

Client::~Client() {
	// TODO Auto-generated destructor stub
	delete [] heldAccount;
}

void Client::setHeldAccount(ExternalAccount& a){
	heldAccount=a;
}

ExternalAccount Client::getHeldAccount(){
	return heldAccount;
}

void Client::copyClient(Client &into){
	into.setHeldAccount(heldAccount);
}

void Client::viewExternalAccount(){
	heldAccount.displayExternalAccount();
}

void Client::withdraw(){
	cout<<"Please select an account you want to withdraw money from:"<<
			"1.checking 2.saving"<<" Please enter a number:";
	int n;
	cin>>n;
	cout<<"Please enter how much you want to withdraw from your account:";
	double m;
	cin>>m;
	InternalAccount temp[2];
	heldAccount.getInternalAccounts(temp);
	if(temp[n-1].getMoney()<m){
		cout<<"Sorry, the balance in your account is sufficient."<<endl;
	}
	else{
		temp[n-1].setMoney(temp[n-1].getMoney()-m);
		heldAccount.setInternalAccounts(temp);
	}
	printOptions();
}
void Client::deposit(){
	cout<<"Please select an account you want to withdraw money from:"<<
			"1.checking 2.saving"<<" Please enter a number:";
	int n;
	cin>>n;
	cout<<"Please enter how much you want to deposit into the account:";
	double m;
	cin>>m;
	InternalAccount temp[2];
	heldAccount.getInternalAccounts(temp);
	temp[n-1].setMoney(temp[n-1].getMoney()+m);
	printOptions();
}
void Client::transfer(){
	cout<<"Please select an account you want to withdraw money from:"<<
			"1.checking 2.saving"<<" Please enter a number:";
	int n;
	cin>>n;
	cout<<"Please enter how much you want to transfer:";
	double m;
	cin>>m;
	InternalAccount temp[2];
	heldAccount.getInternalAccounts(temp);
	if(temp[n-1].getMoney()<m)
		cout<<"Sorry, the balance in your account is sufficient."<<endl;
	else{
		temp[n-1].setMoney(temp[n-1].getMoney()-m);
		switch(n-1){
		case 0:
			temp[1].setMoney(temp[n-1].getMoney()+m);
			break;
		case 1:
			temp[0].setMoney(temp[n-1].getMoney()+m);
			break;
		default:
		}
	}
	printOptions();
}
void Client::printOptions(){
	cout<<"Here you can do: 1.Withdrawal 2.deposit 3.transfer. "<<
			"Enter the number to keep running: ";
	int n;
	cin>>n;
	switch(n){
		case 1:
			withdraw();
			break;
		case 2:
			deposit();
			break;
		case 3:
			transfer();
			break;
		default:
			cout<<"Please enter a valid number."<<endl;
			printOptions();
	}
}


