/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<double> Vektor;

Matrica HorizontalnoOgledalo (Matrica m){
	Matrica k(m.size(),Vektor(m[0].size()));
	for (int i=0;i<m.size();i++){
		for (int j=0;j<m[0].size();j++){
			k[i][j]=m[i][m[0].size()-1-j];
		}
	}
	return k;
}
Matrica VertikalnoOgledalo (Matrica m){
	Matrica k(m.size(),Vektor(m[0].size()));
	for (int i=0;i<m.size();i++){
		for (int j=0;j<m[0].size();j++){
			k[i][j]=m[m.size()-1-i][j];
		}
	}
	return k;
}

Matrica KombinovanoOgledalo (Matrica m){
	Matrica k(m.size(),Vektor(m[0].size()));
	for (int i=0;i<m.size();i++){
		for (int j=0;j<m[0].size();j++){
			k[i][j]=m[m.size()-1-i][m[0].size()-1-j];
		}
	}
	return k;
}
Matrica OgledaloMatrica (Matrica pocetna){
	if (pocetna.size()==0) return pocetna;
	for (int i=0;i<pocetna.size()-1;i++){
		if (pocetna[i].size()!=pocetna[i+1].size()){
			throw std::domain_error ("Matrica nije korektna");
		}
	}
	Matrica konacna (pocetna.size()*3,Vektor(pocetna[0].size()*3));
	Matrica h(HorizontalnoOgledalo(pocetna));
	Matrica v(VertikalnoOgledalo(pocetna));
	Matrica k(KombinovanoOgledalo(pocetna));
	int brojredova(pocetna.size());
	int brojkolona(pocetna[0].size());
	for (int i=0;i<brojredova;i++){
		for (int j=0;j<brojkolona;j++){
			konacna[i][j]=k[i][j];
		}
	}
	for (int i=0;i<brojredova;i++){
		for (int j=0;j<brojkolona;j++){
			konacna[i][j+brojkolona]=v[i][j];
		}
	}
	for (int i=0;i<brojredova;i++){
		for (int j=0;j<brojkolona;j++){
			konacna[i][j+2*brojkolona]=k[i][j];
		}
	}
	
	for (int i=0;i<brojredova;i++){
		for (int j=0;j<brojkolona;j++){
			konacna[i+brojredova][j]=h[i][j];
		}
	}
	
	for (int i=0;i<brojredova;i++){
		for (int j=0;j<brojkolona;j++){
			konacna[i+brojredova][j+brojkolona]=pocetna[i][j];
		}
	}
	
	for (int i=0;i<brojredova;i++){
		for (int j=0;j<brojkolona;j++){
			konacna[i+brojredova][j+2*brojkolona]=h[i][j];
		}
	}
	for (int i=0;i<brojredova;i++){
		for (int j=0;j<brojkolona;j++){
			konacna[i+2*brojredova][j]=k[i][j];	
		}
	}
	for (int i=0;i<brojredova;i++){
		for (int j=0;j<brojkolona;j++){
			konacna[i+2*brojredova][j+brojkolona]=v[i][j];
		}
	}
	for (int i=0;i<brojredova;i++){
		for (int j=0;j<brojkolona;j++){
			konacna[i+2*brojredova][j+2*brojkolona]=k[i][j];
		}
	}
	return konacna;
}

int main ()
{
	try{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if (m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice: "<<std::endl;
	Matrica mat(m,Vektor(n));
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			std::cin>>mat[i][j];
		}
	}
	Matrica mati(OgledaloMatrica(mat));
	std::cout<<"Rezultantna matrica: "<<std::endl;
	for (int i=0;i<mati.size();i++){
		for (int j=0;j<mati[0].size();j++){
			std::cout<<std::setw(4)<<mati[i][j];
		}
		std::cout<<std::endl;
	}
	}
	catch (std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	return 0;
}