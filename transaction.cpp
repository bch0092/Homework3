//code for transaction struct here
#include "transaction.h"

using namespace std;

transaction::transaction(int transaction_num, Person transaction_customer, product transaction_product, int transaction_quantity)
{
    transaction_number = transaction_num;
    customer = transaction_customer;
    purchased_item = transaction_product;
    quantity = transaction_quantity;
}

transaction::transaction()
{
    transaction_number = 0;
    customer = Person();
    purchased_item = product();
    quantity = 0;
}

string transaction::transaction_info()
{
    return "Transaction #: " + to_string(transaction_number) + "\nCustomer:" + customer.person_info() + "Product:" + purchased_item.product_info() + "\nQuantity: " + to_string(quantity) + "\n";
}  

//All this is very similar to previous cpp files so I'm not gonna leave a ton of comments here