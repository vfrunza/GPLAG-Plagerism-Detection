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
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

double SumaKoncentricnogKvadrata (Matrica m, int x, int y, int k)
{
	double suma(0);
	if(x-k<0 || y-k<0) return 0;
	for(int i=0; i<2*k+1; i++) {
		for(int j=0; j<2*k+1; j++) {
			if(i==0 || i==2*k)
				suma+=m.at(i+x-k).at(j+y-k);
			else if(j==0 || j==2*k)
				suma+=m.at(i+x-k).at(j+y-k);
		}
	}

	return suma;
}

Matrica UpisiUMatricu (Matrica m, int x, int y, int nivo)
{

	Matrica rezultat(2*nivo+1, std::vector<double>(2*nivo+1));

	for(int i=0; i<2*nivo+1; i++) {
		for(int j=0; j<2*nivo+1; j++)
			rezultat.at(i).at(j)=m.at(i+x-nivo).at(j+y-nivo);
	}

	return rezultat;
}

Matrica NajvecaPlaninaMatrice (Matrica m)
{
	int max_i(0), max_j(0), max_nivo(0), nivo;
	if(m.size()!=0 && m.at(0).size()!=0) {
		for(int i=0; i<m.size(); i++) {
			for(int j=0; j<m.size(); j++) {
				if(m.at(i).size()!=m.at(j).size())
					throw std::domain_error("Matrica nije korektna");
			}
		}


		for(int i=0; i<m.size(); i++) {
			for(int j=0; j<m.at(i).size(); j++) {
				double vrh=m.at(i).at(j);
				double curr_suma=m.at(i).at(j);
				nivo=1;
				while (i-nivo>=0 && j-nivo>=0 && i+nivo<=m.size()-1 && j+nivo<=m.at(0).size()-1) {
					if(SumaKoncentricnogKvadrata(m,i,j,nivo)<curr_suma) {
						curr_suma=SumaKoncentricnogKvadrata(m,i,j,nivo);
					} else break;
					nivo++;
				}
				nivo--;
				if(nivo>max_nivo || (nivo==max_nivo && vrh>m.at(max_i).at(max_j))
				        || (nivo==max_nivo && vrh==m.at(max_i).at(max_j) && i>max_i)
				        || (nivo==max_nivo && vrh==m.at(max_i).at(max_j) && i==max_i && j>max_j)) {
					max_i=i;
					max_j=j;
					max_nivo=nivo;
				}
			}
		}

		return UpisiUMatricu(m,max_i,max_j,max_nivo); 
	}
	
	Matrica p;
	return p;


}
 

int main ()
{
	std::cout << "Unesite dimenzije matrice (m i n): ";
	int m(0), n(0);
	std::cin >> m>>n;

	if(m<0 || n<0)
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
	else {
		Matrica mat(m, std::vector<double>(n));
		std::cout << "Unesite elemente matrice: ";
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				double unos;
				std::cin >> unos;
				mat.at(i).at(j)=unos;
			}
		}

		try {
			Matrica rez(NajvecaPlaninaMatrice(mat));
			std::cout << std::endl<<"Najveca planina unesene matrice je: " << std::endl;
			for(int i=0; i<rez.size(); i++) {
				for(int j=0; j<rez.at(i).size(); j++) {
					std::cout << std::setw(6)<<rez.at(i).at(j);
				}
				std::cout  << std::endl; 
			}
		} catch(std::domain_error izuzetak) {
			std::cout << izuzetak.what();
		}
	}

	return 0;
}