#include <iostream>
#include <vector>
#include <filesystem>
#include <iomanip>
#include "Color.h"

//навигация по каталогам

void Navigation(const std::vector<std::filesystem::path> content, unsigned short begPosition,
				unsigned short endPosition, int position) 
{
	for (int i = begPosition; i < endPosition; i++) {
		gotoxy(5, i + 5 - begPosition);
		if (i == (position - 1)) {
			SetColor(0, 3);
			std::cout << std::setw(2) << i + 1 << ". " << std::setw(80) <<
				content[i].filename().generic_string() << std::endl;
		} else {
			SetColor(0, 7);
			std::cout << std::setw(2) << i + 1 << ". " << std::setw(80) <<
				content[i].filename().generic_string() << std::endl;
		}
	}
}