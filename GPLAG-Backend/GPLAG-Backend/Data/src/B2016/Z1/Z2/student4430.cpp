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

typedef vector<vector<double>> Matrica; 

Matrica Vertikalna(Matrica m){	
	Matrica izlaz; 
	izlaz.resize(m.size()); 
	for(int i=0; i<m.size(); i++)	
		izlaz[i].resize(m[i].size());
	
	for(int i=0; i<m.size(); i++){
		izlaz[i]=m[m.size()-1-i];
	}
	return izlaz; 
}
Matrica Horizontalna(Matrica m){			
	Matrica izlaz;
	izlaz.resize(m.size()); 
	for(int i=0; i<m.size(); i++)	
		izlaz[i].resize(m[i].size());
		
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++){
			izlaz[i][j]=m[i][m[i].size()-1-j];
		}
	}
	
	return izlaz; 
}

Matrica OgledaloMatrica(Matrica m){
	Matrica izlaz, hor, ver, horver;
	if(m.size()==0) return izlaz; 
	bool ispravna=true; 
	for(int i=0; i<m.size()-1; i++){
		if(m[i].size()!=m[i+1].size()) ispravna=false;
	}
	if(!ispravna) throw domain_error("Matrica nije korektna"); 
	

	hor=Horizontalna(m); 
	ver=Vertikalna(m); 
	horver=Horizontalna(Vertikalna(m)); 
	int red=m.size(); 
	int kolona=m[0].size();
	izlaz.resize(3*red);
	for(int i=0; i<izlaz.size(); i++)				// proširivanje matrice izlaz na 3*m i 3*n 
		izlaz[i].resize(3*kolona);
		
	for(int i=0; i<3*red; i++){
		for(int j=0; j<3*kolona; j++){
			if(i<red && j<kolona) izlaz[i][j]=horver[i][j];
			else if(i<red && j<2*kolona) izlaz[i][j]=ver[i][j-kolona]; 
			else if(i<red && j<3*kolona) izlaz[i][j]=horver[i][j-2*kolona]; 
			else if(i<2*red && j<kolona) izlaz[i][j]=hor[i-red][j]; 
			else if(i<2*red && j<2*kolona) izlaz[i][j]=m[i-red][j-kolona];
			else if(i<2*red && j<3*kolona) izlaz[i][j]=hor[i-red][j-2*kolona]; 
			else if(i<3*red && j<kolona) izlaz[i][j]=horver[i-2*red][j]; 
			else if(i<3*red && j<2*kolona) izlaz[i][j]=ver[i-2*red][j-kolona]; 
			else if(i<3*red && j<3*kolona) izlaz[i][j]=horver[i-2*red][j-2*kolona];
		}
	}
	return izlaz; 
}

int main ()
{
	cout << "Unesite dimenzije matrice (m n): "; 
	int m, n; 
	cin >> m >> n; 
	if(m<0 || n<0){
		cout << "Dimenzije matrice moraju biti nenegativne!"; 
		return 0; 
	}
	cout << "Unesite elemente matrice: "; 
	Matrica M; 
	M.resize(m); 
	for(int i=0; i<M.size(); i++)  			// proširivanje matrice koja se unosi sa tastature
		M[i].resize(n);
	
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){ 			// unos elemenata matrice sa tastature
			cin >> M[i][j]; 
		}
	}
	try{
		Matrica izlaz=OgledaloMatrica(M);
		cout << endl <<  "Rezultantna matrica: " << endl; 
		for(vector<double> vec : izlaz){
			for(double x : vec){
				cout << setw(4) << x;
			}
			cout << endl; 
		}
	}
	catch(domain_error tekst){
		cout << tekst.what() << endl; // hvatanje izuzetka ukoliko je u pitanju grbava matrica
		
	}
	return 0;
}