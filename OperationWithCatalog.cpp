#include <iostream>
#include <filesystem>
#include <windows.h>
#include <string>
#include <fstream>
#include <conio.h>

#include "OperationWithCatalog.h"
#include "Color.h"

//работа с каталогами и файлами(создание, удаление)

void CreatNewFile(std::filesystem::path Path) {
	std::string nameFile;
	gotoxy(5, 3);
	std::cout << "Введите новое имя файла: ";
	std::getline(std::cin, nameFile);
	if (nameFile.empty()) {
		return;
	}
	Path /= nameFile;
	std::ofstream newFile(Path);
	newFile.close();
}

void CreatNewCatalog(std::filesystem::path Path) {
	std::string nameCatalog;
	gotoxy(5, 3);
	std::cout << "Введите новое имя каталога: ";
	std::getline(std::cin, nameCatalog);
	if (nameCatalog.empty()) {
		return;
	}
	Path /= nameCatalog;
	std::filesystem::create_directories(Path);
}

char getChar();
void deleteCatalog(std::filesystem::path catalogPath) {
	gotoxy(5, 3);
	std::cout << "Вы действительно хотите удалить каталог/файл? (y/n): ";
	char select = getChar();
	if (select == 'y' || select == 'Y') {
		std::filesystem::remove_all(catalogPath);
	}
}

char getChar() {
	while (1) {
		char enterSimbol;
		std::cin >> enterSimbol;
		if (enterSimbol == 'y' || enterSimbol == 'Y' || enterSimbol == 'n' || enterSimbol == 'N') {
			return enterSimbol;
		} else {
			gotoxy(5, 3);
			std::cout << "Вы действительно хотите удалить каталог/файл? (y/n): ";
		}
	}
}