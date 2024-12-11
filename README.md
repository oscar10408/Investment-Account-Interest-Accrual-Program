# Investment Account Interest Accrual Simulator

## Description
This project simulates an investment account accruing monthly interest based on tiered balance thresholds. The interest accrual is calculated monthly with options for detailed or final balance reports. The implementation adheres strictly to provided function specifications.

---

## Features
- **Monthly Interest Accrual**: Calculate and add monthly interest to an account balance.
- **Tiered Interest Rates**:
  - **Minimum Interest Rate**: 0.15% for balances under $1,000.
  - **Standard Interest Rate**: 0.225% for balances between $1,000 and $15,000.
  - **Maximum Interest Rate**: 0.4% for balances over $15,000.
- **Reporting Options**: Choose between detailed monthly updates or a final balance summary.

---

## Functions

### 1. `bool accrueInterest(double &balanceAmt, const int numMonths, const bool doPrintEachMonth)`
- **Purpose**: Accrues interest over multiple months based on tiered interest rates.
- **Parameters**:
  - `balanceAmt` (double &): Starting balance; updated to final balance after accrual.
  - `numMonths` (int): Number of months for which interest is accrued.
  - `doPrintEachMonth` (bool): Prints detailed monthly interest and balance if `true`.
- **Returns**:
  - `true`: If the function executes successfully.
  - `false`: If input parameters are invalid (negative balance or non-positive months).
- **Behavior**:
  - Calculates interest for each month.
  - Applies tiered interest rates:
    - Below $1,000: 0.15%.
    - $1,000–$15,000: 0.225%.
    - Above $15,000: 0.4%.
  - Optionally prints monthly details or performs silently.

---

### 2. `bool accrueOneMonthsInterest(double &balanceAmt, const bool doPrintInfo)`
- **Purpose**: Accrues interest for a single month.
- **Parameters**:
  - `balanceAmt` (double &): Starting balance; updated to the new balance after accrual.
  - `doPrintInfo` (bool): Prints interest and updated balance if `true`.
- **Returns**:
  - `true`: If the function executes successfully.
  - `false`: If input balance is invalid (negative value).
- **Behavior**:
  - Applies tiered interest rates to the balance.
  - Optionally prints details of interest added and new balance.

---

### 3. `int main()`
- **Purpose**: Entry point for the program, primarily used to test other functions.
- **Behavior**:
  - Prompts the user for:
    1. Initial account balance (double).
    2. Number of months for accrual (int).
    3. Preference for detailed (`y`) or final-only (`n`) results (char).
  - Executes `accrueInterest` based on user inputs.
  - Prints results according to user preference.

---

## Example Usage

### Compilation
Compile the program using a C++ compiler:
```bash
g++ investment_account.cpp -o investment_account

