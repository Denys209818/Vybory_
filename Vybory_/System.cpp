#include "libs.h"
#include "System.h"

System::System()
{
	this->admin = new Admin();
}

void System::Start()
{
	ifstream file("baza_people.txt");
	if (!file.is_open()) { cout << "Error file!" << endl; }

	char* buffer = new char[255];

	while (!file.eof())
	{
		char name[255];
		char surname[255];
		char age[5];
		char pass_code[255];
		char login[255];
		char password[255];
		int Vpeople;
		bool checkout;

		file.getline(buffer, 255);
		if (buffer[0] != '\0')
		{
			buffer = FileName(buffer, name);
			buffer = FileSurname(buffer, surname);
			buffer = FileAge(buffer, age);
			buffer = FilePass_Code(buffer, pass_code);
			buffer = FileLogin(buffer, login);
			buffer = FilePassword(buffer, password);
			buffer = FileVpeople(buffer, Vpeople);
			buffer = FileCheckout(buffer, checkout);

			this->Peoples.emplace(Admin::id_peoples++, new People(name,
				surname, atoi(age),
				pass_code, login,
				password, Vpeople, checkout));
		}
	}

	file.close();

	ifstream file2("baza_vpeople.txt");
	if (!file2.is_open()) { cout << "Error file2!" << endl; }

	while (!file2.eof())
	{
		int id2;
		int count2;
		char text2[255];
		char name2[255];
		char surname2[255];
		char age2[5];
		file2.getline(buffer, 255);

		if (buffer[0] != '\0')
		{
			buffer = FileId(buffer, id2);
			buffer = FileCount(buffer, count2);
			buffer = FileText(buffer, text2);
			buffer = FileName(buffer, name2);
			buffer = FileSurname(buffer, surname2);
			buffer = FileAge(buffer, age2);

			Admin::id_++;
			this->admin->PushToVPeople(new VPeople(id2, count2, text2, name2, surname2, atoi(age2)));
		}
	}

	file2.close();
}

void System::End()
{
	ofstream file("baza_people.txt", ios_base::trunc);


	for (int i = 0; i < this->Peoples.size(); i++)
	{
		if (this->Peoples[i]->GetCheckout() || System::GetReset)
		{
			if (i > 0) file << "\n";
			file << this->Peoples[i]->GetName() << "&" << this->Peoples[i]->GetSurname() << "&" << this->Peoples[i]->GetAge() << "&";
			file << this->Peoples[i]->GetPassCode() << "&" << this->Peoples[i]->GetLogin() << "&" << this->Peoples[i]->GetPassword() << "&";
			file << this->Peoples[i]->GetVpeople() << "&" << (int)this->Peoples[i]->GetCheckout() << "&";
		}
	}

	file.close();

	ofstream file2("baza_vpeople.txt", ios_base::trunc);

	map<int, VPeople*>::iterator it = this->admin->m.begin();
	int l = 0;
	while (it != this->admin->m.end())
	{
		if (l != 0) file2 << "\n";
		file2 << (*it).second->GetId() << "&" << (*it).second->GetCount() << "&" << (*it).second->GetText() << "&" << (*it).second->GetName() << "&";
		file2 << (*it).second->GetSurname() << "&" << (*it).second->GetAge() << "&";
		it++;
		l++;
	}

	file2.close();

	this->Peoples.erase(this->Peoples.begin(), this->Peoples.end());

	this->admin->m.erase(this->admin->m.begin(), this->admin->m.end());

}

Admin* System::operator() ()
{
	return this->admin;
}

map<int, People*>& System::GetPeoples()
{
	return this->Peoples;
}

Admin* System::GetAdmin()
{
	return this->admin;
}