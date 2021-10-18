/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string> v) {
	for (int i = 0; i < v.size(); i++) {
		int j(0);
		std::string pom(v[i]);
		for (int q = 0; q < pom.size(); q++) if (!(pom[q] >= 'A' && pom[q] <= 'Z') && !(pom[q] >= 'a' && pom[q] <= 'z') && pom[q] != ' ' && pom[q] != ',' && pom[q] != '.' && pom[q] != '(' && pom[q] != ')') throw std::domain_error ("Izuzetak: Nekorektan izbor rijeci");
		char znak;
		while (j < s.length()) {
			int k(j);
			int t(0);
			while (j < s.length() && t < pom.length() && pom[t] == s[j] && pom[t++] == s[j++]);
			if (t == pom.length()) {
				int m(j-1);
				while (k < m) {
					znak = s[k];
					s[k++] = s[m];
					s[m--] = znak;
				}
			}
			j++;
		} 
	}
	return s;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v) {
	for (int i = 0; i < v.size(); i++) {
		int j(0);
		std::string pom(v[i]);
		for (int q = 0; q < pom.size(); q++) if (!(pom[q] >= 'A' && pom[q] <= 'Z') && !(pom[q] >= 'a' && pom[q] <= 'z')) throw std::domain_error ("Izuzetak: Nekorektan izbor rijeci");
		while (j < s.length()) {
			int k(j);
			int t(0);
			while (j < s.length() && pom[t] == s[j] && t < pom.length()) {
				t++; j++;
			}
			if ((k == 0 || (!(s[k-1] >= 'A' && s[k-1] <= 'Z') && !(s[k-1] >= 'a' && s[k-1] <= 'z'))) && t == pom.length() && (j == s.length() || (!(s[j] >= 'A' && s[j] <= 'Z') && !(s[j] >= 'a' && s[j] <= 'z')))) {
				std::string toinsert;
				toinsert.push_back(s[k]);
				char a('a');
				char y('y');
				toinsert.push_back(a);
				toinsert.push_back(y);
				s.insert(j, toinsert);
				while (k < s.length()-1) {
					s[k] = s[k+1];
					k++;
				}
				s.resize(s.length()-1);
			}
			j++;
		}
	}
	
	return s;
}
	


int main ()
{
	std::string s;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, s);
	std::vector<std::string> v;
	std::cout << "Unesite fraze: ";
	for(;;) {
		std::string str;
		std::getline(std::cin, str);
		v.push_back(str);
		if (std::cin.peek() == '\n') break;
	}
	try {
		std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(s, v) << std::endl;
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	try {
		std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(s, v) << std::endl;
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}