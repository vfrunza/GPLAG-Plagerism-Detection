/*B 2017/2018, Zadaća 1, Zadatak 2
	
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

using namespace std;



typedef vector<vector<double> Matrica;

Matrica& NajvecaPlaninaMatrice(Matrica &m)
{
	if(m.size() - 1 == 0)
		throw domain_error("Dimenzije matrice moraju biti nenegativne!");
		
	for(int i = 0; i < m.size() - 1; i++)
		if(m.at(i).size() != m.at(i+1).size())
			throw domain_error("Izuzetak: Matrica nije korektna");
	
	
}

int main ()
{
	return 0;
}