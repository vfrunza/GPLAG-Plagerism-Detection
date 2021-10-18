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



std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> m){
	std::vector<std::vector<double>> planina;
	for(int i(1); i< m.size()-1;i++){
		for(int j(1); j< m.at(i).size();j++){
			//ne prolazi se kroz rubne elemente matrice jer nema potrebe
			
		}
	}
}

int main ()
{
	return 0;
}