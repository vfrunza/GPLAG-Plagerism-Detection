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
#include <cmath>

typedef std::vector<std::vector<double>> Matrica;

bool DaLiJeGrbava(Matrica M){
	int dimenzija(M.at(0).size());
	for(int i(0) ; i<M.size() ; i++){
		if(M.at(i).size()!=dimenzija) return false;
	}
	return true;
}

Matrica KreirajPlaninu(Matrica M,int red,int i,int j){
	Matrica Planina(3,std::vector<double> (3));
	int k(0);
	for(int x(i-1);x<red;x++){
		int l(0);
		for(int y(j-1);y<red;y++){
			Planina.at(k).at(l)=M.at(x).at(y);
			l++;
		}
		k++;
	}
	return Planina;
}


Matrica NajvecaPlaninaMatrice(Matrica M){
	if(!(DaLiJeGrbava(M))) throw std::domain_error("Matrica nije korektna");
	Matrica Planina;
	if((M.size()>0 && M.size()<3) || (M.at(0).size()>0 && M.at(0).size()<3)){
		double max(M.at(0).at(0));
		for(int i(0) ; i<M.at(0).size() ; i++){
		for(int j(0) ; j<M.size() ; j++){
			if(M.at(i).at(j)>max){
				max=M.at(i).at(j);
			}
		}
	}
	Matrica P{{max}};
	return P;
	}
	
	for(int i(0) ; i<M.at(i).size() ; i++){
		for(int j(0) ; j<M.size() ; j++){
			int red(3);
			double vrh(M.at(i).at(j)),suma(3);
			if(j-1>=0 && i-1>=0 && j+1<M.size() && i+1<M.at(i).size()){
				for(int k(i-1) ; k<red ; k++){
					for(int l(j-1) ; l<red ; l++){
						if(i!=red-2 && j!=red-2){
							suma+=M.at(i).at(j);
						}
					}
				}
			}
			if(suma>vrh){
					Planina=KreirajPlaninu(M,red,i,j);
				}
		}
	}
	return Planina;
}


int main ()
{
	std::cout << "Unesite dimenzije matrice (m i n): ";
	int m(0),n(0);
	std::cin >> m >> n;
	if(m<0 || n<0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout << "Unesite elemente matrice: ";
	Matrica M(m,std::vector<double>(n));
	for(int i(0); i<m ; i++){
		for(int j(0) ; j<n ; j++){
			double element(0);
			std::cin >> element;
			M.at(i).at(j)=element;
		}
	}
	Matrica Planina(NajvecaPlaninaMatrice(M));
	std::cout << "\nNajveca planina unesene matrice je: " << std::endl;
	for(auto red : Planina){
		for(auto x : red){
			std::cout << std::setw(6) << x;
		}
		std::cout << std::endl;
	}
	
	return 0;
}