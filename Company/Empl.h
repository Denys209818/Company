#pragma once
#include "libs.h"

class Empl
{
protected:
	string name;
	DateTime dt;
	double salary;
	string nameBoss;
	string position;
	int procSalary = 0;
public:
	Empl();

	Empl(string name, DateTime dt);

	string GetName();

	string GetNameBoss();

	void GetData();

	int GetSalary();

	string GetPosition();

	virtual ~Empl();

	virtual void PlusSalary() = 0;
	virtual void PrognozSalary(int a) = 0;
	friend class Subortinates;
};
