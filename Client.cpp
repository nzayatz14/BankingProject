/*
 * Client.cpp
 *
 *  Created on: Feb 1, 2014
 *      Author: Junjieliao
 */

#include<iostream>
#include<fstream>
#include<sstream>
#include "Client.h"

using namespace std;

Client::Client() {


}

Client::Client(InternalAccount &a, InternalAccount &b){
	a.copyInternalAccount(heldAccount[0]);
	b.copyInternalAccount(heldAccount[1]);

}

Client::~Client() {
	// TODO Auto-generated destructor stub
}

void Client::setHeldAccount(InternalAccount &a,InternalAccount &b){
	a.copyInternalAccount(heldAccount[0]);
	b.copyInternalAccount(heldAccount[1]);
}

void Client::getHeldAccount(InternalAccount &a,InternalAccount &b){
	heldAccount[0].copyInternalAccount(a);
	heldAccount[1].copyInternalAccount(b);
}

void Client::copyClient(Client &into){
	into.setHeldAccount(heldAccount[0],heldAccount[1]);
	into.setPerson(name, birthday, gender, phoneNumber, address, email, userName);
	into.setPassword(password);
	into.setAccountNumber(accountNumber);
}

void Client::viewInternalAccount(){
	heldAccount[0].displayInternalAccount();
	heldAccount[1].displayInternalAccount();
}

void Client::withdraw(){
	heldAccount[0].displayInternalAccount();
	heldAccount[1].displayInternalAccount();
	cout<<"Please select an account you want to withdraw money from:"
			<<endl<<"1. Checking"
			<<endl<<"2. Saving"
			<<endl<<"Please enter a number:";

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

	heldAccount[0].displayInternalAccount();
	heldAccount[1].displayInternalAccount();
	cout<<"Please select an account you want to deposit money to:"
			<<endl<<"1. Checking"
			<<endl<<"2. Savings"
			<<endl<<"Please enter a number:";

	int n;
	cin>>n;
	cout<<"Please enter how much you want to deposit into the account:";
	double m;
	cin>>m;
	heldAccount[n-1].setMoney(heldAccount[n-1].getMoney()+m);
	viewInternalAccount();
}
void Client::transfer(){
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
			heldAccount[1].setMoney(heldAccount[1].getMoney()+m);
			break;
		case 1:
			heldAccount[0].setMoney(heldAccount[0].getMoney()+m);
			break;
		default:
			break;
		}
	}
	viewInternalAccount();
}

void Client::printOptions(){
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
}

void Client::logout(){
<<<<<<< HEAD
	ofstream clientFile;
	ostringstream ss;
	string accountNumb;
	ss<<accountNumber;
	accountNumb = ss.str();
	accountNumb = accountNumb + ".txt";

	clientFile.open(accountNumb.c_str());

	clientFile << userName << "\n";
	clientFile << password << "\n";
=======
	std::ofstring clientFile;
	ostringstream ss;
	string clientNumb;
	ss<<accountNumber;
	clientNumb = ss.str();
	clientNumb = clientNumb + ".txt";
	acct.open(accountNumb.c_str());
	clientFile << userName << "\n";
	clientFile << pass << "\n";
>>>>>>> 713f706f9743562f101c9448fb4d01b3193833dd
	clientFile << accountNumber << "\n\n";
	clientFile << name << "\n";
	clientFile << birthday << "\n";
	clientFile << gender << "\n";
<<<<<<< HEAD
	clientFile << phoneNumber << "\n";
	clientFile << address << "\n";
	clientFile << email << "\n\n";
	clientFile << heldAccount[0].getAccountType()<<endl;
	clientFile << heldAccount[0].getMoney() << "\n\n";
	clientFile << heldAccount[1].getAccountType()<<endl;
	clientFile << heldAccount[1].getMoney() << "\n";;

	clientFile.close();
=======
	clientFile << phone << "\n";
	clientFile << address << "\n";
	clientFile << email << "\n\n";
	clientFile << "Checking\n";
	clientFile << money1 << "\n\n";
	clientFile << "Savings\n";
	clientFile << money2 << "\n";
	adminFile.close();

>>>>>>> 713f706f9743562f101c9448fb4d01b3193833dd
}
