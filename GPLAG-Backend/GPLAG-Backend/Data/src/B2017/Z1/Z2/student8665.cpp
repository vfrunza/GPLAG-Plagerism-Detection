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
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

//Kreira matricu sa zadanim brojem redova i kolona 
Matrica KreirajMatricu(int br_redova, int br_kolona){
	return Matrica(br_redova, std::vector<double> (br_kolona));
}
//Unesi matricu 
/*Matrica UnesiMatricu(int br_redova, int br_kolona){
	auto m(KreirajMatricu(br_redova, br_kolona));
	for(int i=0; i<br_redova; i++){
		for(int j=0; j<br_kolona; j++){
			std::cin >> m[i][j];
		}
	}
	return m;
}*/

Matrica NajvecaPlaninaMatrice(Matrica m){
	if(m.size() == 0) return m;
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++){
			if(m[i].size() != m[i+1].size()) throw std::domain_error("Matrica nije korektna");
		//	if (m.size() == 1 && m[0].size() == 1) return m;
		}
	}
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++){
			
		}
	}
	
	return m;
}

int main ()
{

	int n,m;
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	
	if(m < 0 || n < 0) std::cout << "Dimenzije matrice moraju biti nenegativne!";
	
	Matrica mat(KreirajMatricu(m,n));
	
	std::cout  << "Unesite elemente matrice: ";
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			std::cin >> mat.at(i).at(j);
		}
	}
	try{
		std::cout << "Najveca planina unesene matrice je: " << std::endl;
		auto matrica(NajvecaPlaninaMatrice(mat));
	}
	catch(std::domain_error izuzetak){
		std::cout << izuzetak.what();
	}
	return 0;
}