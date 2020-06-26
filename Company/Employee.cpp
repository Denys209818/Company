#include "libs.h"
#include "Empl.h"
#include "Employee.h"

Employee::Employee(string name, DateTime dt) : Empl(name, dt)
{
	this->position = "Employee";
}

void Employee::PlusSalary()
{
	if (this->procSalary < 30)
	{
		this->procSalary += 3;
		this->salary += (this->salary * 3) / 100;
	}
}

void Employee::PrognozSalary(int a)
{
	int x = this->procSalary;
	int y = this->salary;
	for (int i = 0; i < a; i++)
	{
		if (x < 30)
		{
			x += 3;
			y += (y * 3) / 100;
		}
	}
	cout << "Зарплата через " << a << " лет - " << y << endl;
}

Employee::~Employee()
{

}