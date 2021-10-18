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

Matrica OgledaloMatrica (Matrica m) {
	//Provjeravanje grbave matrice
	int broj_redova, broj_kolona;
	broj_redova=m.size();
	if (broj_redova!=0) broj_kolona=m[0].size();
	else broj_kolona=0;
	for (int i=0; i<broj_redova; i++) {
		if (m[0].size()!=m[i].size())
			throw std::domain_error ("Matrica nije korektna");
	}
	Matrica a(3*broj_redova, std::vector<double>(3*broj_kolona));
	Matrica h(broj_redova, std::vector<double>(broj_kolona));
	Matrica v(broj_redova, std::vector<double>(broj_kolona));
	Matrica hv(broj_redova, std::vector<double>(broj_kolona));
	//Matrica h
	for (int i=0; i<broj_redova; i++) {
		for (int j=0; j<broj_kolona; j++) {
			h[i][j]=m[i][broj_kolona-j-1];
		}
	}
	//Matrica v
	for (int i=0; i<broj_redova; i++) {
		for (int j=0; j<broj_kolona; j++) {
			v[i][j]=m[broj_redova-i-1][j];
		}
	}
	//Matrica hv
	for (int i=0; i<broj_redova; i++) {
		for (int j=0; j<broj_kolona; j++) {
			hv[i][j]=h[broj_redova-i-1][j];
		}
	}
	//Elemente nove matrice upisujemo red po red, prema postavci zadatka
	int i, j, x, y;
	for (i=0; i<broj_redova; i++) {
		for (j=0; j<broj_kolona; j++) a[i][j]=hv[i][j];
		for (x=0; x<broj_kolona; x++) a[i][j+x]=v[i][x];
		for (y=0; y<broj_kolona; y++) a[i][j+x+y]=hv[i][y];
	}
	for (i=broj_redova; i<2*broj_redova; i++) {
		for (j=0; j<broj_kolona; j++) a[i][j]=h[i-broj_redova][j];
		for (x=0; x<broj_kolona; x++) a[i][j+x]=m[i-broj_redova][x];
		for (y=0; y<broj_kolona; y++) a[i][j+x+y]=h[i-broj_redova][y];
	}
	for (i=2*broj_redova; i<3*broj_redova; i++) {
		for (j=0; j<broj_kolona; j++) a[i][j]=hv[i-2*broj_redova][j];
		for (x=0; x<broj_kolona; x++) a[i][j+x]=v[i-2*broj_redova][x];
		for (y=0; y<broj_kolona; y++) a[i][j+x+y]=hv[i-2*broj_redova][y];
	}
	
return a;
}
int main ()
{
	Matrica a;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m, n;
	std::cin>>m>>n;
	if (m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	a.resize(m);
	for (int i=0; i<m; i++)
		a[i].resize(n);
	std::cout<<"Unesite elemente matrice: \n";
	for (int j=0; j<m; j++) {
		for (int k=0; k<n; k++) {
		std::cin>>a[j][k];																																																																																																																																																					
		}
	}
	Matrica rezultanta(OgledaloMatrica(a));
	std::cout<<"Rezultantna matrica: \n";
	if (m==0 && n==0) return 0;
	for (int i=0; i<3*m; i++) {
		for (int j=0; j<3*n; j++) {
			std::cout<<std::setw(4)<<rezultanta[i][j];
		}
		std::cout<<std::endl;
	}
	
	return 0;
}