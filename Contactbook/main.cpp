#include<iostream>
#include"Contact.h"

int main() {
	loadContactsFromFile();
	while (true) {
		showMenu();
		int choice;
		std::cout << "请输入选择: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			addContact();
			break;
		case 2:
			showAllContacts();
			break;
		case 3:
			searchContact();
			break;
		case 4:
			deleteContact();
			break;
		case 5:
			saveContactsToFile();
			break;
		case 0:
			std::cout << "退出程序" << std::endl;
			saveContactsToFile2();
			return 0;
		default:
			std::cout << "无效选择，请重新输入" << std::endl;
		}
	}
	return 0;
}