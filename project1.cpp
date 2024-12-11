#include <iostream>
using namespace std;

// Author: Hao-Chun, Shih
// Date: 09/24/2024
// Purpose: This program is intended to implement functionality to accrue
// interest for an investment account.

// Calculating the interest for months. Interest would be calculated based on
// input balanceAmt, and numMonths. This function will call fucntion
// accrueOneMonthsInterest for "numMonths" times. Depending on doPrintEachMonth
// to decide print month-by-month information or not.
bool accrueInterest
(
  double &balanceAmt,
  const int numMonths,
  const bool doPrintEachMonth
);


// This function is the base of calculating interest per month. Similarly,
// it's based on the input balanceAmt to decide the interest rate, and
// doPrintInfo to decide print month-by-month information or not.
bool accrueOneMonthsInterest
(
  double &balanceAmt,
  const bool doPrintInfo
);


#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main()
{
  double accountBalance;
  int numMonths;
  bool doPrintEachMonth;
  bool success;
  double initialBalance;
  char userInput;

  cout << "Enter the initial balance of the account: ";
  cin >> accountBalance;
  cout << "Enter the number of months to accrue interest: ";
  cin >> numMonths;
  cout << "Show month-by-month results - 'y' for yes, any other for no: ";
  cin >> userInput;
  
  if (userInput == 'y')
  {
    doPrintEachMonth = true;
  }
  else
  {
    doPrintEachMonth = false;
  }
  
  // Recording the initialBalance for final information.
  initialBalance = accountBalance;
  
  success = accrueInterest(accountBalance, numMonths, doPrintEachMonth);
  
  // If the function can successfully operate, print out the final information.
  // Otherwise, print out the error message. 
  if (success)
  {
    cout << "\n\nInitial balance: " << initialBalance << endl;
    cout << "Total interest accrued: " << 
            accountBalance - initialBalance << endl;
    cout << "Final balance: " << accountBalance << endl;
  }
  else
  {
    cout << "\nSorry, an error was detected.  Unable to provide results!" 
         << endl;
  }

  return 0;
}
#endif


bool accrueOneMonthsInterest(double &balanceAmt, const bool doPrintInfo)
{
  const double MINIMUM_INTEREST_RATE = 0.0015;
  const double STANDARD_INTEREST_RATE = 0.00225; 
  const double MAXIMUM_INTEREST_RATE = 0.004;

  const double MINIMUM_BAR_BALANCE = 1000;
  const double MAXIMUM_BAR_BALANCE = 15000;

  double interestOneMonth;
  double interestRate;

  if (balanceAmt < 0)
  {
    cout << "ERROR in accrueOneMonthsInterest: balanceAmt must be >= 0, but"
         << " the value " << balanceAmt << " was provided!";
    return false;
  }
  else
  {
    // Checking for the balanceAmt to decide interest rate.
    if (balanceAmt < MINIMUM_BAR_BALANCE)
    {
      interestRate = MINIMUM_INTEREST_RATE;
    }
    else if (balanceAmt >= MAXIMUM_BAR_BALANCE)
    {
      interestRate = MAXIMUM_INTEREST_RATE;
    }
    else
    {
      interestRate = STANDARD_INTEREST_RATE;
    }

    if (doPrintInfo)
    {
    cout << "Accruing interest for 1 month:" << endl;
    cout << "  Initial balance: " << balanceAmt << endl;
    }

    interestOneMonth = balanceAmt * interestRate;
    balanceAmt += interestOneMonth;

    if (doPrintInfo)
    {
      cout << "  Initial rate: " << interestRate << endl;
      cout << "  Interest accrued: " << interestOneMonth << endl;
      cout << "  New balance: " << balanceAmt << endl;
    }

    return true;
  }
}


bool accrueInterest
( double &balanceAmt,
  const int numMonths,
  const bool doPrintEachMonth)
{  
  // Using doErrorMessage to break function. Otherwise, the error message
  // will be printed out multiple times.
  bool doErrorMessage = true;

  if (numMonths <= 0)
  {
    cout << "ERROR in accrueInterest: numMonths must be > 0,"
            " but the value " << numMonths << " was provided!";

    return false;
  }
  else
  {
    // Calling accrueOneMonthsInterest for "numMonths" times.
    for (int i = 0; i < numMonths; i++)
    {
      if (doErrorMessage)
      {
        doErrorMessage = accrueOneMonthsInterest(balanceAmt, doPrintEachMonth);
      }
      else
      {
        return false;
      }
    }

    cout << "Interest accrued for " << numMonths << " months!";

    return true;
  }
}