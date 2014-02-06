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
	heldAccount=new InternalAccount;
}

Client::~Client() {
	// TODO Auto-generated destructor stub
	delete [] heldAccount;
}

void Client::setHeldAccount(InternalAccount& a[]){
	a[0] = heldAccount[0];
	a[1] = heldAccount[1];
}

InternalAccount Client::getHeldAccount(){
	return heldAccount;
}

void Client::copyClient(Client &into){
	into.setHeldAccount(heldAccount);
}

void Client::viewInternalAccount(){
	heldAccount[0].displayInternalAccount();
	heldAccount[1].displayInternalAccount();
}

void Client::withdraw(){
	cout<<"Please select an account you want to withdraw money from:"<<
			"1.checking 2.saving"<<" Please enter a number:";
	int n;
	cin>>n;
	cout<<"Please enter how much you want to withdraw from your account:";
	double m;
	cin>>m;
	if(heldAccount[n-1].getMoney()<m)
		cout<<"Sorry, there is insufficient money in your account."<<endl;
	else{
		heldAccount[n-1].setMoney(heldAccount[n-1].getMoney()-m);
		viewInternalAccount();
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
	heldAccount[n-1].setMoney(heldAccount[n-1].getMoney()+m);
	viewInternalAccount();
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
	if(heldAccount[n-1].getMoney()<m)
		cout<<"Sorry, the balance in your account is sufficient."<<endl;
	else{
		heldAccount[n-1].setMoney(heldAccount[n-1].getMoney()-m);
		switch(n-1){
		case 0:
			heldAccount[1].setMoney(heldAccount[n-1].getMoney()+m);
			break;
		case 1:
			heldAccount[0].setMoney(heldAccount[n-1].getMoney()+m);
			break;
		default:
		}
	}
	viewInternalAccount();
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


