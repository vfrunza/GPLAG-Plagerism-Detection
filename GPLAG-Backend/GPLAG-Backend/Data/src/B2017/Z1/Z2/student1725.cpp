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
Matrica PlaninaMatrice(Matrica B) {
	for(int i=0;i<B.size();i++) {
		for(int j=0;j<B.at(0).size();j++) {
			if(B.at(i)>(B.at(i-1).at(j-1) + B.at(i-1).at(j)+B.at(i-1).at(j+1)+B.at(i).at(j-1)+B.at(i).at(j+1)+B.at(i+1).at(j-1)+B.at(i+1).at(j)+B.at(i+1).at(j+1))) B.at(i).at(j)
		}
	}
}
Matrica NajvecaPlaninaMatrice (Matrica A) {
	for(int i=0;i<A.size();i++) {
		for(int j=0;j<A.at(0).size();j++) {
			
		}
	}
}


int main ()
{
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int m,n;
	std::cin>>m>>n;
	if(m<0 || n<0) {
	std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	}
	std::cout<<"Unesite elemente matrice: ";
	std::cout<<std::endl;
	std::cout<<"Najveca planina unesene matrice je: ";
	
	return 0;
}