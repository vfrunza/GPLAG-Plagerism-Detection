/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

void Provjera1(int x, int y){
	if(x<0 || y<0){
		throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	}
}

void Provjera(Matrica x){
	for(int i=0; i<x.size(); i++){
		if(x[i].size()!=x[0].size()){
			throw std::domain_error("Matrica nije korektna.");
		}
	}
}

Matrica KreirajMatricu(int br_redova, int br_kolona){
	return Matrica(br_redova, std::vector<double>(br_kolona));
}

int BrRedova(Matrica m){
	return m.size();
}

int BrKolona(Matrica m){
	return m[0].size();
}

Matrica UnesiMatricu(int br_redova, int br_kolona){
	auto m(KreirajMatricu(br_redova, br_kolona));
	for(int i=0; i<br_redova; i++)
		for(int j=0; j<br_kolona; j++){
			std::cin>>m[i][j];
		}
	return m;
}

void IspisiMatricu(Matrica m){
	for(int i=0; i<BrRedova(m); i++){
		for(int j=0; j<BrKolona(m); j++){
			std::cout<<std::setw(4)<<m[i][j];
		}
		std::cout<<std::endl;
	}
}

Matrica OgledaloMatrica(Matrica x){
	if(x.size()==0 || x[0].size()==0){
		return x;
	}
	Matrica k1=x;
	int brKolona=k1[0].size();
	for(int q=0; q<BrRedova(x); q++){
	for (int i = 0, j = brKolona-1; i < j; i++, j--) {
    	double tmp = k1[q][i];
    	k1[q][i] = k1[q][j];
    	k1[q][j] = tmp;
  		}
	}
	Matrica k2=x;
	int brRedova=k2.size();
	for(int q=0; q<BrKolona(x); q++){
	for (int i = 0, j = brRedova-1; i < j; i++, j--) {
    	double tmp = k2[i][q];
    	k2[i][q] = k2[j][q];
    	k2[j][q] = tmp;
  		}
	}
	Matrica k3=x;
	int brRedova1=k3.size();
	for(int i=0; i<BrKolona(x); i++){
		for(int j=0, k=brRedova1-1; j<k; j++, k--){
			double tmp=k3[j][i];
			k3[j][i]=k3[k][i];
			k3[k][i]=tmp;
		}
	}
	int brKolona1=k3[0].size();
	for(int i=0; i<BrRedova(x); i++){
		for(int j=0, k=brKolona1-1; j<k; j++, k--){
			double tmp=k3[i][j];
			k3[i][j]=k3[i][k];
			k3[i][k]=tmp;
		}
	}
	Matrica h=k1;
	Matrica v=k2;
	Matrica hv=k3;
	Matrica w=KreirajMatricu(3*x.size(), 3*x[0].size());
	int k,l;
	for(int i=0; i<3*x.size(); i++){
		for(int j=0; j<3*x[0].size(); j++){
			k=i/x.size();
			l=j/x[0].size();
			if((k==0 || k==2) && (l==0 || l==2)){
				w[i][j]=k3[i-k*x.size()][j-l*x[0].size()];
			}
			else if((k==0 || k==2) && (l==1)){
				w[i][j]=k2[i-k*x.size()][j-l*x[0].size()];
			}
			else if((k==1) && (l==0 || l==2)){
				w[i][j]=k1[i-k*x.size()][j-l*x[0].size()];
			}
			else{
				w[i][j]=x[i-k*x.size()][j-l*x[0].size()];
			}
		}
	}
	return w;
}

int main ()
{
	try{
		int m,n;
		std::cout<<"Unesite dimenzije matrice (m n): ";
		std::cin>>m>>n;
		Provjera1(m,n);
		std::cout<<"Unesite elemente matrice: ";
		auto a(UnesiMatricu(m,n));
		Provjera(a);
		std::cout<<std::endl;
		std::cout<<"Rezultantna matrica: "<<std::endl;
		IspisiMatricu(OgledaloMatrica(a));
	}
	
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}