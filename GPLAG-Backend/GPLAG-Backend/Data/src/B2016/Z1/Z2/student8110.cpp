#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>

//Funkcija koja vraca horizontalno ogledalo matrice M
std::vector<std::vector<double>> HorizontalnoOgledalo (std::vector<std::vector<double>> M) {
	std::vector<std::vector<double>> H(M.size());
	for (int i=0; i<M.size();i++) {
		for(int j=M.at(i).size()-1; j>=0; j--) {
			H[i].push_back(M[i][j]);
		}
	}
	return H;
}

//Funkcija koja vraca Vertikalno ogledalo matrice M
std::vector<std::vector<double>> VertikalnoOgledalo (std::vector<std::vector<double>> M) {
	std::vector<std::vector<double>> V(M.size());
	for (int i=M.size()-1; i>=0;i--) {
		for(int j=0; j<M.at(i).size(); j++) {
			V[M.size()-1-i].push_back(M[i][j]);
		}
	}
	return V;
}
//Funkcija u kojoj obrazujemo konacnu Ogledalo matricu
std::vector<std::vector<double>> OgledaloMatrica (std::vector<std::vector<double>> M) {
	std::vector<std::vector<double>> Mat(3*M.size());
	if(M.size() ==0) {
		return Mat;
	}
	bool grbava(false);
	for(int i=0; i<M.size(); i++) {
		for(int j=i+1; j<M.size(); j++) {
			if(M[i].size()!=M[j].size())
				grbava = true;
				break;
		}
	}
	if(grbava) throw std::domain_error("Matrica nije korektna");
	int m = M.size();
	int n = M.at(0).size();
	
	
	for(int i=0; i<3*m; i++) {
		for(int j=0; j<3*n; j++) {
			if(i<m) {
				if(j<n) {
					Mat.at(i).push_back(HorizontalnoOgledalo(VertikalnoOgledalo(M))[i][j]);
				}
				if(j>=n && j<2*n) {
					Mat.at(i).push_back(VertikalnoOgledalo(M)[i][j-n]);
				}
				if(j>=2*n && j<3*n) {
					Mat.at(i).push_back(HorizontalnoOgledalo(VertikalnoOgledalo(M))[i][j-(2*n)]);
				}
			}
			
			if(i>=m && i<2*m) {
				if(j<n) {
					Mat.at(i).push_back(HorizontalnoOgledalo(M)[i-m][j]);
				}
				if(j>=n && j<2*n) {
					Mat.at(i).push_back(M[i-m][j-n]);
				}
				if(j>=2*n && j<3*n) {
					Mat.at(i).push_back(HorizontalnoOgledalo(M)[i-m][j-(2*n)]);
				}
			}
			
			if(i>=2*m && i<3*m) {
				if(j<n) {
					Mat.at(i).push_back(HorizontalnoOgledalo(VertikalnoOgledalo(M))[i-(2*m)][j]);
				}
				if(j>=n && j<2*n) {
					Mat.at(i).push_back(VertikalnoOgledalo(M)[i-(2*m)][j-n]);
				}
				if(j>=2*n && j<3*n) {
					Mat.at(i).push_back(HorizontalnoOgledalo(VertikalnoOgledalo(M))[i-(2*m)][j-(2*n)]);
				}
			}

		}
	}
	return Mat;
}


int main () {
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
		
	std::cout << "Unesite elemente matrice: " <<std::endl;
	std::vector<std::vector<double>> M (m, std::vector<double>(n));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cin >> M[i][j];
		}
	}
	
	std::cout << "Rezultantna matrica: " << std::endl;
	
	try {
		std::vector<std::vector<double>> Mat = OgledaloMatrica(M);
		for(int i=0; i<Mat.size();i++) {
			for(int j=0; j<Mat.at(i).size(); j++) {
				std::cout << std::right << std::setw(4) << Mat[i][j];
			}
			std::cout << std::endl;
		}
	}
	catch(std::domain_error e) {
		std::cout << e.what();
	}
	
	return 0;
}