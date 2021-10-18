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

Matrica OgledaloMatrica (Matrica hehe){
	
	for (int i=0; i<hehe.size(); i++){
		if (hehe[i].size()!=hehe[0].size()){
			throw std::domain_error ("Matrica nije korektna");
			break;
	}
	}
	
	
	Matrica h, v, hv, velika;
	int l=hehe.size(), k;
	if (l==0) k=0;
	else k=hehe[0].size();
	velika.resize(3*l);
	for (int i=0; i<velika.size(); i++) velika[i].resize(3*k);
	h.resize(hehe.size());
	v.resize (hehe.size());
	hv.resize(hehe.size());
	for (int i=0; i<hehe.size(); i++){
		h[i].resize(hehe[i].size());
		v[i].resize(hehe[i].size());
		hv[i].resize(hehe[i].size());
	}
	
	/*Vertikalna*/
	std::vector<double> pomo;
	for (int i=0; i<v.size(); i++){
			pomo=hehe[i];
			v[i]=hehe[v.size()-i-1];
			v[v.size()-i-1]=pomo;
		}
	
	double pom;
	/*Horizontalna*/
	for (int i=0; i<h.size(); i++){
		for(int j=0; j<h[i].size(); j++){
			pom=hehe[i][j];
			h[i][j]=hehe[i][h[i].size()-j-1];
			h[i][h[i].size()-j-1]=pom;
			
		}
	}
	
	/*Kombinovana*/
	for (int i=0; i<hv.size(); i++){
		for (int j=0; j<hv[i].size(); j++){
			pom=v[i][j];
			hv[i][j]=v[i][hv[i].size()-j-1];
			hv[i][hv[i].size()-j-1]=pom;
		}
	}
	
	for (int i=0; i<velika.size(); i++){
		for (int j=0; j<velika[i].size(); j++){
			if (i<l && j<k) velika[i][j]=hv[i][j];
			else if (i>=2*l && j>=2*k) velika[i][j]=hv[i-2*l][j-2*k];
			else if (i<l && j>=2*k) velika[i][j]=hv[i][j-2*k];
			else if (i>=2*l && j<k) velika[i][j]=hv[i-2*l][j];
			else if (i<l && j>=k && j<2*k) velika[i][j]=v[i][j-k];
			else if (i>=2*l && j>=k && j<2*k) velika[i][j]=v[i-2*l][j-k];
			else if (i>=l && i<2*l && j<k) velika[i][j]=h[i-l][j];
			else if (i>=l && i<2*l && j>=2*k) velika[i][j]=h[i-l][j-2*k];
			
			else velika[i][j]=hehe[i-l][j-k];
		}
	}
	
	return velika;
}

int main ()
{
	Matrica mat, velika;
	int redovi, kolone;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>> redovi >> kolone;
	if (redovi<0 || kolone<0) std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	else{
	mat.resize(redovi);
	for (int i=0; i<mat.size(); i++) mat[i].resize(kolone);
	std::cout<<"Unesite elemente matrice: ";
	for (int i=0; i<mat.size(); i++){
		for (int j=0; j<mat[i].size(); j++){
			std::cin>>mat[i][j];
		}
	}
	std::cout<<"\nRezultantna matrica:\n";
	try{
	velika=OgledaloMatrica(mat);
	for (int i=0; i<velika.size(); i++){
		for (int j=0; j<velika[i].size(); j++){
			std::cout<<std::setw(4)<<velika[i][j];
		}
		std::cout<<std::endl;
	}
	}
	catch(const char izuzetak[]){
		std::cout<<izuzetak;
	}
	}
	return 0;
}