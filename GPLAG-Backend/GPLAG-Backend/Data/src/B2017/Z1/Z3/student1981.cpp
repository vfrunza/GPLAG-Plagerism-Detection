#include <iostream>
#include <cstring>
#include <algorithm>



int main ()
{
	try {
		int broj_recenica;
		std::cout << "Koliko zelite recenica: ";
		std::cin >> broj_recenica;
		std::cin.ignore(1000, '\n');
		std::cout << "Unesite recenice:" << std::endl;
		std::string* recenice = new std::string[broj_recenica];
		for (int i = 0; i < broj_recenica; i++) {
			std::string radni_prostor;
			std::getline(std::cin, radni_prostor);
			recenice[i] = radni_prostor;
		}
		
		std::sort(recenice, recenice + broj_recenica, [](std::string a, std::string b) {
			return a < b;
		});
		
		std::cout << "Sortirane recenice:\n";
		
		for (int i = 0; i < broj_recenica; i++) {
			std::cout << recenice[i] << "\n";
		}
		
		delete[] recenice;
	} catch (std::bad_alloc) {
		std::cout << "\nProblemi s memorijom!" << std::endl;
	}
	
	return 0;
}