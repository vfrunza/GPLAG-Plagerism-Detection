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
typedef std::vector<std::vector<double>> DoubleMatrica;

DoubleMatrica VertikalnoOgledalo (DoubleMatrica matrica) {
	DoubleMatrica v(matrica.size(), std::vector<double> (matrica[0].size()));
	for (int i(0); i<v.size(); i++) 
		for (int j(0); j<v[0].size(); j++)
			v[i][j]=matrica[matrica.size()-1-i][j];
	return v;
}

DoubleMatrica HorizontalnoOgledalo (DoubleMatrica matrica) {
	DoubleMatrica h(matrica.size(), std::vector<double> (matrica[0].size()));
	for (int i(0); i<h.size(); i++)
		for (int j(0); j<h[0].size(); j++)
			h[i][j]=matrica[i][matrica[0].size()-j-1];
	return h;
}

DoubleMatrica OgledaloMatrica (DoubleMatrica m) {
	if(m.size()==0) return m;
	int broj_redova(m.size()), broj_kolona(m[0].size());
	for (int i(1); i<broj_redova; i++)
		if (m[i].size()!=broj_kolona) throw std::domain_error ("Matrica nije korektna");
	DoubleMatrica ogledalo(3*broj_redova, std::vector<double> (3*broj_kolona, 0));
	DoubleMatrica v_ogledalo(VertikalnoOgledalo(m)), h_ogledalo(HorizontalnoOgledalo(m));
	DoubleMatrica hv_ogledalo(HorizontalnoOgledalo(v_ogledalo));
	int hv1(0), hv2(0), h1(0), h2(0), v1(0), v2(0), m1(0), m2(0);
	for (int i(0); i<3*broj_redova; i++) {
		for (int j(0); j<3*broj_kolona; j++) {
			if ((i<broj_redova || i>=2*broj_redova) && (j<broj_kolona || j>=2*broj_kolona)) {ogledalo[i][j]=hv_ogledalo[hv1][hv2]; hv2++;}
			else if ((i<broj_redova || i>=2*broj_redova) && (j>=broj_kolona && j<2*broj_kolona)) {ogledalo[i][j]=v_ogledalo[v1][v2]; v2++; hv2=0;}
			else if ((i>=broj_redova && i<2*broj_redova) && (j<broj_kolona || j>=2*broj_kolona)) {ogledalo[i][j]=h_ogledalo[h1][h2]; h2++;}
			else {ogledalo[i][j]=m[m1][m2]; m2++; h2=0;}
		}
		hv2=0; v2=0; h2=0; m2=0;
		if (i<broj_redova) {hv1++; v1++;}
		else if (i>=broj_redova && i<2*broj_redova) {h1++; m1++; hv1=0; v1=0;}
		else {hv1++; v1++;}
	}
	return ogledalo;
}
int main ()
{
	try {
		int m,n;
		std::cout<<"Unesite dimenzije matrice (m n): ";
		std::cin>>m>>n;
		if(m<0 || n<0) {std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
		DoubleMatrica matrica(m, std::vector<double> (n));
		std::cout<<"Unesite elemente matrice: ";
		for (int i(0); i<m; i++) 
			for (int j(0); j<n; j++) 
				std::cin>>matrica[i][j];
		DoubleMatrica ogledalo(OgledaloMatrica(matrica));
		std::cout<<"\nRezultantna matrica: \n";
		for (int i(0); i<3*m; i++) {
			for (int j(0); j<3*n; j++)
				std::cout<<std::setw(4)<<ogledalo[i][j];
			std::cout<<std::endl;
		}
	}
	catch (std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}