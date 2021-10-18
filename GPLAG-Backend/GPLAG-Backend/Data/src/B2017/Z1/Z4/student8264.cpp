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

std::string Palindrom(std::string s) {
	std::string novi;
	for(int i=s.length()-1;i>=0; i--) {
		novi.push_back(s.at(i));
	}
	return novi;
}

std::string PoluPalindrom(std::string s) {
	std::string novi;
	std::string novi2;
	int duzina(s.length());
	for(int i=s.length()/2-1; i>=0; i--) {
		novi.push_back(s.at(i));
	}
	if(duzina%2!=0) duzina+=1;
	for(int i=0; i<=duzina/2-1; i++) {
		novi2.push_back(s.at(i));
	}
	for(int i=0; i<novi.length(); i++) {
		novi2.push_back(novi.at(i));
	}
	return novi2;
}

std::string NapraviPalindrom(std::string a, std::vector<std::string> b) {
	for(int i=0; i<b.size(); i++) {
		for(int j=0; j<a.size(); j++) {
			if(b.at(i)==a.substr(j, b.at(i).size())) {
				std::string naopako(Palindrom(b.at(i)));
				a.insert((j+b[i].length()), naopako);
			}
		}
	}
	return a;
}

std::string NapraviPoluPalindrom(std::string a, std::vector<std::string> b) {
	for(int i=0; i<b.size(); i++) {
		for(int j=0; j<a.size(); j++) {
			if(b.at(i)==a.substr(j, b.at(i).size())) {
				//if((b.at(i).size())%2==0) {
				std::string naopako(PoluPalindrom(b.at(i)));
				a.erase(j, b.at(i).length());
				a.insert(j, naopako);
			//}
			}
		}
	}
	return a;
}
int main (){

	std::vector<std::string>vektorfraza;
	std::string recenica;
	std::string rijec;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	while(std::getline(std::cin, rijec)) {
		if(rijec=="") break;
		vektorfraza.push_back(rijec);
	}
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica, vektorfraza)<<"\n";
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica, vektorfraza);
	return 0;
}