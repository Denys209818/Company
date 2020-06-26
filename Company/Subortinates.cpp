#include "libs.h"
#include "Empl.h"
#include "Subortinates.h"

Subortinates::Subortinates()
{
	this->size = 0;

}

void Subortinates::AddSub(Empl* s, string nameBoss)
{
	if (this->size == 0)
	{
		this->capacity = 2;
		this->subortinates = new Empl * [this->size + 2];
		this->subortinates[this->size] = s;
		s->nameBoss = nameBoss;
		this->size++;
		return;
	}

	if (this->capacity == this->size)
	{
		this->capacity = this->size + 2;
		Empl** temp = new Empl * [this->size + 2];
		for (int i = 0; i < this->size; i++)
		{
			temp[i] = this->subortinates[i];
		}
		this->subortinates = temp;
	}
	this->subortinates[this->size] = s;
	s->nameBoss = nameBoss;
	this->size++;
}

void Subortinates::MySub(Empl* me)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->subortinates[i]->nameBoss == me->GetName())
		{
			cout << "================" << endl;
			cout << "Name: " << this->subortinates[i]->name << endl;
			cout << "Salary: " << this->subortinates[i]->salary << endl;
			cout << "Date: " << this->subortinates[i]->dt.day << ":" << this->subortinates[i]->dt.month << ":" << this->subortinates[i]->dt.year << endl;
			cout << "Position: " << this->subortinates[i]->GetPosition() << endl;
			cout << "================" << endl;
		}
		else
		{
			Empl** temp = new Empl * [this->size - 1];
			for (int k = 0; k < i; k++)
			{
				temp[k] = this->subortinates[k];
			}

			for (int k = i + 1; k < this->size; k++)
			{
				temp[k - 1] = this->subortinates[k];
			}
			delete this->subortinates[i];
			this->subortinates = temp;
			this->size--;
		}
	}
	_getch();
}

void Subortinates::DeleteSub(int a)
{
	if (a < this->size)
	{
		Empl** temp = new Empl * [this->size - 1];

		for (int i = 0; i < a; i++)
		{
			temp[i] = this->subortinates[i];
		}

		for (int i = a + 1; i < this->size; i++)
		{
			temp[i - 1] = this->subortinates[i];
		}

		delete this->subortinates[a];

		this->subortinates = temp;
	}
	else
	{
		cout << "Номер сотрудника не найден!" << endl;
	}
}

Empl** Subortinates::GetSub()
{
	return this->subortinates;
}