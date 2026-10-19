#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

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

int main()
{

//import from text files
	//Checks to make sure the file even opened properly.
	ifstream personFile("person.txt");
	if(!personFile.is_open()){
		cout << "There was an error opening the person.txt file" << endl;
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
	}

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
	}



	//add to store and other variables

	//print store info after you finish importing info
	//from text files and add them to your store
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;

	//make random number of random transactions

	//print store info at the end
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
}
