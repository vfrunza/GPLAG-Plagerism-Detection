/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>

std::string ObrniFraze (std::string tekst, std::vector<std::string> vs) {
	std::string s(tekst);
	for (int i=0; i<vs.size(); i++) {
		for (int j=0; j<s.length(); j++) {
			if (vs[i] == s.substr(j, vs[i].length())) {
				char tmp;
				for (int i=0; i<vs.size(); i++) {
					for (int j=0; j<s.length(); j++) {
						if (vs[i] == s.substr(j, vs[i].length())) {
							for (int k=0; k<vs[i].length()/2; k++) {
								tmp = s[j+k];
								s[j+k] = s[j-k+vs[i].length()-1];
								s[j-k+vs[i].length()-1] = tmp;
							}
						}
					}
				}
			}
		}
	}
	return s;
}

std::string IzmijeniUPigLatin (std::string tekst, std::vector<std::string> vs) {
	std::string s(tekst);
	for (int i=0; i<vs.size(); i++) {
		for (int j=0; j<vs[i].length(); j++) {
			if (vs[i][j]<'A' || vs[i][j]>'z' || (vs[i][j]>'Z' && vs[i][j]<'a')) {
				throw std::domain_error ("Nekorektan izbor rijeci");
			}
		}
	}
	for (int i=0; i<vs.size(); i++) {
		for (int j=0; j<s.length(); j++) {
			if (vs[i] == s.substr(j, vs[i].length()) && (s[j-1] <'A' || s[j-1] > 'z' || (s[j-1]>'Z' && s[j-1]<'a'))) {
				char x(s[j]);
				s.erase(s.begin()+j);
				s.insert(s.begin()+j-1+vs[i].length(), x);
				s.insert(s.begin()+j+vs[i].length(), 'a');
				s.insert(s.begin()+j+1+vs[i].length(), 'y');
			}
		}
	}
	return s;
}

int main () {
	std::string s;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, s);
	std::vector<std::string> v;
	std::cout << "Unesite fraze: ";
	for (int i=0; ; i++ ) {
		std::string x;
		std::getline(std::cin, x);
		if (x.length()==0) {
			break;
		}
		v.push_back(x);
	}
	try {
		std::string s1(IzmijeniUPigLatin(s,v));
		std::cout << "Recenica nakon PigLatin transformacije: " << s1 << std::endl;
	}
	catch (std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	std::string s2(ObrniFraze(s,v));
	std::cout << "Recenica nakon obrtanja fraza: " << s2;
	return 0;
}