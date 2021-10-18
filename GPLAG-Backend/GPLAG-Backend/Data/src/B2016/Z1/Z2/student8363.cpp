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
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
typedef std::vector<double> vDouble;
typedef std::vector<std::vector<double>> mvDouble;


void ispis_matrice(mvDouble ulaz) {
	for (auto i : ulaz) {
		for (auto j : i) {
			cout.width(4);
			cout<<j;
		}
		cout<<endl;
	}
}

mvDouble duploOgledalo(mvDouble ulaz) {
	int c=0;
	mvDouble izlaz(ulaz.size());
	for (int i = ulaz.size()-1; i>=0; i--) {
		for(int j=ulaz.at(i).size()-1; j>=0; j--) {
			izlaz.at(c).push_back(ulaz.at(i).at(j));
		}
		c++;
	}
	return izlaz;
}

mvDouble horizontalnoOgledalo(mvDouble ulaz) {
	int c=0;
	mvDouble izlaz(ulaz.size());
	for (int i = ulaz.size()-1; i>=0; i--) {
		for(int j=0; j<ulaz.at(i).size(); j++) {
			izlaz.at(c).push_back(ulaz.at(i).at(j));
		}
		c++;
	}
	return izlaz;

}

mvDouble vertikalnoOgledalo(mvDouble ulaz) {
	int c=0;
	mvDouble izlaz(ulaz.size());
	for (int i = 0; i < ulaz.size(); i++) {
		for(int j=ulaz.at(i).size()-1; j>=0; j--) {
			izlaz.at(c).push_back(ulaz.at(i).at(j));
		}
		c++;
	}
	return izlaz;

}

mvDouble OgledaloMatrica(mvDouble ulaz) {
	if(ulaz.size()==0)return ulaz;
	unsigned int column = ulaz.at(0).size();
	
	for (auto i : ulaz) {
		if(i.size()!=column)
		throw std::domain_error("Matrica nije korektna");
	}
	
	mvDouble izlaz(3*ulaz.size());
	mvDouble duplo	 = duploOgledalo(ulaz),
	horizontalno	 = horizontalnoOgledalo(ulaz),
	verikalno 		 = vertikalnoOgledalo(ulaz);
	
	int c =0;
	
	for (int i = 0; i < ulaz.size(); i++) {
		for (auto e : duplo.at(i)) {
			izlaz.at(c).push_back(e);
		}
		for (auto e : horizontalno.at(i)) {
			izlaz.at(c).push_back(e);
		}
		for (auto e : duplo.at(i)) {
			izlaz.at(c).push_back(e);
		}
		c++;
	}

	for (int i = 0; i < ulaz.size(); i++) {
		for (auto e : verikalno.at(i)) {
			izlaz.at(c).push_back(e);
		}
		for (auto e : ulaz.at(i)) {
			izlaz.at(c).push_back(e);
		}
		for (auto e : verikalno.at(i)) {
			izlaz.at(c).push_back(e);
		}
		c++;
	}

	for (int i = 0; i < ulaz.size(); i++) {
		for (auto e : duplo.at(i)) {
			izlaz.at(c).push_back(e);
		}
		for (auto e : horizontalno.at(i)) {
			izlaz.at(c).push_back(e);
		}
		for (auto e : duplo.at(i)) {
			izlaz.at(c).push_back(e);
		}
		c++;
	}

	return izlaz;
}

int main () {
	int m,n;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	if(m<0 || n<0) {
		cout<<"Dimenzije matrice moraju biti nenegativne!"<<endl;
		return 0;
	}
	cout<<"Unesite elemente matrice:"<<endl;
	mvDouble ulaz(m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			double a;
			cin>>a;
			ulaz.at(i).push_back(a);
		}
	}

	try {
		ulaz = OgledaloMatrica(ulaz);
		std::cout<<"Rezultantna matrica:"<<endl;
		ispis_matrice(ulaz);
	} catch(std::domain_error d) {
		cout<<d.what();
	}
	return 0;
}