#include<iostream>
#include"Contact.h"

int main() {
	loadContactsFromFile();
	while (true) {
		showMenu();
		int choice;
		std::cout << "请输入选择: ";
		std::cin >> choice;
		if (std::cin.fail()) { 
			std::cin.clear();  // 清除错误状态
			std::cin.ignore(10000, '\\n'); // 清空输入缓冲区
			std::cout << "输入无效，请重新输入数字！" << std::endl;
			continue; // 跳过本次循环，重新显示菜单
		}

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
			saveContactsToFile();
			std::cout << "数据已保存，退出程序！" << std::endl;
			return 0;
		default:
			std::cout << "无效选择，请重新输入" << std::endl;
		}
	}
	return 0;
}