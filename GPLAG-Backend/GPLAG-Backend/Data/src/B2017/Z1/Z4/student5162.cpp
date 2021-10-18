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

std::string Obrnut(std::string s) // Funkcija koju cemo pozivati da obrne rijec ili dio rijeci ukoliko dodje do poklapanja neke od fraza i recenice
{
	std::string finalni;
	for(int i(s.size()-1); i>=0; i--)
		finalni.push_back(s.at(i));
	return finalni;
}

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> fraze)
{
	for(int i(0); i<fraze.size(); i++) {
		for(int k(0); k<recenica.length(); k++) {
			int j(0);
			if(fraze.at(i).at(j)==recenica.at(k)) {
				if((k+fraze.at(i).length()<=recenica.length()) && (fraze.at(i)==recenica.substr(k,fraze.at(i).length()))) {
					// Ovaj korak provjerava da li je neka od fraza upotpunosti jednaka sa nekom od rijeci recenica
					if((k-1>=0) && ((recenica.at(k-1)>='a' && recenica.at(k-1)<='z') || (recenica.at(k-1)>='A' && recenica.at(k-1)<='Z'))) continue;
					else if((k+fraze.at(i).length()<recenica.length()) && (((recenica.at(k+fraze.at(i).length())>='a' && recenica.at(k+fraze.at(i).length())<='z') || (recenica.at(k+fraze.at(i).length())>='A' && recenica.at(k+fraze.at(i).length())<='Z')))) continue;
					// Najbitniji dio zadatka, gdje se provjerava, da li je sljedeci znak koji dolazi nakon kraja rijeci slovo ili ne, pri cemu obavezno navodimo prvi uslov, kojim ne smijemo izaci van opsega, odnosno baziramo se na principu kratkospojne evaloacije
					else {
						// Specifican mehanizam,po kojem mjenjamo recenicu onako kako se u zadatku i trazi i povecavamo brojac k, da ne bi doslo do beskonacnog ponavljanja
						recenica=recenica.substr(0,k+fraze.at(i).length())+ Obrnut(fraze.at(i)) + recenica.substr(k+fraze.at(i).length(),recenica.length()-k-fraze.at(i).length());
						k=k+2*fraze.at(i).length();
					}
				}
			}
		}
	}
	return recenica;
}
std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> fraze)
{
	for(int i(0); i<fraze.size(); i++) {
		for(int k(0); k<recenica.length(); k++) {
			int j(0);
			if(fraze.at(i).at(j)==recenica.at(k)) {
				if((k+fraze.at(i).length()<=recenica.length()) && (fraze.at(i)==recenica.substr(k,fraze.at(i).length()))) {
					if((k-1>=0) && ((recenica.at(k-1)>='a' && recenica.at(k-1)<='z') || (recenica.at(k-1)>='A' && recenica.at(k-1)<='Z'))) continue;
					if((k+fraze.at(i).length()<recenica.length()) && (((recenica.at(k+fraze.at(i).length())>='a' && recenica.at(k+fraze.at(i).length())<='z') || (recenica.at(k+fraze.at(i).length())>='A' && recenica.at(k+fraze.at(i).length())<='Z')))) continue;
					else {
						if(fraze.at(i).length()%2==1) { //Ukoliko je duzina rijeci neparna, uzet ce se u obzir srednje slovo, a ukoliko je parna, nece, ostatak koda je objasnjen u slicnoj funkciji KreirajPalindrom
							recenica=recenica.substr(0,k+fraze.at(i).length()/2+1) +Obrnut(fraze.at(i).substr(0,fraze.at(i).length()/2)) + recenica.substr(k+fraze.at(i).length(),recenica.length()-k-fraze.at(i).length());
							k=k+fraze.at(i).length();
						} else {
							recenica=recenica.substr(0,k+fraze.at(i).length()/2) +Obrnut(fraze.at(i).substr(0,fraze.at(i).length()/2)) + recenica.substr(k+fraze.at(i).length(),recenica.length()-k-fraze.at(i).length());
							k=k+fraze.at(i).length();
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
	std::string s, palindrom, polupalindrom;
	std::vector<std::string> fraze;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout<<"Unesite fraze: ";
	do {
		std::string unos;
		std::getline(std::cin, unos);
		if(unos.length()==0)
			break;
		else fraze.push_back(unos);
	} while(true);
	palindrom=NapraviPalindrom(s,fraze);
	polupalindrom=NapraviPoluPalindrom(s,fraze);
	std::cout<<"Recenica nakon Palindrom transformacije: "<<palindrom;
	std::cout<<"\nRecenica nakon PoluPalindrom transformacije: "<<polupalindrom;
	return 0;
}