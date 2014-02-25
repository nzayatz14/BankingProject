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

	//create a file stream and check to see if bank.txt is empty
	ifstream in;
	bool empty = emptyFile("bank.txt");

	//if bank.txt is not empty, do stuff, if it is, print that it is empty
	if(!empty){
		//open bank.txt and declare variables
		in.open("bank.txt");
		string user, pass;
		int accountNumber;
		totalAccounts=0;
		currentAccount = -1;

		//until the end of bank.txt
		while(!in.eof()){

			//read in the userName, password, and account number
			in>>user;
			in>>pass;
			in>>accountNumber;

			//create an externalAccount and set the account number and password
			ExternalAccount temp;
			temp.setAccountNumber(accountNumber);
			temp.setPassword(pass);

			//keep track of the next potential account that needs to be made
			if(accountNumber>currentAccount){
				currentAccount = accountNumber;
			}

			//if the user being read in is not the admin
			if(user.compare("admin") != 0){

				//open <account number>.txt
				ifstream acct;
				ostringstream ss;
				string accountNumb;
				ss<<accountNumber;
				accountNumb = ss.str();
				accountNumb = accountNumb + ".txt";
				acct.open(accountNumb.c_str());

				//temporary string used to read in insignificant lines
				string no;

				//read in lines not needed
				getline(acct,no);
				getline(acct,no);
				getline(acct,no);
				getline(acct,no);

				//create a client and read in all of the informaton, then set the clients information to the read in information
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

				//create 2 internalAccounts and set the username of the holder to the username of the current client
				InternalAccount accounts[2];
				accounts[0].setUsername(user);
				accounts[1].setUsername(user);

				//read in the account type and money amount of each account, then set those values to the values of
				//accounts[0] and accounts[1]
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

				//set the external accounts holder to the newly created client and set the internal accounts of
				//that external account to the newly created internalAccounts
				temp.setAccountHolder(person);
				temp.setInternalAccounts(accounts[0],accounts[1]);

				//close the <account number>.txt
				acct.close();
			}

			//insert the new externalAccount to the bank with the username input and increment the bank size
			bank.insert(make_pair<string,ExternalAccount>(user, temp));
			totalAccounts = bank.size();
		}

		//close bank.txt
		in.close();
	}else{
		cout<<"No Bank File can be found."<<endl;
	}
}

Bank::~Bank() {
	// TODO Auto-generated destructor stub
}

//return the total number of accounts
int Bank::getTotalAccounts(){
	return totalAccounts;
}

//set the total number of accounts to g
void Bank::setTotalAccounts(int g){
	totalAccounts = g;
}

//go through the bank and print the username, password, and account number of each account
void Bank::printBank(){
	cout<<"\nUsername:\tPassword:\tAccount Number:"<<endl;
	for(auto &i : bank){
		ExternalAccount temp = i.second;
		string userName = i.first;
		cout<< userName<<"\t"<< temp.getPassword()<<"\t"<< temp.getAccountNumber()<<endl;
	}
	cout<<"\n";
}

//Pre: takes in a new client and the password of the new account
//Post: inserts the new account into the bank
void Bank::createExternalAccount(Client &a, string pass){

	//create an new account and set its account holder, password, and internal accounts
	ExternalAccount n;
	n.setAccountHolder(a);
	n.setPassword(pass);
	n.createInternalAccounts();

	//increment the totalNumber of accounts
	totalAccounts++;
	currentAccount++;
	n.setAccountNumber(currentAccount);

	//get the userName of the new person, make the pair for the unordered_map, and put it into bank.
	//Also, print the general information of the newly created account
	string user = a.getUserName();
	cout<<user<<" ";
	n.displayExternalAccount();
	bank.insert(make_pair<string,ExternalAccount>(user, n));

}

//Pre:takes in the user name of the account to be deleted
//Post:erases the account from bank and increments the totalAccounts as needed
void Bank::deleteExternalAccount(string user){
	bank.erase(user);
	totalAccounts--;
}

//Pre: takes in the userName of the account trying to be found and a pass by reference ExternalAccount
//to return the externalAccount
//Post: if the account with the specific userName is found, copy it to the pass by reference externalAccount
//to be returned
void Bank::find(string user, ExternalAccount &a){
	unordered_map<string,ExternalAccount>::const_iterator found = bank.find (user);
	if(found != bank.end()){
		ExternalAccount temp = found->second;
		temp.copyExternalAccount(a);
	}

}

//Pre: takes in the userName of the account that needs to be updated and an account with the new account information
//Post: sets the externalAccount in bank with the given userName to the provided externalAccount
void Bank::updateAccount(string user, ExternalAccount &a){
	bank[user] = a;
}

//Pre: none
//Post: re-writes bank.txt based on the information in each externalAccount in bank and
//re-writes each <account number>.txt with the information in the clients who hold those externalAccounts
void Bank::logout(){

	//create a file stream and open bank.txt
	ofstream bankFile;
	bankFile.open("bank.txt");

	//for each externalAccount in bank
	for(auto &i : bank){

		//write to bank.txt the username, password, and account number of each account
		ExternalAccount temp = i.second;
		string userName = i.first;
		bankFile<< userName<<" "<< temp.getPassword()<<" "<< temp.getAccountNumber()<<endl;

		//if the user is not the admin, write over the information in <account number>.txt
		if(userName.compare("admin") != 0){

			//get the client of the externalAccount
			Client c;
			Client *cPtr = &c;
			temp.getAccountHolder(cPtr);

			//open a new file stream and open the text file of the corresponding account
			ofstream acctFile;
			ostringstream ss;
			string adminNumb;
			ss<<temp.getAccountNumber();
			adminNumb = ss.str();
			adminNumb = adminNumb + ".txt";

			//get the internal accounts in the externalAccount
			InternalAccount things[2];
			temp.getInternalAccounts(things[0],things[1]);

			//write all of the information to the <account number>.txt and close the file stream
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

	//close bank.txt
	bankFile.close();
}

//Pre: takes in the name of the file
//Post: if the file is empty, return true, else return false
bool Bank::emptyFile(string st){
	//open the file
	ifstream in;
	in.open(st.c_str());
	int count = 0;

	//get the first line of the file
	string temp;
	getline(in, temp);

	//close the file
	in.close();

	//if the length of the first line is not 0, its not empty, if it is, it is empty
	if(temp.length() != 0)
		return false;
	else
		return true;
}
