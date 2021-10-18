/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;
Matrica OgledaloMatrica(Matrica matrica) {
	Matrica nova;
	
	nova.resize(3*matrica.size());
	for(int i=0;i<3*matrica.size();i++) {
		nova[i].resize(3*matrica[0].size());
	}
	if(matrica.size()==0 || matrica[0].size()==0 ) return nova;
	Matrica h(matrica.size(),std::vector<double> (matrica[0].size()));
	Matrica v(matrica.size(),std::vector<double> (matrica[0].size()));
	Matrica hv(matrica.size(),std::vector<double> (matrica[0].size()));
	int k;
	for(int i=0;i<matrica.size();i++) {
		k=0;
		for(int j=matrica[i].size()-1;j>=0;j--) {
			if(matrica[i].size()!=matrica[0].size()) throw std::domain_error ("Matrica nije korektna!");
			h[i][k]=matrica[i][j];
			k++;
		}
	}
	k=0;
	for(int i=matrica.size()-1;i>=0;i--) {
		for(int j=0;j<matrica[i].size();j++) {
			v[k][j]=matrica[i][j];
		}
		k++;
	}
	int p(0),r(0);
	for(int i=matrica.size()-1;i>=0;i--) {
		r=0;
		for(int j=matrica[0].size()-1;j>=0;j--) {
			hv[p][r]=matrica[i][j];
			r++;
		}
		p++;
	}
	int a(0);
	for(int i=0;i<matrica.size();i++) {
		for(int j=0;j<matrica[0].size();j++) {
			nova[a][j]=hv[i][j];
		}
		for(int j=0;j<matrica[0].size();j++) {
			nova[a][j+matrica[0].size()]=v[i][j];
		}
		for(int j=0;j<matrica[0].size();j++) {
			nova[a][j+2*matrica[0].size()]=hv[i][j];
		}
		a++;
	}
	for(int i=0;i<matrica.size();i++) {
		for(int j=0;j<matrica[0].size();j++) {
			nova[a][j]=h[i][j];
		}
		for(int j=0;j<matrica[0].size();j++) {
			nova[a][j+matrica[0].size()]=matrica[i][j];
		}
		for(int j=0;j<matrica[0].size();j++) {
			nova[a][j+2*matrica[0].size()]=h[i][j];
		}
		a++;
	}
	for(int i=0;i<matrica.size();i++) {
		for(int j=0;j<matrica[0].size();j++) {
			nova[a][j]=hv[i][j];
		}
		for(int j=0;j<matrica[0].size();j++) {
			nova[a][j+matrica[0].size()]=v[i][j];
		}
		for(int j=0;j<matrica[0].size();j++) {
			nova[a][j+2*matrica[0].size()]=hv[i][j];
		}
		a++;
	}
	return nova;
}
int main ()
{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!"; 
		return 0;
	}
	std::cout<<"Unesite elemente matrice: \n";
	Matrica matrica(m,std::vector<double> (n));
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			std::cin>>matrica[i][j];
		}	
	}
	try {
		auto nova(OgledaloMatrica(matrica));
		std::cout<<"Rezultantna matrica: \n";
		for(int i=0;i<nova.size();i++) {
			for(int j=0;j<nova[i].size();j++) {
				std::cout<<std::setw(4)<<nova[i][j];
			}
			std::cout<<std::endl;
		}
	} 
	catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}