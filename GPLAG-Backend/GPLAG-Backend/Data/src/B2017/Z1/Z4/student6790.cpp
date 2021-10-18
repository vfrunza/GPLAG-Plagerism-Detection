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

void ObrniPronadjenuFrazu(std::string rijec) {
	char temp;
	for(int i(0);i<rijec.length()/2;i++) {
		temp=rijec.at(i);
		rijec.at(i)=rijec.at(rijec.length()-i-1);
		rijec.at(rijec.length()-i-1)=temp;
	}
}

void NapraviPalindrom (std::string recenica, std::vector<std::string> fraze) {
	int pocetak,kraj;
	for(int i(0);i<fraze.size();i++) {
		for(int j(0);j<recenica.length();j++) {
			
		}
	}
	
}

int main () {
	
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	std::string fraza;
	int a(0);
	for(int i(0);i<=a;i++) {
		std::cout<<i;
		std::getline(std::cin,fraza);
		if(fraza.size()==0) break;
		fraze.push_back(fraza);
		a++;
	}



	
	
	
	
	
	
	
	
	
	std::cout<<"kraj";
	
	return 0;
}