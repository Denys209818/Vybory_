#pragma once
#include "libs.h"
#include "AbstractPeople.h"
class VPeople : public AbstractPeople
{
	int id;
	int count;
	char text[255];
public:
	VPeople(int id, int count, char text[255], string name, string surname, int age);

	void Show();

	int& GetCount();

	char* GetText();

	int& GetId();
};
