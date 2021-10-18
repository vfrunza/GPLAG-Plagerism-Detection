#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

double SumaKvadrata(std::vector<std::vector<double>> matrica, int m, int n,int x){
	double suma = 0;
	for(int i = 0; i < matrica.size(); i++){
		for(int j = 0; j < matrica.at(0).size(); j++){
			if(i == m - x && j >= n - x && j <= n + x) suma += matrica.at(i).at(j);
			else if(i == m + x && j >= n - x && j <= n + x) suma += matrica.at(i).at(j);
			else if(j == n - x && i >= m - x && i <= m + x) suma += matrica.at(i).at(j);
			else if(j == n + x && i >= m - x && i <= m + x) suma += matrica.at(i).at(j);
		}
	}
	return suma;
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> matrica){
	int br_kv, br;
	int m = matrica.size();
	int n = matrica.at(0).size();
	for(int i = 0; i < m; i++){
		if(matrica.at(i).size() != n) throw std::domain_error("Matrica nije korektna");
	}
	std::vector<double> sume;
	std::vector<std::vector<double>> rezultat;
	int max = 0, max_i = 0, max_j = 0;
	for(int i = 1; i < m - 1; i++){
		for(int j = 1; j < n - 1; j++){
			if(matrica.at(i).at(j) > SumaKvadrata(matrica,i,j,1)){
				sume.push_back(matrica.at(i).at(j));
				br_kv = 0;
				while(i - br_kv > 0 && i + br_kv < m - 1 && j - br_kv > 0 && j + br_kv < n - 1) br_kv++;
				for(int k = 0; k < br_kv; k++){
					sume.push_back(SumaKvadrata(matrica,i,j,k+1));
				}
				br = 1;
				for(int k = 0; k < sume.size() - 1; k++){
					if(sume.at(k) > sume.at(k+1)) br++;
				}
				if(br == sume.size()){
					if(br > max){
						 max = br;
						 max_i = i;
						 max_j = j;
					}
					else if(br == max){
						if(matrica.at(i).at(j) > matrica.at(max_i).at(max_j)){
							max = br;
							max_i = i;
							max_j = j;
						}
						else if(matrica.at(i).at(j) == matrica.at(max_i).at(max_j)){
							if(i < max_i){
								max = br;
								max_i = i;
								max_j = j;
							}
							else if(i == max_i){
								if(j < max_j){
									max = br;
									max_i = i;
									max_j = j;
								}
							}
						}
					}
				}
				sume.resize(0);
			}
		}
	}
	if(max != 0){
		int vel = 2 * max - 1;
		rezultat.resize(vel);
		for(int i = 0; i < vel; i++) rezultat.at(i).resize(vel);
		for(int i = 0; i < vel; i++){
			for(int j = 0; j < vel; j++){
				rezultat.at(i).at(j) = matrica.at(max_i - max + 1 + i).at(max_j - max + 1 + j);
			}
		}
	}
	else{
		rezultat.resize(1);
		rezultat.at(0).resize(1);
		int najveci = matrica.at(0).at(0);
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(matrica.at(i).at(j) > najveci) najveci = matrica.at(i).at(j);
			}
		}
		rezultat.at(0).at(0) = najveci;
	}
	return rezultat;
}


int main ()
{
	try{
		int m,n;
		std::vector<std::vector<double>> matrica;
		std::vector<std::vector<double>> rezultat;
		std::cout << "Unesite dimenzije matrice (m i n): ";
		std::cin >> m >> n;
		if(m < 0 || n < 0) std::cout << "Dimenzije matrice moraju biti nenegativne!";
		else{
			matrica.resize(m);
			for(int i = 0; i < m; i++) matrica.at(i).resize(n);
			std::cout << "Unesite elemente matrice:" << std::endl;
			for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++){
					std::cin >> matrica.at(i).at(j);
				}
			}
			rezultat = NajvecaPlaninaMatrice(matrica);
			std::cout << "Najveca planina unesene matrice je:" << std::endl;
			for(int i = 0; i < rezultat.size(); i++){
				for(int j = 0; j < rezultat.at(0).size(); j++){
					std::cout << std::setw(6) << rezultat.at(i).at(j);
				}
				std::cout << std::endl;
			}
		}
	}
	catch(const std::domain_error &e){
		std::cout << "Izuzetak: " << e.what() << std::endl;
	}
	return 0;
}