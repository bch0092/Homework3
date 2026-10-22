//code for person class here
#include "person.h"

using namespace std;

//Initalizes a new instance of the Person class with the given variables.

Person::Person(string name, string phone, address person_address, credit_card person_credit_card)
{
    name_ = name;
    phone_ = phone;
    person_address_ = person_address;
    person_credit_card_ = person_credit_card;
}

//Intializes an EMPTY new instance from the Person class, default values for all parameters(Broke).

Person::Person()
{
    name_ = "";
    phone_ = "";
    person_address_ = address();
    person_credit_card_ = credit_card();
}

//Sets name_ as name

void Person::name(string name)
{
    name_ = name;
}

//Returns name_.

string Person::name()
{
    return name_;
}

//Sets phone_ as phone

void Person::phone(string phone)
{
    phone_ = phone;
}

//Returns phone_.

string Person::phone()
{
    return phone_;
}

//Sets person_address_ as person_address

void Person::person_address(address person_address)
{
    person_address_ = person_address;
}

//Returns person_address_.

address Person::person_address()
{
    return person_address_;
}

//Sets person_credit_card_ as person_credit_card

void Person::person_credit_card(credit_card person_credit_card)
{
    person_credit_card_ = person_credit_card;
} 

//Returns person_credit_card_.

credit_card Person::person_credit_card()
{
    return person_credit_card_;
}

//Returns a big, fat string with all our parameter info. Dadgum.

string Person::person_info()
{
    return "\nName: " + name_ + "\nPhone: " + phone_ + "\nAddress: " + person_address_.address_info() + "\nCredit Card: " + person_credit_card_.credit_card_info() + "\n";
}