#include <string>

#ifndef PRODUCT_H
#define PRODUCT_H

//a struct that can be used to capture
//product information
struct product
{
	//data members
	std::string name;
	std::string description;
	double price;

	//prints information about one transaction
	std::string product_info();

    //constructors//
    product(std::string product_name, std::string product_description, double product_price); 
    product();
};
#endif