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
using namespace std;
typedef vector < vector <double> > Matrica;
typedef vector <double> Vektor;

Matrica V ( Matrica pocetna ){
	Matrica pomocna;
	pomocna.resize(pocetna.size());
	for (int i{0}; i<pocetna.size(); i++) pomocna[i].resize(pocetna[i].size());
	//Sad prebacivanje
	for(int i{0}; i<(int)pomocna.size(); i++){
		for( int j{0}; j<(int)pomocna[i].size(); j++){
			pomocna[i][j]=pocetna[(int)pomocna.size()-1-i][j];
		}
	}
	return pomocna;
}

Matrica H ( Matrica pocetna ){
	Matrica pomocna;
	pomocna.resize(pocetna.size());
	for (int i{0}; i<pocetna.size(); i++) pomocna[i].resize(pocetna[i].size());
	//Sad prebacivanje
	for(int i{0}; i<(int)(int)pomocna.size(); i++){
		for(int j{0}; j<(int)pomocna[i].size(); j++ ){
			pomocna[i][j]=pocetna[i][(int)pomocna[i].size()-1-j];
		}
	}
	return pomocna;
}

Matrica OgledaloMatrica ( Matrica pocetna ){
	if(pocetna.size()==0) return pocetna;
	Matrica pomocna;
	Matrica vert{V(pocetna)};
	Matrica hor{H(pocetna)};
	Matrica hv{H(V(pocetna))};
	//Resize pomocne matrice na nuzne dimenzije 
	pomocna.resize(3*pocetna.size());
	if(pocetna.size()!=0) {
	
	
	int redovi{(int)(int)pomocna.size()}, kolone{(int)pocetna[0].size()};
	
	for(int i{0}; i<redovi; i++) if ((int)pomocna[0].size()!=(int)pomocna[i].size()) throw domain_error("Matrica nije korektna");
	
	for(int i{0}; i<redovi; i++){
		pomocna[i].resize(3*kolone);
	}
	// Blok 1 1
	for(int i{0}, I{0}; i<(int)pomocna.size()/3; i++, I++){
		for(int j{0}, J{0}; j<(int)pomocna[i].size()/3; j++, J++){
			pomocna[i][j]=hv[I][J];
		}
	}
	// Blok 1 2
	for(int i{0}, I{0}; i<(int)pomocna.size()/3; i++, I++){
		for( int j{(int)pomocna[i].size()/3}, J{0}; j<2*(int)pomocna[i].size()/3; j++, J++){
			pomocna[i][j]=vert[I][J];
		}
	}
	//Blok 1 3
	for(int i{0}, I{0}; i<(int)pomocna.size()/3; i++, I++){
		for( int j{2*(int)pomocna[i].size()/3}, J{0}; j<(int)pomocna[i].size(); j++, J++ ){
			pomocna[i][j]=hv[I][J];
		}
	}
	//Blok 2 1
	for(int i{(int)pomocna.size()/3}, I{0}; i<2*(int)pomocna.size()/3; i++, I++){
		for(int j{0}, J{0}; j<(int)pomocna[i].size()/3; j++, J++){
			pomocna[i][j]=hor[I][J];
			
		}
	}
	//Blok 2 2
	for(int i{(int)pomocna.size()/3}, I{0}; i<2*(int)pomocna.size()/3; i++, I++){
		for(int j{(int)pomocna[i].size()/3}, J{0}; j<2*(int)pomocna[i].size()/3; j++, J++ ){
			pomocna[i][j]=pocetna[I][J];
		}
	}
	//Blok 2 3
	for(int i{(int)pomocna.size()/3}, I{0}; i<2*(int)pomocna.size()/3; i++, I++){
		for(int j{2*(int)pomocna[i].size()/3}, J{0}; j<(int)pomocna[i].size(); j++,J++){
			pomocna[i][j]=hor[I][J];
		}
	}
	//Blok 3 1
	for(int i{2*(int)pomocna.size()/3}, I{0}; i<(int)pomocna.size(); i++,I++){
		for(int j{0}, J{0}; j<(int)pomocna[i].size()/3; j++, J++){
			pomocna[i][j]=hv[I][j];
		}
	}
	//Blok 3 2
	for(int i{2*(int)pomocna.size()/3}, I{0}; i<(int)pomocna.size(); i++,I++){
		for(int j{(int)pomocna[i].size()/3}, J{0}; j<2*(int)pomocna[i].size()/3; j++, J++){
			pomocna[i][j]=vert[I][J];
		}
	}
	//Blok 3 3
	for(int i{2*(int)pomocna.size()/3}, I{0}; i<(int)pomocna.size(); i++, I++){
		for(int j{2*(int)pomocna[i].size()/3}, J{0}; j<(int)pomocna[i].size(); j++,J++){
			pomocna[i][j]=hv[I][J];
		}
	}
	}
	return pomocna;
}


int main (){
	cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	cin>>m>>n;
	if(m<0 || n<0 ) {
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica mMain;
	mMain.resize(m);
	for (int i{0}; i<m; i++) mMain[i].resize(n);
	cout<<"Unesite elemente matrice: ";
	for(int i{0}; i<m; i++){
		for( int j{0}; j<n; j++){
			cin>>mMain[i][j];
		}
	}
	cout<<endl<<"Rezultantna matrica: "<<endl;
	for(int i{0}; i<3*m; i++){
		for( int j{0}; j<3*n; j++){
			cout << setw(4)<<OgledaloMatrica(mMain)[i][j];
		}
		cout << endl;
	}
	
	return 0;
}