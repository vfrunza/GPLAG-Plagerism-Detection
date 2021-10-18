/*B 2016/2017, Zadaća 1, Zadatak 2 */
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

bool DaLiJeGrbava(Matrica mat){
	for(int i=0; i<mat.size(); i++){
		if(i>0 && mat[i].size()!=mat[i-1].size())return true;
	}
	return false;
}

Matrica OgledaloMatrica(Matrica mat){
	Matrica spojena, v(mat), hv(mat), h(mat);
	std::vector<double> pomocni;
	int broj_redova(0), broj_kolona(0);
	double pomocni_broj;
	
	if(mat.size()!=0){	// u suprotnom vraca praznu 0x0
	broj_redova=mat.size();
	broj_kolona=mat[0].size();
	}
	if(DaLiJeGrbava(mat))throw std::domain_error("Matrica nije korektna");
	
	// promijenjeni redovi (v)
	for(int i=0; i<broj_redova/2; i++){
		pomocni=v[i];
		v[i]=v[broj_redova-1-i];
		v[broj_redova-1-i]=pomocni;
	}
	
	// promijenjene kolone (h)
	for(int i=0; i<broj_redova; i++){
		for(int j=0; j<broj_kolona/2; j++){
			pomocni_broj=h[i][j];
			h[i][j]=h[i][broj_kolona-1-j];
			h[i][broj_kolona-1-j]=pomocni_broj;
		}
	}
	
	hv=h; // dodijeljeni promijenjene kolone, jos promijeni redove
	for(int i=0; i<broj_redova/2; i++){
		pomocni=hv[i];
		hv[i]=hv[broj_redova-1-i];
		hv[broj_redova-i-1]=pomocni;
	}

	spojena.resize(3*broj_redova);
	for(int i=0; i<3*broj_redova; i++){
		spojena[i].resize(3*broj_kolona);
	}
	
	
	for(int i=0; i<2*broj_redova; i++){ 
		for(int j=0; j<2*broj_kolona; j++){
			if(i<broj_redova && j<broj_kolona){
				spojena[i][j]=hv[i][j];
				spojena[i+2*broj_redova][j]=hv[i][j];
				spojena[i][j+2*broj_kolona]=hv[i][j];
				spojena[i+2*broj_redova][j+2*broj_kolona]=hv[i][j];
			}
			if(i>=broj_redova && j<broj_kolona){
				spojena[i][j]=h[i-broj_redova][j];
				spojena[i][j+2*broj_kolona]=h[i-broj_redova][j];
			}
			if(i>=broj_redova && j>=broj_kolona){
				spojena[i][j]=mat[i-broj_redova][j-broj_kolona];
			}
			if(i<broj_redova && j>=broj_kolona){
				spojena[i][j]=v[i][j-broj_kolona];
				spojena[i+2*broj_redova][j]=spojena[i][j];
			}
		}
	}
	
	return spojena;
}

int main ()
{
	int m(0), n(0);
	Matrica mat;
	
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	mat.resize(m);
		for(int i=0; i<m; i++)mat[i].resize(n);
		std::cout << "Unesite elemente matrice: ";
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				std::cin >> mat[i][j];
			}	
		}
	try{
	Matrica Rezultantna=OgledaloMatrica(mat);
	std::cout << std::endl << "Rezultantna matrica: " << std::endl;
	for(int i=0; i<Rezultantna.size(); i++){
		for(int j=0; j<Rezultantna[i].size(); j++){
			std::cout << std::setw(4) << Rezultantna[i][j];
		}
		std::cout << std::endl;
			}
		}
	catch(std::domain_error izuzetak){
		std::cout << izuzetak.what();
	}
	return 0;
}