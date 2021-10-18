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

char *Podstring(std::string s1, std::string s2)
{
	for(int i=0;i<s1.length();i++)
	{
		 char *p=s1[i];
	     char *q=s2[0];
		
		while (*p++==*q++)
		if(*q==s2[s2t.length()]) return s1;
	}
	
	return NULL;
}



/*std::string NapraviPalindrom(std::string s,std::vector<std::string>spisak)
{
	for(int i=0;i<spisak.size();i++)
	{
		if(Podstring(s,spisak[i]))
		{
			std::cout << "Rijec jeste podstring" << std::endl;
		}
		
	}
}*/



int main ()
{
	std::string s;
	std::vector<std::string> spisak ;
	std::cout << "Unesite prvi string" << std::endl;
	std::getline(std::cin,s);
	int n;
	std::cout << "Unesite broj elemenata vektroa" << std::endl;
	std::cin >> n;
	
	for(int i=0;i<n;i++)
	{
		std::string c;
		std::getline(std::cin,c);
		spisak.push_back(c);
	}
	
	if(Podstring(s,spisak[0])) std::cout << "jeste" << std::endl;
	
	
	return 0;
}