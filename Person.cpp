/*
 * Person.cpp
 *
 *  Created on: Feb 1, 2014
 *      Author: mac2nd
 */

#include "Person.h"

using namespace std;

Person::Person() {
	setPerson("name", "birthday", 'G', "phone", "address", "email", "user");
}

Person::~Person() {
	// TODO Auto-generated destructor stub
}

void Person::setName(string n)
{
	name = n;
}

string Person::getName()
{
	return  name;
}

void Person::setBirthday(string b)
{
	birthday = b;
}

string Person::getBirthday()
{
	return birthday;
}

void Person::setGender(char g)
{
	gender = g;
}

char Person::getGender()
{
	return gender;
}

void Person::setPhoneNumber(string p)
{
	phoneNumber = p;
}

string Person::getPhoneNumber()
{
	return  phoneNumber;
}

void Person::setAddress(string a)
{
	address = a;
}

string Person::getAddress()
{
	return address;
}

void Person::setEmail(string e)
{
	email = e;
}

string Person::getEmail()
{
	return email;
}

string Person::getUserName()
{
	return userName;
}

void Person::setUserName(string un)
{
	userName = un;
}

void Person::setPerson(string n, string b, char g, string p, string a, string e, string un)
{
	name = n;
	birthday = b;
	gender = g;
	phoneNumber = p;
	address = a;
	email = e;
	userName = un;
}

void Person::displayPersonalInformation()
{
	/*string n;
	n=Person.getName();
	cout<<n;
	*/
}
