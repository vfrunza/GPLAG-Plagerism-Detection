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


std::string NapraviPalindrom(std::string s, std::vector<std::string> r)
{
	std::string p(s), q;
	
}
int main ()
{
	std::string s("Ova zadaca od svih zadaca je najteza zadacaaaaa");
	std::vector<std::string> vs{"zadaca" , "je"};
	
	std::string p(NapraviPalindrom(s,vs));
	std::cout<<vs[1].size();
	
	return 0;
}