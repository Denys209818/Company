#include "libs.h"
#include "Empl.h"

void SumSalary(Empl** empl, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += empl[i]->GetSalary();
	}
	cout << "Suma: " << sum << endl;
}