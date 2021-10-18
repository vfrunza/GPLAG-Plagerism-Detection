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
#include <vector>

std::string Obrnuto(std::string s)
{
	std::string r;
	
	for (int i = s.length() - 1; i >= 0; i--) {
		r.push_back(s.at(i));
	}
		
	return r;
}

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> rijeci)
{
	bool nadjena;
	int i;
	
	for (std::string r : rijeci) {
		for (char c1 : recenica) {
			i = 0;
			nadjena = true;
			for (char c2 : r)
				if (c1 != c2) {
					nadjena = false;
					break;
				}
			if (nadjena) {
				recenica.insert(i + r.length(), Obrnuto(r));
			}
			i++;
		}
	}
	
	return recenica;
}

int main ()
{
	char rijec[100];
	std::string recenica;
	std::vector<std::string> rijeci;
	
	std::cout << "Unesite recenicu: ";
	std::cin.getline(rijec, sizeof rijec);
	recenica = rijec;
	
	std::cout << "Unesite fraze: ";
	std::cin.getline(rijec, sizeof rijec);
	while (rijec[0] != 0) {
		rijeci.push_back(rijec);
		std::cin.getline(rijec, sizeof rijec);
	}
	
	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, rijeci) << std::endl;
	//std::cout << "Recenica nakon PoluPalindrom transformacije: Danas je lijil i sunnus dan";
	
	return 0;
}