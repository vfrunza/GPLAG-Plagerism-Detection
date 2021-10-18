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
#include <iomanip>

bool Slovo(char znak)															//fja koja provjerava da li je poslani znak slovo
{
	if((znak>='a' && znak<='z') || (znak>='A' && znak<='Z')) return true;
	return false;
}

std::string IzvrnutNaopacke(std::string s)
{
	int duzina(s.length());
	std::string rezultat;
	for(int i=duzina-1; i>=0; i--)
		rezultat.push_back(s.at(i));
	return rezultat;
}

std::string NapraviPoluPalindrom
(std::string s, std::vector<std::string> popis_rijeci)
{

	for(int i=0; i<popis_rijeci.size(); i++) {
		int duzina(popis_rijeci.at(i).length());								//uzima se string po string sa spiska fraza
		for(int j=0; j<=s.length()-duzina; j++) {								//provjerava se slovo po slovo iz poslanog stringa s

			if(j+popis_rijeci.at(i).length()>s.length()) break;
			std::string podstring(s.substr(j, popis_rijeci.at(i).length()));

			
			if(popis_rijeci.at(i)==podstring &&
			        (j==0 || Slovo(s.at(j-1))==false) &&
			        (j+duzina-1==s.length()-1 || Slovo(s.at(j+duzina))==false)) {

				if(podstring.length()%2!=0) j++;
				podstring.resize(podstring.length()/2);
				std::string x(IzvrnutNaopacke(podstring));
				int brojac(0);
				for(auto znak: x) {
					s.at(j+brojac+x.length())=znak;								//mijenja se drugi dio fraze
					brojac++;
				}
				j++;
			}
		}
	}
	return s;
}

std::string NapraviPalindrom
(std::string s, std::vector<std::string> popis_rijeci)
{

	for(int i=0; i<popis_rijeci.size(); i++) {
		int duzina(popis_rijeci.at(i).length());								//uzima se jedan po jedan string sa spiska fraza
		for(int j=0; j<=s.length()-duzina; j++) {								//provjerava se slovo po slovo iz poslanog stringa s

			if(j+int(popis_rijeci.at(i).length())>s.length()) break;
			std::string podstring(s.substr(j, popis_rijeci.at(i).length()));
			

			if(popis_rijeci.at(i)==podstring &&
			        (j==0 || Slovo(s.at(j-1))==false) &&
			        (j+duzina-1==s.length()-1 || Slovo(s.at(j+duzina))==false)) {

				std::string x(IzvrnutNaopacke(podstring));

				for(int k=0; k<x.length(); k++) {
					char znak=x.at(k);
					s.insert(s.begin()+j+duzina+k, znak);						//na kraj rijeci nadovezujemo istu rijec okrenutu naopacke
				}
			}
		}
	}
	return s;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> vektor_fraza(0);
	for(;;) {																	//prekid ove petlje je kada korisnik naprazno unese enter
		std::string pomocni;
		std::getline(std::cin, pomocni);
		if(pomocni.length()!=0) vektor_fraza.push_back(pomocni);				//uneseni string je ispravan i smjesta se u vektor
		else break;
	}
	std::cout<<"Recenica nakon Palindrom transformacije: "						//ispis
	         <<NapraviPalindrom(recenica, vektor_fraza)<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "
	         <<NapraviPoluPalindrom(recenica, vektor_fraza)<<std::endl;
	return 0;
}