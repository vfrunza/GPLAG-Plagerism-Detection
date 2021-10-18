/*B 2016/2017, Zadaća 1, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stdexcept>

using std::cin;
using std::cout;


std::vector<std::vector<double>> kolone(std::vector<std::vector<double>>v)
{
	int velicina1=v[0].size()-1;
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<(v[0].size()/2); j++) {
			double pomocni1=v[i][j];
			v[i][j]=v[i][velicina1-j];
			v[i][velicina1-j]=pomocni1;
		}
	}
	return v;
}

std::vector<std::vector<double>> redovi(std::vector<std::vector<double>>v)
{
	int velicina2=v.size()-1;
	for(int i=0; i<(v.size()/2); i++) {
		for(int j=0; j<v[0].size(); j++) {
			double pomocni2=v[i][j];
			v[i][j]=v[velicina2-i][j];
			v[velicina2-i][j]=pomocni2;
		}
	}
	return v;
}

std::vector<std::vector<double>> koloneiredovi(std::vector<std::vector<double>>v)
{
	int velicina1=v[0].size()-1;
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<(v[0].size()/2); j++) {
			double pomocni1=v[i][j];
			v[i][j]=v[i][velicina1-j];
			v[i][velicina1-j]=pomocni1;
		}
	}

	int velicina2=v.size()-1;
	for(int i=0; i<(v.size()/2); i++) {
		for(int j=0; j<(v[0].size()); j++) {
			double pomocni2=v[i][j];
			v[i][j]=v[velicina2-i][j];
			v[velicina2-i][j]=pomocni2;
		}
	}
	return v;
}

std::vector<std::vector<double>>OgledaloMatrica(std::vector<std::vector<double>>v)
{
	if(v.size()==0) return v;
	else {
		int brkolonav(v[0].size()), brredovav(v.size());
		int brkolona(3*brkolonav), brredova(3*brredovav);

		for(int i=0; i<v.size()-1; i++) {
			if(v[i].size()!=v[i+1].size()) throw std::domain_error("Matrica nije korektna");
		}

		std::vector<std::vector<double>>rezultat(brredova,std::vector<double>(brkolona));


		std::vector<std::vector<double>>r(redovi(v));
		std::vector<std::vector<double>>k(kolone(v));
		std::vector<std::vector<double>>kir(koloneiredovi(v));


		for(int i=0; i<kir.size(); i++) {
			for(int j=0; j<kir[0].size(); j++) {
				rezultat.at(i).at(j)=kir.at(i).at(j);
				rezultat.at(i).at(j+brkolonav*2)=kir.at(i).at(j);
				rezultat.at(i+brredovav*2).at(j)=kir.at(i).at(j);
				rezultat.at(i+brredovav*2).at(j+brkolonav*2)=kir.at(i).at(j);
			}
		}

		for(int i=0; i<r.size(); i++) {
			for(int j=0; j<r[0].size(); j++) {
				rezultat.at(i).at(j+brkolonav)=r.at(i).at(j);
				rezultat.at(i+brredovav*2).at(j+brkolonav)=r.at(i).at(j);
			}
		}

		for(int i=0; i<k.size(); i++) {
			for(int j=0; j<k[0].size(); j++) {
				rezultat.at(i+brredovav).at(j)=k.at(i).at(j);
				rezultat.at(i+brredovav).at(j+brkolonav*2)=k.at(i).at(j);
			}
		}

		for(int i=0; i<v.size(); i++) {
			for(int j=0; j<v[0].size(); j++) {
				rezultat.at(i+brredovav).at(j+brkolonav)=v.at(i).at(j);
			}
		}
		return rezultat;
	}
}

int main ()
{
	int m,n;

	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;

	if(m<0 || n<0) std::cout<<"Dimenzije matrice moraju biti nenegativne!";

	else {
		cout<<"Unesite elemente matrice: "<<"\n";

		std::vector<std::vector<double>>matrica(m,std::vector<double>(n));

		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				cin>>matrica[i][j];
			}
		}
		try {
			std::vector<std::vector<double>>rezultantna;

			rezultantna=OgledaloMatrica(matrica);
			std::cout<<"Rezultantna matrica: "<<"\n";

			for(int i=0; i<rezultantna.size(); i++) {
				for(int j=0; j<rezultantna[0].size(); j++) cout<<std::setw(4)<<rezultantna.at(i).at(j);
				cout<<"\n";
			}
		} catch(std::domain_error e) {
			cout<<e.what();
		}
	}
	return 0;
}