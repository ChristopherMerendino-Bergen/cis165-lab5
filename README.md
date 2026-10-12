# CIS 165 - Lab 5: Compound Interest and Loan Payments

## How to Compile and Run
To compile and run these programs from the terminal, use the following commands:

**Compound Interest Program:**
`g++ -std=c++17 -Wall -Wextra compound_interest.cpp -o compound_interest`
`./compound_interest`

**Loan Payment Program:**
`g++ -std=c++17 -Wall -Wextra loan_payment.cpp -o loan_payment`
`./loan_payment`

* Note: I use a Mac, and so my terminal compiles slightly differently than a Windows machine. More specifically, I use `clang++` instead of `g++`*

## Program Plans

**compound_interest.cpp Plan:**
1. Declare variables to hold the user inputs: `principal`, `annual_rate_pct`, and `times_compounded`.
2. Use `cin` to prompt the user and store the inputs.
3. Convert the percentage to a decimal by dividing by 100.0.
4. Calculate the total `amount` using the `pow` function from `<cmath>`.
5. Subtract the `principal` from the `amount` to find the `interest_earned`.
6. Output a clean report using `fixed`, `setprecision(2)`, and `setw(10)` from `<iomanip>` to align the dollar values.

**loan_payment.cpp Plan:**
1. Declare variables for user inputs: `loan_amount`, `annual_rate_pct`, and `number_of_payments`.
2. Use `cin` to retrieve these values.
3. Calculate the `monthly_rate` by dividing the annual percentage by 100, and then by 12.
4. Calculate the complex monthly payment formula using `pow`. To keep it readable, I will store the repeating `pow(1 + monthly_rate, number_of_payments)` calculation in an intermediate variable called `math_power`.
5. Calculate `amount_paid_back` by multiplying the monthly payment by the total number of payments.
6. Calculate `interest_paid` by subtracting the original loan amount from the amount paid back.
7. Output the final values, using `setprecision(2)` for monetary values.

## Test Tables

| Program and test | Inputs | Expected results | Actual output | Match or correction |
| :--- | :--- | :--- | :--- | :--- |
| **Compound interest** (assigned) | `1000`, `4.25%`, `12` | Interest: $43.34, Savings: $1043.34 | Interest: $43.34, Savings: $1043.34 | ✅ Match |
| **Compound interest** (changed) | `5000`, `5.0%`, `4` | Interest: $254.73, Savings: $5254.73 | Interest: $254.73, Savings: $5254.73 | ✅ Match |
| **Loan payment** (assigned) | `10000`, `12%`, `36` | Payment: $332.14, Paid Back: $11957.15, Int: $1957.15 | Payment: $332.14, Paid Back: $11957.15, Int: $1957.15 | ✅ Match |
| **Loan payment** (changed) | `20000`, `5%`, `60` | Payment: $377.42, Paid Back: $22645.48, Int: $2645.48 | Payment: $377.42, Paid Back: $22645.48, Int: $2645.48 | ✅ Match |

* Note: I have restored the original values to both programs and re-ran them to confirm they still output the assigned data.*

## Code Explanations

**Why must a percentage be divided by 100 before using it in a formula?**
Standard mathematical formulas require the decimal representation of percentages. For example, 5% is mathematically equivalent to 0.05. If I didn't divide by 100, the formula would calculate the interest as if the rate were 500%.

**How does pow represent exponentiation?**
The `pow()` function from the `<cmath>` library takes two arguments: a base and an exponent (`pow(base, exponent)`). It calculates and returns the base raised to the power of the exponent.

**What does the number of compounding periods change in the savings formula?**
The number of compounding periods divides the annual rate into smaller intervals, but it applies that fraction of the interest more frequently throughout the year. This results in slightly higher overall interest earned, as the previously earned interest begins earning its own interest faster.

**How is an annual interest rate converted to a monthly rate?**
It is first divided by 100 to convert it from a raw percentage into a mathematical decimal, and then it is divided by 12 to spread that annual rate evenly across the 12 months in a year.

**Why should double be used for these calculations?**
Financial calculations inherently involve decimals and fractions of cents. If I used integer data types, C++ would immediately truncate the decimals during its division steps, resulting in wildly inaccurate financial calculations.

**Why should calculations use full precision when money is displayed to two decimal places?**
Keeping full precision in variables prevents rounding errors from snowballing during intermediate mathematical steps. I only use `setprecision(2)` on the `cout` stream at the very end to format the perfect underlying number like real-world currency.

**How are the amount paid back and total interest calculated?**
The amount paid back is calculated by taking the required monthly payment and multiplying it by the total number of payments required for the loan. The total interest paid is then calculated by taking that total amount paid back and subtracting the original loan principal from it.

**Why are calculations stored in variables before being displayed?**
Storing calculations in variables separates the mathematical processing logic from the output display formatting. It makes the code easier to read, easier to debug, and allows me to reuse the exact same calculations later in the program without making the computer do the math twice.
