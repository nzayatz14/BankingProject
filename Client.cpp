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

		int n,stop1=0;

		//loop to check the if the input of option is valid
		do{
			cout<<"Please select an account you want to withdraw money from:"
					<<endl<<"1. Checking"
					<<endl<<"2. Saving"
					<<endl<<"0. Exit"
					<<endl<<"Please enter a number:";
			try{
				cin>>n;
				if((!cin))
					throw 1;
				else if(n==1 || n==2 || n==0)
					stop1=1;
				else
					throw 1;
			}
			catch(int a){
				n=0;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"Please enter a valid number."<<endl;
			}
		}while(stop1!=1);

		//check if the user want to quit the current operation
		if(n!=0){
			double m;
			int stop2=0;
			//loop to check if the input of money is valid
			do{
				cout<<"Please enter how much you want to withdraw from your account:";
				try{
					cin>>m;
					if((!cin))
						throw 2;
					else if(m>0)
						stop2=1;
					else
						throw 2;
				}
				catch(int b){
					m=0;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
					cout<<"Please enter a valid number."<<endl;
				}
			}while(stop2!=1);

			//update the money in both account
			if(heldAccount[n-1].getMoney()<m)
				cout<<"Sorry, there is insufficient money in your account."<<endl;
			else{
				heldAccount[n-1].setMoney(heldAccount[n-1].getMoney()-m);
				cout<<"Process succeeds."<<endl;
				viewInternalAccount();
			}
		}
}
void Client::deposit(){
		heldAccount[0].displayInternalAccount();
		heldAccount[1].displayInternalAccount();
		int n,stop1=0;
		//loop to check if the input of option is valid
		do{
			cout<<"Please select an account you want to deposit money to:"
				<<endl<<"1. Checking"
				<<endl<<"2. Savings"
				<<endl<<"0. Exit"
				<<endl<<"Please enter a number:";
			try{
				cin>>n;
				if(!cin)
					throw 1;
				else if(n==1 || n==2 ||n==0)
					stop1=1;
				else
					throw 1;
			}
			catch(int a){
				n=0;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"Please enter a valid number."<<endl;
			}
		}while(stop1!=1);

		//check if the user wants to quit the current operation
		if(n!=0){
			double m;
			int stop2=0;
			//loop to check if the input of money is valid
			do{
				cout<<"Please enter how much you want to deposit into the account:";
				try{
					cin>>m;
					if(!cin)
						throw 2;
					else if(m>0)
						stop2=1;
					else
						throw 2;
				}
				catch(int b){
					m=0;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
					cout<<"Please enter a valid number."<<endl;
				}
			}while(stop2!=1);

			//update the money in the account
			heldAccount[n-1].setMoney(heldAccount[n-1].getMoney()+m);
			cout<<"Process succeeds."<<endl;
			viewInternalAccount();
		}
}
void Client::transfer(){
	heldAccount[0].displayInternalAccount();
	heldAccount[1].displayInternalAccount();
	int n,stop1=0;
	//loop to check if the input of option is valid
	do{
		cout<<"Please select an account you want to transfer money from:"
				<<endl<<"1. Checking"
				<<endl<<"2. Savings"
				<<endl<<"0. Exit"
				<<endl<<"Please enter a number:";
		try{
			cin>>n;
			if(!cin)
				throw 1;
			else if(n==1||n==2 ||n==0)
				stop1=1;
			else
				throw 1;
		}
		catch(int a){
			n=0;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"Please enter a valid number."<<endl;
		}
	}while(stop1!=1);

	if(n!=0){
		double m;
				int stop2=0;
				//loop to check if the input of money is valid
				do{
					cout<<"Please enter how much you want to transfer:";
					try{
						cin>>m;
						if(!cin)
							throw 2;
						else if(m>0)	//money needs to be positive
							stop2=1;
						else
							throw 2;
					}
					catch(int b){
						m=0;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(),'\n');
						cout<<"Please enter a valid number."<<endl;
					}
				}while(stop2!=1);

				//check if it's enough money
				if(heldAccount[n-1].getMoney()<m)	//check if enough money to do the operation
					cout<<"Sorry, the balance in this account is insufficient."<<endl;
				//update the money in accounts
				else{
					heldAccount[n-1].setMoney(heldAccount[n-1].getMoney()-m);//update the money in the account
					cout<<"Process succeeds."<<endl;
					switch(n-1){
						case 0:
							heldAccount[1].setMoney(heldAccount[1].getMoney()+m);//update the money in the other account
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

		//call what function the user wants to do
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
	ofstream clientFile;
	ostringstream ss;
	string accountNumb;
	ss<<accountNumber;
	accountNumb = ss.str();
	//get the file name in string format
	accountNumb = accountNumb + ".txt";

	//open the internalAccount text file, ex  1.txt
	clientFile.open(accountNumb.c_str());

	//overwrite all the information into the text file
	clientFile << userName << "\n";
	clientFile << password << "\n";
	clientFile << accountNumber << "\n\n";
	clientFile << name << "\n";
	clientFile << birthday << "\n";
	clientFile << gender << "\n";
	clientFile << phoneNumber << "\n";
	clientFile << address << "\n";
	clientFile << email << "\n\n";
	clientFile << heldAccount[0].getAccountType()<<endl;
	clientFile << heldAccount[0].getMoney() << "\n\n";
	clientFile << heldAccount[1].getAccountType()<<endl;
	clientFile << heldAccount[1].getMoney() << "\n";;

	//close up the text file
	clientFile.close();
}
