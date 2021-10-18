/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

bool imalEngleza(std::string niz, bool tip) {
	if (tip) {
		for (int i = 0; i < niz.size(); i++) {
			if (niz[i] == ' ')
				return true;
		}
	}
	for (int i = 0; i < niz.size(); i++) {
		if ((niz[i] >= 65 && niz[i] <= 90) || (niz[i] >= 97 && niz[i] <= 122) || niz[i] == ' ' || niz[i] == '.' || niz[i] == ',') continue;
		return true;
	}
	return false;
}

std::string cut(std::string niz, int x, int y) {
	std::string novi;
	if (y > niz.size()) return novi;
	for (int i = x; i < y; i++) 
		novi.push_back(niz[i]);
	return novi;
	
}

std::string obrni(std::string niz, int x, int y) {
	while (x < y) {
		char tmp(niz[x]);
		niz[x] = niz[y];
		niz[y] = tmp;
		x++;
		y--;
	}
	return niz;
}
std::string ObrniFraze(std::string niz, std::vector<std::string> fraze) {
	std::string novi(niz);
	if (imalEngleza(niz, false)) throw std::domain_error("Nekorektan izbor rijeci");
	for (int i = 0; i < fraze.size(); i++)
		if (imalEngleza(fraze[i], false)) throw std::domain_error("Nekorektan izbor rijeci");
	if (niz.size() == 0) return novi;
	for (int brojac = 0; brojac < fraze.size(); brojac++)
		for (int i = 0; i < niz.size() - fraze.size(); i++) {
			if (fraze[brojac] == cut(novi, i, fraze[brojac].size() + i)) 
				novi = obrni(novi, i, fraze[brojac].size() + i - 1);
			
		}
	return novi;
}

std::string pig(std::string niz, int x, int y) {
	std::string novi;
	for (int i = 0; i < niz.size(); i++) {
		if (i < x || i > y) 
			novi.push_back(niz[i]);
		else {
			char tmp(niz[i]);
			for (int j = i+1; j <= y; j++)
				novi.push_back(niz[j]);
			novi.push_back(tmp);
			novi.push_back('a');
			novi.push_back('y');
			i += (y - x);
			}
	}
	return novi;
}

std::string IzmijeniUPigLatin(std::string niz, std::vector<std::string> fraze) { //nije ispravno reci da je drugi element fraze al mrsko mi mjenjati
	if (imalEngleza(niz, false)) 
		throw std::domain_error("Nekorektan izbor rijeci");
	for (int i = 0; i < fraze.size(); i++)
		if (imalEngleza(fraze[i], true)) 
			throw std::domain_error("Nekorektan izbor rijeci");
	std::string novi(niz);
	if (niz.size() == 0) 
		return novi;
	int ukupno(0);
	if (fraze.size() == 0) {
		int prva(0);
		for (int i = 0; i < niz.size(); i++) {
			if (niz[i] == ' ' || i == niz.size() - 1) {
				if (i == niz.size() - 1) {
					novi = pig(novi, prva + ukupno, i + ukupno);
					break;
				}
				
				if (niz.size() == 1) {
					novi = pig(novi, 0, 0);
					break;
				}
				if (i == 0) 
					continue;
				if (niz[i - 1] == ' ') 
					continue;
				if (i != niz.size())
					novi = pig(novi, prva + ukupno, i + ukupno - 1);
				else 
					novi = pig(novi, prva + ukupno, i + ukupno - 1);
				ukupno += 2;
				prva = i + 1;
			}
		}
	}
	for (int brojac = 0; brojac < fraze.size(); brojac++)
		for (int i = 0; i < novi.size() - fraze.size(); i++) {
			int x(i + ukupno), y(fraze[brojac].size() + i + ukupno);
				if (fraze[brojac] == cut(novi, x, y)) {
					if (x != 0)
						if (novi[x - 1] != ' ') continue;
					if (y != novi.size()) 
						if (novi[y] != ' ') continue;
					novi = pig(novi, x, y - 1);
					ukupno += 2;
				}
		}
	return novi; 
}


int main () {
	
	std::string niz;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, niz);
	std::cout << "Unesite fraze: ";
	std::vector<std::string> fraze;
	for (;;) {
		std::string tmp;
		std::getline(std::cin, tmp);
		if (tmp.size() == 0) break;
		fraze.push_back(tmp);
	}
	try {
		std::string tmp(IzmijeniUPigLatin(niz, fraze));
		std::cout << "Recenica nakon PigLatin transformacije: " <<  tmp;
	}
	catch(std::domain_error e) {
		std::cout << "Izuzetak: " << e.what();
	}
	std::cout << "\n";
	try {
		std::string tmp(ObrniFraze(niz, fraze));
		std::cout << "Recenica nakon obrtanja fraza: " << tmp;
	}
	catch(std::domain_error e) {
		std::cout << "Izuzetak: " << e.what();
	}
	return 0;
}