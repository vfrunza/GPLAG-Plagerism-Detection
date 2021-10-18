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
#include <string>

std::string Palindrom (std::string s) {
	std::string obrnut;
	obrnut.resize(int(s.length()));
	for (int i=0; i<int(s.length()); i++) {
		obrnut.at(i)=s.at(int(s.length() -1-i));
	}
	return obrnut;
}

std::string NapraviPalindrom (std::string s, std::vector<std::string>fraze) {
	for (int i=0; i<fraze.size(); i++) {
		bool razmak(true);
		for (int k=0; k<s.length(); k++) {
			if(s.at(k)==' ') razmak=true;
			else if (razmak) {
				razmak=false;
				if(s.substr(k, fraze.at(i).length()) == fraze.at(i) && ((k+fraze.at(i).length() == s.length()) || (!((s.at(k+fraze.at(i).length()) >= 'A' && s.at(k+fraze.at(i).length()) <='Z') || (s.at(k+fraze.at(i).length())>='a' && s.at(k+fraze.at(i).length())<='z'))))) {
					s.insert(k+fraze.at(i).length(), Palindrom(fraze.at(i)));
				}
			}
		}
	}
		
	return s;
}

std::string NapraviPoluPalindrom (std::string s, std::vector<std::string>fraze) {
	for (int i=0; i<int(fraze.size()); i++) {
		bool razmak(true);
		for(int j=0; j<s.length(); j++) {
			if(s.at(j)==' ') razmak=true;
			else if(razmak) {
				razmak=false;
				if(s.substr(j, fraze.at(i).length()) == fraze.at(i) && ((j+fraze.at(i).length() == s.length()) || (!((s.at(j+fraze.at(i).length())>='A' && s.at(j+fraze.at(i).length())<='Z') || (s.at(j+fraze.at(i).length())>='a' && s.at(j+fraze.at(i).length())<='z'))))) {
					int br(j+fraze.at(i).length()/2 - 1);
					if(fraze.at(i).length() % 2!=0) {
						for(int k=j+fraze.at(i).length()/2 + 1; k<j+fraze.at(i).length(); k++) {
							s.at(k)=s.at(br);
							br--;
						}
					} else {
						for (int k=j+fraze.at(i).length()/2; k<j+fraze.at(i).length(); k++) {
							s.at(k)=s.at(br);
							br--;
						}
					}
						
					
				}
			}
		}
		
	}
	return s;
}

int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	std::vector<std::string>fraze;
	std::string s;
	do {
		std::getline (std::cin, s);
		if(s.length()==0) break;
		fraze.push_back(s);
	} while (s.length()!=0);

	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, fraze) << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica, fraze);
	
	return 0;
}