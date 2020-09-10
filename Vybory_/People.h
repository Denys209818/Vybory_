#pragma once
#include "libs.h"
#include "AbstractPeople.h"
#include "VPeople.h"

class People : public AbstractPeople
{
	char pass_code[255];
	char login[255];
	char password[255];
	int VPeoples;
	bool checkout;
public:
	People(string name, string surname, int age, char pass_code[255], char login[255], char password[255], int VPeoples, bool checkout);

	void Show();

	char* GetPassCode();

	char* GetLogin();

	char* GetPassword();

	void Click(VPeople* p);

	bool& GetCheckout();

	int& GetVpeople();
};
