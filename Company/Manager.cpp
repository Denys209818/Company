#include "libs.h"
#include "Empl.h"
#include "Subortinates.h"
#include "Manager.h"

Manager::Manager(string name, DateTime dt) : Empl(name, dt)
{
	this->position = "Manager";
}

void Manager::PlusSalary()
{
	if (this->procSalary < 30)
	{
		this->procSalary += 5;
		this->salary += (this->salary * 5) / 100;
	}

	for (int i = 0; i < this->size; i++)
	{
		if (this->subortinates[i]->GetNameBoss() == this->name)
		{
			if (this->subortinates[i]->GetPosition() == "Employee")
			{
				this->salary += (this->salary * 0.5) / 100;
			}
		}
	}
}

void Manager::PrognozSalary(int a)
{
	int x = this->procSalary;
	double y = this->salary;
	for (int i = 0; i < a; i++)
	{
		if (x < 40)
		{
			x += 5;
			y += (y * 5) / 100;
		}

		for (int i = 0; i < this->size; i++)
		{
			if (this->subortinates[i]->GetNameBoss() == this->name)
			{
				if (this->subortinates[i]->GetPosition() == "Employee")
				{
					y += (y * 0.5) / 100;
				}
			}
		}
	}

	cout << "Зарплата через " << a << " лет - " << y << endl;
}

Manager::~Manager()
{

}