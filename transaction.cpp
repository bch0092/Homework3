//code for transaction struct here
#include "transaction.h"

using namespace std;

transaction::transaction(int transaction_number, Person customer, product purchased_item, int quantity)
{
    transaction_number = transaction_number;
    customer = customer;
    purchased_item = purchased_item;
    quantity = quantity;
}

transaction::transaction()
{
    transaction_number = 0;
    customer = Person();
    purchased_item = product();
    quantity = 0;
}

transaction::transaction_info()
{
    return "Transaction Number: " + to_string(transaction_number) + "\nCustomer Info:\n" + customer.person_info() + "\nPurchased Item Info:\n" + purchased_item.product_info() + "\nQuantity: " + to_string(quantity);
}  

//All this is very similar to previous cpp files so I'm not gonna leave a ton of comments here
