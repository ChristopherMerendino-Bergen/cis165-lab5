/******************************************************************************
Made in OnlineGDB by C.J. Merendino
Lab 5 - Program 1 - Compound Interest
This program calculates compound interest and displays a formatted financial report.
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    // Variables for user input
    double principal;
    double annual_rate_pct;
    int times_compounded;

    // Variables for calculations
    double rate_decimal;
    double amount;
    double interest_earned;

    // Ask user for input
    cout << "Enter the principal balance: ";
    cin >> principal;
    cout << "Enter the annual interest rate (as a percentage): ";
    cin >> annual_rate_pct;
    cout << "Enter the number of times interest is compounded per year: ";
    cin >> times_compounded;

    // Calculations
    rate_decimal = annual_rate_pct / 100.0;
    amount = principal * pow(1.0 + rate_decimal / times_compounded, times_compounded);
    interest_earned = amount - principal;

    // Display formatted report
    cout << endl; 
    cout << fixed << setprecision(2);
    cout << "Interest Rate:      " << setw(10) << annual_rate_pct << "%" << endl;
    cout << "Times Compounded:   " << setw(10) << times_compounded << endl;
    cout << "Principal:         $" << setw(10) << principal << endl;
    cout << "Interest Earned:   $" << setw(10) << interest_earned << endl;
    cout << "Amount in Savings: $" << setw(10) << amount << endl;

    return 0;
}