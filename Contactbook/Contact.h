#pragma once
#include<string>
struct Contact {
	std::string name;
	std::string phone;
};

void addContact();
void showAllContacts();
void showMenu();