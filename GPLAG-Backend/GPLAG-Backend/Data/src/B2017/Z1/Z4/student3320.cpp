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
#include <algorithm>

using namespace std;

string Palindrom(string s) {
	string okreni(s.rbegin(), s.rend());
	return okreni;
}

string NapraviPalindrom(string s, vector<string>kolekcija) {
	if(s.empty() || kolekcija.size()==0) return 0;
	int duzina=kolekcija.size();
	for(int i=0; i<duzina-1; i++) {
		for(int j=i+1; j<duzina; j++) {
			if(kolekcija.at(i)==kolekcija.at(j)) {
				for(int k=i; k<duzina-1; k++) {
					kolekcija.at(k)=kolekcija.at(k+1);
				}
				j--;
				duzina--;
			}
		}
	}
	kolekcija.resize(duzina);
	
	int brojac;
	int a, nazad;
	for(int i=0; i<kolekcija.size(); i++) {
		for(int j=0; j<s.length(); j++) {
			if(s.at(i)==' ') continue;
			else {
				if(s.at(j)==kolekcija.at(i).at(0)) {
					a=0;
					brojac=0;
					nazad=j;
					while(s.at(j)==kolekcija.at(i).at(a)) {
						a++;
						j++;
						brojac++;
					}
					if(brojac==kolekcija.at(i).length()) {
						s.insert(nazad, Palindrom(kolekcija.at(i)));
					} else {
						do{
							j++;
						}while(s.at(j)!=' ');
					}
				} 
			}
		}
	}
	return s;
}

//void NapraviPoluPalindrom(std::string string, std::vector)

int main () {
	try {
   		cout << "Unesite recenicu: ";
		string s;	
		getline(cin, s);
	
		cout << "Unesite fraze: ";
		vector<string>V;
		string temp;
		while(getline(cin, temp)) {
			if(temp.empty()) break;
			else V.push_back(temp);
		}
		
	//	std::cout << V.size() << " " << s.length() << std::endl;
		string rez=NapraviPalindrom(s, V);
	//	string rez=Palindrom(s);
		cout << "Recenica nakon Palindrom transformacije: ";
		cout << rez;
		
//		std::cout << s;
//		std::cout << "Recenica nakon PoluPalindrom transformacije: " << endl;
//		NapraviPoluPalindrom(s, temp);
	}catch(domain_error izuzetak) {
		cout << izuzetak.what() << endl;
	}
	return 0;
}

/*for(int i=0; i<string.length(); i++) {
		while(string.at(i)==' ') continue;
		for(int j=0; j<vektor.size(); j++) {
			provjera=true;
			if(string.at(i)!=vektor.at(j).at(0)) continue;
			else {
				int a=1, b=1, brojac=0;
				while(string.at(a)!=' ') {
					if(string.at(a)==vektor.at(j).at(b)) {
						a++;
						b++;
						brojac++;
						continue;
					} else {
						provjera=false;
						break;
					}
				}
				if(provjera) {
					a--;
					char temp;
					for(int x=0; x<brojac/2; x++) {
						temp=string.at(i+a-brojac);
						string.at(i+a-brojac)=string.at(i+a-x);
						string.at(i+a-x)=temp;
					}
					i=a;
				}
			}
		}
	}*/