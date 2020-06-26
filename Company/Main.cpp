#include "libs.h"
#include "Empl.h"
#include "Employee.h"
#include "Subortinates.h"
#include "Manager.h"
#include "Sales.h"

void SumSalary(Empl** empl, int size);


void main() 
{
	setlocale(LC_CTYPE, "ukr");
	int size = 3;
	DateTime dt;
	dt.day = 10;
	dt.month = 12;
	dt.year = 2000;
	Empl** empl = new Empl*[100];
	empl[0] = new Employee("Denys", dt);
	empl[1] = new Manager("Vasyl", dt);
	empl[2] = new Sales("Sasha", dt);


    int counter = 1;
	int ch = 1;


	while (true) 
	{
		system("cls");
	    for (int i = 0; i < size; i++) 
	    {
			cout << i+1 << ": ";
			if (counter - 1 == i) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); empl[i]->GetData(); }
			else { cout << empl[i]->GetName() << endl; }
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	    }
		ch = _getch();
		switch (ch) 
		{
		  case 224: 
		  {
			switch (_getch()) 
			{
			case 80: {counter < size ? counter++ : counter = 1; break; }
			case 72: {counter > 1 ? counter-- : counter = size; break; }
			}
			break;
		  }

		  case 'm': 
		  {
			  DateTime dt_;
			  string name;
			  cout << "Enter name: " << endl;
			  cin >> name;
			  cout << "Enter day: ";
			  cin >> dt_.day;
			  cout << "Enter month: ";
			  cin >> dt_.month;
			  cout << "Enter year: ";
			  cin >> dt_.year;

			  empl[size] = new Manager(name,dt_);
			  size++;
			  break;
		  }

		  case 'e': 
		  {
			  DateTime dt_;
			  string name;
			  cout << "Enter name: " << endl;
			  cin >> name;
			  cout << "Enter day: ";
			  cin >> dt_.day;
			  cout << "Enter month: ";
			  cin >> dt_.month;
			  cout << "Enter year: ";
			  cin >> dt_.year;

			  empl[size] = new Employee(name, dt_);
			  size++;
			  break;
		  }

		  case 's': 
		  {
			  DateTime dt_;
			  string name;
			  cout << "Enter name: " << endl;
			  cin >> name;
			  cout << "Enter day: ";
			  cin >> dt_.day;
			  cout << "Enter month: ";
			  cin >> dt_.month;
			  cout << "Enter year: ";
			  cin >> dt_.year;

			  empl[size] = new Sales(name, dt_);
			  size++;
			  break;
		  }

		  case '+': 
		  {
			int k = 0;
			  if (empl[counter-1]->GetPosition() != "Employee")
			  {
				  do 
				  {
					  cout << "Enter id of Worker: ";
					  cin >> k;
				  } while (k < 0 || k > size);

				  if (empl[k-1]->GetNameBoss() != empl[counter-1]->GetName() && counter != k) 
				  {
					  if (empl[counter - 1]->GetPosition() == "Manager") ((Manager*)empl[counter - 1])->AddSub(empl[k - 1], empl[counter - 1]->GetName());
					  else if (empl[counter - 1]->GetPosition() == "Sales") ((Sales*)empl[counter - 1])->AddSub(empl[k - 1], empl[counter - 1]->GetName());
				  }
			  }
			  break;
		  }

		  case '-':
		  {
			  int k = 0;
			  do
			  {
				  cout << "Enter id of Worker: ";
				  cin >> k;
			  } while (k < 0 || k > size);
			  Empl** temp = new Empl * [size - 1];
			  for (int i = 0; i < k; i++) 
			  {
				  temp[i] = empl[i];
			  }

			  for (int i = k+1; i < size; i++)
			  {
				  temp[i-1] = empl[i];
			  }
			  delete empl[k];
			  empl = temp;
			  size--;
			  counter--;
			  break;
		  }

		  case 13: 
		  {
			  if (empl[counter-1]->GetPosition() != "Employee") 
			  {
				       empl[counter - 1]->GetPosition() == "Manager" ? 
					  ((Manager*)empl[counter - 1])->MySub(empl[counter-1]) :
					  ((Sales*)empl[counter - 1])->MySub(empl[counter - 1]);
			  }
			  break;
		  }

		  case 'z': 
		  {
			  empl[counter - 1]->PlusSalary();
			  break;
		  }

		  case 'p': 
		  {
			  int k = 0;
			  cout << "Ââåäèòü êèëüêèñòü ðîêèâ - ";
			  cin >> k;
			  empl[counter - 1]->PrognozSalary(k);
			  _getch();
			  break;
		  }
		}


	}
        //Видалення
        for (int i = 0; i < size; i++) 
	{
		delete[] empl[i];
	}
	delete[] empl;

}
