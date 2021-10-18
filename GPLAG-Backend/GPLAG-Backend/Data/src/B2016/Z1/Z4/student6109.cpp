/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>

std::string ObrniFraze(std::string recenica, std::vector<std::string>fraze) {
	std::vector<std::string>POMOCNI;
	std::string string1=recenica;
	
		
	return string1;
}


int main() {
	
	std::cout << "Unesite recenicu: ";
	std::string string;
	std::getline(std::cin, string);
	std::cout << "Unesite fraze: ";
	std::vector<std::string>rijeci;
	std::string temp;
	do{
    	std::cin >> temp;
      	rijeci.push_back(temp);
	}while(temp.length()!='\n');
	
	std::string POMOCNI;
	POMOCNI=ObrniFraze(string, rijeci);
	std::cout << POMOCNI;
	return 0;
}