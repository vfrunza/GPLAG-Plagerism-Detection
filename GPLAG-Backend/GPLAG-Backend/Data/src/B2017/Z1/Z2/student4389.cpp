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
typedef std::vector<std::vector<double>> Matrica;


Matrica NajvecaPlaninaMatrice( Matrica mat)
{
	Matrica matrica;
	int i(0),j(0),e,razlicite(0);
	std::vector<int> sume;
	double max;
	if(mat.size()>1) {
		for ( i=0; i<mat.size(); i++) {
			for(j=0; j<mat.at(i).size(); j++) {

			}
			if(mat.size()<=(i+1)) break;
			else if(mat.at(i).size()!=mat.at(i+1).size()) {
				razlicite++;
				break;
			} else razlicite=0;
		}



		if(razlicite>0) {
			throw std::domain_error("Matrica nije korektna");

		}
		
	}
	
}

int main ()
{

	int m(0),n(0);
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;

	} else {
		try {
			Matrica mat(m);
			std::cout<<"Unesite elemente matrice: ";
			for( int i=0; i<m; i++) {
				for(int j=0; j<n; j++) {
					mat.at(i).resize(n);
					std::cin>>mat.at(i).at(j);

				}
			}

			mat=NajvecaPlaninaMatrice(mat);
			for( int i=0; i<mat.size(); i++) {
				for(int j=0; j<mat.at(i).size(); j++) {
					std::cout<<std::endl<<"Najveca planina unesene matrice je:"<<std::endl<<std::setw(6)<<std::right<<mat.at(i).at(j);
				}
				std::cout<<std::endl;
			}

		} catch (std::domain_error izuzetak ) {
			std::cout<<izuzetak.what()<<std::endl;

		}

		return 0;
	} 
	
}
