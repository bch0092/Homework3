#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::string;

int main()
{
//import from text files

    //create store//
    Store store1;

    //stores customers//
    Person people[100];

	//Checks to make sure the file even opened properly.
	ifstream personFile("people.txt");
	if(!personFile.is_open()){
		cout << "There was an error opening the people.txt file." << endl;
		return -1;
	}

	//Now's time to actually read the text files.
	int customer_count;
	personFile >> customer_count;
	personFile.ignore(); // Ignore the newline character after the integer

	for (int i = 0; i < customer_count; i++){
		string name, phone, address_line1, address_line2, city, state, zip;

		getline(personFile, name);
		getline(personFile, phone);
		getline(personFile, address_line1);
		getline(personFile, address_line2);
		getline(personFile, city);
		getline(personFile, state);
		getline(personFile, zip);

		address customer_address(address_line1, address_line2, city, state, zip);

        //saves customer's info//
        people[i].name(name);
        people[i].phone(phone);
        people[i].person_address(customer_address);
	}

    personFile.close();

	//Read credit card information

	ifstream ccFile("credit_card.txt");
	if(!ccFile.is_open()){
		cout << "There was an error opening the credit_card.txt file" << endl;
		return -1;
	}

	int num_cards;
	ccFile >> num_cards;
	ccFile.ignore(); // Ignore the newline character after the integer

	for (int i = 0; i < num_cards; i++){
		string name;
		int card_number;
		double limit, balance;

		getline(ccFile, name);
		ccFile >> card_number >> limit >> balance;
		ccFile.ignore(); // Ignore the newline character after the last double

		credit_card customer_card(card_number, limit, balance);

        //matches cc to customer//
        for (int j = 0; j < customer_count; j++)
        {
            if (people[j].name() == name)
            {
                people[j].person_credit_card(customer_card);
                break;
            }
        }
	}

    ccFile.close();

    //reads product info//
    ifstream productFile("products.txt");
    if(!productFile.is_open())
    {
        cout << "There was an error opening the products.txt file." << endl;
        return -1;
    }

    int product_count;
    productFile >> product_count;
    productFile.ignore(); 

    for (int i = 0; i < product_count; i++)
    {
        string name, description;
        double price;

        getline(productFile, name);
        getline(productFile, description);
        productFile >> price;
        productFile.ignore();

        //creates product//
        product new_product;
        new_product.name = name;
        new_product.description = description;
        new_product.price = price;

        //adds product to store//
        store1.add_product(new_product);
    }

    productFile.close();

    //add to store and other variables

    //adds customers to store//
    for (int i = 0; i < customer_count; i++) 
    {
        store1.add_customer(people[i]);
    }

	//print store info after you finish importing info
	//from text files and add them to your store
	cout << store1.store_info();

	//make random number of random transactions
    srand(static_cast<unsigned int>(time(nullptr)));
    int random_transactions = rand() % 89 + 11;

    for (int i = 0; i < random_transactions; i++)
    {
        int random_customer_index = rand() % store1.num_customers();
        int random_product_index = rand() % store1.num_products();

        Person customer = store1.get_customer(random_customer_index);
        product item = store1.get_product(random_product_index);

        int random_quantity = rand() % 5 + 1;

        //attempts to make a purchase//
        if (store1.make_purchase(customer, item, random_quantity))
        {
            cout << "Successful transaction!" << endl;
            cout << "Transaction Details: " << endl;

            cout << store1.get_transaction(store1.num_transactions() - 1).transaction_info() << endl << endl;
        }
        else
        {
            cout << "Unsuccessful transaction!" << endl;
            cout << "Transaction Details: " << endl;
            cout << "Customer: " << customer.person_info();
            cout << "Quantity: " << random_quantity << endl << endl << endl;
        }
    }

	//print store info at the end
	cout << store1.store_info();

    return 0;
}