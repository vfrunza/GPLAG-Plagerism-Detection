#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

/*B 2016/2017, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

typedef std::vector<std::string> Matrica;

bool ImaLiEnglisha(Matrica Rijeci)
{
	if(Rijeci.size()==0) return true;
	
	auto i = Rijeci.size();
	auto j = Rijeci[0].size();
	for(i=0; i< Rijeci.size(); i++) {
		for(j=0; j<Rijeci[i].size(); j++) {
			if(Rijeci[i][j]<'A' || (Rijeci[i][j]>'Z' && Rijeci[i][j]<'a') || Rijeci[i][j]>'z') {
				return false;
			}
		}
	}
	return true;
}

char toUpper(char c)
{
	if (c>='a' && c<='z')
		return c - ('a' - 'A'); // prebaci c u veliko i vrati
	return c; // ako nije bilo malo slovo, ostaje nepromjenjeno
}

bool isSlovo(char c)
{
	c = toUpper(c);
	// vrati 1 ako je c slovo, 0 ako nije
	return c>='A' && c<='Z';
}

std::string IzmijeniUPigLatin(std::string s, Matrica Rijeci)
{
	if(!ImaLiEnglisha(Rijeci)) throw std::domain_error("Nekorektan izbor rijeci");

	if(Rijeci.size()==0) {	// ako je prazna matrica rijeci
		
		auto i = s.length();
		
		for(i=0; i < s.length(); i++) {

			if(isSlovo(s[i])) {
				char a = s[i];
				s.erase(s.begin() + i);
				auto kraj = i;
				while(kraj < s.length() && isSlovo(s[kraj])) kraj++;
				s.insert(s.begin() + kraj, a);
				s.insert(s.begin() + kraj +1, 'a');
				s.insert(s.begin() + kraj +2, 'y');
				while(i < s.length() && isSlovo(s[i])) i++;
			}
			if(i == s.length()) break;
		}

		return s;
	}

	auto i = s.length();
	for(i=0; i < s.length(); i++) {

		auto h = i;
		while(h<s.length() && isSlovo(s[h])) h++;
		auto k = Rijeci.size();
		for(k=0; k < Rijeci.size(); k++) {
			if(s.substr(i, h-i) == Rijeci[k]) {		// gleda samo RIJEC zasebnu
				char a = s[i];
				s.erase(s.begin() + i);
				s.insert(s.begin() + i + Rijeci[k].size() -1, a);
				s.insert(s.begin() + i + Rijeci[k].size(), 'a');
				s.insert(s.begin() + i + Rijeci[k].size() +1, 'y');
			}
		}
		while(i < s.length() && isSlovo(s[i])) i++;

		if(i == s.length()) break;
	}
	return s;
} 

std::string ObrniFraze(std::string s, Matrica Rijeci)
{
	auto k = Rijeci.size();
	auto i = s.length();
	for(k=0; k < Rijeci.size(); k++) {
		for(i = 0; i < s.length(); i++) {
			if(i + Rijeci[k].size()-1 < s.size() && s.substr(i, Rijeci[k].size()) == Rijeci[k]) {
				auto index = i + Rijeci[k].size() -1;
				auto h = index;
				h=0;
				auto j = index;
				for(j= index; j >= i && j>=0; j--) {
					s[j] = Rijeci[k][h];
					h++;
					if(j ==0) break;
				}
			}
		}

	}
	return s;
}



int main ()
{
	Matrica Rijeci;
	std::string s;
	std::string pomocni;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout << "Unesite fraze: ";
	auto k = Rijeci.size();
	k=0;
	for(;;) {
		std::getline(std::cin, pomocni);
		if(pomocni.size()==0) break;
		Rijeci.resize(k+1);
		Rijeci[k] = pomocni;
		k++;
	}

	try {
		std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(s,Rijeci) << std::endl;
	} catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}

	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(s, Rijeci);
	
	return 0;
}