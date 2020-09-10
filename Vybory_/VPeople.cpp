#include "libs.h"
#include "VPeople.h"

VPeople::VPeople(int id, int count, char text[255], string name, string surname, int age)
{
	this->id = id;
	this->count = count;
	strcpy_s(this->text, strlen(text) + 1, text);
	this->GetAge() = age;
	this->GetName() = name;
	this->GetSurname() = surname;
}

void VPeople::Show()
{
	cout << setw(4) << this->GetName() << endl;
	cout << setw(4) << this->GetSurname() << endl;
	cout << setw(4) << this->GetAge() << endl;
	cout << "Рейтинг: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 43);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	cout << "Про мене:" << endl;
	cout << this->text << endl;
}

int& VPeople::GetCount()
{
	return this->count;
}

char* VPeople::GetText()
{
	return this->text;
}

int& VPeople::GetId()
{
	return this->id;
}