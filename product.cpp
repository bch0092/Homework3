//code for product struct here

#include <iostream>
#include "product.h"

using namespace std;

//This method initializes a new instance from the product class with the given variables.

product::product(string product_name, string product_description, double product_price)
{
    name = product_name;
    description = product_description;
    price = product_price;
}

//Creates a new product with default parameters(Empty).

product::product()
{
    name = "";
    description = "";
    price = 0.0;
}

//Returns a nice, pretty string with all parameters.

product::product_info()
{
    return "Product Name: " + name + "\nDescription: " + description + "\nPrice: $" + to_string(price);
}
