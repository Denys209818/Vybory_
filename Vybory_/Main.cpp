#include "libs.h"
#include "AbstractPeople.h"
#include "VPeople.h"
#include "People.h"
#include "Admin.h"
#include "System.h"

int Admin::id_ = 1;

int Admin::id_peoples = 0;

bool System::GetReset = true;

int StartMenu(System* s);

void MenuAdmin(System* s, Admin* admin);

void MenuPeople(System* s, People* p);

void main()
{
	setlocale(LC_CTYPE, "ukr");
	System s;
	s.Start();


	int status = -2;
	while (status == -2)
	{
		status = StartMenu(&s);
		system("cls");
	}

	switch (status)
	{
	case -1:
	{
		MenuAdmin(&s, s.GetAdmin());
		break;
	}
	default:
	{
		MenuPeople(&s, s.GetPeoples()[status]);
		break;
	}
	}

	s.End();
}