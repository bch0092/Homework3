//implementation code for address struct here
#include "address.h"

using namespace std;

//Intializes a new instance of the address struct with the given variables.

address::address(string add_line_1, string add_line_2, string add_city, string add_state, string add_zip)
{
    address_line1 = add_line_1;
    address_line2 = add_line_2;
    city = add_city;
    state = add_state;
    zip = add_zip;
}

//Intializes an EMPTY new instance of the address struct, default values for all parameters(Homeless lowkey).

address::address()
{
    address_line1 = "";
    address_line2 = "";
    city = "";
    state = "";
    zip = "";
}

//Returns an elegant string with all our intialized info.

string address::address_info()
{
    return "\n" + address_line1 + "\n" + address_line2 + "\n" + city + ", " + state + "\n" + zip ;
}