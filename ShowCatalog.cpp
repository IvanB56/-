#include <iostream>
#include <vector>
#include <iterator>
#include <filesystem>
#include <Windows.h>
#include <iomanip>

#include "ShowCatalog.h"
#include "Color.h"
#include "KeyPress.h"

void ShowCatalog(std::vector<std::filesystem::path>& content, std::filesystem::path& Path) {
	int position{ 1 };
	while (position <= (content.size()) && position >= 1) {
		for (int i = 0; i < content.size(); i++)
		{
			gotoxy(5, i + 4);
			if (i == position - 1) {
				SetColor(0, 3);
				std::cout << std::setw(2) << i + 1 << ". " << std::setw(80) << content[i].filename() << std::endl;
			}
			else {
				SetColor(0, 7);
				std::cout << std::setw(2) << i + 1 << ". " << std::setw(80) << content[i].filename() << std::endl;
			}
		}
		KeyPress(content, Path, position);
	}
}