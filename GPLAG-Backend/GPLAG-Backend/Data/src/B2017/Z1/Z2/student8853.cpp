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

typedef std::vector<std::vector<double>> Matrica;

NadjiPlaninu Matrica(Matrica a){
	Matrica b;
	for(int i=0; i<a.size(); i++)
	for(int j=0; j<(a.at(0)).size(); j++){
		if((i!=0)&&(j!=0)&&(i!=a.size()-1)&&(j!=(a.at(0)).size()-1)){
			if(a.at(i).at(j)>a.at(i).at(j-1)+a.at(i).at(j+1)+a.at(i+1).at(j-1)+a.at(i+1).at(j)+a.at(i+1).at(j+1)+a.at(i-1).at(j-1)+a.at(i-1).at(j)+a.at(i-1).at(j+1)){
				for(int k=i-1; i<)
			}
			
		}
	}
}


int main ()
{
	return 0;
}