//implementation code for credit_card struct here

#include <iostream>
#include "credit_card.h"

using namespace std;

//This method initializes the credit card number, limit, and the current card balance.

credit_card::credit_card(int cardNum, double cardLimit, double cardBalance)
{
    cc_number = cardNum;
    limit = cardLimit;
    current_balance = cardBalance;

}

//This method tries to make a purchase against the credit card limit. If the purchase amount 
//is within the limit, it adds the purchase amount to the current balance and returns true. 
//Otherwise, it returns false.

credit_card::make_purchase(double purchase_amount)
{
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

credit_card::make_payment(double payment_amount)
{
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

credit_card::credit_card_info()
{
    return "Credit Card Number: " + to_string(cc_number) + "\nLimit: " + to_string(limit) + "\nCurrent Balance: " + to_string(current_balance);
}
