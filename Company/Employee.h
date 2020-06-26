#pragma once
#include "libs.h"
#include "Empl.h"

class Employee : public Empl
{
public:
	Employee(string name, DateTime dt);

	void PlusSalary();

	void PrognozSalary(int a);

	virtual ~Employee();
};