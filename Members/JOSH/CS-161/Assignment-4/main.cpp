//Joshua Mauricio and Natalie Legras
//Assignment 4 / Lab 4
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << fixed << setprecision(2);

    double balance;
    cout << "Enter Balance: ";
    cin >> balance;

    double payment;
    cout << "Enter Payment: ";
    cin >> payment;

    double apr;
    cout << "Enter your APR: ";
    cin >> apr;

    int month = 0;

    cout << "Month" << '\t' << "Int." << '\t' << "Pay"
         << '\t' << "Balance" <<  endl;
    cout << month << '\t' << '\t' << '\t' << balance << endl;

    month++;

    double interest = ((apr / 12) * balance) / 100;

    while (balance > 0){
        if (balance > payment){
            interest = ((apr / 12) * balance) / 100;
            balance = balance + interest;
            balance = balance - payment;
            cout << month <<'\t' << interest << '\t' << payment
             << '\t' << balance << endl;
            month++;
        }
        else{
            interest = ((apr / 12) * balance) / 100;
            payment = balance + interest;
            balance = 0;
        }
    }
    cout << month <<'\t' << interest << '\t' << payment
         << '\t' << balance << endl;
}


