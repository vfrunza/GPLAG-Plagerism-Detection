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

std::string StringUnazad(std::string s)
{
	std::string s1;
	for(int i=s.length()-1; i>=0; i--) {
		s1.push_back(s.at(i));
	}
	return s1;
}

std::vector<std::string> VektorStringovaUnazad(std::vector<std::string> v)
{
	std::vector<std::string> v1;
	int i(0);
	while(i<v.size()) {
		v.at(i)=StringUnazad(v.at(i));
		v1.push_back(v.at(i));
		i++;
	}
	return v1;
}

std::string fja(std::string s, std::vector<std::string>v)
{

	return s;
}


int main ()
{
	std::vector<std::string> s {"rijec!","slov.o"};
	std::string recenica ("bla rijec!");
	/*	s=VektorStringovaUnazad(s);
			for(char i: s.at(1)) {
				std::cout<<i;
			}*/
	std::cout << " "<< fja(recenica, s);
	return 0;
}