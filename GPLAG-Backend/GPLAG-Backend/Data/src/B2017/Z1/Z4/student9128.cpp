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

using std::cout;
using std::cin;

bool Slovo(char znak) {
	return ((znak>='A' && znak<='Z') || (znak>='a' && znak<='z'));
}

std::string NapraviPalindrom (std::string recenica, std::vector<std::string> spisak) {
	
	for(int i=0; i<spisak.size(); i++) {
		int j(0);
		while(j<recenica.size()) {
			int k(0), l(j);
			if(l!=0 && Slovo(recenica.at(l-1))) {
				j++;
				continue;
			}
			while(k<spisak.at(i).length() && l<recenica.size() && spisak.at(i).at(k)==recenica.at(l)) {
			//	if(l!=0 && Slovo(recenica.at(l-1))) break;
				k++;
				l++;
				if(k==spisak.at(i).length() && (l==recenica.length() || !Slovo(recenica.at(l)))) {
					for(int m=0; m<spisak.at(i).length(); m++) {
						recenica.insert(recenica.begin()+l, spisak.at(i).at(m));
						j++;
					}
					break;
				}
			}
			j++;
		}
	}
	return recenica;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> spisak) {
	for(int i=0; i<spisak.size(); i++) {
		int j(0), broj_slova(0), cuvaj(0);
		while(j<recenica.size()) {
			int k(0), l(j);
			if(l!=0 && Slovo(recenica.at(l-1))) {
				j++;
				continue;
			}
			while(k<spisak.at(i).length() && l<recenica.size() && spisak.at(i).at(k)==recenica.at(l)) {
				k++;
				l++;
				broj_slova++;
				if(k==spisak.at(i).length() && (l==recenica.length() || !Slovo(recenica.at(l)))) {
					int m(0);
					cuvaj=l-1;
					l--;
					while(m<(spisak.at(i).length())/2) {
						recenica.at(l)=spisak.at(i).at(m);
						l--;
						m++;
					}
					j+=(cuvaj-j)+1;
				}
			}
			j++;
		}
	}
	return recenica;
}

int main ()
{
	std::string recenica, pomocni, palindrom, polu_palindrom;
	std::vector<std::string> fraze;
	
	cout<<"Unesite recenicu: ";
	std::getline(cin, recenica);
	cout<<"Unesite fraze: ";
	
	for(int i=0; ; i++) {
		std::getline(cin, pomocni);
		if(pomocni.size()==0) break;
		fraze.resize(i+1);
		fraze[i]=pomocni;
		if(char(cin.peek())=='\n') break;
	}
	
	palindrom=NapraviPalindrom(recenica, fraze);
	polu_palindrom=NapraviPoluPalindrom(recenica, fraze);
	cout<<"Recenica nakon Palindrom transformacije: "<<palindrom;
	cout<<"\nRecenica nakon PoluPalindrom transformacije: "<<polu_palindrom;
	
	return 0;
}