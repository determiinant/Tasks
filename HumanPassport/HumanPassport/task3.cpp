/*  Умова:
Зробити паспорт людини. Вводиться імя, призвіще, національність,вік,ріст.
АЛЕ найголовніше, що всі значення встановлюються через функції наприклад. setAge, де попросить ввести імя і поверне імя.
ТАКОЖ всі змінні(національність,вік,ріст) оголошені тільки в main().

Доп умови:
Зробити можливість міняти значення паспорта.
*/
#include <iostream>
#include <string>
using namespace std;

void ShowInfo(string* name, string* srmn, string* nationality, int* age, float* height);
void ShowMenu(string* name, string* srmn, string* nationality, int* age, float* height);
void ChangeInfo(string* name, string* srmn, string* nationality, int* age, float* height);

string setName(string* name)
{
	cin >> *name;
	return *name;
}

string setSurname(string* srnm)
{
	cin >> *srnm;
	return *srnm;
}

string setNationality(string* nationality)
{
	cin >> *nationality;
	return *nationality;

}

int setAge(int* age)
{
	cin >> *age;
	return *age;
}

float setHeight(float* height)
{
	cin >> *height;
	return *height;
}

void ShowMenu(string* name, string* srmn, string* nationality, int* age, float* height)
{
	int selection;
	cout << "1. Change info" << endl <<
		"2. Show info " << endl <<
		"3. Exit" << endl;

	cin >> selection;
	switch (selection)
	{
	case 1: ChangeInfo(name, srmn, nationality, age, height);
		break;

	case 2: ShowInfo(name, srmn, nationality, age, height);
		break;
	case 3: exit(0);
	}
}


void ChangeInfo(string* name, string* srmn, string* nationality, int* age, float* height)
{
	cout << "Choose what you have change. Enter number." << endl;
	cout << "1. Name " << endl <<
		"2. Surname " << endl <<
		"3. Nationality " << endl <<
		"4. Age " << endl <<
		"5. Height " << endl;

	int sel;
	cin >> sel;
	switch (sel)
	{
	case 1: cout << "Enter your name: ";
		setName(name);
		break;
	case 2: cout << "Enter your surname: ";
		setSurname(srmn);
		break;
	case 3: cout << "Enter your nationality: ";
		setNationality(nationality);
		break;
	case 4: cout << "Enter your age: ";
		setAge(age);
		break;
	case 5: cout << "Enter your height: ";
		setHeight(height);
		break;
	}
	ShowMenu(name, srmn, nationality, age, height);
}

void ShowInfo(string* name, string* srmn, string* nationality, int* age, float* height)
{
	cout << "Name: " << *name << endl;
	cout << "Surname: " << *srmn << endl;
	cout << "Nationality: " << *nationality << endl;
	cout << "Age: " << *age << endl;
	cout << "Height: " << *height << endl;

	ShowMenu(name, srmn, nationality, age, height);
}

int main()
{
	string name, srmn, nationality;
	int age;
	float height;

	cout << "Enter your name: ";
	setName(&name);

	cout << "Enter your surname: ";
	setSurname(&srmn);
	cout << "Enter your nationality: ";
	setNationality(&nationality);
	cout << "Enter your age: ";
	setAge(&age);
	cout << "Enter your height: ";
	setHeight(&height);

	ShowMenu(&name, &srmn, &nationality, &age, &height);

	cout << endl << endl;
}