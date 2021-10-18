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
typedef std::vector<std::vector<double>> Matrica;


int main (){
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	}
	
 return 0;
}