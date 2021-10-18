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


void IzvrniString(std::string &str)
{
	char temp;

	for(int i=0; i<=((int)str.size()/2)-1; i++) {
		temp = str.at(i);
		str.at(i) = str.at(str.size()-1-i);
		str.at(str.size()-1-i) = temp;
	}

}

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> fraza)
{
	for(int i=0; i<recenica.size()-1; i++) {
	
		}
	}
}

int main ()
{
	std::string s;
	std::cout<<"Unesi recenicu: ";
	getline(std::cin, s);
	std::cout<<"Izvrnuti string je: ";
	IzvrniString(s);
	std::cout<<s<<std::endl;
	return 0;
}