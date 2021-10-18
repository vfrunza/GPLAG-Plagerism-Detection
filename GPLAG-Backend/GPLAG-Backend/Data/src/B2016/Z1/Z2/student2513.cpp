/*B 2016/2017, Zadaća 1, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
// Nije dovrseno, nedostaje bacanje izuzetka!! dovrsiti
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
typedef std::vector<std::vector<double>>matrica;
typedef std::vector<double>vektor;
using std::cout;
using std::cin;
using std::endl;

vektor spoji (vektor a, vektor b, vektor c)
{
	for(int i=0; i<b.size(); i++) {
		a.push_back(b[i]);
	}
	for(int i=0; i<c.size(); i++) {
		a.push_back(c[i]);
	}
	return a;
}

matrica HorizontalnoOgledalo(matrica m)
{
	double pomocni;
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m[i].size(); j++) {
			if(j<m[i].size()/2) {
				pomocni=m[i][j];
				m[i][j]=m[i][m[i].size()-j-1];
				m[i][m[i].size()-j-1]=pomocni;
			}
		}
	}
	return m;
}

matrica VertikalnoOgledalo (matrica m)
{
	double pomocni;
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m[i].size(); j++) {
			if(i<m.size()/2) {
				pomocni=m[i][j];
				m[i][j]=m[m.size()-1-i][j];
				m[m.size()-1-i][j]=pomocni;
			}
		}
	}
	return m;
}

matrica KombinovanoOgledalo (matrica m)
{

	m=HorizontalnoOgledalo(m);
	m=VertikalnoOgledalo(m);
	return m;
}

matrica OgledaloMatrica (matrica m)
{
	matrica kopija=m;
	matrica h=HorizontalnoOgledalo(m);
	matrica v=VertikalnoOgledalo(m);
	matrica hv=KombinovanoOgledalo(m);

	matrica konacna;
	for(int i=0; i<hv.size(); i++) {
		vektor a=spoji(hv[i], v[i], hv[i]);
		konacna.push_back(a);
	}
	for(int i=0; i<hv.size(); i++) {
		vektor a=spoji(h[i], kopija[i], h[i]);
		konacna.push_back(a);
	}
	for(int i=0; i<hv.size(); i++) {
		vektor a=spoji(hv[i], v[i], hv[i]);
		konacna.push_back(a);
	}
	return konacna;
}

int main ()
{

	double a;
	int m1, n;
	cout << "Unesite dimenzije matrice (m n): ";
	cin >> m1;
	cin >> n;
	if(m1<0 || n<0) cout << "Dimenzije matrice moraju biti nenegativne!";
	else {
		cout << "Unesite elemente matrice: ";
		matrica m(m1,std::vector<double>(n));
		for(int i=0; i<m1; i++) {
			for(int j=0; j<n; j++) {
				cin >> a;
				m[i][j]=a;
			}
		}
		matrica konacna=OgledaloMatrica(m);
		cout << endl << "Rezultantna matrica: " << endl;
		for(int i=0; i<konacna.size(); i++) {
			for(int j=0; j<konacna[i].size(); j++) {
				cout << std::setw(4) << konacna[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}