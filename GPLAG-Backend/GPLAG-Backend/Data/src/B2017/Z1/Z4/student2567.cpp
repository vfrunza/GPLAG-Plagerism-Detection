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

int NijeSlovo(char a) {
	if(a>'a' && a<'z') return 0;
	if(a>'A' && a<'Z') return 0;
	return 1;
}

std::string Palindrom(std::string s) {
	std::string p;
	for(int i(s.length()-1);i>=0;i--) 
		p.push_back(s.at(i));
	return p;
}

std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> fraze) {
	for(int i(0);i<fraze.size();i++)
		for(int j(0);j<s.length()-fraze.at(i).length();j++)
			if(s.substr(j,fraze.at(i).length())==fraze.at(i) && (NijeSlovo(s.at(j+fraze.at(i).length())) || j+fraze.at(i).length()==s.length()-1)) {
				std::string polovica;
				for(int k(0);k<fraze.at(i).length()/2;k++) polovica.push_back(fraze.at(i).at(k));
				polovica=Palindrom(polovica);
				if(fraze.at(i).length()%2==0) {
					j+=fraze.at(i).length()/2;
					s.erase(j,fraze.at(i).length()/2+1);
					s.insert(j,polovica);
					j+=fraze.at(i).length()/2;
				}
				else {
					j+=fraze.at(i).length()/2+1;
					s.erase(j,fraze.at(i).length()/2);
					s.insert(j,polovica);
					j+=fraze.at(i).length()/2;
				}
			}
	return s;
}

std::string NapraviPalindrom(std::string s, std::vector<std::string> fraze) {
	for(int i(0);i<fraze.size();i++)
		for(int j(0);j<s.length()-fraze.at(i).length();j++)
			if(s.substr(j,fraze.at(i).length())==fraze.at(i) && (NijeSlovo(s.at(j+fraze.at(i).length())) || j+fraze.at(i).length()==s.length()-1)) {
				s.insert(j+fraze.at(i).length(),Palindrom(fraze.at(i)));
				j+=fraze.at(i).length()*2;
			}
	return s;
}

int main () {
	std::string a;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin,a);
	std::cout << "Unesite fraze: ";
	std::string unos;
	std::vector<std::string> fraze;
	std::string terminate="\n";
	do{
		std::getline(std::cin,unos);
		fraze.push_back(unos);
	}while(unos.length()!=0);
	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(a,fraze) <<std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(a,fraze);
	return 0;
}