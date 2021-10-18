/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autostudent9315ovima. Zalbe za ne analiziranje student9315ova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) student9315ovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autostudent9315ove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::string;
string ObrniString (string r) {
	string povratniString;
	for (int i=r.size()-1;i>=0;i--) {
		povratniString.push_back(r.at(i));
	}
	return povratniString;
}
std::vector<int> NadjiPodstring (string recenica, string rijec) {
	std::vector<int> indeksi;
	for (int i=0;i<recenica.length();i++) {
		if (i+rijec.length()<recenica.length())
			if (recenica.substr(i,rijec.length())==rijec) {
				indeksi.push_back(i);
				i+=rijec.length()-1;
			}
		}
	return indeksi;
}
string NapraviPolindrom(string recenica, std::vector<string> popisRijeci) {
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
				for (int k : indeksi) k+=rijec.length();
			}
		}
	}
	return recenica;
}
/*string NapraviPoluPalindrom(string recenica, std::vector<string> popisRijeci) {
	
}*/
int main ()
{
	string recenica{"Danas je divan, mnogo divan dan"};
	std::vector<string> popisRijeci{{"Danas"}, {"divan"}};
	string palindrom=NapraviPolindrom(recenica, popisRijeci);
	
	cout<<palindrom;
	return 0;
}