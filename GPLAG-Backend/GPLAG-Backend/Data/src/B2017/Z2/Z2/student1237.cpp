#include <iostream>
#include <vector>
#include <deque>
#include <type_traits>

enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo };

template <typename T>
T PjescaniSat(T cont, SmjerKretanja direction)
{
	// Error handling...
	
	// Get hourglass...
	
}

int main (void)
{
	std::vector<std::deque<std::deque<int>>> box{{{1, 2, 3}, {1, 2, 3}, {1, 2, 3}}, {{4, 5, 6}, {4, 5, 6}, {4, 5, 6}}, {{7, 8, 9}, {7, 8, 9}, {7, 8, 9}}};
	
	auto hourglass(PjescaniSat(box, SmjerKretanja::NaprijedNazad));
	for (int plane(0); plane < hourglass.size(); plane++)
	{
		for (int y(0), offset(0); y < hourglass.size(); (y < hourglass.size() / 2) ? (offset++) : (offset--), y++)
		{
			int temp(offset);
			while (temp != 0) { std::cout << "  "; temp--; }
				
			for (int x(0); x < hourglass.at(y).size(); x++)
				std::cout << hourglass.at(plane).at(y).at(x) << " ";
			
			temp = offset;
			while (temp != 0) { std::cout << " "; temp--; }
			std::cout << std::endl;
		}
		
		std::cout << std::endl;
	}
	
	return 0;
}