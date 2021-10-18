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
#include <cmath>
#include <stdexcept>

typedef std::vector<std::vector<double>> matrica;
const double epsilon = 0.000001;

std::vector<double> Vecaplanina (std::vector<double> a, std::vector<double> b)
{
	if(a.at(1)>b.at(1)) return a;
	if(a.at(1)<b.at(1)) return b;
	if(a.at(1)-b.at(1)<epsilon) {
		if(a.at(2)<b.at(2)) return a;
		if(a.at(2)>b.at(2)) return b;
		if(a.at(2)-b.at(2)<epsilon) return b;
		{
			if(a.at(3)<b.at(3)) return a;
			if(a.at(3)>b.at(3)) return b;
		}
	}
}
std::vector<double> Najveci(matrica a)
{
	for(int i=0; i<a.size()-1; i++) {
		if(a.at(0).at(0)>a.at(1).at(0)) return a.at(0);
		if(abs(a.at(0).at(0)-a.at(1).at(0))<epsilon) {
			a.at(1)=Vecaplanina(a.at(0),a.at(1));
			a.erase(a.begin()+0);
		}
	}
	return a.at(0);
}

matrica KreirajMatricu(int a,int b)
{
	matrica m;
	if(a==0 || b==0) return m;
	if(a<0 || b<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	return matrica(a,std::vector<double> (b));
}

bool Planina(std::vector<std::vector<double>> a)
{
	int x=a.size()/2;
	int koncentricni {0};
	std::vector<double> planina;
	planina.push_back(a.at(x).at(x));
	for(int k=0; k<x; k++) {
		for(int i=0; i<a.size(); i++) {
			for(int j=0; j<a.size(); j++) {
				if((i>=x-k-1 && i<=x+k+1 && (j==x-k-1||j==x+k+1)) || (j>=x-k-1 && j<=x+k+1 && (i==x-k-1 || i==x+k+1))) koncentricni+=a.at(i).at(j);
			}
		}
		planina.push_back(koncentricni);
		koncentricni=0;
	}
	for(int i=0; i<planina.size()-1; i++) {
		if(planina.at(i)<planina.at(i+1))return false;
	}
	return true;
}

std::vector<std::vector<double>>MaxElement(matrica a){
	double max(a.at(0).at(0));
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a.at(0).size();j++){
			if(a.at(i).at(j)>max)max=a.at(i).at(j);
		}
	}
	return (matrica(1,std::vector<double> (1,max)));
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice(matrica a)
{
	if(a.size()==0 || a.at(0).size()==0) return KreirajMatricu(0,0);
	
	int redovi=a.size();
	int kolone=a[0].size();
	if(redovi==1 && kolone==1) return a;
	if(redovi<3 && kolone<3) return MaxElement(a);
	for(int i=0; i<a.size(); i++) {
		if(a.at(i).size()!=a.at(0).size()) throw std::domain_error("Matrica nije korektna");
	}
	int n {0};
	std::vector<double> sacuvaj;
	if(redovi==kolone) {
		n=redovi;

	} else if(redovi<kolone) n=redovi;
	else n=kolone;
	if(n%2==0) n-=1;
	matrica sveplanine;
	matrica planina;
	std::vector<double> x;
	for(int dim=n; dim>=3; dim-=2) {
		for(int k=0; k<=redovi-dim; k++) {
			for(int z=0; z<=kolone-dim; z++) {
				for(int i=0+k; i<dim+k; i++) {
					for(int j=0+z; j<dim+z; j++) {
						x.push_back(a.at(i).at(j));
					}
					planina.push_back(x);
					x.resize(0);
				}
				if(Planina(planina)) {
					sacuvaj.push_back(dim);
				    sacuvaj.push_back(planina.at((dim+k)/2).at((dim+z)/2));
				    //else sacuvaj.push_back(planina.at(0).at(0));
					sacuvaj.push_back(k);
					sacuvaj.push_back(z);
					sveplanine.push_back(sacuvaj);
					sacuvaj.resize(0);
					planina.resize(0);
				} else planina.resize(0);
			}
		}
	}
	if(sveplanine.size()==0) return matrica(KreirajMatricu(0,0));
	sacuvaj=Najveci(sveplanine);
//	planina=KreirajMatricu(sacuvaj.at(0),sacuvaj.at(0));
	for(int i=sacuvaj.at(2); i<sacuvaj.at(0)+sacuvaj.at(2); i++) {
		for(int j=sacuvaj.at(3); j<sacuvaj.at(0)+sacuvaj.at(3); j++) {
			x.push_back(a.at(i).at(j));
		}
		planina.push_back(x);
		x.resize(0);
	}
	return planina;
}


int main ()
{
	try {
		std::cout<<"Unesite dimenzije matrice (m i n): ";
		int m,n;
		std::cin>>m>>n;
		matrica a(KreirajMatricu(m,n));
		std::cout<<"Unesite elemente matrice: "<<std::endl;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				std::cin>>a.at(i).at(j);

			}
		}

		a=NajvecaPlaninaMatrice(a);
		std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
		for(int i=0; i<a.size(); i++) {
			for(int j=0; j<a.at(0).size(); j++) {
				std::cout<<std::right<<std::setw(6)<<a.at(i).at(j);
			}
			std::cout<<std::endl;
		}
	} catch(std::domain_error e) {
		std::cout<<e.what();
	}
	return 0;
}