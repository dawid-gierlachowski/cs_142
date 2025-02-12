// Group_1_Lab_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

	// (1)  declare and initialize the variables

	const float federal_tax_rate = 0.15f;
	const float state_tax_rate = 0.03f;
	const float overtime_rate = 1.5f;
	const int overtime_threshold = 40;

	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(2);

	// (2)  prompt user and read the employee number

	// Storing it as a string due to:
	// 1. Leading zeros being handled (ex. 00005)
	// 2. We aren't performing mathematical expressions on it
	// 3. In case there is an ID with alpha chars in future
	string employee_id;
	char id_user_confirmation;
	do 
	{
		cout << "Please enter the employee's ID number: ";
		cin >> employee_id;

		cout << "\nYou entered Employee ID: \033[1;33m" << employee_id << "\033[0m\n";
		cout << "Is this correct? (y/n): ";
		cin >> id_user_confirmation;
		cout << "\n";

		// If user types in "yes" or "no" we want to ignore following chars
		cin.ignore(256, '\n');

		id_user_confirmation = tolower(id_user_confirmation);
		
	}
	while (id_user_confirmation != 'y');

	// (3)  prompt user and read the number of hours worked

	char hours_worked_confirmation;
	int hours_worked;
	do
	{
		cout << "Please enter the number of hours worked: ";
		cin >> hours_worked;

		cout << "\nYou entered number of hours worked: \033[1;33m" << hours_worked << "\033[0m\n";
		cout << "Is this correct? (y/n): ";
		cin >> hours_worked_confirmation;
		cout << "\n";

		// If user types in "yes" or "no" we want to ignore following chars
		cin.ignore(256, '\n');

		hours_worked_confirmation = tolower(hours_worked_confirmation);

	} while (hours_worked_confirmation != 'y');

	// (4)  prompt user and read the employee hourly wage

	char hourly_wage_confirmation;
	float hourly_wage;
	do
	{
		cout << "Please enter the employee's hourly wage: $";
		cin >> hourly_wage;

		cout << "\nYou entered hourly wage: \033[1;33m$" << hourly_wage << "\033[0m\n";
		cout << "Is this correct? (y/n): ";
		cin >> hourly_wage_confirmation;
		cout << "\n";

		// If user types in "yes" or "no" we want to ignore following chars
		cin.ignore(256, '\n');

		hourly_wage_confirmation = tolower(hourly_wage_confirmation);

	} while (hourly_wage_confirmation != 'y');

	// (5)  use a selection control structure to determine the gross pay
	// (6)  determine whether overtime pay is included 
	
	float gross_pay;
	bool is_overtime = false;

	if (hours_worked > overtime_threshold)
	{
		float base_pay;
		float overtime_pay;

		base_pay = overtime_threshold * hourly_wage;
		overtime_pay = hourly_wage * overtime_rate * (hours_worked - overtime_threshold);
		gross_pay = base_pay + overtime_pay;

		is_overtime = true;
	}
	else
	{
		gross_pay = hourly_wage * hours_worked;
	}
	
	// (7)  determine the federal and state taxes
	
	float federal_tax_amount = gross_pay * federal_tax_rate;
	float state_tax_amount = gross_pay * state_tax_rate;
	float total_tax_amount = federal_tax_amount + state_tax_amount;
	
	// (8)  determine the net pay

	float net_pay = gross_pay - total_tax_amount;

	// (9)  display the employee number 

	cout << "\033[1;97;100m";
	cout << left << setw(30) << "Employee Number";
	cout << left << setw(11) << employee_id << endl;

	// (10)  display the employee number of hours worked 

	cout << "\033[0m";
	cout << left << setw(30) << "Hours Worked This Week";
	cout << left << setw(11) << to_string(hours_worked) + " hours" << endl;

	// (11)  display the hourly wage 

	cout << "\033[1;97;100m";
	cout << left << setw(30) << "Hourly Wage";
	cout << '$' << left << setw(10) << hourly_wage << endl;

	// (12)  display the gross pay 

	cout << "\033[0m";
	cout << left << setw(30) << "Gross Pay";
	cout << '$' << left << setw(10) << gross_pay << endl;

	// (13)  display the total tax deductions 

	cout << "\033[1;97;100m";
	cout << left << setw(30) << "Total Tax Deductions";
	cout << '$' << left << setw(10) << total_tax_amount << endl;

	// (14)  display the net pay 
	
	cout << "\033[0m";
	cout << left << setw(30) << "Net Pay";
	cout << '$' << left << setw(10) << net_pay << endl;

	// (15)  display whether overtime pay is included 

	if (is_overtime)
	{
		cout << "\033[31m";
		cout << "Overtime Pay Included" << endl;
		cout << "\033[0m";
	}

	std::cout << "\nPress Enter to exit...";
	std::cin.get();

	return 0;
}

