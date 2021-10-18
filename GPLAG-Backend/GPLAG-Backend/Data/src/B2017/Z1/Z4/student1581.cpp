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
#include <vector>
#include <string>

bool jeLiPodstring(std::string s1, std::string s2) {
	//ispitujemo da li je string s2 podstring stringa s1
	if (s2.length() > s1.length()) return false;

	for (int i=0; i<s1.length(); i++) {
		for (int j=0; j<s1.length()-i; j++) {
			std::string pom = s1.substr(i, j);
			if (pom == s2 && pom.length() < s1.length()) return true;
		}
	}
	
	return false;
}

std::vector<std::string> pom2(std::string s) {
	std::vector<std::string> rijeci;
	int i{};
	while (i != s.length()) {
		while (i != s.length() && s.at(i) == ' ') ++i;
		int j = i;
		while (j != s.length() && s.at(j) != ' ') j++;
		if (i != j) {
			rijeci.push_back(s.substr(i, j-i));
			i = j;
		}
	}
	return rijeci;
}

bool imaLiRazmaka(std::string rijec) {
	bool x = false;
	for (int i=0; i<rijec.length(); i++) {
		if (rijec.at(i) == ' ') x = true;
	}	
	return x;
}

std::vector<int> nadjiFrazu(std::string rec, std::string rijec) {
	std::vector<int> pom;

	for (int i=0; i<rec.length(); i++) {
		std::string s = rec.substr(i, rijec.length());
		if (!imaLiRazmaka(rijec)) {
			std::vector<std::string> rijeci = pom2(rec);
			std::string x;
			int g=i;
			if ((rec.at(g) >= 'a' && rec.at(g) <= 'z') || (rec.at(g) >= 'A' && rec.at(g) <= 'Z')) {
				while (((rec.at(g) >= 'a' && rec.at(g) <= 'z') || (rec.at(g) >= 'A' && rec.at(g) <= 'Z'))
				&& g < rec.length()-1) {
					x += rec.at(g);
					g++;
				}
			}
			if (s == rijec && !jeLiPodstring(x, s)) {
				for (int j=0; j<rijeci.size(); j++) {
					if (s == rijeci.at(j)) {
						int br = i+rijec.length();
						pom.push_back(br);
						break;
					}
				}
			}
		}
		else {
			if (s == rijec) {
				int br = i+rijec.length();
				pom.push_back(br);
			}
		}
	}
	return pom;
}


std::string dajObrnutu(std::string s) {
	std::string pom{};
	for (int i=s.length()-1; i>=0; i--) pom += s.at(i);
	return pom;
}

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> s) {
	for (int i=0; i<s.size(); i++) {
			std::vector<int> indeksi = nadjiFrazu(recenica, s.at(i));  
			 if (indeksi.size() != 0){
			//indeks sadrzi indeks posljednjeg slova nase rijeci ili fraze
				std::string obrnuta = dajObrnutu(s.at(i));  
				int k{}, x{};
				while (k < indeksi.size()) {
		
					recenica.insert(indeksi.at(k)+x, obrnuta);
					
				    k++; x+=obrnuta.length();
				}
			}
	}
	return recenica;
} 


std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> s) {
	for (int i=0; i<s.size(); i++) {
		std::vector<int> v = nadjiFrazu(recenica, s.at(i));
		if (v.size() != 0) {
			for (int j=0; j<v.size(); j++) {
				int c{};
				int prvi = v.at(j) - s.at(i).length();
				if (s.at(i).length() % 2 == 0) {
					int sr = (prvi+v.at(j))/2;
			    	int brslova = sr-prvi;
					std::string pom = recenica.substr(prvi, brslova);
					std::string obrnuta = dajObrnutu(pom);
				   
					while(sr <= recenica.length()-1 && c<=obrnuta.length()-1) {
						recenica.at(sr) = obrnuta.at(c);
						sr++; c++;
					}
				}
				else {
					int sr = ((prvi+v.at(j))/2) + 1;
					int brslova = sr-prvi-1;
					std::string pom = recenica.substr(prvi, brslova);
					std::string obrnuta = dajObrnutu(pom);
					while (sr <= recenica.length()-1 && c<=obrnuta.length()-1) {
						recenica.at(sr) = obrnuta.at(c);
						sr++; c++;
					}
				}
			}
		}
	}
	return recenica;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	std::vector<std::string> fraze;
	std::cout<<"Unesite fraze: ";
	std::string fraza;
    while (true) {
		std::getline(std::cin, fraza);
		if (fraza.empty()) break;
		fraze.push_back(fraza);
	}
	
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::string s1 = NapraviPalindrom(recenica, fraze);
	std::cout<<s1<<std::endl;
	
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	std::string s2 = NapraviPoluPalindrom(recenica, fraze);
	std::cout<<s2<<std::endl;
	return 0;
}