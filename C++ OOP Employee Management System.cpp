// C++ OOP Employee Management System

#include <iostream>
using namespace std;

// Base Class
class Employee {
protected:
	string name;
	int id;
public:
	Employee(string n, int i) : name(n), id(i) {}
	virtual void calculateSalary() = 0; // Pure virtual function
	void displayInfo() {
		cout << "ID: " << id << ", Name: " << name << endl;
	}
	virtual ~Employee() {} // Virtual destructor
};

// Base class (Employee) stores name and ID.

//Pure virtual function (calculateSalary))
// forces derived classes to implement it.

// Virtual destructor (~Employee()) ensures
// proper cleanup of derived objects.

class FullTimeEmployee : public Employee {
private:
	double monthlySalary;
public:
	FullTimeEmployee(string n, int i, double salary) : Employee(n, i), monthlySalary(salary) {}
	void calculateSalary() override {
		cout << "Full-Time Employee Salary: 5" << monthlySalary << endl;
	}
};

// New attribute (monthlySalary): Stores the
// salary of a full-time employee.

// Constructor (FullTimeEmployee()): Calls the
// base class constructor (Employeen, 1)) to
// initialise name and ID.

// ~ Overrides calculateSalary): Displays the
// monthly salary for full-time employees.

// The override keyword ensures it's correctly
// overriding a base class function.

class PartTimeEmployee : public Employee {
private:
	double hourlyRate;
	int hoursWorked;
public:
	PartTimeEmployee(string n, int i, double rate, int hours) : Employee(n, i), hourlyRate(rate), hoursWorked(hours) {}
	void calculateSalary() override {
		cout << "Part-Time Employee Salary: $" << (hourlyRate * hoursWorked) << endl;
	}
};

// New attributes (hourlyRate, hours Worked):
// Used to calculate salary for part-time employees.

// Constructor (PartTimeEmployee()): Calls the
// base class constructor (Employee (n, i)).

// Overrides calculateSalary (): Computes
// salary as hourly rate x hours worked.

// Main Function
int main() {
	Employee * emp1 = new FullTimeEmployee("Erick", 101, 5000);
	Employee * emp2 = new PartTimeEmployee("Parker", 102, 50, 50);
	
	cout << "\nEmployee Details & Salary Calculation:\n";
	emp1->displayInfo();
	emp1->calculateSalary();
	cout << endl;
	
	emp2->displayInfo();
	emp2->calculateSalary();
	
	// Clean up
	delete emp1;
	delete emp2;
	
	return 0;
}

// Creates FullTimeEmployee and PartTimeEmployee
// objects using base class pointers (Employee*).

// Demonstrates polymorphism: Calls the
// correct calculateSalary() function dynamically.

// Deletes objects (delete emp1; delete emp2;)
// to free memory.
