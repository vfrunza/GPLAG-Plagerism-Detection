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
#include <stdexcept>
#include <string>


std::string NapraviPalindrom(std::string palindrom, std::vector<std::string> fraze) {
	for(int i = 0; i < fraze.size(); i++) {
		int j(0), k(0);
		while(k < palindrom.length()) {
			j = 0;
			while (fraze.at(i).at(j) != palindrom.at(k))  {
				k++;
				if(k == palindrom.length()) break;
			}
			if(k < palindrom.length()) {
				while (fraze.at(i).at(j) == palindrom.at(k) && k < palindrom.length() && j < fraze.at(i).length()) {
					j++;
					k++;
					if(j == fraze.at(i).length() || k == palindrom.length()) break;
				}
				if(j == fraze.at(i).length()) {
					j = 0;
					bool pro = false;
					if(palindrom.length() == k) {
						k--;
						pro = true;
					}
					if(!((palindrom.at(k) >= 'A' && palindrom.at(k) <= 'Z') || (palindrom.at(k) >= 'a' && palindrom.at(k) <= 'z')) || k + 1 == palindrom.length()) {
						if(pro) k++;
						std::string naopacke = fraze.at(i);
						int g(0);
						for (j = fraze.at(i).length() - 1; j >= 0 ; j--) {
							naopacke.at(g++) = fraze.at(i).at(j);
						}
						palindrom.insert(k, naopacke);
						k += fraze.at(i).length();
					}
				}
			}
		}
	}
	return palindrom;
}

std::string NapraviPoluPalindrom(std::string palindrom, std::vector<std::string> fraze) {
		for(int i = 0; i < fraze.size(); i++) {
		int j(0), k(0);
		while(k < palindrom.length()) {
			j = 0;
			while (fraze.at(i).at(j) != palindrom.at(k))  {
				k++;
				if(k == palindrom.length()) break;
			}
			if(k < palindrom.length()) {
				while (fraze.at(i).at(j) == palindrom.at(k) && k < palindrom.length() && j < fraze.at(i).length()) {
					j++;
					k++;
					if(j == fraze.at(i).length() || k == palindrom.length()) break;
				}
				
				if(j == fraze.at(i).length()) {
					j = 0;
					std::string naopacke(fraze.at(i).length()/2, 'a');
					k = k - fraze.at(i).length()/2;
					for (j = fraze.at(i).length()/2 - 1; j >= 0 ; j--) {
						palindrom.at(k++) = fraze.at(i).at(j);
					}
					k += fraze.at(i).length()/2 + 1;
				}
			}
		}
	}
	return palindrom;
}
int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::vector<std::string> fraze;
	std::cout << "Unesite fraze: ";
		for(;;) {
		std::string fraza;
		std::getline(std::cin, fraza);
		if(fraza == "") break;
		fraze.push_back(fraza);
	}
	std::cout << "Recenica nakon Palindrom transformacije: ";
	std::cout <<  NapraviPalindrom(recenica, fraze) <<std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: ";
	std::cout <<  NapraviPoluPalindrom(recenica, fraze);
	return 0;
}