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

std::string Obrni(std::string rijec) {
	std::string obrnuto = "";
	for(int i = rijec.size() - 1; i >= 0; i--) {
		obrnuto.push_back(rijec[i]);
	}
	return obrnuto;
}

std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze) {
	for(int i = 0; i < fraze.size(); i++) {
		int pozicija;
		std::string fraza = Obrni(fraze[i]);
		if(fraze[i] == fraza)
			continue;
		do {
			pozicija = recenica.find(fraze[i]);
			if(pozicija != std::string::npos) {
				recenica.replace(pozicija, fraza.size(), fraza);
			}
		} while(pozicija != std::string::npos);
	}
	return recenica;
}

std::string IzmijeniUPL(std::string rijec) {
	std::string pigLatin = "";
	for(int i = 1; i < rijec.size(); i++) {
		pigLatin.push_back(rijec[i]);
	}
	if(rijec.size() > 0) {
		pigLatin.push_back(rijec[0]);
	}
	pigLatin += "ay";
	return pigLatin;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> fraze) {
	if(fraze.size() > 0) {
		for(int i = 0; i < fraze.size(); i++) {
			for(int j = 0; j < fraze[i].size(); j++) {
				if(!((fraze[i][j] >= 'A' && fraze[i][j] <= 'Z') || (fraze[i][j] >= 'a' && fraze[i][j] <= 'z'))) {
					throw std::domain_error("Nekorektan izbor rijeci");
				}
			}
			int pozicija;
			do {
				std::string pigLatin = IzmijeniUPL(fraze[i]);
				pozicija = recenica.find(fraze[i]);
				if(pozicija != std::string::npos) {
					recenica.replace(pozicija, fraze[i].size(), pigLatin);
				}
			} while(pozicija != std::string::npos);
		}
	}
	else {
		int pozicija, duzina;
		pozicija = 0;
		while(recenica[pozicija] != '\0') {
			while(!((recenica[pozicija] >= 'A' && recenica[pozicija] <= 'Z') || (recenica[pozicija] >= 'a' && recenica[pozicija] <= 'z'))) {
				pozicija++;
				if(recenica[pozicija] == '\0')
					break;
			}
		}
		duzina = 0;
		while((recenica[pozicija + duzina] >= 'A' && recenica[pozicija + duzina] <= 'Z') || (recenica[pozicija + duzina] >= 'a' && recenica[pozicija + duzina] <= 'z')) {
			duzina++;
		}
		std::string pigLatin = "";
		for(int i = 0; i < duzina; i++) {
			pigLatin.push_back(recenica[pozicija + i]);
		}
		pigLatin = IzmijeniUPL(pigLatin);
		recenica.replace(pozicija, duzina, pigLatin);
		while((recenica[pozicija] >= 'A' && recenica[pozicija] <= 'Z') || (recenica[pozicija] >= 'a' && recenica[pozicija] <= 'z')) {
			pozicija++;
		}
	}
	return recenica;
}

int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	std::vector<std::string> fraze;
	std::string fraza;
	do {
		std::getline(std::cin, fraza);
		if(fraza != "") {
			fraze.push_back(fraza);
		}
	} while(fraza != "");
	std::cout << "Recenica nakon PigLatin transformacije: ";
	std::string pigLatin = IzmijeniUPigLatin(recenica, fraze);
	std::cout << pigLatin << std::endl;
	std::cout << "Recenica nakon obrtanja fraza: ";
	std::string obrnuta = ObrniFraze(recenica, fraze);
	std::cout << obrnuta << std::endl;
	return 0;
}