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

std::string NapraviPalindrom (std::string s, std::vector<std::string>v){
	int brojac{0};
	std::string trenutna_rijec;
	for (int i=0;i<v.size();i++){
		trenutna_rijec=v.at(i);
		for (int j=0;j<s.length();j++){
			brojac=0;
			while (j<s.length() && brojac<trenutna_rijec.length() && s.at(j)==trenutna_rijec.at(brojac)){
				brojac++;
				j++;
			}
			if (brojac==trenutna_rijec.length() && (j==s.length() || s.at(j)==' ' || s.at(j)=='.' || s.at(j)==',')) {
				s.resize(int(int(s.length())+int(trenutna_rijec.length())));
				for (int k=s.length()-1;k>=j+trenutna_rijec.length();k--)
					s.at(k)=s.at(k-trenutna_rijec.length());
				for (int l=0;l<trenutna_rijec.length();l++){
					s.at(j+trenutna_rijec.length()-l-1)=trenutna_rijec.at(l);
				}
			}
		}
	}
	return s;
}

std::string NapraviPoluPalindrom (std::string s, std::vector<std::string> v){
	std::string trenutna_rijec;
	int brojac{0};
	for (int i=0;i<v.size();i++){
		trenutna_rijec=v.at(i);
		for (int j=0;j<s.length();j++){
			brojac=0;
			while (j<s.length() && brojac<trenutna_rijec.length() && s.at(j)==trenutna_rijec.at(brojac)){
				j++;
				brojac++;
			}
		
			if (brojac==trenutna_rijec.length() && (j==s.length() || s.at(j)==' ' || s.at(j)==',')){	
				for (int k=0;k<int(brojac/2);k++){
					s.at(j-k-1)=s.at(j-brojac+k);
				}
			}
		}
	}
	return s;
}

int main (){
	std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s);
	std::vector<std::string>v;
	std::string fraza;
	std::cout<<"Unesite fraze: ";
	while(1){
		std::getline(std::cin,fraza);
		if (fraza=="") break;
		v.push_back(fraza);
	} 
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(s,v)<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(s,v);
	return 0;
}