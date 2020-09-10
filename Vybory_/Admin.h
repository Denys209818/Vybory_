#pragma once
#include "libs.h"
#include "VPeople.h"
#include "People.h"

class Admin
{
	map<int, VPeople*> m;
public:
	static int id_;
	static int id_peoples;
	void PushToVPeople(VPeople* p);

	void RemoveFromVPeople(VPeople* p);

	void PushToPeople(map<int, People*>& m);

	VPeople* GetIdVpeople(int a);

	int GetSize();

	friend class System;
};