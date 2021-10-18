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
#include <algorithm>

int BrojRijeci(std::string recenica) {
	bool neslovo(true);
	int i(0), broj_rijeci(0);
	while(i<recenica.length()) {
		if(!((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z'))) {
			neslovo=true;
		}
		else if(neslovo==true) {
			neslovo=false;
			broj_rijeci++;
		}
		i++;
	}
	return broj_rijeci;
}

std::string IzdvojiRijec(std::string s, int n) {
	std::string rijec;
	int i(0), pocetak, kraj, broj_rijeci(0);
	bool neslovo(true);
	
	while(i<s.length()) {
		if(!((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))) {
			neslovo=true;
		}
		else if(neslovo==true) {
			neslovo=false;
			broj_rijeci++;
			if(broj_rijeci==n+1) pocetak=i;
		}
		if(broj_rijeci==n+1 && neslovo==true) {
			kraj=i;
			break;
		}
		i++;
	}
	
	//copy_backward(pocetak, kraj, rijec);
	
	return rijec;
}

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> rijeci) {
	for(int i=0; i<rijeci.size(); i++) {
		for(int j=0; j<BrojRijeci(recenica); j++) {
			std::string s(IzdvojiRijec(recenica, j));
			if(s==rijeci.at(i)) {
				recenica.insert(i, s);
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
	
	std::vector<std::string> Fraze;
	
	std::cout << "Unesite fraze: ";
	
	for(int i=0; ; i++) {
		std::string pom;
		std::getline(std::cin, pom);
		if(pom[0]=='\n') break;
		Fraze.push_back(pom);
	} 
	
	
	recenica = NapraviPalindrom(recenica, Fraze);
	
	
	return 0;
}