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

std::string NapraviPalindrom(std::string s,std::vector<string> fraze){
	if(int(fraze.size())==0) return s;
	else{
	for(int i=0;i<fraze.size();i++){
		for(int j=0;j<fraze.size();j++){
			std::string fraza(fraze.at(i));
			string palindrom;
			for(int i=fraze.size()-1;i>=0;i--) palindrom+=fraza.at(i);
		}
	}
	}
}
int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	return 0;
}