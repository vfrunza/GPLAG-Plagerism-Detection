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
std::string Polindrom(std::string recenica1, std::string fraza)
{
	std::string Novi;
	for(int i=0; i<recenica1.length(); i++) {
		for(int j=0; j<fraza.length(); i++) {
			if(recenica1.at(i)==fraza.at(j)) {
				std::string Pamti;
				int 	m=i;

				do {
					Pamti.push_back(fraza.at(j));
					i++;
					j++;

				} while(recenica1.at(i)!=fraza.at(j));
				if(Pamti==fraza) {
					for( int k=0; k<Pamti.length(); k++)
						Novi.push_back(Pamti.at(k));
					for( int k=Pamti.length(); k>0; k--)
						Novi.push_back(Pamti.at(i));


				} else i=m;
			}
		}
		Novi.push_back(recenica1.at(i))	;


int main ()

{


	return 0;
}
