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

void IzvrniString(std::string &s) 
{
   int y(s.length()-1);
   for(int i=0; i<(s.length()/2); i++) 
     {
        std::swap(s.at(i),s.at(y)); 
        y--;
     }
}

std::string NapraviPalindrom (std::string recenica, std::vector<std::string>> rijeci)
 
NapraviPoluPalindrom

int main ()
{
	return 0;
}