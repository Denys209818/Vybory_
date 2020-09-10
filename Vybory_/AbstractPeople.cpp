#include "libs.h"
#include "AbstractPeople.h"

string& AbstractPeople::GetName()
{
	return this->name;
}

string& AbstractPeople::GetSurname()
{
	return this->surname;
}

int& AbstractPeople::GetAge()
{
	return this->age;
}