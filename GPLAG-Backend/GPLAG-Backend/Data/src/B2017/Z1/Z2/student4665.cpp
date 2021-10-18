#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

std::vector<std::vector<double>>  KreirajMatricu(int m, int n) {
        return std::vector<std::vector<double>>(m, std::vector<double> (n));
}
std::vector<std::vector<double>>  UnesiMatricu(int m, int n) {
        auto M(KreirajMatricu(m, n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                std::cin >> M.at(i).at(j);
            }
        return M;
}
std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> M) {
	std::vector<std::vector<double>> planina;
	if(M.size() == 0) return M;
	if(M.at(0). size() == 0) return M;
	for (int i = 1; i < M.size(); i++) 
		if(M.at(0).size() != M.at(i).size()) throw std::domain_error("Matrica nije korektna");
	if(M.size() < 3 || M.at(0).size() < 3) {
		int max = M.at(0).at(0);
		for (int i = 0; i < M.size(); i++) {
			for (int j = 0; j < M.at(i).size(); j++) {
				if(max < M.at(i).at(j)) max = M.at(i).at(j);
			}
		}
	   std::vector<std::vector<double>> vektor(1);
	   vektor.at(0).push_back(max);
	   return vektor;
	}
	if(M.size() == 3 && M.at(0).size() == 3) return M;
	int m = M.size() - 1, n = M.at(0).size() - 1;
	if(M.size() == 3) {
		m++;
		planina.resize(3); planina.at(0).resize(3);  planina.at(1).resize(3);  planina.at(2).resize(3);
	}
	if(M.at(0).size()) n++;
	for (int i = 1; i < m; i++) {
		if(i == M.size() - 1) break;
		for (int j = 1; j < n; j++) {
			if(j == M.at(0).size() - 1) break;
			int zbir0 = 0, zbir1 = 0, k = 1;
			zbir0 = M.at(i-1).at(j - 1) + M.at(i-1).at(j) + M.at(i-1).at(j+1) + M.at(i).at(j-1) + M.at(i).at(j+1) + M.at(i+1).at(j-1) + M.at(i+1).at(j) + M.at(i+1).at(j+1);
			
			if(zbir0 < M.at(i).at(j)) {
				if(M.size() == 3 || M.at(0).size() == 3) {
					if(M.at(i).at(j) > planina.at(1).at(1)) {
						planina.at(0).at(0) =  M.at(i-1).at(j - 1); planina.at(0).at(1) =  M.at(i-1).at(j); planina.at(0).at(2) =  M.at(i-1).at(j + 1);
						planina.at(1).at(0) =  M.at(i).at(j - 1); planina.at(1).at(1) =  M.at(i).at(j); planina.at(1).at(2) =  M.at(i).at(j + 1);
						planina.at(2).at(0) =  M.at(i+1).at(j - 1); planina.at(2).at(1) =  M.at(i+1).at(j); planina.at(2).at(2) =  M.at(i+1).at(j + 1);	
					}
				}
				if((i - 2 > 0 && i + 2 < M.size() && j + 2 < M.at(0).size() && j - 2 > 0)) {
					zbir1 = M.at(i-1-k).at(j - 1-k) + M.at(i-1-k).at(j) + M.at(i-1-k).at(j+1+k) + M.at(i).at(j-1-k) + M.at(i).at(j+1+k) + M.at(i+1+k).at(j-1-k) + M.at(i+1+k).at(j) + M.at(i+1+k).at(j+1+k);
					k++;
					while(zbir1 < zbir0 && i - 1 - k > 0 && i + 1 + k < M.size() && j + 1 + k < M.at(0).size() && j - 1 - k > 0) {
						zbir0 = zbir1;
						zbir1 = M.at(i-1-k).at(j - 1-k) + M.at(i-1-k).at(j) + M.at(i-1-k).at(j+1+k) + M.at(i).at(j-1-k) + M.at(i).at(j+1+k) + M.at(i+1+k).at(j-1-k) + M.at(i+1+k).at(j) + M.at(i+1+k).at(j+1+k);
						k++;
					}
					if(zbir1 >= zbir0) {
						if(k*2 + 1 > planina.size()) {
							planina.resize(k*2 + 1);
							for(int h = i  - k; h < i + 1 + k; h++) {
								planina.at(h - i  + k).resize(k*2 + 1);
								for(int f = i  - k; f < i + 1 + k; f++)
									planina.at(h - i + k).at(f - i  + k) = M.at(h).at(f);
							}
						} else if (k*2 + 1 == planina.size()) {
							if(M.at(i).at(j) > planina.at(planina.size() - (planina.size() - 1)/2 - 1).at(planina.size() - (planina.size() - 1)/2 - 1)) {
								planina.resize(k*2 + 1);
								for(int h = i  - k; h < i + 1 + k; h++) {
									planina.at(h - i  + k).resize(k*2 + 1);
									for(int f = i  - k; f < i + 1 + k; f++)
										planina.at(h - i  + k).at(f - i  + k) = M.at(h).at(f);
								}
							}
						}
					} else {
						if(k*2 + 1 > planina.size()) {
							planina.resize(k*2 + 1);
							for(int h = i - k; h < i + 1 + k; h++) {
								planina.at(h - i  + k).resize(k*2 + 1);
								for(int f = i - k; f < i + 1 + k; f++)
									planina.at(h - i  + k).at(f - i  + k) = M.at(h).at(f);
							}
						} else if (k*2 + 1 == planina.size()) {
							if(M.at(i).at(j) > planina.at(planina.size() - (planina.size() - 1)/2 - 1).at(planina.size() - (planina.size() - 1)/2 - 1)) {
								planina.resize(k*2 + 1);
								for(int h = i - 1 - k; h < i + 2 + k; h++) {
									planina.at(h).resize(k*2 + 1);
									for(int f = i - 1 - k; f < i + 2 + k; f++)
										planina.at(h).at(f) = M.at(h).at(f);
								}
							}
						}
					}
				}
			}
		}
	}
	return planina;
}

int main ()
{
	try {
		int m,n;
		std::cout << "Unesite dimenzije matrice (m i n): ";
		std::cin >> m >> n;
		if(m >= 0 && n >= 0) {
			auto M(UnesiMatricu(m,n));
			std::cout << "Unesite elemente matrice:" << std::endl;
			auto planina(NajvecaPlaninaMatrice(M));
			std::cout << "Najveca planina unesene matrice je:" << std::endl;
			for (int i = 0; i < planina.size(); i++) {
				for (int j = 0; j < planina.at(i).size(); j++) {
					std::cout <<  std::setw(6) << planina.at(i).at(j);
				}
				std::cout << std::endl;
			}
		} else {
			std::cout << "Dimenzije matrice moraju biti nenegativne!";
		}
	}
	catch (const char error[]) {
		std::cout << error << std::endl;
	}
	
	return 0;
}