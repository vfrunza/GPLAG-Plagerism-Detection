/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <iomanip>

using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::setw;

typedef vector<vector<double>> Matrica;

Matrica KreirajMatricu(int broj_redova, int broj_kolona){
	return Matrica(broj_redova, vector<double> (broj_kolona));
}

bool Grbava(Matrica mat){
	for(int i=0;i<mat.size();i++){
		for(int j=i;j<mat.at(i).size();j++){
			if(mat.at(i).size()!=mat.at(j).size()){
				return false;
			}
		}
	}
	return true;
}

Matrica NajvecaPlaninaMatrice(Matrica mat){
	if(Grbava(mat)){
		return Matrica();
	}
	return Matrica();
}

int main ()
{
	int m(0), n(0);
	cout << "Unesite dimenzije matrice (m i n): ";
	cin >> m >> n;
	if(m<0 || n<0){
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica mat(KreirajMatricu(m,n)), matric;
	matric=NajvecaPlaninaMatrice(mat);
	cout << "Najveca planina unesene matrice je: ";
	for(auto v : matric){
		for(auto h : v){
			cout << setw(6) << h;
		}
		cout << endl;
	}
	return 0;
}