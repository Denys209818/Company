#include "libs.h"
#include "Empl.h"
#include "Subortinates.h"
#include "Sales.h"


Sales::Sales(string name, DateTime dt) : Empl(name, dt)
{
	this->position = "Sales";
}

void Sales::PlusSalary()
{
	if (this->procSalary < 35)
	{
		this->procSalary += 1;
		this->salary += (this->salary * 1) / 100;
	}

	for (int i = 0; i < this->size; i++)
	{
		if (this->subortinates[i]->GetNameBoss() == this->name) this->salary += (this->salary * 0.3) / 100;
	}
}

void Sales::PrognozSalary(int a)
{
	int x = this->procSalary;
	int y = this->salary;
	for (int i = 0; i < a; i++)
	{
		if (x < 35)
		{
			x += 1;
			y += (y * 1) / 100;
		}

		for (int i = 0; i < this->size; i++)
		{
			if (this->subortinates[i]->GetNameBoss() == this->name) y += (y * 0.3) / 100;
		}
	}
	cout << "Зарплата через " << a << " лет - " << y << endl;
}

Sales::~Sales()
{

}