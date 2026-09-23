#pragma once
#include<string>
struct Contact {
	std::string name;
	std::string phone;
};

void addContact();
void searchContact();
void deleteContact();
void showAllContacts();
void showMenu();
void saveContactsToFile();//保存到文件
void loadContactsFromFile();//从文件读取