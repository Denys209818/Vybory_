#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <map>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;


void SetCol(int a);

char* FileName(char buffer[255], char name_[255]);

char* FileSurname(char buffer[255], char surname_[255]);

char* FileAge(char buffer[255], char age_[255]);

char* FilePass_Code(char buffer[255], char pass_code_[255]);

char* FileLogin(char buffer[255], char login_[255]);

char* FilePassword(char buffer[255], char password_[255]);

char* FileVpeople(char buffer[255], int& Vpeople_);

char* FileCheckout(char buffer[255], bool& checkout_);

char* FileId(char buffer[255], int& id_);

char* FileCount(char buffer[255], int& count_);

char* FileText(char buffer[255], char text_[255]);
