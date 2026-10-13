/******************************************************************************
Made in OnlineGDB by C.J. Merendino
Lab 5 - Program 2 - Monthly Loan Payment
This program calculates a monthly loan payment and the total interest paid.
*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    // Variables for user input
    double loan_amount;
    double annual_rate_pct;
    int number_of_payments;

    // Variables for calculations
    double monthly_rate;
    double math_power;
    double monthly_payment;
    double amount_paid_back;
    double interest_paid;

    // Ask user for input
    cout << "Enter the loan amount: ";
    cin >> loan_amount;
    cout << "Enter the annual interest rate (as a percentage): ";
    cin >> annual_rate_pct;
    cout << "Enter the number of monthly payments: ";
    cin >> number_of_payments;

    // Calculations
    monthly_rate = annual_rate_pct / 100.0 / 12.0;
    
    // Storing exponentiation part in a variable keeps final formula readable
    math_power = pow(1.0 + monthly_rate, number_of_payments);
    monthly_payment = ((monthly_rate * math_power) / (math_power - 1.0)) * loan_amount;
    
    amount_paid_back = monthly_payment * number_of_payments;
    interest_paid = amount_paid_back - loan_amount;

    // Display formatted report
    cout << endl;
    cout << fixed << setprecision(2);
    cout << "Loan Amount:           $" << loan_amount << endl;
    // Display monthly rate with higher precision to show exact decimal
    cout << setprecision(6); 
    cout << "Monthly Interest Rate:  " << monthly_rate << endl;
    
    cout << setprecision(2); // Return to standard currency precision
    cout << "Number of Payments:     " << number_of_payments << endl;
    cout << "Monthly Payment:       $" << monthly_payment << endl;
    cout << "Amount Paid Back:      $" << amount_paid_back << endl;
    cout << "Interest Paid:         $" << interest_paid << endl;

    return 0;
}