/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>  

std::string ObrniFraze (std::string recenica, std::vector<std::string> rijec)
{
	int y(rijec.size()-1);
	for(int i=0; i<recenica.length(); i++) 
	{
		
	}
    return recenica;
}

std::string IzmijeniUPigLatin (std::string recenica, std::vector<std::string> rijec)
{
	return recenica;
}

int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	
	std::vector<std::string> rijec;
	std::cout << "Unesite fraze: ";
	for(int i=0; i<rijec.size(); i++) std::getline(std::cin, rijec.at(i));
	
	std::cout << "Recenica nakon PigLatin transformacije: ";
	IzmijeniUPigLatin(recenica,rijec);
	
	std::cout << "Recenica nakon obrtanja fraze: ";
	ObrniFraze(recenica, rijec);
	
	return 0;
}