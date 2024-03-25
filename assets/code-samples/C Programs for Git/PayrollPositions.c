#include <stdio.h>
#include <stdlib.h>

// float and int variables
int numberOfEmployees = 7;
float taxRate = 0.08625;
float totalCompanySalaries;
// Array variables
float idNumbers[7];
int payRates[7];
float annualSalary[7];
float grossSales[7];
float taxesPaid[7];
float grossPay[7];
float employeePaycheck[7];

// calculation functions for gross pay
float HourlyEmployeePay();
float CommissionedEmployeePay();
float ManagerPay();
int main() {
  float hoursWorked;
  // Begin for loop by requesting ID and pay code of each employee.
  for (int i = 0; i < numberOfEmployees; i++) {
    printf("Please enter employee ID number: \n");
    scanf("%f", &idNumbers[i]);
    printf("Please enter employee Pay Code: \n");
    scanf("%i", &payRates[i]);
    // run the switch statement to call the correct function
    //  for each pay code, and place all values in correct arrays.
    switch (payRates[i]) {
    case 1:
      // call ManagerPay() calculation function to calculate gross pay and add
      // to array.
      grossPay[i] = ManagerPay();
      // calculate taxes and add it to the taxes array as well.
      taxesPaid[i] = grossPay[i] * taxRate;
      // calculate net pay and add to the paycheck array.
      employeePaycheck[i] = grossPay[i] - taxesPaid[i];
      break;
    case 2:
      // Call HourlyEmployee function and add its output to the gross pay array.
      grossPay[i] = HourlyEmployeePay();
      taxesPaid[i] = grossPay[i] * taxRate;
      employeePaycheck[i] = grossPay[i] - taxesPaid[i];

      break;
    case 3:
      // Calls function to calculate commisioned employee gross pay, then adds
      // it to array.
      grossPay[i] = CommissionedEmployeePay();
      taxesPaid[i] = grossPay[i] * taxRate;
      employeePaycheck[i] = grossPay[i] - taxesPaid[i];
      break;
    }
  }
  for (int i = 0; i < numberOfEmployees; i++) {
    printf("ID number:  %.0f\n", idNumbers[i]);
    printf("Employee Gross pay: %.2f \n", grossPay[i]);
    printf("Employee Taxes Paid: %.2f \n", taxesPaid[i]);
    printf("Employee Net Pay: %.2f \n", employeePaycheck[i]);
  }
  for (int i = 0; i < numberOfEmployees; i++) {
    totalCompanySalaries += grossPay[i];
  }
  printf("The gross overall payroll for this week was: %.2f \n",
         totalCompanySalaries);
}
float ManagerPay() {
  // Calculates gross monthly pay by dividing annual salary into weeks.
  float annualSalary;
  printf("Please print manager's annual salary: \n");
  scanf("%f", &annualSalary);
  float grossPay = annualSalary / 52;
  return grossPay;
}
float HourlyEmployeePay() {
  // Calculates gross pay by multiplying hoursWorked by hourlyWage.
  // If over 40 hoursWorked, subtract 40 from hours and multiply it by the wage
  // and by 1.5 for overtime pay.
  float hoursWorked;
  float hourlyWage;
  printf("Please enter number of hours worked this week: \n");
  scanf("%f", &hoursWorked);
  printf("Please print employee hourly wage: \n");
  scanf("%f", &hourlyWage);
  if (hoursWorked >= 40.0f) {
    float overtimeHours = hoursWorked - 40;
    float overtimePay = overtimeHours * (hourlyWage * 1.5);
    float grossPay = overtimePay + (hourlyWage * 40);
    return grossPay;
  } else {
    float grossPay = hoursWorked * hourlyWage;
    return grossPay;
  }
}
float CommissionedEmployeePay() {
  // requests the gross weekly sales, calculates 7.2%, adds 375, and outputs
  // gross pay.
  float grossSales;
  printf("Please enter the gross weekly sales: \n");
  scanf("%f", &grossSales);
  float commission = grossSales * .072;
  float grossPay = commission + 375.00f;
  return grossPay;
}
