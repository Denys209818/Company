#pragma once
#include "libs.h"
#include "Empl.h"
#include "Subortinates.h"

class Manager : public Empl, public Subortinates
{
public:
	Manager(string name, DateTime dt);

	void PlusSalary();

	void PrognozSalary(int a);

	virtual ~Manager();
};

