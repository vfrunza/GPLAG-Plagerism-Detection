#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

//Kreira matricu sa zadanim brojem redova i kolona
Matrica KreirajMatricu(int m, int n) {
	return Matrica(m, std::vector<double>(n));
}

//Vraca broj redova zadane matrice
int BrojRedova(Matrica M) {
	return M.size();
}

//Vraca broj kolona zadane matrice
int BrojKolona(Matrica M) {
	return M.at(0).size();
}

//Unosi matricu
Matrica UnesiMatricu(int m, int n) {
	auto M (KreirajMatricu(m,n));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cin >> M.at(i).at(j);
		}
	}
	return M;
}

void IspisiMatricu(Matrica M) {
	for(int i=0; i<BrojRedova(M); i++) {
		for(int j=0; j< BrojKolona(M); j++) {
			std::cout << std::setw(5) << M.at(i).at(j);
		}
		std::cout << std::endl;
	}
}


std::vector<std::vector<double>> NajvecaPlaninaMatrice (std::vector<std::vector<double>> M) {
	std::vector<std::vector<double>> M1(0);



	for(int i=0; i<M.size(); i++) {
		if(M.at(i).size()!=M.at(0).size())  {
			throw std::domain_error ("Matrica nije korektna");

		}
	}

	if(BrojKolona(M)==0 || BrojKolona(M) ==0 || BrojKolona(M)==1 || BrojRedova(M)==1 || BrojKolona(M)==2 || BrojRedova(M)==2) {
		return M1;
	}
	
	int sum=0;
	for(int i(0); i<BrojRedova(M)-1; i++) {
		for(int j(0); i<BrojKolona(M)-1; j++) {

           
			while(1) {
				for(int p=i; i<i+1; i++) {
					for(int q=j;  j<j+1; j++) {
						sum+=M.at(p).at(q);
					}
				}
			}



			/*if((M.at(i-1).at(j-1) + M.at(i-1).at(j) + M.at(i-1).at(j+1) + M.at(i).at(j-1) + M.at(i).at(j+1) + M.at(i+1).at(j-1) +
			        M.at(i+1).at(j) + M.at(i+1).at(j+1)) > M.at(i).at(j)
			        && (M.at(i-2).at(j-2) + M.at(i-2).at(j-1) + M.at(i-2).at(j) + M.at(i-2).at(j+1) + M.at(i-2).at(j+2) + M.at(i-1).at(j-2) +
			        M.at(i-1).at(j+2) + M.at(i).at(j-2) + M.at(i).at(j+2) + M.at(i+1).at(j-2) + M.at(i+1).at(j+2) + M.at(i+2).at(j-2) +
			        M.at(i+2).at(j-1) + M.at(i+2).at(j) + M.at(i+2).at(j+1) + M.at(i+2).at(j+2)) < (M.at(i-1).at(j-1) + M.at(i-1).at(j) +
			        M.at(i-1).at(j+1) + M.at(i).at(j-1) + M.at(i).at(j+1) + M.at(i+1).at(j-1) + M.at(i+1).at(j) + M.at(i+1).at(j+1))) {
				return
			}*/
		}
	}

	return M1;

}

int main () {
	try {
		std::cout << "Unesite dimenzije matrice (m i n): ";
		int m,n;
		std::cin >> m >> n;
		if(m<0 || n<0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
			return 0;
		}

		std::cout << "Unesite elemente matrice:\n";
		std::vector<std::vector<double>> Matrica;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				auto M(UnesiMatricu(m,n));
			}
		}

		std::cout << "Najveca planina unesene matrice je:\n";

		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				IspisiMatricu(NajvecaPlaninaMatrice(Matrica));
			}
		}

	} catch(std::domain_error &e) {
		std::cout << "Izuzetak:" << e.what() << std::endl;
	} catch(...) {
		throw "Pogrešan izuzetak!";
	}

	return 0;
}