#pragma once
#include "libs.h"

class AbstractPeople
{
	string name;
	string surname;
	int age;

public:
	virtual void Show() = 0;

	string& GetName();

	string& GetSurname();

	int& GetAge();
};
