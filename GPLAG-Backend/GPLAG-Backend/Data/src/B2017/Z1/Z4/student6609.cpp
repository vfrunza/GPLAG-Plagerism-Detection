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

bool Slovo (char c) {
	if ((c>='A' && c<='Z') || (c>='a' && c<='z')) return true;
	return false;
}

/*bool ImaFraza (std::string recenica, int pozicija, std::string rijec) {
	int br(0);
	for (int i=pozicija; i<recenica.length(); i++) {
		br=0;
		while (recenica.at(i)==rijec.at(br) && i<recenica.length()) {			//IZUZETAK?????
			i++; br++;
		}
		if (br==rijec.length()) return true;
		if (i==recenica.length()) break;
	}
	return false;
}*/


bool IMAFRAZA (std::string recenica, std::string fraza) {
	if (recenica==fraza) return true;
	return false;
}


std::string Naopako (std::string s) {
	std::string rez;
	for (int i=s.length()-1; i>=0; i--) {
		rez.push_back(s.at(i));
	}
	return rez;
}

bool Provjera (std::string recenica, int pozicija, int duzina) {				//GRESKA U OVOJ FUNKCIJI
	/*if (pozicija==0 || pozicija==recenica.length()-1) return true;
	if (Slovo(recenica.at(pozicija-1))) return false;
	if (Slovo(recenica.at(pozicija+duzina+1))) return false;
	return true;*/
	
	
	if (pozicija==0 && !Slovo(recenica.at(duzina))) return true;
	if (pozicija+duzina==recenica.size()-1 && !Slovo(recenica.at(pozicija-1)) && pozicija!=0) return true;
	if (pozicija!=0 && !Slovo(recenica.at(pozicija-1)) && !Slovo(recenica.at(pozicija+duzina)))return true;
	return false;
	
}

std::string NapraviPalindrom (std::string recenica, std::vector<std::string> fraze) {
	
	std::string rez;
	
	if (recenica.length()==0) return rez;
	if (fraze.size()==0) return recenica;
	
	for (int i=0; i<fraze.size(); i++) {
		for (int j=0; j<recenica.length(); j++) {
			if (fraze.at(i).at(0)==recenica.at(j)) {																// v.at(0).at(0) prvi el prve fraze
				//if (ImaFraza(recenica, j, fraze.at(i))) {
				if ( IMAFRAZA (recenica.substr(j, fraze.at(i).length()), fraze.at(i)) ) {							// NE PROVJERAVA SLJEDECE NAKON PRVE FRAZE?????
					
					if (Provjera(recenica, j, fraze.at(i).length())) {
						//std::cout << "Pr: " << Provjera(recenica, j, fraze.at(i).length()) << " ";
						std::string s1 = recenica.substr(0, j);
						std::string s2 = recenica.substr(j+fraze.at(i).length(), recenica.length()-j-fraze.at(i).length());
						
						recenica = s1 + fraze.at(i) + Naopako(fraze.at(i)) + s2;
						
						j += 2*fraze.at(i).length()+1;
					
					}
					//else continue;											// ZASTO NE RADI ZA VISE POJAVLJIVANJA JEDNE RIJECI?
				}
			}
		}
	}
	rez = recenica;
	return rez;
}


std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> fraze) {
	std::string rez;
	
	if (recenica.length()==0) return rez;
	if (fraze.size()==0) return recenica;
	
	for (int i=0; i<fraze.size(); i++) {
		for (int j=0; j<recenica.length(); j++) {
			if (fraze.at(i).at(0)==recenica.at(j)) {
				if (IMAFRAZA(recenica.substr(j, fraze.at(i).length()), fraze.at(i))) {
					
					if (Provjera(recenica, j, fraze.at(i).length())) {
					
						std::string pola, pola_pom;
						if (fraze.at(i).length()%2==0) {
							pola = recenica.substr(j, fraze.at(i).length()/2);
							pola_pom = pola;
						}
						else {
							pola = recenica.substr(j, fraze.at(i).length()/2 + 1);
							pola_pom = pola.substr(0, pola.length()-1);
						}
						std::string s1 = recenica.substr(0, j);
						std::string s2 = recenica.substr(j+pola.length()+pola_pom.length(), recenica.length()-j-2*pola.length());
						recenica = s1 + pola + Naopako(pola_pom) + s2;
						j += pola.length() + pola_pom.length();
					}
					//else continue;
					
				}
				
			}
		}
	}
	
	rez = recenica;
	return rez;
}


int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::vector<std::string> fraze;
	std::string s;
	std::cout << "Unesite fraze: ";
	for (;;) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::getline(std::cin, s);
		if (s=="") break;
		fraze.push_back(s);
	}
	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, fraze) << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica, fraze) << std::endl;
	return 0;
}