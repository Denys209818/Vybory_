#include "libs.h"
#include "People.h"

People::People(string name, string surname, int age, char pass_code[255], char login[255], char password[255], int VPeoples, bool checkout)
{
	this->GetName() = name;
	this->GetSurname() = surname;
	this->GetAge() = age;
	strcpy_s(this->pass_code, strlen(pass_code) + 1, pass_code);
	strcpy_s(this->login, strlen(login) + 1, login);
	strcpy_s(this->password, strlen(password) + 1, password);
	this->VPeoples = VPeoples;
	this->checkout = checkout;
}

void People::Show()
{
	cout << "Name:" << this->GetName();
	cout << setw(4) << "Surname: " << this->GetSurname();
	cout << setw(4) << "Age: " << this->GetAge();
	cout << setw(4) << "Code Pass: " << this->GetPassCode() << endl;
}

char* People:: GetPassCode()
{
	return this->pass_code;
}

char* People::GetLogin()
{
	return this->login;
}

char* People::GetPassword()
{
	return this->password;
}

void People::Click(VPeople* p)
{
	if (this->VPeoples != -5) return;

	p->GetCount()++;
	this->VPeoples = p->GetId();
}

bool& People::GetCheckout()
{
	return this->checkout;
}

int& People::GetVpeople()
{
	return this->VPeoples;
}