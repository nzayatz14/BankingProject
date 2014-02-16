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
>>>>>>> 34ccad84ec6ba7d37c82bd1aedd71dcb34d7e832
}

Client::~Client() {
	// TODO Auto-generated destructor stub
	delete [] heldAccount;
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
>>>>>>> 34ccad84ec6ba7d37c82bd1aedd71dcb34d7e832
}

void Client::copyClient(Client &into){
	into.setHeldAccount(heldAccount[0],heldAccount[1]);
	into.setPerson(name, birthday, gender, phoneNumber, address, email, userName);
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
	cout<<"\t"<<"1.checking"<<endl;
	cout<<"\t"<<"2.saving"<<endl;
	cout<<"Please enter a number:";
>>>>>>> 34ccad84ec6ba7d37c82bd1aedd71dcb34d7e832
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
	cout<<"\t"<<"1.checking"<<endl;
	cout<<"\t"<<"2.saving"<<endl;
	cout<<"Please enter a number:";
>>>>>>> 34ccad84ec6ba7d37c82bd1aedd71dcb34d7e832
	int n;
	cin>>n;
	cout<<"Please enter how much you want to deposit into the account:";
	double m;
	cin>>m;
	heldAccount[n-1].setMoney(heldAccount[n-1].getMoney()+m);
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
=======
	cout<<"Please select an account you want to withdraw money from:"<<endl;
	cout<<"\t"<<"1.checking"<<endl;
	cout<<"\t"<<"2.saving"<<endl;
	cout<<"Please enter a number:";
>>>>>>> 34ccad84ec6ba7d37c82bd1aedd71dcb34d7e832
	int n;
	cin>>n;

	cout<<"Please enter how much you want to transfer:";
	double m;
	cin>>m;

	if(heldAccount[n-1].getMoney()<m)
<<<<<<< HEAD
		cout<<"Sorry, the balance in this account is insufficient."<<endl;
=======
		cout<<"Sorry, the balance in your account is sufficient."<<endl;
>>>>>>> 34ccad84ec6ba7d37c82bd1aedd71dcb34d7e832
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
		cout<<"\t"<<"0.Exit"<<endl;
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

	logout();
=======
	cout<<"Here you can do:"<<endl;
	cout<<"\t"<<"1.withdrawel"<<endl;
	cout<<"\t"<<"2.deposit"<<endl;
	cout<<"\t"<<"3.transfer"<<endl;
	cout<<"\t"<<"0.Exit"<<endl;
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
			cout<<"\t"<<"2.deposit"<<endl;
			cout<<"\t"<<"3.transfer"<<endl;
			cout<<"\t"<<"0.Exit"<<endl;
			cout<<"Enter a number to keep running:";
		int n;
		cin>>n;
	}
	logout();
}

void Client::logout(){


>>>>>>> 34ccad84ec6ba7d37c82bd1aedd71dcb34d7e832
}

void Client::logout(){


}
