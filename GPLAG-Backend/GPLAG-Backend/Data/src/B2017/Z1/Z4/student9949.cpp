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

std::string ObrniRijec(std::string rijec)
{
	std::string nova_rijec;
	for(int i=rijec.length()-1; i>=0; i--) {
		nova_rijec.push_back(rijec.at(i));
	}
	return nova_rijec;
}

bool UporediRijeci(std::string s1, std::string s2)
{
	bool isti(true);
	if(s1.length()!=s2.length()) return false;
	else {
		for(int i=0; i<s1.length(); i++) {
			if(s1.at(i)!=s2.at(i)) {
				isti=false;
				break;
			}
		}
	}
	return isti;
}

int BrojRijeci(std::string s)
{
	bool razmak(true);
	int k(0);
	for(int i=0; i<s.length(); i++) {
		if(s.at(i)==' ') {
			razmak=true;
		} else if(razmak) {
			k++;
			razmak=false;
		}
	}
	return k;
}

std::string NapraviPalindrom(std::string s, std::vector<std::string> Vs)
{
	std::string povratni(s);
	for(int i=0; i<Vs.size(); i++) {
		std::string s1(Vs.at(i));
		int br(BrojRijeci(s1));
		for(int j=0; j<s.length(); j++) {
			std::string Novi;
			if(br>1) {
				if(s1.at(0)==s.at(j)) {
					int k(j);
					Novi=s.substr(j,s1.length());
					if(UporediRijeci(s1,Novi)) {
						bool zadnji(false);
						while(j!=(k+s1.length())) {
							if(j==s.length()-1) {
								zadnji=true;
								break;
							}
							j++;
						}
						std::string Obrnut(ObrniRijec(Novi));
						for(int k=0; k<Obrnut.length(); k++) {
							if(zadnji) s.insert(s.begin()+(j+1),Obrnut.at(k));
							else s.insert(s.begin()+j,Obrnut.at(k));
							j++;
						}
						povratni=s;
					}
				}
			} else if(s.at(j)!=' ') {
				bool zadnji(false);
				while(s.at(j)!=' ') {
					Novi.push_back(s.at(j));
					if(j==s.length()-1) {
						zadnji=true;
						break;
					}
					j++;
				}
				if(UporediRijeci(s1,Novi)) {
					std::string Obrnut(ObrniRijec(Novi));
					for(int k=0; k<Obrnut.length(); k++) {
						if(zadnji) s.insert(s.begin()+(j+1),Obrnut.at(k));
						else s.insert(s.begin()+j,Obrnut.at(k));
						j++;
					}
					povratni=s;
				}
			}
		}
	}
	return povratni;
}

std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> Vs)
{
	std::string povratni(s);
	for(int i=0; i<Vs.size(); i++) {
		std::string s1(Vs.at(i));
		int br(BrojRijeci(s1));
		for(int j=0; j<s.length(); j++) {
			std::string Novi;
			if(br>1) {
				if(s1.at(0)==s.at(j)) {
					int k(j);
					Novi=s.substr(j,s1.length());
					if(UporediRijeci(s1,Novi)) {
						while(j!=k+s1.length()/2) {
							if(j==s.length()-1) {
								break;
							}
							j++;
						}
						std::string Obrnut(ObrniRijec(Novi));
						for(int k=Obrnut.length()/2; k<Obrnut.length(); k++) {
							s.at(j)=Obrnut.at(k);
							if(j==s.length()-1 || k==Obrnut.length()-1) break;
							j++;
						}
						povratni=s;
					}
				}
			} else if(s.at(j)!=' ') {
				int k(j);
				while(s.at(j)!=' ') {
					Novi.push_back(s.at(j));
					if(j==s.length()-1) {
						break;
					}
					j++;
				}
				if(UporediRijeci(s1,Novi)) {
					j=k+s1.length()/2;
					std::string Obrnut(ObrniRijec(Novi));
					for(int k=Obrnut.length()/2; k<Obrnut.length(); k++) {
						s.at(j)=Obrnut.at(k);
						if(j==s.length()-1 || k==Obrnut.length()-1) break;
						j++;
					}
					povratni=s;
				}
			}
		}
	}
	return povratni;
}

int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	std::string fraza;
	std::vector<std::string> vec_fr;
	while(std::cin.peek()!='\n') {
		std::getline(std::cin, fraza);
		vec_fr.push_back(fraza);
	}
	std::string Palindrom(NapraviPalindrom(recenica,vec_fr));
	std::cout << "Recenica nakon Palindrom transformacije: ";
	std::cout << Palindrom;
	std::cout << std::endl;
	std::string PoluPalindrom(NapraviPoluPalindrom(recenica,vec_fr));
	std::cout << "Recenica nakon PoluPalindrom transformacije: ";
	std::cout << PoluPalindrom;
	return 0;
}