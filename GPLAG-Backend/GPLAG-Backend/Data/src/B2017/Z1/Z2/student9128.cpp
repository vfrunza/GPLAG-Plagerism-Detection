#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stdexcept>

using std::cout;
using std::cin;

typedef std::vector<double> vektor;
typedef std::vector<vektor> Matrica;

int PorediMatrice(Matrica m1, Matrica m2) {
	if(m2.size()==0) return 1;
	if(m1.size()>m2.size()) return 1;
	else if(m2.size()>m1.size()) return 2;
	
	if(m1.at(m1.size()/2).at(m1.size()/2) > m2.at(m2.size()/2).at(m2.size()/2)) return 1;
	else if(m2.at(m2.size()/2).at(m2.size()/2) > m1.at(m1.size()/2).at(m1.size()/2)) return 2; 
	
	return 1;
}

Matrica NapraviMatricu(Matrica m, int i, int j, int n) {
	Matrica povratna;
	int redovi(0), kolone(0);
	vektor pomocni;
	for(int k=i-n; k<=i+n; k++) {
		for(int l=j-n; l<=j+n; l++) {
			povratna.resize(redovi+1);
			povratna.at(redovi).push_back(m.at(k).at(l));
		}
		redovi++;
	}
	return povratna;
}

int NajveciUVektoru (vektor v) {
	int max(1);
	for(int i=1; i<v.size(); i++) {
		if(v.at(i)>v.at(max)) max=i;
	}
	return max;
}

int SumaN (Matrica m, int i, int j, int n) {
	int suma(0);

	for(int k=i-n; k<=i+n; k++) {
		for(int l=j-n; l<=j+n; l++) {
			if(k<0 || l<0 || k>=m.size() || l>=m.at(0).size()) return -1;
			suma+=m.at(k).at(l);
		}
	}
	
	return suma;
}

Matrica NajvecaPlaninaMatrice (Matrica m) {
	for(int i=0; i<m.size(); i++) {
		for(int j=i; j<m.size(); j++) {
			if(m.at(i).size()!=m.at(j).size()) throw std::domain_error("Matrica nije korektna");
		}
	}
	int min;
	Matrica max_planina, pomocna_matrica;
	if(m.size()==0) return max_planina;
	for(int i=0; i<m.size(); i++) {
		if(m.at(i).size()==0) return max_planina;
	}
	if(m.size()>m.at(0).size()) min=m.at(0).size();
	else min=m.size();
	
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m[0].size(); j++) {
			int n(1);
			vektor suma;
			suma.push_back(m.at(i).at(j));
			while(n<=min) {
				int pomocna_suma(0);
				pomocna_suma=SumaN(m, i, j, n);
				if(pomocna_suma==-1 || (n==1 && (pomocna_suma-m.at(i).at(j)>m.at(j).at(j)))) break;
				suma.push_back(SumaN(m, i, j, n)-suma.at(suma.size()-1));
				n++;
			}
			if(suma.size()>1) n=NajveciUVektoru(suma);
			else n=0;
			pomocna_matrica=NapraviMatricu(m, i, j, n);
			if(PorediMatrice(pomocna_matrica, max_planina)==1) max_planina=pomocna_matrica;
		}
	}
	return max_planina;
}

int main ()
{
	int m, n; 
	double broj;
	Matrica mat, planina;
	cout<<"Unesite dimenzije matrice (m i n): ";
	cin>>m>>n;
	if(m<0 || n<0) {
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	mat.resize(m);
	for(int i=0; i<m; i++) {
		mat.at(i).resize(n);
	}
	cout<<"Unesite elemente matrice:";
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin>>broj;
			mat.at(i).at(j)=broj;
		}
	}
	try {
		planina=NajvecaPlaninaMatrice(mat);
	} catch(std::domain_error izuzetak) {
		cout<<"IZUZETAK: "<<izuzetak.what();
	}
	cout<<"\nNajveca planina unesene matrice je:\n";
	for(int i=0; i<planina.size(); i++) {
		for(int j=0; j<planina[0].size(); j++) {
			cout<<std::right<<std::setw(6)<<planina.at(i).at(j);
		}
		cout<<std::endl;
	}
	return 0;
}