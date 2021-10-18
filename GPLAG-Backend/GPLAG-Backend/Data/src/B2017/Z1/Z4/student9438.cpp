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

bool JeLiSlovo(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
    return false;
}

std::string NapraviPalindrom (std::string recenica, std::vector<std::string> fraze) {
	
	std::string rezultat = recenica;
	int p;
	
	for (int i(0); i<fraze.size(); i++) { // ide kroz vektor stringova
		for (int j(0); j<recenica.size(); j++) { //ide kroz glavni string
			for (int k(0); k<fraze.at(i).length(); k++) { // prolazi kroz svaku frazu pojedinacno
				if(j < recenica.size() && fraze.at(i).at(k) == recenica.at(j)) {
					if(j == 0 || !JeLiSlovo(recenica.at(j - 1))) {
						p = 0;
						while(k < fraze.at(i).length() && j <= recenica.length() - 1 && fraze.at(i).at(k) == recenica.at(j)) {
							j++;
							k++;
							p++;
						}
						if(p == fraze.at(i).size() && (j == recenica.size() || recenica.at(j) == ' ' || recenica.at(j) == ',')) {
							for(int l(0); l<fraze.at(i).size(); l++) {
								recenica.insert(recenica.begin() + j, fraze.at(i).at(l));
							}
						}
					}
				}
			}
		}
	}
	return recenica;
}

std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> fraze) {
	
	int p;
	for (int i(0); i<fraze.size(); i++) { //ide kroz vektor stringova
		for (int j(0); j<recenica.size(); j++) { //ide kroz glavni string
			for (int k(0); k<fraze.at(i).length(); k++) { //fraza se mora u potpunosti poklapati da bismo je mogli modificirati, samo sto ovdje idemo do pola rijeci
				if (j<recenica.size() && fraze.at(i).at(k) == recenica.at(j)) { //da li smo u zadanom opsegu
					if (j==0 || !JeLiSlovo(recenica.at(j - 1))) {
						p=0;
						while (k<fraze.at(i).length() && j<=recenica.length() - 1 && fraze.at(i).at(k) == recenica.at(j)) {
							j++;
							k++;
							p++;
						}
						if (p==fraze.at(i).size() && (j==recenica.size() || !JeLiSlovo(recenica.at(j)))) {
							j--; //vracamo se na posljednji znak u stringu gdje smo pronasli poklapanje
							for (int l(0); l<fraze.at(i).size()/2; l++) { //idemo do pola rijeci i prepisujemo je preko slova na kojima smo stali
								recenica.at(j) = fraze.at(i).at(l);
								j--;
							}
							j += fraze.at(i).size()/2; // vracamo se tamo gdje smo bili prije pravljenja polupalindroma
						}
					}
				}
			}
		}
	}
	return recenica;
}


int main ()
{
	
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	
	std::vector<std::string> fraze;
	std::cout << "Unesite fraze: ";
	
	while(1) {
		std::string novi;
		std::getline(std::cin, novi);
		
		if(novi.length() == 0) break;
		else if(novi.length() != 0) fraze.push_back(novi);
	}
	
	auto palindromrezultat = NapraviPalindrom (recenica, fraze);
	std::cout << "Recenica nakon Palindrom transformacije: " <<  palindromrezultat << std::endl;
	
	auto polupalindromrezultat = NapraviPoluPalindrom (recenica, fraze);
	std:: cout << "Recenica nakon PoluPalindrom transformacije: " << polupalindromrezultat;
	
	return 0;
}