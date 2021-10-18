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
using std::string;
bool DaLiJeSlovo (char s) {
	if ((s>='a' && s<='z') || (s>='A' && s<='Z')) return true;
	else return false;
}
string ObrniString (string r) {
	string povratniString;
	for (int i=r.size()-1;i>=0;i--) 
		povratniString.push_back(r.at(i));
	return povratniString;
}
string PopoloviIObrni(string r) {
	return ObrniString(r.substr(0, int(r.length())/2));
}
std::vector<int> NadjiPodstring (string recenica, string rijec) {
	std::vector<int> indeksi;
	for (int i=0;i<recenica.length();i++) 
		if (i+rijec.length()<=recenica.length())
			if (recenica.substr(i,rijec.length())==rijec) 
				if ((i==0 || !DaLiJeSlovo(recenica.at(i-1)))  && (i+rijec.length()>=recenica.length() || !DaLiJeSlovo(recenica.at(i+rijec.length())))) {
					indeksi.push_back(i);
					i+=rijec.length()-1;
				}
	return indeksi;
}
string NapraviPalindrom(string recenica, std::vector<string> popisRijeci) {
	for (auto rijec : popisRijeci) {
		auto indeksi=NadjiPodstring(recenica, rijec);
		if (indeksi.size()) {
			for (int i=0;i<indeksi.size();i++) {
				auto obrnutiString=ObrniString(rijec);
				int k(0);
				for (int j=indeksi[i]+rijec.length();j<indeksi[i]+2*rijec.length();j++) {
					recenica.insert(recenica.begin()+j, obrnutiString[k]);
					k++;
				}
				for (int l=0;l<indeksi.size();l++)
					indeksi.at(l)+=rijec.length();
			}
		}
	}
	return recenica;
}
string NapraviPoluPalindrom(string recenica, std::vector<string> popisRijeci) {
	for (auto rijec: popisRijeci) {
		auto indeksi=NadjiPodstring(recenica, rijec);
		if (indeksi.size()) {
			for (int i=0;i<indeksi.size();i++) {
				auto obrnutiString=PopoloviIObrni(rijec);
				int k(0);
				for (int j=indeksi.at(i)+obrnutiString.length()+(rijec.length()%2==1);j<indeksi.at(i)+rijec.length();j++) {
					recenica.at(j)=obrnutiString.at(k);
					k++;
				}
			}
		}
	}
	return recenica;
}
int main ()
{
	cout<<"Unesite recenicu: ";
	string recenica;
	std::getline(std::cin, recenica);
	cout<<"Unesite fraze: ";
	std::vector<string> popisRijeci;
	string rijec;
	do {
		std::getline(std::cin, rijec);
		if (rijec.length()) 
			popisRijeci.push_back(rijec);

	} while(rijec.length());
	cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica, popisRijeci)<<std::endl<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica, popisRijeci);
	return 0;
}