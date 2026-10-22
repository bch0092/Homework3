//code for product struct here
#include "product.h"

#include <iomanip>
#include <sstream>

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

string product::product_info()
{
    std::stringstream output;
    output << std::fixed << std::setprecision(2);
    output << "\nProduct Name: " << name << "\nDescription: " << description << "\nPrice: $" << price;
    return output.str();
}