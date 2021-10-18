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

std::string ObrniFraze (std::string recenica , std::vector<std::string> popis_rijeci ){
	
	for (int i = 0 ; i < recenica.length(); i++){
		for(int j = 0 ; i < popis_rijeci.length(); j++){
			if (recenica.at(i) != popis_rijeci.at(j) ) j++;
			else {
				while (recenica[i] != ' '){
					
				}
				
			}
		}
	}
	
	return recenica;
}
int main ()
{
	return 0;
}