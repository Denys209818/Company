#include "libs.h"
#include "Empl.h"

Empl::Empl()
{
	this->salary = 1000;
}

Empl::Empl(string name, DateTime dt)
{
	this->name = name;
	this->dt = dt;
	this->salary = 1000;
}

string Empl::GetName()
{
	return this->name;
}

string Empl::GetNameBoss()
{
	return this->nameBoss;
}

void Empl::GetData()
{
	cout << "Name: " << this->name << endl;
	cout << "Date: " << this->dt.day << " : " << this->dt.month << " : " << this->dt.year << endl;
	cout << "Salary: " << this->salary << endl;
	cout << "Name Boss: " << this->nameBoss << endl;
	cout << "Position: " << this->position << endl;
}

int Empl::GetSalary()
{
	return this->salary;
}

string Empl::GetPosition()
{
	return this->position;
}

Empl::~Empl()
{

}