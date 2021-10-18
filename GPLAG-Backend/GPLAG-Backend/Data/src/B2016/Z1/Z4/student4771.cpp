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

std::string ObrniFraze (std::string recenica, std::vector<std::string> fraze) {
	for (int i=0; i<fraze.size(); i++) {
		for (int j=0; i<recenica.size(); j++) {
			if (fraze[i]==recenica.substr(j,fraze[i].length())) {
				int poc(j), kraj=fraze[i].length-1+j;
				
				while(poc<kraj) {
					char pom=recenica[poc];
					recenica[poc]=recenica[kraj];
					recenica[kraj]=pom;
					poc++; kraj--;
				}
			}
		}
	}
return recenica;
}

int main ()
{
	std::string s;
	std::cin.getline(std::cin,s);
	std::vector<std::string> v {'ja', 'ti', 'mi'};
	std::cout << ObrniFraze(s,v);
	return 0;
}