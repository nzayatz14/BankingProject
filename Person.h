/*
 * Person.h
 *
 *  Created on: Feb 1, 2014
 *      Author: nzayatz14
 */

#ifndef PERSON_H_
#define PERSON_H_

namespace std {

class Person {
public:
	Person();
	virtual ~Person();
	void setName(string);
	string getName();
	void setBirthday(string);
	string getBirthday();
	void setGender(char);
	string getGender();
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

private:
	string name;
	string birthday;
	char gender;
	string phoneNumber;
	string address;
	string email;
	string userName;
};

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

string Person::getGender()
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

void setPerson(string n, string b, char g, string p, string a, string e, string un)
{

}

void displayPersonalInformation()
{
	/*string n;
	n=Person.getName();
	cout<<n;
	*/
}

void printOptions()
{

}
}

#endif /* PERSON_H_ */
