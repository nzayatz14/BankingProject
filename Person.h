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
	Person();
	virtual ~Person();
	void setName(string);
	string getName();
	void setBirthday(string);
	string getBirthday();
	void setGender(char);
	char getGender();
	void setPhoneNumber(string );
	string getPhoneNumber();
	void setAddress(string);
	string getAddress();
	void setEmail(string);
	string getEmail();
	void setUserName(string);
	string getUserName();
	void setPerson(string, string, char, string, string, string, string);
	void displayPersonalInformation();

	virtual void printOptions() = 0;

protected:
	string name;
	string birthday;
	char gender;
	string phoneNumber;
	string address;
	string email;
	string userName;
};

#endif /* PERSON_H_ */
