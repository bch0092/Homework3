//implementation code for credit_card struct here
#include "credit_card.h"

#include <iomanip>
#include <sstream>

using namespace std;

//This method initializes the credit card number, limit, and the current card balance.

credit_card::credit_card(int cardNum, double cardLimit, double cardBalance)
{
    cc_number = cardNum;
    limit = cardLimit;
    current_balance = cardBalance;

}

//creates an empty instance of the credit card struct (lowk broke)//
credit_card::credit_card()
{
    cc_number = 0;
    limit = 0.0;
    current_balance = 0.0;
}

//This method tries to make a purchase against the credit card limit. If the purchase amount 
//is within the limit, it adds the purchase amount to the current balance and returns true. 
//Otherwise, it returns false.

bool credit_card::make_purchase(double purchase_amount)
{
    //checks purchase of a negative amount//
    if (purchase_amount < 0) 
    {
        return false; 
    }

    if (current_balance + purchase_amount <= limit)
    {
        current_balance += purchase_amount;
        return true;
    }
    else
    {
        return false;
    }
}

//This method tries to make a payment towards the credit card balance. If the payment amount
//is less than or equal to the current balance, it subtracts the payment amount from the
//current balance and returns true. Otherwise, it returns false.

bool credit_card::make_payment(double payment_amount)
{
    //checks payment of a negative amount//
    if (payment_amount < 0)
    {
        return false;
    }

    if (payment_amount <= current_balance)
    {
        current_balance -= payment_amount;
        return true;
    }
    else
    {
        return false;
    }
}

//This method returns a string containing the credit card number, limit, and current balance.

string credit_card::credit_card_info()
{
    std::stringstream output;
    output << std::fixed << std::setprecision(2);
    output << "\nCredit Card Number: " << cc_number << "\nCredit Card Limit: $" << limit << "\nCurrent Balance: $" << current_balance;
    return output.str();
}