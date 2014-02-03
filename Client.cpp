
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

}

Client::~Client() {
	// TODO Auto-generated destructor stub
}

void Client::viewExternalAccount(){
	ExternalAccount::displayExternalAccount();
}

void Client::withdraw(){
	cout<<"Please enter the account name you wish to withdraw money"<<
			"from:";
	string acc;
	cin>>acc;

}
void Client::deposit(){
	cout<<"Please enter the account you want to deposit into:";
	string acc;
	cin>>acc;
	cout<<"How much do you want to deposit into the account:";
	double m;
	cin>>m;


}
void Client::transfer(){
	cout<<"Please enter the account you want to transfer from:"
	string acc;
	cin>>acc;
	cout<<"How much do you want to transfer with:";
	double m;
	cin>>m;


}
void Client::printOptions(){
	cout<<"Here you can do: 1.Withdrawl 2.deposit 3.transfer,"<<
			"enter the number to keep running: ";
	int n;
	cin>>n;
	switch(n):

}


