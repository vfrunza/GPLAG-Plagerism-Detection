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
#include <stdexcept> 
#include <vector> 
#include <iomanip>




typedef std::vector<std::vector<double>> Matrica; 

Matrica FormirajMatricu(Matrica m, int x, int y, int nivo){
	Matrica pomocna; 
	pomocna.resize(1 + nivo*2); 
	int duzina(1 + nivo*2);
	
	int k_x(x-nivo);
	int k_y(y-nivo); 
	

	for(int i = 0; i < duzina; i++) pomocna.at(i).resize(duzina); 
	
	int l(0), k(0); 
	for(int i = k_x; i < duzina+k_x; i++){
		l = 0; 
		for(int j = k_y; j < duzina+k_y; j++) {
			pomocna.at(k).at(l) = m.at(i).at(j); 
			l++;
		}
		k++; 
	}
	return pomocna; 
}


double SaberiOkolne(Matrica m){
	double suma(0); 
	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m.at(i).size(); j++){
			if(i == 0 || j == 0 || i == m.size()-1 || j == m.at(i).size()-1) suma = suma + m.at(i).at(j); 
		}
	}
	return suma; 
}

double SaberiUnutarnje(Matrica m){
	double suma(0);
	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m.at(i).size(); j++){
			if((i == 1 && j > 0 && j < m.at(i).size()-1) || (i == m.size()-2 && j < m.at(i).size()-1 && j > 0) || (j == 0 && i > 0 && i < m.size()-1) || (j == m.at(i).size()-2 && i > 0 && i < m.size()-1))  suma = suma + m.at(i).at(j); 
		}
	}
return suma; 
}

bool JeLiGrbava(Matrica m){
	if(m.size() == 0 || m.at(0).size() == 0) return false; 
	for(int i = 0; i < m.size()-1; i++){
		if(m.at(i).size() != m.at(i+1).size()) return true; 
	}
	return false; 
}

bool JeLiPlanina(double suma, double clan){
	if(suma < clan) return true;
	return false; 
}

double DajSumuVrha(Matrica m){
	double suma(0);
	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m.at(i).size(); j++){
			if(i == j) suma = m.at(i).at(j); 
		}
	}
	
	return suma; 
}



Matrica NajvecaPlaninaMatrice(Matrica m){
	if(JeLiGrbava(m)) throw std::domain_error("Matrica nije korektna");
	Matrica planina; 
	for(int i = 0; i < m.size(); i++){
		
		for(int j = 0; j < m.at(i).size(); j++){
			
			int n(0); 
			
			while(i+n < m.size() && j+n < m.at(0).size() && j - n  >= 0 && i - n >= 0){
				
			Matrica pom = FormirajMatricu(m, i, j, n); 
			
			if((JeLiPlanina(SaberiOkolne(pom), SaberiUnutarnje(pom)) || pom.size() == 1) && pom.size() > planina.size() || (pom.size() == planina.size() && pom.at(pom.size()/2).at(pom.size()/2) > planina.at(planina.size()/2).at(planina.size()/2))){ 
				planina = pom; 
			}
			
			n++; 
			}
		}
		
	}
	
	return planina; 
}



int main(){
	std::cout << "Unesite dimenzije matrice (m i n): "; 
	int m, n; 
	std::cin >> m >> n; 
	
	if(m < 0 || n < 0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl; 
		return 0; 
	}
	std::cout << "Unesite elemente matrice: " << std::endl; 

	
	Matrica mat;
	mat.resize(m); 
	for(int i = 0; i < m; i++) mat.at(i).resize(n); 
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			double r; 
			std::cin >> r; 
			mat.at(i).at(j) = r;  
		}
	}
	try{
	Matrica planina(NajvecaPlaninaMatrice(mat)); 
	std::cout << "Najveca planina unesene matrice je:" << std::endl; 
	for(int i = 0; i < planina.size(); i++){
		for(int j = 0; j < planina.at(i).size(); j++){
			std::cout << std::setw(6) << planina.at(i).at(j);  
		}
		std::cout << std::endl; 
	}
	}
	catch(std::domain_error greska){
		std::cout << "Izuzetak: " << greska.what() << std::endl; 
	}
	return 0; 
}



