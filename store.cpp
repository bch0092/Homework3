//code for store class here
#include "store.h"

#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

//we only declare Store() in store.h, so i dont think we need this//
/*
//Intializes a grand, new store with all our variables set as parameters.

Store::Store(int num_customers, int num_products, int num_transactions)
{
    num_customers_ = num_customers;
    num_products_ = num_products;
    num_transactions_ = num_transactions;
}
*/

//Initializes a store with no name, address, no nothing. Dare I say, it's imaginary.

Store::Store()
{
    num_customers_ = 0;
    num_products_ = 0;
    num_transactions_ = 0;
}

void Store::num_customers(int customer_count)
{
    if (customer_count >= 0 && customer_count <= 100) {
        num_customers_ = customer_count;
    }
}

int Store::num_customers()
{
    return num_customers_;
}

void Store::num_products(int product_count)
{
    if (product_count >= 0 && product_count <= 100) {
        num_products_ = product_count;
    }
}

int Store::num_products()
{
    return num_products_;
}

void Store::num_transactions(int transaction_count)
{
    if (transaction_count >= 0 && transaction_count <= 100) {
        num_transactions_ = transaction_count;
    }
}


int Store::num_transactions()
{
    return num_transactions_;
}

bool Store::add_customer(Person customer)
{

    //Ensures we aren't crossing the customer limit
    if (num_customers_ < 100)
    {
        //Iterates and creates a new customer from the list!
        customers_[num_customers_] = customer;
        num_customers_++;
        return true;
    }
    else
    {
        //Returns false because our store is not goated enough to hold more than 100 customers.
        return false;
    }
}   

bool Store::update_customer(int index, Person customer)
{
    //Updates the customer's info
    if (index >= 0 && index < num_customers_)
    {
        customers_[index] = customer;
        return true;
    }
    else
    {
        return false;
    }
}

Person Store::get_customer(int index)
{
    //Returns the customer at the specified index
    if (index >= 0 && index < num_customers_)
    {
        return customers_[index];
    }
    else
    {
        return Person();
    }
}

bool Store::add_product(product item)
{
    //Ensures we aren't crossing the product limit
    if (num_products_ < 100)
    {
        //Iterates and creates a new product from the list
        products_[num_products_] = item;
        num_products_++;
        return true;
    }
    else
    {
        //Returns false because our store is not goated enough to hold more than 100 products.
        return false;
    }
}

product Store::get_product(int index)
{
    //Returns the product at the specified index
    if (index >= 0 && index < num_products_)
    {
        return products_[index];
    }
    else
    {
        return product();
    }
}

bool Store::add_transaction(transaction ntransaction)
{
    //Ensures we aren't crossing the transaction limit
    if (num_transactions_ < 100)
    {
        //Iterates and creates a new transaction from the list
        transactions_[num_transactions_] = ntransaction;
        num_transactions_++;
        return true;
    }
    else
    {
        //Returns false because our store is not goated enough to hold more than 100 transactions.
        return false;
    }
}

transaction Store::get_transaction(int index)
{
    //Returns the transaction at the specified index
    if (index >= 0 && index < num_transactions_)
    {
        return transactions_[index];
    }
    else
    {
        return transaction();
    }
}

bool Store::make_purchase(Person customer, product item, int quantity)
{
    //checks validity of quantity//
    if (quantity > 0 && num_transactions_ < 100)
    {
        //finds customer//
        int index = find_customer(customer);

        if (index >= 0)
        {
            //stores customer in store//
            Person stored_customer = customers_[index];

            //copies customer's cc//
            credit_card card = stored_customer.person_credit_card();

            //calculates total cost//
            double total_cost = item.price * quantity;

            //attempts to make purchase//
            if (card.make_purchase(total_cost))
            {
                //updates customer's cc//
                stored_customer.person_credit_card(card);
                customers_[index] = stored_customer;

                //creates new transaction//
                transaction new_transaction;
                new_transaction.transaction_number = num_transactions_ + 1;
                new_transaction.customer = stored_customer;
                new_transaction.purchased_item = item;
                new_transaction.quantity = quantity;

                //adds transaction to store//
                if (add_transaction(new_transaction))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                //insufficient funds//
                return false;
            }
        }
        else
        {
            //customer not found//
            return false;
        }
    }
    else
    {
        //invalid quantity or transaction limit reached//
        return false;
    }

    //doesn't save the updated cc//
    /*
    //Calculates the total cost of the purchase
    double total_cost = item.price * quantity;

    //Attempts to make a purchase using the customer's credit card
    if (customer.person_credit_card().make_purchase(total_cost))
    {
        //If successful, creates a new transaction and adds it to the store's transactions
        transaction new_transaction;
        new_transaction.transaction_number = num_transactions_ + 1;
        new_transaction.customer = customer;
        new_transaction.purchased_item = item;
        new_transaction.quantity = quantity;

        add_transaction(new_transaction);
        return true;
    }
    else
    {
        //If unsuccessful, returns false(BROKE)
        return false;
    }
    */
}

string Store::product_info()
{
    //Returns a string listing all products associated with this store
    string info = "Products:\n";
    //For loop since we know the ending point/number of times it would need to iterate
    for (int i = 0; i < num_products_; i++)
    {
        info += products_[i].product_info() + "\n\n";
    }
    return info;
}

string Store::transaction_info()
{
    //Returns a string listing all transactions associated with this store
    string info = "All Transactions:\n";
    if (num_transactions_ > 0)
    {
        info += "\n";
    }
    //Same deal as above, lowkey
    for (int i = 0; i < num_transactions_; i++)
    {
        info += transactions_[i].transaction_info() + "\n\n";
    }
    return info;
}

string Store::customer_info()
{
    //Returns a string listing all customers associated with this store
    string info = "Customers:\n";
    //Love me some for loops(Why did I ever even do a comment for the first, gonna stop now)
    for (int i = 0; i < num_customers_; i++)
    {
        info += customers_[i].person_info() + "\n";
    }
    return info;
}

string Store::store_info()
{
    //Returns a string listing all information about this store (transactions and products)
    string info = "Store info:\n\n";
    info += customer_info() + "\n";
    info += product_info() + "\n";
    info += transaction_info() + "\n";
    return info;
}

string Store::purchase_history(Person customer)
{
    //Searches through the transactions_[] and returns a string representing all transactions that belong to a specific customer
    string info = "Purchase History for " + customer.name() + ":\n";
    for (int i = 0; i < num_transactions_; i++)
    {
        if (transactions_[i].customer.name() == customer.name())
        {
            info += transactions_[i].transaction_info() + "\n";
        }
    }

    //They're gonna see all the Great Value donuts they bought
    return info;
}

int Store::find_customer(Person customer)
{
    //Given a customer, returns the index in the customer_[] where that customer is located
    for (int i = 0; i < num_customers_; i++)
    {
        if (customers_[i].name() == customer.name())
        {
            return i;
        }
    }
    //If not found, returns -1
    return -1;
}