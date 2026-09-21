#include"Contact.h"
#include<vector>
#include<iostream>
#include <fstream>
std::vector<Contact> contacts;
void showMenu() {
	std::cout << "\n=====通讯录系统=====" << std::endl;
	std::cout << "1.添加联系人" << std::endl;
	std::cout << "2.显示所有联系人" << std::endl;
	std::cout << "3.查找联系人" << std::endl;
	std::cout << "4.删除联系人" << std::endl;
	std::cout << "5.保存" << std::endl;
	std::cout << "0.退出" << std::endl;
	std::cout << "====================" << std::endl;
}

void addContact() {
	Contact newContact;
	std::cout << "请输入姓名：";
	std::cin >> newContact.name;
	std::cout << "请输入手机号：";
	std::cin >> newContact.phone;

	contacts.push_back(newContact);
	std::cout << "添加联系人成功" << std::endl;
}

void showAllContacts() {
	if (contacts.empty()) {
		std::cout << "通讯录为空" << std::endl;
		return;
	}
	std::cout << "=====所有联系人====="<<std::endl;
	for (int i = 0;i < contacts.size();i++) {
		std::cout << "姓名：" << contacts[i].name << "	|	电话：" << contacts[i].phone << std::endl;
	}
}

void searchContact() {
	if (contacts.empty()) {
		std::cout << "通讯录为空" << std::endl;
		return;
	}

	std::string targetName;
	std::cout << "请输入要查找的姓名：";
	std::cin >> targetName;

	bool found = false;
	for (int i=0;i < contacts.size(); i++){
		if (contacts[i].name == targetName) {
			std::cout << "找到联系人 -> 姓名：" << contacts[i].name << "	|	电话：" << contacts[i].phone << std::endl;
			found = true;
			break;
		}
	}
	if (!found) {
		std::cout << "没有找到名为" << targetName << "的联系人。" << std::endl;
	}
}

void deleteContact() {
	if (contacts.empty()) {
		std::cout << "通讯录为空，无可删除的联系人" << std::endl;
		return;
	}

	std::string targetName;
	std::cout << "请输入要删除的联系人姓名：";
	std::cin >> targetName;

	int targetIndex = -1;
	for (int i = 0;i < contacts.size();i++) {
		if (contacts[i].name == targetName)
		{
			targetIndex = i;
			break;
		}

	}

	if (targetIndex == -1) {
		std::cout << "没有找到名为" << targetName << "的联系人，删除失败。" << std::endl;
	}
	else {
		contacts.erase(contacts.begin() + targetIndex);
		std::cout << "成功删除联系人：" << targetName << std::endl;
	}
}

void saveContactsToFile() {
	std::ofstream outFile("contacts.txt");
	if (!outFile) {
		std::cout << "保存文件失败" << std::endl;
		return;
	}

	for (int i = 0;i < contacts.size();i++) {
		outFile << contacts[i].name << " " << contacts[i].phone << std::endl;
	}
	outFile.close();
	std::cout << "已保存到本地" << std::endl;
}

void loadContactsFromFile() {
	std::ifstream inFile("contact.txt");
	if (!inFile) {
		return;
	}
	contacts.clear();
	Contact tempContact;
	while (inFile >> tempContact.name >> tempContact.phone) {
		contacts.push_back(tempContact);
	}
	inFile.close();
	std::cout << "已加载本地数据" << std::endl;
}

void saveContactsToFile2() {
	std::ofstream outFile("contacts.txt");
	if (!outFile) {
		std::cout << "保存文件失败" << std::endl;
		return;
	}

	for (int i = 0;i < contacts.size();i++) {
		outFile << contacts[i].name << " " << contacts[i].phone << std::endl;
	}
	outFile.close();
}