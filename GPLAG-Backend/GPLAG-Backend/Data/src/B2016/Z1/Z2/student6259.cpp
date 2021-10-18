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

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::setw;
using std::domain_error;

typedef vector<vector<double>> Matrica;

Matrica horizontalno_ogledalo(Matrica a) {
	for(int i(0); i<a.size(); i++) {
		for(int j(0); j<a.at(0).size()/2; j++) {
			double temp=a[i][j];
			a[i][j]=a[i][a.at(0).size()-j-1];
			a[i][a.at(0).size()-j-1]=temp;
		}
	}
	return a;
}

Matrica vertikalno_ogledalo(Matrica a) {
	for(int i(0); i<a.size()/2; i++){
		for(int j(0); j<a.at(0).size(); j++) {
			double temp=a[i][j];
			a[i][j]=a[a.size()-i-1][j];
			a[a.size()-i-1][j]=temp;
		}
	}
	return a;
}

Matrica horizontalno_vertikalno_ogledalo(Matrica a) {
	a=horizontalno_ogledalo(vertikalno_ogledalo(a));
	return a;
}

Matrica OgledaloMatrica(Matrica a) {
	
	for(int i(0); i<a.size(); i++) {
		if(a.at(0).size()!=a.at(i).size()) throw domain_error("Matrica nije korektna");
	}
	
	Matrica matrica, h, v, hv;
	
	hv=horizontalno_vertikalno_ogledalo(a);
	v=vertikalno_ogledalo(a);
	h=horizontalno_ogledalo(a);
	
	matrica.resize(3*a.size());
	for(int i(0); i<matrica.size(); i++) matrica.at(i).resize(3*a.at(0).size());
	
	for(int i(0); i<matrica.size(); i++) {
		for(int j(0); j<matrica.at(0).size(); j++) {
			if(i<matrica.size()/3) {
				if(j<matrica.at(0).size()/3) matrica[i][j]=hv[i][j];
				else if(j>=2*matrica.at(0).size()/3) matrica[i][j]=hv[i][j-2*matrica.at(0).size()/3];
				else matrica[i][j]=v[i][j-matrica.at(0).size()/3];
			}
			else if(i>=2*matrica.size()/3) {
				if(j<matrica.at(0).size()/3) matrica[i][j]=hv[i-2*matrica.size()/3][j];
				else if(j>=2*matrica.at(0).size()/3) matrica[i][j]=hv[i-2*matrica.size()/3][j-2*matrica.at(0).size()/3];
				else matrica[i][j]=v[i-2*matrica.size()/3][j-matrica.at(0).size()/3];
				
				}
			else  {
				if(j<matrica.at(0).size()/3) matrica[i][j]=h[i-matrica.size()/3][j];
				else if(j>=2*matrica.at(0).size()/3) matrica[i][j]=h[i-matrica.size()/3][j-2*matrica.at(0).size()/3];
				else matrica[i][j]=a[i-matrica.size()/3][j-matrica.at(0).size()/3];
				
			}
		}
	}
	
	return matrica;
}

int main ()
{
	try {
		int m, n;
	
		cout<<"Unesite dimenzije matrice (m n): ";
		cin>>m>>n;
	
		if(m<0 || n<0) cout<<"Dimenzije matrice moraju biti nenegativne!";
		else {
			Matrica matrica;
			matrica.resize(m);
			for(int i(0); i<m; i++) matrica.at(i).resize(n);
			cout<<"Unesite elemente matrice: ";
			for(int i(0); i<m; i++) {
				for(int j(0); j<n; j++) cin>>matrica[i][j];
			}
	
			cout<<endl<<"Rezultantna matrica: "<<endl;
			Matrica konacno;
			konacno=OgledaloMatrica(matrica);
				for(int i(0); i<konacno.size(); i++) {
				for(int j(0); j<konacno.at(0).size(); j++) {
					cout<<setw(4)<<konacno[i][j];
				}
				cout<<endl;
			}
		}
	}
	
	catch(domain_error greska) {
		cout<<greska.what()<<endl;
	}
	
	
	return 0;
}