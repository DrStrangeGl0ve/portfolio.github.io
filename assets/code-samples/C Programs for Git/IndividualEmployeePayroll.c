#include <stdio.h>
#include <stdlib.h>


int employeePayrollInfo();

int main() {

  int numberOfEmployees;

  printf("How many employees do you have? \n");
  // Get initial value to determine number of loops.
  scanf("%i", &numberOfEmployees);

  do {
    employeePayrollInfo();
    numberOfEmployees--;
  } while (numberOfEmployees > 0);

  return 0;
}


int employeePayrollInfo() {
  int employeeIDnumber;
  float hourlyPayRate;
  float weeklyHoursWorked;
  float overtimePayRate;
  float overtimeHours;
  float overTimePay;
  float grossPay;
  float netPay;
  float taxWithheld;
  
  const float taxRate = .03525;

  // Request user inputs to initialize variables.
  printf("Please enter employee ID number: \n");
  scanf("%i", &employeeIDnumber);
  printf("Please enter employee hourly pay rate: \n");
  scanf("%f", &hourlyPayRate);
  printf("Please enter the hours this employee worked this week: \n");
  scanf("%f", &weeklyHoursWorked);
  /*Determine if employee worked over 40 hours.
  If so, use the extra hours to calculate pay at 1.5 times the usual pay rate.
  Gross pay can be calculated with or without overtime, depending on the hours
  worked.*/
  if (weeklyHoursWorked > 40) {
    overtimeHours = weeklyHoursWorked - 40;
    overTimePay = hourlyPayRate * 1.5 * overtimeHours;
    grossPay = overTimePay + (hourlyPayRate * 40);
  } else {
    grossPay = hourlyPayRate * weeklyHoursWorked;
  }
  // Multiply gross pay by tax rate to determine taxes to withhold
  taxWithheld = taxRate * grossPay;
  // Net pay is gross pay - tax withheld
  netPay = grossPay - taxWithheld;
  // Prints a summary of the employee's gross pay, tax withholding, and net pay.
  printf("Employee #%i: \n Hours Worked: %.2f \n Gross Pay: $%.2f \n Tax "
         "Withheld: $%.2f \n Net "
         "Pay: $%.2f \n",
         employeeIDnumber, weeklyHoursWorked, grossPay, taxWithheld, netPay);
  return 0;
}
