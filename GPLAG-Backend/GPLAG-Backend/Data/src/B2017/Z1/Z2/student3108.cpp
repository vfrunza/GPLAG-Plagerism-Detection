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

typedef std::vector<std::vector<double>>Matrica;
/*
int SaberiRed (std::vector<double> red, int poc, int kraj) {
	int suma(0);
	for (int i=poc; i<=kraj; i++) suma+= red.at(i);
	
	return suma;
}

int SaberiKolonu (Matrica matrica, int poc, int kraj, int kolona) {
	int suma(0);
	for (int i=poc; i<=kraj; i++) suma+=matrica.at(i).at(kolona);
	return suma;
}
*/


Matrica NajvecaPlaninaMatrice (Matrica matrica) {
	Matrica Planina;
/*	Matrica NajvecaPlanina;*/
	if (matrica.size()==0) return Planina;
	else if (matrica.size() == 1 && matrica.at(0).size() == 1) return matrica;
	else if (matrica.size() == 2 && matrica.at(0).size() == 2 && matrica.at(1).size()==2) {
		int max=matrica.at(0).at(0);
		for (int i=0; i<2; i++) {
			for (int j=0; j<2; j++) {
				if(matrica.at(i).at(j)>max) max=matrica.at(i).at(j);
			}
		}
		Planina.resize(1);
		Planina.at(0).push_back(max);
		return Planina;
	}
	/*else {
		int vel=matrica.at(0).size();
		for (int i=0; i<matrica.size(); i++) 
			if (vel!=matrica.at(i).size()) throw std::domain_error ("Matrica nije korektna");
	} 
	
	for (int i=1; i<matrica.size(); i++) {
		for (int j=1; j<matrica.at(i).size(); j++) {
			int br(1);
			int kvadrant(0), kvadrant2(0);
			bool planina(true);
			kvadrant+= SaberiRed(matrica.at(i-1), j-1, j+1) + SaberiRed(matrica.at(i+1), j-1, j+1) + matrica.at(i).at(j-1) + matrica.at(i).at(j+1);
			if (matrica.at(i).at(j) < kvadrant) {
				planina=false;
				break;
			} else {
				planina=true;
				if(i-2>=0 && i+2<matrica.size() && j-2>=0 && j+2<matrica.at(0).size()) {
					kvadrant2+= SaberiRed(matrica.at(i-2), j-2, j+2) + SaberiRed(matrica.at(i+2), j-2, j+2) + SaberiKolonu(matrica, i-1, i+1, j-2) + SaberiKolonu(matrica, i-1, i+1, j+2);
					
				} else {
					Planina.resize(3, std::vector<double>(3));
					for (int a=0; a<3; a++) {
						for (int b=0; b<3; b++) 
							Planina.at(a).at(b)=matrica.at(a).at(b);
					}
				
					break;
				}
				
				while (kvadrant2<kvadrant) {
					kvadrant=kvadrant2;
					if(i-br>=0 && j-br>=0 && i+br<matrica.size() && j+br<matrica.at(0).size()) {
						kvadrant2+= SaberiRed(matrica.at(i-br), j-br, j+br) + SaberiRed(matrica.at(i+br), j-br, j+br) + SaberiKolonu(matrica, i-br+1, i+br-1, j-br) + SaberiKolonu(matrica, i-br+1, i+br-1, j+br);
					}
					br++;
				}
				Planina.resize(2*br+1, std::vector<double>(2*br+1));
				int m(0), n(0);
				for (int a=i-br; a<=i+br; i++) {
					for (int b=j-br; b<=j+br; b++) {
						Planina.at(m).at(n)=matrica.at(a).at(b);
						n++;
					}
					m++;
				}
				
				
			}
		}
	}*/
	
	
	return Planina;
}

int main ()
{
	std::cout << "Unesite dimenzije matrice (m i n): ";
	int m, n;
	std::cin >> m >> n;
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout << "Unesite elemente matrice: ";
	Matrica matrica (m, std::vector <double>(n));
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			std::cin >> matrica.at(i).at(j);
		}
	}
	std::cout << std::endl << "Najveca planina unesene matrice je:" << std::endl;
	
	try {
		Matrica planina = NajvecaPlaninaMatrice(matrica);
		for (int i=0; i<planina.size(); i++) {
			for(int j=0; j<planina.at(i).size(); j++) {
				std::cout << std::right << std::setw(6) << planina.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	} catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}
	
	return 0;
}