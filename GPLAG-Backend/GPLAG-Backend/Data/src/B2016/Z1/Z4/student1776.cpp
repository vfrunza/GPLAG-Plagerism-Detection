/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

void Provjera(std::vector<std::string> s) {
	for (int i = 0; i <= s.size() - 1; i++) {
		for (int j = 0; j <= s[i].length() - 1; j++) {
			if (s[i][j] < 'A' || (s[i][j] > 'Z' && s[i][j] < 'a') || s[i][j] > 'z') throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
}

std::string ObrniFraze (std::string recenica, std::vector<std::string> popis) {
	int duzinaRecenice(recenica.length());
	for (int i = 0; i < popis.size(); i++) {
		int duzinaFraze(popis.at(i).size());
		for (int j = 0; j <= duzinaRecenice - duzinaFraze; j++) {
			if (recenica.substr(j, duzinaFraze) == popis.at(i)) {
				for (int k = 0; k <= duzinaFraze/2 - 1; k++) {
					char temp = recenica.at(j + duzinaFraze - k - 1);
					recenica.at(j + duzinaFraze - k - 1) = recenica.at(j + k);
					recenica.at(j + k) = temp;
				}
				j += duzinaFraze;
			}
		}
	}
	return recenica;
}

std::string IzmijeniUPigLatin (std::string recenica, std::vector<std::string> popis) {
	if (popis.size() != 0) Provjera(popis);
	int duzinaRecenice(recenica.length());
	if (popis.size() == 0) {
		for (int j = 0; j <= duzinaRecenice - 1; j++) {
			int brojac(0);
			if (recenica.at(j) < 'A' || (recenica.at(j) > 'Z' && recenica.at(j) < 'a') || recenica.at(j) > 'z') continue;
			while (j <= duzinaRecenice - 1 && ((recenica.at(j) >= 'A' && recenica.at(j) <= 'Z') || (recenica.at(j) >= 'a' && recenica.at(j) <= 'z'))) {
				brojac++;
				j++;
			}
			j -= brojac;
			duzinaRecenice += 2;
			recenica.insert(recenica.begin() + j + brojac, recenica[j]);
			recenica.erase(recenica.begin() + j);
			recenica.insert(recenica.begin() + j + brojac, 'a');
			recenica.insert(recenica.begin() + j + brojac + 1, 'y');
			j += brojac + 2;
		}
		return recenica;
	}
	for (int i = 0; i <= popis.size() - 1; i++) {
		int duzinaFraze(popis.at(i).size());
		for (int j = 0; j <= duzinaRecenice - duzinaFraze; j++) {
			if ((recenica.substr(j, duzinaFraze) == popis.at(i) && ( recenica[j-1] < 'A' || (recenica[j-1] > 'Z' && recenica[j-1] < 'a') || recenica[j-1] > 'z')) || (recenica.substr(j, duzinaFraze) == popis.at(i) && j == 0)) {
				duzinaRecenice += 2;
				recenica.insert(recenica.begin() + j + duzinaFraze, recenica[j]);
				recenica.erase(recenica.begin() + j);
				recenica.insert(recenica.begin() + j + duzinaFraze, 'a');
				recenica.insert(recenica.begin() + j + duzinaFraze + 1, 'y');
				j += duzinaFraze + 2;
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
	std::string fraza;
	for (int i = 0; ; i++) {
		std::getline(std::cin, fraza);
		if (fraza.length() == 0) {
			break;
		}
		fraze.push_back(fraza);
	}
	std::string obrnuto(ObrniFraze(recenica, fraze));
	try {
		std::string pig(IzmijeniUPigLatin(recenica, fraze));
		std::cout << "Recenica nakon PigLatin transformacije: ";
		for (int i = 0; i < pig.length(); i++) 
			std::cout << pig[i];
	}
	catch (std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what();
	}
	std::cout << std::endl;
	std::cout << "Recenica nakon obrtanja fraza: ";
	for (int i = 0; i < obrnuto.length(); i++)
		std::cout << obrnuto[i];
	
	return 0;
}