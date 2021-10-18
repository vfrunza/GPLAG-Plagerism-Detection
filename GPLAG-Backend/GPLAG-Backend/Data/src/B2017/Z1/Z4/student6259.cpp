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
using std::endl;
using std::vector;
using std::string;

int Da_li_sadrzi_frazu(string recenica, string fraza) {
	
	for(char x : fraza) if(x != ' ') {
	
		for(int i(0); i < recenica.length(); i++) { 
		
		
			for(int j(0); j < fraza.length(); j++) {
			
				if(recenica.at(i) != fraza.at(j)) {
					break;
				}
				else if(j == fraza.length() - 1 && ( (i < recenica.length() - 1 && (recenica.at(i + 1) == ' ' || recenica.at(i + 1) == ',' || recenica.at(i + 1) == '.' || recenica.at(i + 1) == '!' || recenica.at(i + 1) == '?')) || i == recenica.length() - 1)) return (i - fraza.length() + 1);
				else if(i < recenica.length() - 1) i++;
			
			}

		}
		
		break;
	}
	
	
	return -1;
}

string NapraviPalindrom(string recenica, vector<string> fraze) {
	
	for(int i(0); i < fraze.size() ; i++) {
		
		int indeks_pocetak(Da_li_sadrzi_frazu(recenica, fraze.at(i)));
		
		if(indeks_pocetak != -1) {
			
			string pom(recenica.substr((indeks_pocetak + fraze.at(i).size()), recenica.length() - 1 ));
			recenica.resize(recenica.length() + fraze.at(i).size());
			
			int k(indeks_pocetak + 2 * fraze.at(i).size()), j(0);
			while(k < recenica.length()) {
				recenica.at(k) = pom.at(j);
				k++;
				j++;
			}
			
			k = indeks_pocetak + fraze.at(i).size();
			for(int l(fraze.at(i).size() - 1); l >= 0; l--) {
				recenica.at(k) = fraze.at(i).at(l);
				k++;
			}
			
			i--;
			
		}
	}
	
	return recenica;

}

string NapraviPoluPalindrom(string recenica, vector<string> fraze) {
	
	int indeks_vec(-1);
	for(int i(0); i < fraze.size(); i++) {
		
		int indeks_pocetak(Da_li_sadrzi_frazu(recenica, fraze.at(i)));
		
		if(indeks_pocetak != -1 && indeks_pocetak != indeks_vec) {
			
			int br = indeks_pocetak + fraze.at(i).size() / 2;
			
			for(int j((fraze.at(i).size() - 1) / 2 ); j >= 0; j--) {
				recenica.at(br) = fraze.at(i).at(j);
				br++;
			}
			
			i--;
		}
		
		indeks_vec = indeks_pocetak;
	}
	return recenica;
}

int main ()
{
	string recenica, fraza;
	cout << "Unesite recenicu: ";
	getline(cin, recenica);
	
	vector<string> fraze;
	cout << "Unesite fraze: ";
	for(;;) {
		getline(cin, fraza);
		if(fraza.length() == 0) break; 
		fraze.push_back(fraza);
	}
	
	cout << "Recenica nakon Palindrom transformacije: ";
	cout << NapraviPalindrom(recenica, fraze);
	cout << "\nRecenica nakon PoluPalindrom transformacije: ";
	cout << NapraviPoluPalindrom(recenica, fraze);
	
	return 0;
}