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

std::string NaopakoString (std::string s) {
	std::string s1;
	for (int i = s.length()-1; i > -1; i--) {
		s1.push_back(s.at(i));
	}

	return s1;
}

std::string NapraviPalindrom (std::string recenica, std::vector<std::string> v) {
	for(int i(0); i < v.size(); i++) {
		for(int j(0); j < recenica.length(); j++) {
			if(v.at(i).at(0) == recenica.at(j)) {
				if(j==0){
					if(j+v.at(i).length()<recenica.length()){
						char a (recenica.at(j+v.at(i).length()));
						if((recenica.substr(0,v.at(i).length())==v.at(i)) &&(a<'A' || a>'Z' && a<'a' || a>'z')){
						std::string	s1=NaopakoString(v.at(i));
						recenica.insert(j+v.at(i).length(),s1);
							j+=2*v.at(i).length()-1;
						}
					}else if(v.at(i).length()==recenica.length()){
						if(recenica.substr(0,v.at(i).length())==v.at(i)) {
							std::string s1=NaopakoString(v.at(i));
							recenica.insert(j+v.at(i).length(),s1);
							return recenica;
						}
					}
				}else if(j+v.at(i).length()<recenica.length()){
					char a (recenica.at(j-1));
					char b (recenica.at(j+v.at(i).length()));
						if(recenica.substr(j,v.at(i).length())==v.at(i) && (a<'A'|| a>'Z' && a<'a' || a>'z' ) &&(b<'A' || b>'Z' && b<'a' || b>'z')){
							recenica.insert(j+v.at(i).length(),NaopakoString(v.at(i)));
							j+=2*v.at(i).length()-1;
						}
				}else if(j+v.at(i).length()==recenica.length()){
					char a (recenica.at(j-1));
						if(recenica.substr(j,v.at(i).length())==v.at(i) &&(a<'A' || a>'Z'&& a<'a' || a>'z'))
							recenica.insert(j+v.at(i).length(),NaopakoString(v.at(i)));
				}
			}
		}
	}
	return recenica;
}
std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> v)
{
	for(int i(0); i<v.size(); i++) {
		for(int j(0); j<recenica.length(); j++) {
			if(v.at(i).at(0)== recenica.at(j)) {
				if(j==0) {
					if(j+v.at(i).length()<recenica.length()) {
						char a(recenica.at(j+v.at(i).length()));
						if(recenica.substr(0, v.at(i).length())==v.at(i) && (a<'A' || a>'Z' && a<'a' || a>'z')) {
							for (int k= j+v.at(i).length()-1; k > j ; k--) {
								recenica.at(k)=recenica.at(j);
								j++;
							}
						}
					} else if(j+v.at(i).length()==recenica.length()) {
						if(recenica.substr(0, recenica.length())==v.at(i)) {
							for(int k=j+v.at(i).length()-1; k>j; k--) {
								recenica.at(k)=recenica.at(j);
								j++;
							}
						}
						return recenica;
					}
				}
			 else if(j+v.at(i).length()==recenica.length()) {
				if(recenica.substr(0,v.at(i).length())==v.at(i) &&(recenica.at(j-1)<'A'|| recenica.at(j-1)>'Z'&&recenica.at(j-1)<'a'||recenica.at(j-1)>'z')) {
					for (int k= j+v.at(i).length()-1; k > j; k--) {
						recenica.at(k)=recenica.at(j);
						j++;
					}
				}
			}
			//}
			else if(j+v.at(i).length()<recenica.length()) {
				char a (recenica.at(j-1));
				char b (recenica.at(j+v.at(i).length()));
				if(recenica.substr(j,v.at(i).length())==v.at(i) &&(a<'A' || a>'Z'&& a<'a'||a>'z')&&(b<'A' ||b>'Z'&& b<'a'||b>'z')) {
					for (int k= j+v.at(i).length()-1; k > j; k--) {
						recenica.at(k)=recenica.at(j);
						j++;
					}
				}
			} 
		}
	}
}
	return recenica;
}
int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	std::string unos;
	int kraj(0);
	do {
		std::getline(std::cin, unos);
		if(unos.length() == 0) break;
		else fraze.push_back(unos);
	} while(1);
	std::string ispisni = NapraviPalindrom(recenica, fraze),ispisni2 = NapraviPoluPalindrom(recenica,fraze);
	std::cout<<"Recenica nakon Palindrom transformacije: "<<ispisni<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<ispisni2;
	return 0;
}