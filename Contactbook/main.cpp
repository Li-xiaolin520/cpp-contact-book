#include<iostream>
#include"Contact.h"

int main() {
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
		case 0:
			std::cout << "退出程序" << std::endl;
			return 0;
		default:
			std::cout << "无效选择，请重新输入" << std::endl;
		}
	}
	return 0;
}