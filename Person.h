/*
 * Person.h
 *
 *  Created on: Feb 1, 2014
 *      Author: mac2nd
 */
#include <iostream>
#ifndef PERSON_H_
#define PERSON_H_

using namespace std;

class Person {
public:
	Person();	// constructor for person
	virtual ~Person();	// destructor for person
	void setName(string);	// sets the name given to a string
	string getName();	// returns the name
	void setBirthday(string);	// sets the Birthday to a string
	string getBirthday();	// returns the birthday
	void setGender(char);	// sets the gender given to a char
	char getGender();	// returns the gender
	void setPhoneNumber(string);	// sets the phone number to a given string
	string getPhoneNumber();	// returns the phone number
	void setAddress(string);	// sets the address to a given string
	string getAddress();	// returns the address
	void setEmail(string);	// sets the Email to a given string
	string getEmail();	// returns the Email to a given string
	void setUserName(string);	// sets the username to a given string
	string getUserName();	// returns the username
	void setPerson(string, string, char, string, string, string, string); // sets all the values given to a person
	void displayPersonalInformation(); // returns all information regarding a specific person
	void setAccountNumber(int);	// sets the account number to a given int
	int getAccountNumber();	// returns the account number
	void setPassword(string);	// sets the password to a string 
	string getPassword();	// returns the password

	virtual void printOptions() = 0;	// virtual function that will be in both admin and client class
	virtual void logout() = 0;

protected:	// protected variables used in functions
	string name;
	string birthday;
	char gender;
	string phoneNumber;
	string address;
	string email;
	string userName;
	int accountNumber;
	string password;
};

#endif /* PERSON_H_ */

