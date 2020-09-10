#pragma once
#include "libs.h"
#include "People.h"
#include "VPeople.h"
#include "Admin.h"
class System
{

	Admin* admin;
	map<int, People*> Peoples;

public:
	static bool GetReset;
	System();

	void Start();

	void End();

	Admin* operator() ();

	map<int, People*>& GetPeoples();

	Admin* GetAdmin();
};
