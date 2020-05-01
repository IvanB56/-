#include <iostream>
#include <vector>
#include <iterator>
#include <filesystem>
#include <Windows.h>
#include <iomanip>
#include <conio.h>

#include "ShowDisk.h"
#include "Color.h"

//работа с дисками(отображение и навигация)
void ShowDisk(std::vector<std::filesystem::path> &diskPath, std::filesystem::path &Path)
{
	int pos{ 1 };
	while (pos <= diskPath.size() && pos >= 1) {
		for (int i = 0; i < diskPath.size(); i++) {
		
			gotoxy(5, i + 5);
			if (i == (pos - 1)) {
				SetColor(0, 3);
				std::cout << i + 1 << ". " << std::setw(30) << diskPath[i].generic_string() << std::endl;
			} else {
				SetColor(0, 7);
				std::cout << i + 1 << ". " << std::setw(30) << diskPath[i].generic_string() << std::endl;
			}
		}

		int key = _getch();

		if (pos <= diskPath.size() && pos >= 1) {
			if (key == 72) {
				if (pos > 1) {
					--pos;
				} else if (pos < 1){
					pos = 1;
				}
			} else if (key == 80) {
				if (pos <= diskPath.size()) {
					++pos;
				} else if (pos == diskPath.size()){
					pos = diskPath.size() - 1;
				}
			} else if (key == 13) {
				Path = diskPath[pos - 1];
				pos = 1;
				return;
			} else if (key == 27) exit(0);
		}
	}
}