/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <new>

int PotencijalniKrivci (char **&znak, std::vector<std::string> imena) {
	int broj(0);
	try {
		char **niz(new char* [imena.size()]);
		for(int i(0); i<imena.size(); i++) {
			try {
				niz[i]=new char[std::strlen(imena[i])+1];
				std::strcpy(niz[i], imena[i]);
				broj++;
			}
			catch(std::bad_alloc) {
				delete[] niz;
				std::cout << "Alokacija nije uspjela." << std::endl;
			}
		}	
	}	
	catch (std::bad_alloc) {
		std::cout << "Alokacija nije uspjela." << std::endl;
	}
	return broj;
}


int main () {
	
	return 0;
}