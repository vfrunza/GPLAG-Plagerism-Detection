/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <string>

void ObrniFraze (std::string s, std::vector<std::string> v) {
	for (int i=0; i<v.size(); i++) {
		for (int j=0; j<s.length(); j++) {
			if (v[i]==s.substr(j, v[i].length())) {
				char tmp(0);
				for (int k=j; k<v[i].length()/2; k++) {
					tmp=v[i][k];
					v[i][k]=v[i][v[i].length()-1-i];
					v[i][v[i].length()-1-i]=tmp;
					j=k*2;
				}
			}
		}
	}
}

int main ()
{
	std::string recenica;
	std::cout << "Unesi recenicu: ";
	std::getline(std::cin, recenica);
	std::cout << "Unesi fraze: "
	std::vector<std::string> v;
	for (int i=0; i<v.size(); i++) {
		std::getline(std::cin, v[i]);
		v.push_back(v[i])
	}
	return 0;
}