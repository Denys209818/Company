#pragma once
#include "libs.h"
#include "Empl.h"

class Subortinates
{
protected:
	Empl** subortinates;
	int size;
	int capacity;
public:
	Subortinates();

	void AddSub(Empl* s, string nameBoss);

	void MySub(Empl* me);

	void DeleteSub(int a);

	Empl** GetSub();
};

