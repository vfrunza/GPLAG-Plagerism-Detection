/*B 2016/2017, Zadaća 1, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include<vector>
#include<iomanip>
#include<iostream>
#include<cmath>
#include<stdexcept>
using std::cout;
using std::cin;
using std::endl;
using std::setw;
typedef std::vector<std:: vector<double>> mat;
typedef std:: vector<double> vektor;
/*fja za horizontalnu*/
mat Horizontalna(mat matrica)
{
	mat ogledalce(matrica.size(),vektor (matrica[0].size()));
	for(int i=0; i<matrica.size(); i++) {
		int k=0;
		for(int j=matrica[i].size()-1; j>=0; j--) {
			ogledalce[i][k]=matrica[i][j];
			k++;
		}
	}
	return ogledalce;
}
/*fja za vertikalnu*/
mat Vertikalna(mat matrica)
{
	mat ogledalce(matrica.size(), vektor (matrica[0].size()));
	for(int i=0; i<matrica.size(); i++) {
		ogledalce[i]=matrica[matrica.size()-i-1];
	}
	return ogledalce;
}
/*fja vraca poslatu matricu*/
mat Obicna(mat matrica)
{
	mat ogledalce(matrica.size(), vektor (matrica[0].size()));
	for(int i=0; i<matrica.size(); i++) {
		for(int j=0; j<matrica[i].size(); j++) {
			ogledalce[i][j]=matrica[i][j];
		}
	}
	return ogledalce;
}
/*fja za kombinovanu*/
mat Kombinovana(mat matrica)
{
	mat ogledalce(matrica.size(), vektor (matrica[0].size()));
	for(int i=0; i<matrica.size(); i++) {
		for(int j=0; j<matrica[i].size(); j++) {
			ogledalce[i][j]=matrica[matrica.size()-1-i][matrica[matrica.size()-1-i].size()-1-j];
		}
	}
	return ogledalce;
}
mat OgledaloMatrica(mat matrica)
{
	if(matrica.size()==0) {
		return matrica;
	}
	/*izuzetak*/
	for(int i=0; i<matrica.size()-1; i++) {
		if(matrica[i].size()!=matrica[i+1].size())throw std::domain_error("Matrica nije korektna");
	}
	mat horizontalna=Horizontalna(matrica);
	mat vertikalna=Vertikalna(matrica);
	mat obicna=Obicna(matrica);
	mat kombinovana=Kombinovana(matrica);
	mat ogledalo(3*matrica.size(), vektor (3*matrica[0].size()));
	/*prva trecina ogledalo matrice*/
	for(int i=0; i<matrica.size(); i++) {
		int k=0,l=0;
		for(int j=0; j<3*matrica[i].size(); j++) {
			if(j<matrica[i].size())ogledalo[i][j]=kombinovana[i][j];

			if(j<2*matrica[i].size() && j>=matrica[i].size()) {
				ogledalo[i][j]=vertikalna[i][k];
				k++;
			}

			if(j<3*matrica[i].size() && j>=2*matrica[i].size()) {
				ogledalo[i][j]=kombinovana[i][l];
				l++;
			}
		}
	}
	/*druga trecina*/
	for(int i=matrica.size(); i<2*matrica.size(); i++) {
		int n=0, o=0;
		for(int j=0; j<3*matrica[i-matrica.size()].size(); j++) {

			if(j<matrica[i-matrica.size()].size()) {
				ogledalo[i][j]=horizontalna[i-matrica.size()][j];
			}
			if(j<2*matrica[i-matrica.size()].size() && j>=matrica[i-matrica.size()].size()) {
				ogledalo[i][j]=obicna[i-matrica.size()][n];
				n++;
			}
			if(j<3*matrica[i-matrica.size()].size() && j>=2*matrica[i-matrica.size()].size()) {
				ogledalo[i][j]=horizontalna[i-matrica.size()][o];
				o++;
			}
		}
	}
	/*treca trecina ogledala*/
	for(int i=2*matrica.size(); i<3*matrica.size(); i++) {
		int n=0, o=0;
		for(int j=0; j<3*matrica[i-2*matrica.size()].size(); j++) {

			if(j<matrica[i-2*matrica.size()].size()) {
				ogledalo[i][j]=kombinovana[i-2*matrica.size()][j];
			}
			if(j<2*matrica[i-2*matrica.size()].size() && j>=matrica[i-2*matrica.size()].size()) {
				ogledalo[i][j]=vertikalna[i-2*matrica.size()][n];
				n++;
			}
			if(j<3*matrica[i-2*matrica.size()].size() && j>=2*matrica[i-2*matrica.size()].size()) {
				ogledalo[i][j]=kombinovana[i-2*matrica.size()][o];
				o++;
			}
		}
	}
	return ogledalo;


}

int main ()
{
	/*unos dimenzija*/
	cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	cin>>m>>n;
	/*ako nisu unesene dimenzije pravilne zavrsavanje programa*/
	if(m<0 || n<0) {
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	mat matrica(m, vektor (n));
	/*unosenje elemenata matrice*/
	cout<<"Unesite elemente matrice: ";
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin>>matrica[i][j];
		}
	}
	cout<<endl;
	/*pozivanje fje*/
	try {
		cout<<"Rezultantna matrica: "<<endl;
		mat rezultat=OgledaloMatrica(matrica);
		for(vektor red : rezultat) {
			for(double x : red)cout<<setw(4)<<x;
			cout<<endl;
		}
	}
	/*hvatanje izuzetka*/
	catch(std::domain_error izuzetak) {
		cout<<izuzetak.what()<<endl;
	}
	return 0;
}