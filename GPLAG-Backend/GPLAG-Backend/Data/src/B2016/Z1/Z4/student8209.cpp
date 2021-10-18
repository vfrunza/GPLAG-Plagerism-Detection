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

std::string Obrni(std::string s, int a, int b) {
	
	char temp;
	for(int i = a; i < b; i++) {
		int k = 1;
		temp = s[i];
		s[i] = s[b - k];
		s[b - k] = temp;
		k++;
	}
	return s;
}

std::string ObrniFraze(std::string s, std::vector<std::string> v) {
	
/*	for(int i = 0; i < s.length(); i++) {
		int temp = i;
		bool provjera(false);
		for(int j = 0; j < v.size(); j++) {
			for(int k = 0; k < v[i].length(); k++) {
				while((s[i] == v[j][k]) && (k < v[i].length())){
					provjera = true;
					k++;
				}
				k--;
			}
		}
	}*/
	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v[i].length(); j++) {
			for(int k = 0; k < s.length(); k++) {
				bool provjera = false;
				int priv = k;
				while ((s[k] == v[i][j]) && (k < s.length()) && (j < v[i].length())) {
					provjera = true;
					k++;
					j++;
				}
				if(j != v[i].length()) provjera = false;
				else {
					s = Obrni(s, priv, priv + v[i].length());
				}
			}
		}
	}
	
	return s;
}

bool DaLiJeEngAlfabet(std::vector<std::string> v) {
	for(int i = 0; i < v.size(); i++) {
		
	}
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v) {
	if(v.size() == 0) throw std::domain_error("Nekorektan izbor riječi");
}

int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string s;
	std::getline(std::cin, s);
	std::cout << "Unesite fraze: ";
	std::vector<std::string> v;
	std::string s_pom;
	do {
		std::getline(std::cin, s_pom);
		v.push_back(s_pom);
	} while (std::cin.peek() != '\n');
	
	std::cout << "Recenica nakon PigLatin transformacije: ";
	std::string n_str = IzmijeniUPigLatin(s, v);
	std::cout << n_str << std::endl;
	std::cout << "Recenica nakon obrtanja fraza: ";
	n_str = ObrniFraze(s, v);
	std::cout << n_str << std::endl;
	   
	
	return 0;
}