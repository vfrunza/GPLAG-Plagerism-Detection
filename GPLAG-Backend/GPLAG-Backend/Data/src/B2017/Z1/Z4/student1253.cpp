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
#include <cmath>
#include <cstring>


bool DaLiJeSlovo(char znak) {
	return ((znak>='A' && znak<='Z') || (znak>='a' && znak<='z'));
}

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> fraze)
{

	for(int k=0; k<int(fraze.size()); k++) {           //pomocu "k" pristupamo frazama koje se nalaze u drugom parametru funkcije
		int duzina((fraze.at(k)).length());            //ovo je duzina fraze i koristit cemo je za funkciju "substr" pri poredjenju rijeci
		for(int i=0; i<int(recenica.length()); i++) {
			if(duzina <= (int(recenica.length())-i)) { //fraza, da bi se pronasla, mora biti manja ili jednaka duzini preostalog dijela recenice, od "i" do kraja
				if( (recenica.substr(i, duzina) == fraze.at(k)) && ( (i+duzina)==int(recenica.length()) || !DaLiJeSlovo(recenica.at(i+duzina)) ) && (i==0 || !DaLiJeSlovo(recenica.at(i-1))) ) { //uslov je da se ne trebaju mijenjati dijelovi rijeci, pa provjeravamo da li je iza/ispred rijeci slovo ili kraj/pocetak stringa
					for(int j=duzina-1; j>=0; j--) {
						recenica.insert(recenica.begin() + (duzina+i), (fraze.at(k)).at(j));
						i++;
					}
					i--;     //for petlja ce pomjeriti "i" pa ovo radimo da se ne preskoci neki znak
				}
			} else break;
		}
	}
	return recenica;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> fraze)
{

	for(int k=0; k<int(fraze.size()); k++) {
		int duzina((fraze.at(k)).length());
		for(int i=0; i<int(recenica.length()); i++) {
			if(duzina <= (int(recenica.length())-i)) {
				if( (recenica.substr(i, duzina) == fraze.at(k)) && ( (i+duzina)==int(recenica.length()) || !DaLiJeSlovo(recenica.at(i+duzina)) ) && (i==0 || !DaLiJeSlovo(recenica.at(i-1))) ) {
					for(int j=duzina-1-(duzina/2); j>=0; j--) {
						recenica.at(i + std::floor(duzina/2)) = (fraze.at(k)).at(j); //funkcije su iste, samo sto ovdje palindrom pravimo na drugi nacin
						i++;
					}
					i--; 
				}
			} else break;
		}
	}

	return recenica;
}

int main ()
{
	std::string s;
	std::vector<std::string> rijeci;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout<<"Unesite fraze: ";
	char znak;
	int i(0);   //pomocu "i" mijenjamo velicinu vektora stringova
	while( (znak=std::cin.get()) != '\n' ) {
		rijeci.resize(i+1);
		(rijeci.at(i)).push_back(znak);
		while((znak=std::cin.get()) != '\n' ) (rijeci.at(i)).push_back(znak); //upisujemo znakove u jedan string sve dok se ne unese "\n"
		i++;
	}
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(s, rijeci)<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(s, rijeci)<<std::endl;

	return 0;
}