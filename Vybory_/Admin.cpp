#include "libs.h"
#include "Admin.h"

void Admin::PushToVPeople(VPeople* p)
{
	this->m.emplace(p->GetId(), p);
}

void Admin::RemoveFromVPeople(VPeople* p)
{
	map<int, VPeople*>::iterator it = this->m.find(p->GetId());
	this->m.erase(it);
	Admin::id_--;
}

void Admin::PushToPeople(map<int, People*>& m)
{
	map<int, People*>::iterator it = m.begin();
	while (it != m.end())
	{
		system("cls");
		int counter = 1;
		int ch = 1;
		if (!(*it).second->GetCheckout())
		{
			while (ch != 13)
			{
				system("cls");
				(*it).second->Show();
				if (counter == 1) SetCol(12);
				cout << "1. Добавити в базу" << endl;
				SetCol(7);
				if (counter == 2) SetCol(12);
				cout << "2. Видалити" << endl;
				SetCol(7);


				ch = _getch();

				switch (ch)
				{
				case 224:
				{
					switch (_getch())
					{
					case 72: {counter < 2 ? counter++ : counter = 1; break; }
					case 80: {counter > 1 ? counter-- : counter = 2; break; }
					}
				}
				}
			}

			switch (counter)
			{
			case 1: { (*it).second->GetCheckout() = true; break; }
			case 2: {(*it).second->GetCheckout() = false; break; }
			}
		}
		it++;
	}
}

VPeople* Admin::GetIdVpeople(int a)
{
	if (this->m[a] == nullptr)
	{
		return nullptr;
	}
	return this->m[a];
}

int Admin::GetSize()
{
	return this->m.size();
}