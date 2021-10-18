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
#include <iomanip>

// kad je samo 1 red
// kad je samo 1 kolona
// moraju li svi okolo biti elementi za planinu

std::vector<std::vector<int>> NajvecaPlaninaMatrice (std::vector<std::vector<int>> matrix){
	
	std::vector<std::vector<std::vector<int>>> MatricaMatrica;
	std::vector<int> SUMA;
	for(int i=1; i<matrix.size()-1; i++){
		
		for(int j=1; j<matrix[i].size()-1; j++){
			// sume redati u neki vektor da se mogu porediti
			int brojac(1);
			suma = matrix[i-brojac][j] + matrix[i-brojac][j-brojac] + matrix[i][j-brojac] + matrix[i+brojac][j-brojac] + matrix[i+brojac][j] + matrix[i+brojac][j+brojac] + matrix[i][j+brojac] + matrix[i-brojac][j+brojac];
			SUMA.push_back(suma);
			
			if(suma >= matrix[i][j]){
				// ako je suma veca od elementa jeste planina stavi je u matricu
			}
			
			// ispitati postoji li jos planina za taj element
			if((i-brojac) == 0 || (j-brojac) == 0){
				// nema vise planina za taj element
				continue;
			}
			
			// UPIS ELEMENATA U MATRICU
			for(int i=0; i<(brojac*2)+1; i++){
				for(int j=0; j<(brojac*2)+1; j++){
					
				}
			}
			
			brojac++;
			
			while(brojac != 1){
				if((i-brojac) == 0 || (j-brojac) == 0){
					brojac = 1;
				}
				suma = matrix[i-brojac][j] + matrix[i-brojac][j-brojac] + matrix[i][j-brojac] + matrix[i+brojac][j-brojac] + matrix[i+brojac][j] + matrix[i+brojac][j+brojac] + matrix[i][j+brojac] + matrix[i-brojac][j+brojac];
				SUMA.push_back(suma);
				if(SUMA[SUMA.size()-1] >= SUMA.size()-2){
					// ako je suma veca od prethodne sume upisi matricu
				}
				brojac++;
			}
		}
	}
	
	return matrix;
}

int main (){
	std::vector<std::vector<int>> matrix = {{0, 0, 0, 15, 12, 6}, {1, 25, 1, 5, 2, 9}, {1, 1, 20, 15, 10, 5}, {3, 2, 19, 130, 14, 8}, {90, 6, 20, 12, 17, 2}, {12, 3, 5, 1, 8, 4}};
	std::vector<std::vector<int>> max_planina = NajvecaPlaninaMatrice(matrix);
	for(int i=0; i<max_planina.size(); i++){
		for(int j=0; j<max_planina[i].size(); j++){
			std::cout << std::setw(6) << max_planina[i][j];
		}
		std::cout << std::endl;
	}
	
	/*int m, n;
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	
	std::cout << "Unesite elemente matrice: ";
	std::vector<std::vector<int>> matrix;
	for(int i=0; i<m; i++){
		std::vector<int> red;
		for(int j=0; j<n; j++){
			int element;
			std::cin >> element;
			red.push_back(element);
		}
		matrix.push_back(red);
	}
	
	std::vector<std::vector<int>> max_planina = NajvecaPlaninaMatrice(matrix);
	
	std::cout << "Najveca planina unesene matrice je: " << std::endl;
	for(int i=0; i<max_planina.size(); i++){
		for(int j=0; j<max_planina[i].size(); j++){
			std::cout << max_planina[i][j];
		}
		std::cout << std::endl;
	}*/
	
	return 0;
}