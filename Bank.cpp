/*
 * Bank.cpp
 *
 *  Created on: Feb 1, 2014
 *      Author: nzayatz14
 */

#include "Bank.h"
#include <fstream>
#include <sstream>
using namespace std;
Bank::Bank() {
	// TODO Auto-generated constructor stub
	ifstream in;
	bool empty = emptyFile("bank.txt");

	if(!empty){
		in.open("bank.txt");
		string user, pass;
		int accountNumber;
		totalAccounts=0;

		//getline(in, user);
		while(!in.eof()){
			in>>user;
			in>>pass;
			in>>accountNumber;

			ExternalAccount temp;
			temp.setAccountNumber(accountNumber);
			temp.setPassword(pass);

			ifstream acct;
			ostringstream ss;
			string accountNumb;
			ss<<accountNumber;
			accountNumb = ss.str();
			accountNumb = accountNumb + ".txt";
			acct.open(accountNumb.c_str());

			string no;
			//read in data
			getline(acct,no);
			getline(acct,no);
			getline(acct,no);
			getline(acct,no);

			if(user.compare("admin") != 0){
				Client person;
				string name,birthday,phone,address,email;
				char gender;
				getline(acct,name);
				getline(acct,birthday);
				acct>>gender;
				getline(acct,no);
				getline(acct,phone);
				getline(acct,address);
				getline(acct,email);
				getline(acct,no);
				person.setPerson(name, birthday, gender, phone,address,email,user);
				person.setAccountNumber(accountNumber);
				person.setPassword(pass);

				InternalAccount accounts[2];
				accounts[0].setUsername(user);
				accounts[1].setUsername(user);

				string account1;
				getline(acct,account1);
				accounts[0].setAccountType(account1);

				double money1;
				acct>>money1;
				accounts[0].setMoney(money1);

				getline(acct,no);
				getline(acct,no);

				string account2;
				getline(acct,account2);
				accounts[1].setAccountType(account2);

				double money2;
				acct>>money2;
				accounts[1].setMoney(money2);

				temp.setAccountHolder(person);
				temp.setInternalAccounts(accounts[0],accounts[1]);
			}

			acct.close();

			//create externalAccount and Person and internalAccounts based on data

			bank.insert(make_pair<string,ExternalAccount>(user, temp));
			totalAccounts = bank.size();
		}

		in.close();
	}else{
		cout<<"No Bank File can be found."<<endl;
	}
}

Bank::~Bank() {
	// TODO Auto-generated destructor stub
}

int Bank::getTotalAccounts(){
	return totalAccounts;
}

void Bank::setTotalAccounts(int g){
	totalAccounts = g;
}

void Bank::printBank(){
	cout<<"\nUsername:\tPassword:\tAccount Number:"<<endl;
	for(auto &i : bank){
		ExternalAccount temp = i.second;
		string userName = i.first;
		cout<< userName<<"\t"<< temp.getPassword()<<"\t"<< temp.getAccountNumber()<<endl;
	}
	cout<<"\n";
}

void Bank::createExternalAccount(Client &a, string pass){
	ExternalAccount n;
	n.setAccountHolder(a);
	n.setPassword(pass);
	n.createInternalAccounts();
	string user = a.getUserName();
	totalAccounts++;
	n.setAccountNumber(totalAccounts);
	cout<<user<<" ";
	n.displayExternalAccount();
	bank.insert(make_pair<string,ExternalAccount>(user, n));
	cout<<"insert"<<endl;

}

void Bank::deleteExternalAccount(string user){
	bank.erase(user);
	totalAccounts--;
}

void Bank::find(string user, ExternalAccount &a){
	unordered_map<string,ExternalAccount>::const_iterator found = bank.find (user);
	if(found != bank.end()){
		ExternalAccount temp = found->second;
		temp.copyExternalAccount(a);
	}

}

void Bank::updateAccount(string user, ExternalAccount &a){
	bank[user] = a;
}

void Bank::logout(){
	ofstream bankFile;
	bankFile.open("bank.txt");
	//bankFile<<"admin admin 1"<<endl;

	for(auto &i : bank){
		ExternalAccount temp = i.second;
		string userName = i.first;
		bankFile<< userName<<" "<< temp.getPassword()<<" "<< temp.getAccountNumber()<<endl;

		if(userName.compare("admin") != 0){
			Client c;
			Client *cPtr = &c;
			temp.getAccountHolder(cPtr);
<<<<<<< HEAD
=======
			cout<<c.getName();
>>>>>>> 713f706f9743562f101c9448fb4d01b3193833dd

			ofstream acctFile;
			ostringstream ss;
			string adminNumb;
			ss<<temp.getAccountNumber();
			adminNumb = ss.str();
			adminNumb = adminNumb + ".txt";
			InternalAccount things[2];
			temp.getInternalAccounts(things[0],things[1]);

			acctFile.open(adminNumb.c_str());
			acctFile << c.getUserName() << "\n";
			acctFile << temp.getPassword() << "\n";
			acctFile << temp.getAccountNumber() << "\n\n";
			acctFile << c.getName() << "\n";
			acctFile << c.getBirthday() << "\n";
			acctFile << c.getGender() << "\n";
			acctFile << c.getPhoneNumber() << "\n";
			acctFile << c.getAddress() << "\n";
			acctFile << c.getEmail() << "\n\n";
			acctFile << things[0].getAccountType()<<endl;
			acctFile << things[0].getMoney() << "\n\n";
			acctFile << things[1].getAccountType()<<endl;
			acctFile << things[1].getMoney() << "\n";
			acctFile.close();
		}
	}

	bankFile.close();
}

bool Bank::emptyFile(string st){
	ifstream in;
	in.open(st.c_str());
	int count = 0;
	string temp;
	getline(in, temp);

	if(temp.length() != 0)
		count++;

	in.close();
	if(count == 0)
		return true;
	else
		return false;
}
