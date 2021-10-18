#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

typedef vector<vector<double>> matrix;

matrix NapraviMatricu(matrix mat, vector<double> vek) {
	int vel(vek.at(1));
	matrix matrica(vel, vector<double> (vel));
	int i(vek.at(2)),j(vek.at(3)),m(0),n(0);
	for(int k=i-(vel/2);k<=i+(vel/2);k++) {
		n=0;
		for(int l=j-(vel/2);l<=j+(vel/2);l++) {
			matrica.at(m).at(n)=mat.at(k).at(l);
			n++;
		}
		m++;
	}
	return matrica;
}

bool JeLiGrbava(matrix matrica) {
	int vel(matrica.at(0).size());
	for(int i=1;i<matrica.size();i++) {
		if(matrica.at(i).size()!=vel) return true;
		vel=matrica.at(i).size();
	}
	return false;
}

vector<double> Najveca(matrix vijenac) {
	vector<double> trenutna_najveca(vijenac.at(0));
	for(int i=1;i<vijenac.size();i++) {
		if(vijenac.at(i).at(0)>trenutna_najveca.at(0)) trenutna_najveca=vijenac.at(i);
		else if(vijenac.at(i).at(0)==trenutna_najveca.at(0)) {
			if(vijenac.at(i).at(1)>trenutna_najveca.at(1)) trenutna_najveca=vijenac.at(i);
		}
	}
	return trenutna_najveca;
}

matrix MaxEl(matrix matrica) {
	matrix m(1, vector<double> (1));
	double max(matrica.at(0).at(0));
	if(matrica.size()==1 && matrica.at(0).size()==1) return matrica;
	for(int i=0;i<matrica.size();i++) {
		for(int j=1;j<matrica.at(0).size();j++) {
			if(matrica.at(i).at(j)>max) max=matrica.at(i).at(j);
		}
	}
	m.at(0).at(0)=max;
	return m;
}

matrix NajvecaPlaninaMatrice(matrix matrica) {
	
	if(JeLiGrbava(matrica)) throw domain_error("Matrica nije korektna");
	
	if(matrica.size()<3 && matrica.at(0).size()<3) {
		return MaxEl(matrica);
	}
	
	double trenutni_vrh;
	matrix planina, planinski_vijenac;
	
	for(int i=1;i<matrica.size()-1;i++) {
		for(int j=1;j<matrica.at(i).size()-1;j++) {
			trenutni_vrh=matrica.at(i).at(j);
			int planina_dim(1);
			int a(i-1),b(j-1);
			double max_sum(trenutni_vrh);
			
			while(a>=0 && b>=0 && 2*a+3<=matrica.size() && 2*b+3<=matrica.at(0).size()) {
				planina_dim+=2;
				double sum(0);
				
				for(int k=0;k<planina_dim;k++) {
					for(int l=0;l<planina_dim;l++) {
						if(k==0 || k==planina_dim-1) sum+=matrica.at(a+k).at(b+l);
						else if(l==0 || l==planina_dim-1) sum+=matrica.at(a+l).at(b+k);
					}
				}
				if(sum<max_sum) {
					a--;
					b--;
				}
				else break;
			}
			
			if(planina_dim>=3) {
				vector<double> pomocni;
				pomocni.push_back(trenutni_vrh);
				pomocni.push_back(planina_dim);
				pomocni.push_back(i);
				pomocni.push_back(j);
				planinski_vijenac.push_back(pomocni);
			}
		}
	}
	
	if(planinski_vijenac.size()==0) return planina; 
	vector<double> v(Najveca(planinski_vijenac));
	planina=NapraviMatricu(matrica,v);
	return planina;
}


int main() {
	cout << "Unesite dimenzije matrice (m i n): ";
	int m,n;
	cin >> m >> n;
	if(m<=0 || n<=0) {
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	cout << "Unesite elemente matrice: ";
	matrix matrica(m, vector<double> (n));
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			double a;
			cin >> a;
			matrica.at(i).at(j)=a;
		}
	}
	try {
		matrica=NajvecaPlaninaMatrice(matrica);
		cout << endl << "Najveca planina unesene matrice je: " << endl;
		for(int i=0;i<matrica.size();i++) {
			for(int j=0;j<matrica.at(i).size();j++) cout << setw(6) << matrica.at(i).at(j);
			cout << endl;
		}
	}
	catch(domain_error izuzetak) {
		cout << "Izuzetak: " << izuzetak.what();
	}
	return 0;
}
