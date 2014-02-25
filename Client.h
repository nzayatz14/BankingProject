/*
 * Client.h
 *
 *  Created on: Feb 1, 2014
 *      Author: Junjieliao
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Person.h"
#include "InternalAccount.h"

using namespace std;

class Client: public Person {
public:
<<<<<<< HEAD
		Client();//default Constructor
		virtual ~Client();//default destructor
		Client(InternalAccount &a, InternalAccount &b);
		//Constructor that copies the information from
		//other two InternalAccounts and store the information
		//into member heldAccount[0] and heldAccount[1]

		void getHeldAccount(InternalAccount &a, InternalAccount &b);
		//Function passes heldAccounts from other internalAccounts' heldAccounts.
		//to the local member heldAccouts
		//Pass the information of heldAccounts from other input InternalAccounts,
		//and store them into the local member heldAccount

		void setHeldAccount(InternalAccount &a, InternalAccount &b);
		//Function sets the heldAccounts for the other two InternalAccounts' members
		//Pass the information from the local member heldAccount to the members
		//heldAccounts to the other input InternalAccounts' heldAccounts

		void copyClient(Client &into);
		//Function copies information from local client to the input client
		//Pass the information from local heldAccounts to the input Client' heldAccounts;
		//pass the information of a person like name, birthday, gender, phone number,
		//address, email and user name to the input Client;
		//pass the password from local password to the input Client;
		//pass the account number from local password to the input Client

		void viewInternalAccount();
		//function calls displayExternalAccount()

		void withdraw();
		//ask the user which account they wish to withdraw from and how much
		//check to see that money is less than the total amount of money
		//in the account.If it is, subtract that money from the account,
		//or else print an error message

		void deposit();
		//ask the user what account they wish to deposit form and how much
		//add that money to the account

		void transfer();
		//ask the user what account they wish to transfer from and how
		//much money, check to see that money is less than the total
		//amount of money in the account.If it is, ask which account they
		//want to transfer this money into and make the transfer, or else
		//print an error message

		void printOptions();
		//print and number the capabilities of the client(make a
		//withdrawal, deposit of transfer)
		//ask the option which the user wants to do(by number)and call
		//the respective function

		void logout();
		//overwrite all the information which means all the values of all members
		//back into the account-number-corresponding text file

=======
	Client();//Constructor
	Client(InternalAccount &a, InternalAccount &b);
	//Constructor that copies the information from
	//other two InternalAccounts and store the information
	//into member heldAccount[0] and heldAccount[1]

	void getHeldAccount(InternalAccount &a, InternalAccount &b);
	//Function passes heldAccounts from other internalAccounts' heldAccounts.
	//to the local member heldAccouts
	//Pass the information of heldAccounts from other input InternalAccounts,
	//and store them into the local member heldAccount

	void setHeldAccount(InternalAccount &a, InternalAccount &b);
	//Function sets the heldAccounts for the other two InternalAccounts' members
	//Pass the information from the local member heldAccount to the members
	//heldAccounts to the other input InternalAccounts' heldAccounts

	void copyClient(Client &into);
	//Function copies information from local client to the input client
	//Pass the information from local heldAccounts to the input Client' heldAccounts;
	//pass the information of a person like name, birthday, gender, phone number,
	//address, email and user name to the input Client;
	//pass the password from local password to the input Client;
	//pass the account number from local password to the input Client

	void viewInternalAccount();
	//function calls displayExternalAccount()

	void withdraw();
	//ask the user which account they wish to withdraw from and how much
	//check to see that money is less than the total amount of money
	//in the account.If it is, subtract that money from the account,
	//or else print an error message

	void deposit();
	//ask the user what account they wish to deposit form and how much
	//add that money to the account

	void transfer();
	//ask the user what account they wish to transfer from and how
	//much money, check to see that money is less than the total
	//amount of money in the account.If it is, ask which account they
	//want to transfer this money into and make the transfer, or else
	//print an error message

	void printOptions();
	//print and number the capabilities of the client(make a
	//withdrawal, deposit of transfer)
	//ask the option which the user wants to do(by number)and call
	//the respective function

	void logout();
	//overwrite all the information which means all the values of all members
	//back into the account-number-corresponding text file
>>>>>>> 2ead286fa2377be4ae263db42b0d5c416c0b3264

protected:
	InternalAccount heldAccount[2];//length-two array variable
};


#endif /* CLIENT_H_ */
