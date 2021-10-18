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

typedef std::vector<std::vector<double>> MATRICA;

std::vector<double> NadjiMax(MATRICA m){
	double max(m[0][0]);
	for(int i(0); i < m.size(); i++){
		for(int j(0); j < m.at(i).size(); j++){
			if(m.at(i).at(j) > max)
			max = m.at(i).at(j);
		}
	}
	return std::vector<double>({max});
	
}

/*double TraziVrh(MATRICA m, broj){
	double max(m[0][0]);
	for(int i(1); i < m.size()-1; i++){
		for(int j(1); j < m.at(i).size()-1; j++){
			if(m.at(i).at(j) > max)
			max = m.at(i).at(j);
		}
	}
	
	return max;
}*/

MATRICA Planine(MATRICA m, int red, int kolona){
	for(int i(red); i <= red; i++){
		for(int j(kolona); j <= kolona; j++){
			suma += m.at(i).at(j);
		}
	}
}

MATRICA NajvecaPlaninaMatrice(MATRICA m){
	MATRICA Planina;
	if(m.size() == 0 || m.at(0).size() == 0) return Planina;
	
	for(int i(0); i < m.size()-1; i++){
		if(m.at(i).size() != m.at(i+1).size())
		 throw std::domain_error("Matrica nije korektna");
	}
		 if(m.size() == 1 || m.size() == 2 || m[0].size() == 1 || m[0].size() == 2){
		 	Planina.push_back(NadjiMax(m));
		 }
		 else{
		 	for(int i(1); i < m.size()-1; i++){
		 		for(int j(1);  j < m.at(i).size()-1; j++){
		 			
		 		}
		 	}
		 }
		 
		/* for(int i(0); i < m.size(); i++){
		 	for(int j(0); j.at(i).size(); j++){
		 		
		 	}
		 }*/
		//return Planina;
	
	
	//Planina = {{2,3},{1,2}};
	
	return Planina;
	
}
int main ()
{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(m < 0 || n < 0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice: ";
	MATRICA mat(m,std::vector<double>(n));
	//double broj;
	for(int i(0); i < m; i++){
		for(int j(0); j < n; j++){
			std::cin>>mat.at(i).at(j);
			
		}
	}
	MATRICA najveca;
	try{
	najveca = NajvecaPlaninaMatrice(mat);
	std::cout<<std::endl<<"Najveca planina unesene matrice je: "<<std::endl;
	for(int i(0); i < najveca.size(); i++){
		for(int j(0); j < najveca.at(i).size(); j++){
			std::cout<<std::setw(6)<<najveca.at(i).at(j);
		}
		std::cout<<std::endl;
	}
	}catch(std::domain_error poruka){
		std::cout<<poruka.what();
	}
	return 0;
}