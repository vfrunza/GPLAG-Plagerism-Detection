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

bool DaLiJeSlovo (char znak) {
	return ((znak>='a' && znak<='z') || (znak>='A' && znak<='Z'));
}


// Funkcija koja pronalazi rijeci sa popisa unutar recenice, te ukoliko je pronadje na kraj te rijeci u recenici
// dodaje palindrom pronadjene rijeci
std::string NapraviPalindrom (std::string recenica, std::vector<std::string> popis) {
	for (int i=0; i<popis.size(); i++) {
		for (int j=0; j<recenica.length(); j++) {
			if (popis.at(i)==recenica.substr(j, popis.at(i).length()) && ((j+popis.at(i).length()==recenica.length()) ||  (!DaLiJeSlovo(recenica.at(j+popis.at(i).length()))))  && ((j==0) || (recenica.at(j-1)==' '))) {
				std::string pomocni;
				int duzina_rijeci(popis.at(i).length());
				for (int k=duzina_rijeci-1; k>=0; k--) {
					pomocni.push_back(popis.at(i).at(k));
				}
				recenica.insert(j+duzina_rijeci,pomocni);
			}
		}
	}
	return recenica;
}

// Funkcija koja takodjer pronalazi  rijeci sa popisa unutar recenice, te ukoliko je pronadje od te rijeci formira polupalindrom
std::string NapraviPolupalindrom (std::string recenica, std::vector<std::string> popis) {
for (int i=0; i<popis.size(); i++) {
		for (int j=0; j<recenica.length(); j++) {
			if (popis.at(i)==recenica.substr(j, popis.at(i).length()) && ((j+popis.at(i).length()==recenica.length()) || (!DaLiJeSlovo(recenica.at(j+popis.at(i).length())))) && ((j==0) || (recenica.at(j-1)==' '))) {
				int k(j), duzina_rijeci(popis.at(i).length());
				
				if (duzina_rijeci%2!=0) {
					k+=(duzina_rijeci/2); 
					std::string pomocni;
					for (int l=(k-1); l>=j; l--) {
						pomocni.push_back(recenica.at(l));
					}
					recenica.insert(k+1,pomocni);
					int vel(pomocni.length());
					recenica.erase(k+vel+1,vel);
				}
				
				if (duzina_rijeci%2==0) {
					k+=(duzina_rijeci/2); 
					std::string pomocni;
					for (int l=(k-1); l>=j; l--) {
						pomocni.push_back(recenica.at(l));
					}
					recenica.insert(k,pomocni);
					int vel(pomocni.length());
					recenica.erase(k+vel,vel);
				}
				
			}
		}
	}
	return recenica;
}

int main () {
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline (std::cin, recenica, '\n');
	
	std::cout<<"Unesite fraze: ";
	std::string pomocni;
	
	std::vector<std::string> fraze;
	while (std::cin.peek()!='\n') {
		std::getline(std::cin, pomocni);
		fraze.push_back(pomocni);
	}
	std::cin.ignore(10000,'\n');
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::cout<<NapraviPalindrom(recenica,fraze)<<std::endl;

	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	std::cout<<NapraviPolupalindrom(recenica,fraze)<<std::endl;

	std::cout<<std::endl;

	return 0;
}
