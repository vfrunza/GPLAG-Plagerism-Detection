#include <iostream>
#include <vector>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

bool GrbavaMatrica(Matrica m)
{
	int a;
	a=int(m.at(0).size());
	for(int i=1; i<m.size(); i++)
		if(a!=int(m.at(i).size())) return true;
	return false;
}
Matrica NajvecaPlaninaMatrice(Matrica m)
{
	Matrica rezultat;
	if(m.size()==0 || m.at(0).size()==0) return rezultat;
	else if(GrbavaMatrica(m)==true) throw std::domain_error ("Matrica nije korektna");
/*	Matrica pomocna;
	int vrhpomocneRed(0);
	int vrhpomocneKolona(0);
	int vrhrezultatRed(0);
	int vrhrezultaKolona(0);
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m.at(i).size(); j++) {
			int TrenutnaSuma(m.at(i).at(j));
			int brojac(0),suma(0);
			if(i-brojac<m.size() && i+brojac<m.size() && j+brojac<m.at(i).size() && j-brojac<m.at(i).size()) {
				for(int l=i-brojac; l<=i+brojac; l++) {
					for(int k=j-brojac; k<=j+brojac; k++) {
						if(l==i-brojac || l==i+brojac) suma+=m.at(l).at(k);
						else {
							if(k==j-brojac || k==j+brojac) suma+=m.at(l).at(k);
						}
					}
				}
				if(suma>TrenutnaSuma) {
					vrhpomocneRed=i;
					vrhpomocneKolona=j;
					pomocna.resize(2*brojac+1);
					pomocna=m;
				}
				brojac++;

			} else break;
		}
	}
	if(pomocna.size()>rezultat.size()) rezultat=pomocna;
	//else if(pomocna.at(pomocna.size()/2).at(pomocna.size()/2)> rezultat.at(rezultat.size()/2).at(rezultat.size()/2)) rezultat=pomocna;
	else if(vrhpomocneRed<vrhrezultatRed) rezultat=pomocna;
	else if(vrhpomocneKolona>vrhrezultaKolona) rezultat=pomocna;*/
	return rezultat;
}

int main ()
{
	try {
		int m,n;
		std::cout<<"Unesite dimenzije matrice (m i n): ";
		std::cin>>m>>n;
		if(m<0 || n<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
		else
			std::cout<<"Unesite elemente matrice:";
		Matrica mat(m,std::vector<double>(n));
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				std::cin>>mat.at(i).at(j);
			}
		}
		Matrica matrix;
		matrix=NajvecaPlaninaMatrice(mat);
		for(int i=0; i<matrix.size(); i++) {
			for(int j=0; j<matrix.at(i).size(); j++) {
				std::cout<<matrix.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	} catch( std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}