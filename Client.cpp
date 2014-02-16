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
<<<<<<< HEAD


}

Client::Client(InternalAccount &a, InternalAccount &b){
	a.copyInternalAccount(heldAccount[0]);
	b.copyInternalAccount(heldAccount[1]);

=======
	// TODO Auto-generated constructor stub
	heldAccount=new InternalAccount;
>>>>>>> d643bf78c6c0972e5bb84d933167bdf1c8d7e158
}

Client::~Client() {
	// TODO Auto-generated destructor stub
}

<<<<<<< HEAD
void Client::setHeldAccount(InternalAccount &a,InternalAccount &b){
	a.copyInternalAccount(heldAccount[0]);
	b.copyInternalAccount(heldAccount[1]);
}

void Client::getHeldAccount(InternalAccount &a,InternalAccount &b){
	heldAccount[0].copyInternalAccount(a);
	heldAccount[1].copyInternalAccount(b);
=======
void Client::setHeldAccount(InternalAccount& a[]){
	a[0] = heldAccount[0];
	a[1] = heldAccount[1];
}

InternalAccount Client::getHeldAccount(){
	return heldAccount;
>>>>>>> d643bf78c6c0972e5bb84d933167bdf1c8d7e158
}

void Client::copyClient(Client &into){
	into.setHeldAccount(heldAccount);
}

void Client::viewInternalAccount(){
	heldAccount[0].displayInternalAccount();
	heldAccount[1].displayInternalAccount();
}

void Client::withdraw(){
<<<<<<< HEAD
	heldAccount[0].displayInternalAccount();
	heldAccount[1].displayInternalAccount();
	cout<<"Please select an account you want to withdraw money from:"
			<<endl<<"1. Checking"
			<<endl<<"2. Saving"
			<<endl<<"Please enter a number:";

=======
	cout<<"Please select an account you want to withdraw money from:"<<endl;
	cout<<"\t"<<"1. Checking"<<endl;
	cout<<"\t"<<"2. Savings"<<endl;
	cout<<"\t"<<"0. Exit"<<endl;
	cout<<"Please enter a number:";
>>>>>>> d643bf78c6c0972e5bb84d933167bdf1c8d7e158
	int n;
	cin>>n;
	if(n!=0){
		cout<<"Please enter how much you want to withdraw from your account:";
		double m;
		cin>>m;
		if(heldAccount[n-1].getMoney()<m)
			cout<<"Sorry, there is insufficient money in your account."<<endl;
		else
			heldAccount[n-1].setMoney(heldAccount[n-1].getMoney()-m);
	}
	else
		cout<<"Operation quits."<<endl;
	viewInternalAccount();
}
void Client::deposit(){
<<<<<<< HEAD

	heldAccount[0].displayInternalAccount();
	heldAccount[1].displayInternalAccount();
	cout<<"Please select an account you want to deposit money to:"
			<<endl<<"1. Checking"
			<<endl<<"2. Savings"
			<<endl<<"Please enter a number:";

=======
	cout<<"Please select an account you want to deposit money into:"<<endl;
	cout<<"\t"<<"1. Checking"<<endl;
	cout<<"\t"<<"2. Savings"<<endl;
	cout<<"\t"<<"0. Exit"<<endl;
	cout<<"Please enter a number:";
>>>>>>> d643bf78c6c0972e5bb84d933167bdf1c8d7e158
	int n;
	cin>>n;
	if(n!=0){
		cout<<"Please enter how much you want to deposit into the account:";
		double m;
		cin>>m;
		heldAccount[n-1].setMoney(heldAccount[n-1].getMoney()+m);
	}
	else
		cout<<"Operation quits."<<endl;
	viewInternalAccount();
}
void Client::transfer(){
<<<<<<< HEAD
	heldAccount[0].displayInternalAccount();
	heldAccount[1].displayInternalAccount();
	cout<<"Please select an account you want to transfer money from:"
			<<endl<<"1. Checking"
			<<endl<<"2. Savings"
			<<endl<<"Please enter a number:";

	int n;
	cin>>n;

	cout<<"Please enter how much you want to transfer:";
	double m;
	cin>>m;

	if(heldAccount[n-1].getMoney()<m)
		cout<<"Sorry, the balance in this account is insufficient."<<endl;
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
			break;
=======
	cout<<"Please select an account you want to withdraw money from:"<<endl;
	cout<<"\t"<<"1. Checking"<<endl;
	cout<<"\t"<<"2. Savings"<<endl;
	cout<<"\t"<<"0. Exit"<<endl;
	cout<<"Please enter a number:";
	int n;
	cin>>n;
	if(n!=0){
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
>>>>>>> d643bf78c6c0972e5bb84d933167bdf1c8d7e158
		}
	}
	else
		cout<<"Operation quits."<<endl;
	viewInternalAccount();
}
void Client::printOptions(){
<<<<<<< HEAD
	heldAccount[0].displayInternalAccount();
	heldAccount[1].displayInternalAccount();
	int n;
	do{
		cout<<"Here you can do:"<<endl;
		cout<<"\t"<<"1.Withdrawal"<<endl;
		cout<<"\t"<<"2.Deposit"<<endl;
		cout<<"\t"<<"3.Transfer"<<endl;
		cout<<"\t"<<"0.Logout"<<endl;
		cout<<"Enter a number to keep running:";

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
		case 0:
			break;
		default:
			cout<<"Please enter a valid number."<<endl;
		}
	}while(n!=0);

=======
	cout<<"Here you can do:"<<endl;
	cout<<"\t"<<"1. Withdrawal"<<endl;
	cout<<"\t"<<"2. Deposit"<<endl;
	cout<<"\t"<<"3. Transfer"<<endl;
	cout<<"\t"<<"0. Exit"<<endl;
	cout<<"Enter a number to keep running:";
	int n;
	cin>>n;
	while(n!=0){
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
		}
		cout<<"Here you can do:"<<endl;
			cout<<"\t"<<"1. Withdrawal"<<endl;
			cout<<"\t"<<"2. Deposit"<<endl;
			cout<<"\t"<<"3. Transfer"<<endl;
			cout<<"\t"<<"0. Exit"<<endl;
			cout<<"Enter a number to keep running:";
		int n;
		cin>>n;
	}
>>>>>>> d643bf78c6c0972e5bb84d933167bdf1c8d7e158
	logout();
}

void Client::logout(){

}
<<<<<<< HEAD
=======

>>>>>>> d643bf78c6c0972e5bb84d933167bdf1c8d7e158
