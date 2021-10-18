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
#include <iomanip>

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> m) {
	if (m.size() == 0) return m;
	else if (m.size() == 1) return m;
	for (int j=0; j<m.size(); j++) 
		if (m.at(j).size() != m.at(0).size()) throw std::domain_error("Matrica nije korektna");
	
	std::vector<std::vector<double>> x;
	return x;
		
}

int main ()
{ 
	try {
		int m{}, n{};
		std::cout<<"Unesite dimenzije matrice (m i n): ";
		std::cin>>m>>n;
		std::vector<std::vector<double>> mat(m, std::vector<double>(n));
		
		std::cout<<"Unesite elemente matrice: ";
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++)
				std::cin>>mat.at(i).at(j);
		}
		std::cout<<"\nNajveca planina unesene matrice je: \n";
		std::vector<std::vector<double>> x = NajvecaPlaninaMatrice(mat);
		for (auto a:x) {
			for (auto b:a) 
				std::cout<<std::setw(6)<<b<<" ";
			std::cout<<std::endl;
		}
	}
	catch(std::domain_error e) {
		std::cout<<e.what()<<std::endl;
	}
	return 0;
}