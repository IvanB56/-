#include <iostream>
#include <filesystem>
#include <windows.h>
#include <direct.h>
#include <fstream>

#include "OperationWithCatalog.h"
#include "Color.h"

//работа с каталогами и файлами(создание, удаление)

void CreatNewFile(std::filesystem::path Path) {
	std::string nameFIle;
	gotoxy(5, 3);
	std::cout << "Enter the name of the new file: ";
	std::cin >> nameFIle;
	Path /= nameFIle;
	std::fstream newFile(Path);
	/*if (newFile.is_open()) {
		std::cout << "File exist!";
	}*/
	newFile.close();
}

void CreatNewCatalog(std::filesystem::path Path) {
	char nameCatalog[MAX_PATH];
	gotoxy(5, 3);
	std::cout << "Enter new name: ";
	std::cin >> nameCatalog;
	Path /= nameCatalog;
	std::filesystem::create_directories(Path);
}

char getChar();
void deleteCatalog(std::filesystem::path catalogPath) {
	gotoxy(5, 3);
	std::cout << "Do you really want to delete a directory/file? (y/n): ";
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
			std::cout << "Do you really want to delete a directory/file? (y/n): ";
		}
	}
}