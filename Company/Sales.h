#pragma once
#include "libs.h"
#include "Empl.h"
#include "Subortinates.h"

class Sales : public Empl, public Subortinates
{
public:
	Sales(string name, DateTime dt);

	void PlusSalary();

	void PrognozSalary(int a);

	virtual ~Sales();
};