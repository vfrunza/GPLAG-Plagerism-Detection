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
#include <exception>
typedef std::vector<std::vector<double>> Matrica;
bool SumaElemenataVektora (std::vector<double> v){
	double suma(0);
	for (int i=0;i<v.size();i++) suma+=v.at(i);
	return suma;
}
bool DaLiJePlanina (Matrica m){
	
}
Matrica NajvecaPlaninaMatrice (Matrica m){
	for (int i=2;i<m.size()-1;i++){
		for (int j=2;j<m[i].size()-1;j++){
			
		}
	}
}
int main ()
{
	return 0;
}