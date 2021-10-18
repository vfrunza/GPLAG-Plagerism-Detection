/*B 2016/2017, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string> v) {
	std::string pomocni;
	for(int i(0); i<v.size(); i++) {
		for(int j(v[i].length()-1); j>=0; j--) {
			pomocni.push_back(v[i][j]); 
		}
		for(int k(0); k<s.length()-v[i].length()+1; k++) {
			if(v[i]==s.substr(k, v[i].length()))
				s=s.substr(0, k) + pomocni + s.substr(k+pomocni.length(), s.length()-pomocni.length()-k); 
		}
		pomocni.clear();
	}
	return s;
}
std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v) {
	std::string pomocni;
	std::string akojeprazan;
	for(int i(0); i<v.size(); i++) {
		for(int j(0); j<v[i].length(); j++) {
			if(!((v[i][j]>='A' && v[i][j]<='Z') || (v[i][j]>='a' && v[i][j]<='z')))
				throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	int brojac=0;
	if(v.size()==0) {															//ako je proslijedjen prazan vektor
		for(int i(0); i<s.length(); i++) {
			if(v.size()==0) {
				if(s[i]==' ') {
					akojeprazan=s.substr(0,i);
					v.push_back(akojeprazan);
					i--;
				}
			}
			else {
				if(s[i]!=' ' || s[i]==' ' || i==s.length()-1) {
					if(s[i]==' ') {
						//if(akojeprazan!=std::string(" "))
						v.push_back(akojeprazan);
						akojeprazan.clear();
						brojac=i;
					}
					else if(i==s.length()-1) {
						akojeprazan=s.substr(brojac+1, s.length()-brojac);
						v.push_back(akojeprazan);
					}
					else if(s[i]!=' ') {
						akojeprazan.push_back(s[i]);
					}
				}
			}
		}
	}
	for(int i(0); i<v.size(); i++) {
		pomocni=v[i].substr(1,v[i].length()-1) + v[i].substr(0,1) + std::string("ay");
		for(int j(0); j<s.length()-v[i].length()+1; j++) {
			int d=v[i].length();
			if(v[i]==s.substr(j, v[i].length()) && (s[j-1]<'A' || (s[j-1]>'Z' && s[j-1]<'a') || s[j-1]>'z') && (s[j+d]<'A' || (s[j+d]>'Z' && s[j+d]<'a') || s[j+d]>'z')) //dodao dva uslova
				s=s.substr(0, j) + pomocni + s.substr(j+v[i].length(), s.length()-v[i].length()-j);
		}
		//pomocni.clear(); ne treba
	}
	
	return s;
}

int main() {
	std::string s, s1;
	std::vector<std::string> v;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout << "Unesite fraze: ";
	do {
		std::getline(std::cin, s1);
		if(s1!=std::string(""))
			v.push_back(s1);
	}while(s1!=std::string(""));
	try {
		std::cout << "Recenica nakon PigLatin transformacije: "<< IzmijeniUPigLatin(s, v) << std::endl;
	}
	catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: "<< izuzetak.what() << std::endl;
	}
	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(s, v);
}
