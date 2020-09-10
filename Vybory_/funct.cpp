#include "libs.h"
#include "System.h"
#include "Admin.h"
#include "People.h"

void SetCol(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

char* FileName(char buffer[255], char name_[255])
{
	int i = 0;

	while (buffer[i] != '&')
	{
		name_[i] = buffer[i];
		i++;
	}

	name_[i] = '\0';

	return buffer + i + 1;
}

char* FileSurname(char buffer[255], char surname_[255])
{
	int i = 0;

	while (buffer[i] != '&')
	{
		surname_[i] = buffer[i];
		i++;
	}

	surname_[i] = '\0';
	return buffer + i + 1;
}

char* FileAge(char buffer[255], char age_[255])
{
	int i = 0;

	while (buffer[i] != '&')
	{
		age_[i] = buffer[i];
		i++;
	}
	age_[i] = '\0';

	return buffer + i + 1;
}

char* FilePass_Code(char buffer[255], char pass_code_[255])
{
	int i = 0;

	while (buffer[i] != '&')
	{
		pass_code_[i] = buffer[i];
		i++;
	}

	pass_code_[i] = '\0';

	return buffer + i + 1;
}

char* FileLogin(char buffer[255], char login_[255])
{
	int i = 0;

	while (buffer[i] != '&')
	{
		login_[i] = buffer[i];
		i++;
	}

	login_[i] = '\0';

	return buffer + i + 1;
}

char* FilePassword(char buffer[255], char password_[255])
{
	int i = 0;

	while (buffer[i] != '&')
	{
		password_[i] = buffer[i];
		i++;
	}

	password_[i] = '\0';

	return buffer + i + 1;
}

char* FileVpeople(char buffer[255], int& Vpeople_)
{
	int i = 0;
	char Vpeople[255];

	while (buffer[i] != '&')
	{
		Vpeople[i] = buffer[i];
		i++;
	}
	Vpeople[i] = '\0';

	Vpeople_ = atoi(Vpeople);
	return buffer + i + 1;
}

char* FileCheckout(char buffer[255], bool& checkout_)
{
	int i = 0;
	char checkout[255];

	while (buffer[i] != '&' && buffer[i] != '\0')
	{
		checkout[i] = buffer[i];
		i++;
	}
	checkout[i] = '\0';

	switch (atoi(checkout))
	{
	case 0: {checkout_ = false; break; }
	case 1: {checkout_ = true; break; }
	default: {checkout_ = false; }
	}
	if (buffer + i + 1 != nullptr)
	{
		return buffer + i + 1;
	}
	return buffer + i;
}

char* FileId(char buffer[255], int& id_)
{
	int i = 0;
	char id[255];
	while (buffer[i] != '&')
	{
		id[i] = buffer[i];
		i++;
	}

	id[i] = '\0';

	id_ = atoi(id);

	return buffer + i + 1;
}

char* FileCount(char buffer[255], int& count_)
{
	int i = 0;
	char count[255];
	while (buffer[i] != '&')
	{
		count[i] = buffer[i];
		i++;
	}

	count[i] = '\0';

	count_ = atoi(count);

	return buffer + i + 1;
}

char* FileText(char buffer[255], char text_[255])
{
	int i = 0;

	while (buffer[i] != '&')
	{
		text_[i] = buffer[i];
		i++;
	}

	text_[i] = '\0';

	return buffer + i + 1;
}

int StartMenu(System* s)
{
	const string login_admin = "loginadmin";
	const string password_admin = "passwordadmin";
	int counter = 1;
	int ch = 1;

	do
	{
		system("cls");
		if (counter == 1)SetCol(12);
		cout << "1. Ввiйти як користувач" << endl;
		SetCol(7);
		if (counter == 2)SetCol(12);
		cout << "2. Ввiйти як адмiн" << endl;
		SetCol(7);

		if (counter == 3)SetCol(12);
		cout << "3. Зареєструватись" << endl;
		SetCol(7);


		ch = _getch();

		switch (ch)
		{
		case 224:
		{
			switch (_getch())
			{
			case 80: counter < 3 ? counter++ : counter = 1; break;
			case 72: counter > 1 ? counter-- : counter = 3; break;
			}
		}
		}

	} while (ch != 13);
	system("cls");
	if (counter == 3)
	{
		char name[255];
		char surname[255];
		char age[5];
		char passCode[255];
		char login_[255];
		char password_[255];
		int Vpeople = 0;
		bool Check = 0;

		cout << "Ведiть iм'я - ";
		cin >> name;
		cout << "Ведiть прiзвище - ";
		cin >> surname;
		cout << "Ведiть вiк - ";
		cin >> age;
		cout << "Ведiть код паспорта - ";
		cin >> passCode;
		cout << "Ведiть логiн - ";
		cin >> login_;
		cout << "Ведiть пароль - ";
		cin >> password_;


		People* p = new People(name, surname, atoi(age), passCode, login_, password_, Vpeople, Check);

		s->GetPeoples().emplace(Admin::id_peoples++, p);
		return s->GetPeoples().size() - 1;
	}

	char login[255];
	char password[255];

	system("cls");

	cout << "Введiть логiн - ";
	cin >> login;
	cout << "Введiть пароль - ";
	cin >> password;


	switch (counter)
	{
	case 1:
	{
		for (int i = 0; i < s->GetPeoples().size(); i++)
		{
			if (strstr(s->GetPeoples()[i]->GetLogin(), login) && strstr(s->GetPeoples()[i]->GetPassword(), password))
			{
				return i;
			}
		}
		return -2;
		break;
	}
	case 2:
	{
		if (strstr(login, login_admin.c_str()) && strstr(password, password_admin.c_str()))
		{
			return -1;
		}
		return -2;
		break;
	}
	}
}

void MenuAdmin(System* s, Admin* admin)
{
	admin->PushToPeople(s->GetPeoples());
	system("cls");

	int counter = 1; int ch = 1;
	while (true)
	{
		do
		{
			system("cls");
			if (counter == 1)SetCol(12);
			cout << "Добавити кандидата" << endl;
			SetCol(7);
			if (counter == 2)SetCol(12);
			cout << "Видалити кандидата" << endl;
			SetCol(7);
			if (counter == 3) SetCol(12);
			cout << "Вийти" << endl;
			SetCol(7);

			ch = _getch();

			switch (ch)
			{
			case 224:
			{
				switch (_getch())
				{
				case 80: { counter < 3 ? counter++ : counter = 1; break; }
				case 72: {counter > 1 ? counter-- : counter = 3; break; }
				}
			}
			}


		} while (ch != 13);

		if (counter == 3) return;

		switch (counter)
		{
		case 1:
		{
			system("cls");
			char text[255];
			text[0] = '\0';
			char name[255], surname[255];
			char age[5];
			while (text[0] == '\0')
			{
				system("cls");
				cout << "Введiть текст \"Про себе\"";
				cin.getline(text, 255);
			}
			cout << "Введiть iм'я - ";
			cin >> name;
			cout << "Введiть прiзвище - ";
			cin >> surname;
			cout << "Введiть вiк - ";
			cin >> age;
			int age_;
			try
			{
				age_ = atoi(age);
			}
			catch (exception * ex)
			{
				system("cls");
				cout << ex->what() << endl;
				return;
			}

			admin->PushToVPeople(new VPeople(Admin::id_++, 0, text, name, surname, age_));
			break;
		}
		case 2:
		{
			system("cls");
			for (int i = 1; i <= admin->GetSize(); i++)
			{
				cout << i << " - " << admin->GetIdVpeople(i)->GetSurname() << endl;
			}
			char number[5];
			cin >> number;
			int num;
			try
			{
				num = atoi(number);
			}
			catch (exception * ex)
			{
				system("cls");
				cout << ex->what() << endl;
				return;
			}
			if (num <= admin->GetSize() && num > 0)
			{
				admin->RemoveFromVPeople(admin->GetIdVpeople(num));
			}
			break;
		}
		case 3:
		{
			return;
			break;
		}
		}
	}
}

void MenuPeople(System* s, People* p)
{
	int ch = 1, counter = 1;
	if (p->GetCheckout())
	{
		while (true)
		{
			do
			{
				system("cls");

				for (int i = 1; i <= (*s)()->GetSize(); i++)
				{
					if (p->GetVpeople() == i) SetCol(12);
					if (i == counter) cout << "============================" << endl;
					else cout << endl;
					cout << "Name: " << (*s)()->GetIdVpeople(i)->GetName() << endl;
					cout << "Surname: " << (*s)()->GetIdVpeople(i)->GetSurname() << endl;
					cout << "Age: " << (*s)()->GetIdVpeople(i)->GetAge() << endl;
					cout << "Count: " << (*s)()->GetIdVpeople(i)->GetCount() << endl;
					cout << "Text: " << endl;

					for (int k = 0; k < strlen((*s)()->GetIdVpeople(i)->GetText()); k++)
					{

						if (k % 20 == 0 && k != 0)
						{
							cout << (*s)()->GetIdVpeople(i)->GetText()[k] << endl;
						}
						else
						{
							cout << (*s)()->GetIdVpeople(i)->GetText()[k];
						}
					}




					if (i == counter) cout << "\n============================" << endl;
					else cout << endl;
					SetCol(7);
				}

				if (counter == (*s)()->GetSize() + 1) cout << "============================" << endl;
				cout << "\nВийти\n" << endl;
				if (counter == (*s)()->GetSize() + 1) cout << "============================" << endl;


				ch = _getch();

				switch (ch)
				{
				case 224:
				{
					switch (_getch())
					{
					case 80: counter < (*s)()->GetSize() + 1 ? counter++ : counter = 1; break;
					case 72: counter > 1 ? counter-- : counter = (*s)()->GetSize() + 1; break;
					}
				}
				}


			} while (ch != 13);
			if (counter == (*s)()->GetSize() + 1) return;

			(*s)()->GetIdVpeople(counter)->GetCount()++;

			if (p->GetVpeople() > 0 && p->GetVpeople() <= (*s)()->GetSize())
			{
				(*s)()->GetIdVpeople(p->GetVpeople())->GetCount()--;
			}

			p->GetVpeople() = counter;
		}
	}
	else
	{
		cout << "Аккаунт ще обробляється!" << endl;
	}
}