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

std::vector<std::vector<double>> NajvecaPlaninaMatrice (std::vector<std::vector<double>> m){
	if (m.size()==0 || m.size()==1) return m;
	for (int i=0;i<m.size();i++)
		if (m.at(0).size()!=m.at(i).size())
			throw std::domain_error ("Matrica nije korektna");
	std::vector<std::vector<double>> najveca_planina;
	double suma{0},suma1{0}, suma2{0},vrh{0};
	int brojac{1},koordinata_x{0},koordinata_y{0},dimenzija_trenutne{0};
	for (int i=1;i<m.size();i++){
		for (int j=1;j<m.at(0).size();j++){
			suma=m.at(i).at(j);
			brojac=1;
			suma1=0;
			while (i+brojac<m.size() && j+brojac<m.at(0).size() && i-brojac>=0 && j-brojac>=0){
				suma1=0;
				suma2=0;
				for (int s=i-brojac; s<=i+brojac ;s++){
					for (int g=j-brojac; g<=j+brojac; g++){
						suma1+=m.at(s).at(g);
						if (s+1<i+brojac && g+1<j+brojac) suma2+=m.at(s+1).at(g+1);
					}
				}
				suma1-=suma2;
				if (suma1<suma && dimenzija_trenutne<=(brojac*2+1) &&  m.at(i).at(j)>=vrh && koordinata_x<=i && koordinata_y<=j){
					najveca_planina.resize(brojac*2+1);
					for (int k=0;k<najveca_planina.size();k++){
						najveca_planina.at(k).resize(najveca_planina.size());
					}
					
					for (int l=0;l<najveca_planina.size();l++){
						for (int n=0;n<najveca_planina.size();n++){
							najveca_planina.at(l).at(n)=m.at(i-brojac+l).at(j-brojac+n);
						}
					}
					dimenzija_trenutne=brojac*2+1;
					vrh=m.at(i).at(j);
					koordinata_x=i;
					koordinata_y=j;
					suma=suma1;
				}
			    brojac++;
			}
		}
	}

	if (najveca_planina.size()==0){
		najveca_planina.resize(1);
		double najveci{m.at(0).at(0)};
		for (int i=0;i<m.size();i++){
			for (int j=0;j<m.at(0).size();j++){
				if (m.at(i).at(j)>najveci)
					najveci=m.at(i).at(j);
			}
		}
		najveca_planina.at(0).push_back(najveci);
	}
	
	
	return najveca_planina;
}

int main (){
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if (m<0 || n<0) { std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0; }
	std::vector<std::vector<double>> mat(m,std::vector<double>(n));
	std::cout<<"Unesite elemente matrice: "<<std::endl;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			std::cin>>mat.at(i).at(j);
		}
	}
	try{
		std::vector<std::vector<double>>najveca_planina1{NajvecaPlaninaMatrice(mat)};
		std::cout<<"Najveca planina unesene matrice je: "<<std::endl;
		for( int i=0;i<najveca_planina1.size();i++){
			for (int j=0;j<najveca_planina1.at(0).size();j++){
				std::cout<<std::setw(6)<<najveca_planina1.at(i).at(j);
			}
			std::cout<<std::endl;
		}
	}
	
	catch (std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	return 0;
}