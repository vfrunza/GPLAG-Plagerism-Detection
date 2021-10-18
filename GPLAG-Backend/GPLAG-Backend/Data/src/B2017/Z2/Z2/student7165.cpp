/*B 2017/2018, Zadaća 2, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>


int main ()
{
	std::vector<int> vektor{1,2,3,1,2,3,1,2,3,1};
	int period(1);
	for(int i(0); i<vektor.size(); i++){
		if((period+i<vektor.size()) && (vektor.at(i)==vektor.at(period+i))){
			int k(period);
		while((i+period<vektor.size()) && (i<k) && (vektor.at(i)==vektor.at(i+period))) i++;
		if(i==k-1) break;
		else{
			period++;
			i=-1;
		}
	}
	else{
		i=-1;
			period++;
		}
	}
	std::cout<<"Period je: "<<period;
	return 0;
}