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
std::string obrnirijec(std::string s) {
	char i=0;
		char k=s.length();
		while(i<k) {
			
		}
		
	}
	
}
std::string NapraviPalindrom(std::string s, std::vector<std::string> v) {
	for(int i(0); i<v.size(); i++) {
		int vel=v.at(i).length();
		for(int j(0); j<s.length(); j++) {
			if(s.substr(j,vel)==v.at(i)) {
				int tmp=j+vel;
				s.resize(s.length()+vel);
				for(int k=s.length()-1; k>tmp; k++) {
					s.at(k)=s.at(k-vel);
				}
			}
		}
	} 
}

int main ()
{
	std::string s;
	std::vector<std::string> v;
	std::cout<<"Unesi recenicu: ";
	std::getline(std::cin,s);
	std::cout<<"Unesite rijeci: ";
	std::string s1;
	for(;;) {
		std::getline(std::cin,s1);
		if(s1.length()==0) break;
		v.push_back(s1);
	}
	std::string s2;
	s2=NapraviPalindrom(s,v);
	std::cout<<s2;
	return 0;
}