//B 2017/2018, Zadaća 1, Zadatak 2
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
using namespace std;

typedef vector<vector<double>>Matrica;

int Najveci (Matrica m, int red, int kolona){
	int kvadrat(0);
	for (int i=1; i<m.size(); i++){
		for (int j=1; j<=i; j++){
			
			if (kolona-j >= 0 && red-i >= 0){
				if (m.at(red).at(kolona) <= m.at(red-i).at(kolona-j)) return kvadrat;
			}
			else return kvadrat;
			
			if (red-i>=0){
				if (m.at(red).at(kolona) <= m.at(red-i).at(kolona)) return kvadrat;
			}
			else return kvadrat;
			
			if (kolona-j>=0){
				if (m.at(red).at(kolona) <= m.at(red).at(kolona-j)) return kvadrat;
			}
			else return kvadrat;
			
			// staje
			
			if (kolona+j < m.at(0).size()){
				if (m.at(red).at(kolona) <= m.at(red).at(kolona+j)) return kvadrat;
			}
			else return kvadrat;
			
			if (kolona-j >= 0 && red+i <= m.size()){
				if (m.at(red).at(kolona) <= m.at(red+i).at(kolona-j)) return kvadrat;
			}
			else return kvadrat;
			
			if (red+i < m.size()){
				if (m.at(red).at(kolona) <= m.at(red+i).at(kolona)) return kvadrat;
			}
			else return kvadrat;
			
			if (kolona+j < m.at(0).size() && red+i < m.size()){
				if (m.at(red).at(kolona) <= m.at(red+i).at(kolona+j)) return kvadrat;
			}
			else return kvadrat;
		}
		kvadrat++;
	}
	return kvadrat;
}


Matrica NajvecaPlaninaMatrice(Matrica m){
	for (int i=0; i<m.size()-1; i++){
		for (int j=i; j<m.size(); j++){
			if (m.at(i).size()!=m.at(j).size()) throw domain_error ("Matrica nije korektna");
		}
	}
	Matrica indexi; 
	for (int i=0; i<m.size(); i++){
		for (int j=0; j<m.at(0).size(); j++){
			indexi.push_back({m.at(i).at(j), i-Najveci(m,i,j), j-Najveci(m,i,j), Najveci(m,i,j)}); //?
		}
	}
	vector<double>glavni;
	
	if (indexi.size()!=0) glavni = indexi.at(0); //Uslov ako je poslata matrica 0x0
	for (int i=1; i<indexi.size(); i++){
		if (glavni.at(3) < indexi.at(i).at(3)) glavni = indexi.at(i);
		if (glavni.at(3) == indexi.at(i).at(3)){
			if (glavni.at(0) < indexi.at(i).at(0)) glavni = indexi.at(i);
			if (glavni.at(0) == indexi.at(i).at(0)){
				if (glavni.at(1) > indexi.at(i).at(0)) glavni = indexi.at(i);
				if (glavni.at(1) == indexi.at(i).at(1)){
					if (glavni.at(2) > indexi.at(i).at(2)) glavni = indexi.at(i);
				}
			}
		}
	}
	Matrica gotova;
	if (glavni.size()!=0){ //Uslov ako je poslata matrica 0x0
		gotova.resize(glavni.at(3)*2+1);
		for (int i=0; i<=glavni.at(3)*2; i++){
			gotova.at(i).resize(glavni.at(3)*2+1);
			for (int j=0; j<=glavni.at(3)*2; j++){
				gotova.at(i).at(j) = m.at(glavni.at(1)+i).at(glavni.at(2)+j);
			}
		}
	}
	return gotova;
}


int main (){
	
	int m,n;
	cout << "Unesite dimenzije matrice (m i n): ";
	cin >> m >> n;
	
	if (m<0 || n<0) cout << "Dimenzije matrice moraju biti nenegativne!";
	else {
		Matrica mat;
		mat.resize(m);
		cout << "Unesite elemente matrice:\n";
		for (int i=0; i<m; i++){
			mat.at(i).resize(n);
			for (int j=0; j<n; j++)
			    cin >> mat.at(i).at(j);
		}
		
		try{
			Matrica nova (NajvecaPlaninaMatrice(mat));
			cout << "Najveca planina unesene matrice je: " << endl;
			for (int i=0; i<nova.size(); i++){
				for (int j=0; j<nova.at(0).size(); j++)
				    cout << setw(6) << nova.at(i).at(j);
				    cout << endl;
			}
		}
		catch (domain_error izuzetak){
			cout << izuzetak.what();
		}
	
	}

	return 0;
}