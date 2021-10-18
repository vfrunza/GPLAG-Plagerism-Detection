/*B 2017/2018, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/
#include <iostream>
#include <string>
#include <vector>
typedef std::string String;
typedef std::vector<std::string> Vektor;





int main ()
{

	std::cout << "Unesite recenicu: ";

	String recenica;
	std::getline(std::cin, recenica);

	std::cout << "Unesite fraze: ";

	std::vector<String> fraze;
	String fraza;

	do {
		
		std::getline(std::cin, fraza, '\n');
		fraze.push_back(fraza);
	} while(std::cin.peek()!='\n');
	
	std::cin.clear();
	bool ima=false;
	String rijec;
	std::cin >> rijec;
	
			
			
	
	

	
	std::cout << ima << std::endl;
	
	std::cout << rijec[0] << std::endl;
	std::cout << recenica[0] << std::endl;
	
	std::cout << "Recenica nakon palindrom transformacije: ";
	
	std::cout<< std::endl;
	
	std::cout << "Recenica nakon PoluPalindrom transformacije: ";

	return 0;
}