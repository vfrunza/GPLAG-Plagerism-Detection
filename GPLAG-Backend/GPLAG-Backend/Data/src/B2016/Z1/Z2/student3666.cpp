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

using namespace std;
typedef vector<vector<double>> Matrica;

int VratiBrojKolona(Matrica a){
	if(a.size()==0) return 0;
	return(a[0].size());
}

Matrica KreirajMatricu(int red, int kol){
	return Matrica(red, vector<double>(kol));
}

Matrica UnesiMatricu(int red, int kol){
	auto m(KreirajMatricu(red, kol));
	for(int i(0); i<red; i++){
		for(int j(0); j<kol; j++){
			cin >> m[i][j];
		}
	}
	return m;
}

void IspisiMatricu(Matrica m){
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<VratiBrojKolona(m); j++){
			cout << setw(4) << m[i][j];
		}
		cout << endl;
	}
}



Matrica OgledaloMatrica(Matrica m){
	int broj_redova=m.size();
	int broj_kolona=VratiBrojKolona(m);
	
	if(broj_redova==0 && broj_kolona==0)
		return Matrica(0,vector<double>(0));
	
	for(int i(0); i<broj_redova; i++){
		if(m[i].size()!=broj_kolona)
			throw domain_error("Matrica nije korektna");
	}
	
	
	Matrica vrati(3*broj_redova, vector<double>(3*broj_kolona));
	Matrica horizontalna(broj_redova, vector<double>(broj_kolona)); 

	
	for(int i(0); i<broj_redova; i++){
		for(int j(0); j<broj_kolona; j++){
			horizontalna[i][j]=m[i][broj_kolona-1-j];
		}
	}
	
	
	Matrica vertikalna(broj_redova, vector<double>(broj_kolona));
	for(int i(0); i<broj_redova; i++){
		vertikalna[i]=m[broj_redova-1-i];
	}

	
	Matrica hv(broj_redova, vector<double>(broj_kolona));
	for(int i(0); i<broj_redova; i++){
		hv[i]=horizontalna[broj_redova-1-i];
	}
	
	for(int i(0); i<3*broj_redova; i++){
		for(int j(0); j<3*broj_kolona; j++){
			
			if(i<broj_redova){
				if(j<broj_kolona)
					vrati[i][j]=(hv[i][j]);
				if(j>=broj_kolona && j<2*broj_kolona)
					vrati[i][j]=(vertikalna[i][j-broj_kolona]);
				if(j>=2*broj_kolona && j<3*broj_kolona)
					vrati[i][j]=(hv[i][j-2*broj_kolona]);
			}
			
			if(i>=broj_redova && i<2*broj_redova){
				if(j<broj_kolona)
					vrati[i][j]=(horizontalna[i-broj_redova][j]);
				if(j>=broj_kolona && j<2*broj_kolona)
					vrati[i][j]=(m[i-broj_redova][j-broj_kolona]);
				if(j>=2*broj_kolona && j<3*broj_kolona)
					vrati[i][j]=(horizontalna[i-broj_redova][j-2*broj_kolona]);
			}
			
			if(i>=2*broj_redova && i<3*broj_redova){
				if(j<broj_kolona)
					vrati[i][j]=(hv[i-2*broj_redova][j]);
				if(j>=broj_kolona && j<2*broj_kolona)
					vrati[i][j]=(vertikalna[i-2*broj_redova][j-broj_kolona]);
				if(j>=2*broj_kolona && j<3*broj_kolona)
					vrati[i][j]=(hv[i-2*broj_redova][j-2*broj_kolona]);
			}
			
		}
	}
	
	
	return vrati;
}

int main ()
{
	int m,n;
	cout << "Unesite dimenzije matrice (m n): ";
	cin >> m >> n;
	if(m<0 || n<0){
		 cout << "Dimenzije matrice moraju biti nenegativne!";
		 return -2;}
	cout << "Unesite elemente matrice: ";
	auto mat(UnesiMatricu(m,n));
	cout << endl;
	cout << "Rezultantna matrica:" << endl;
	IspisiMatricu(OgledaloMatrica(mat));
	
	return 0;
}