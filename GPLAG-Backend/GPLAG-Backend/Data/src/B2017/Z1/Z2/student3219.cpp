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
#include <cmath>
#include <stdexcept>

using namespace std;


vector<vector<double>> NajvecaPlaninaMatrice (vector<vector<double>> matrica){
	vector<vector<double>> novamatrica;

	
	//	if(matrica.size()<0) throw range_error("Dimenzije matrice moraju biti nenegativne!");
	
	for(int i=0;i<matrica.size();i++) {
		int brojac=0;
		for(int k=1;k<matrica.size();k++){
			// if(matrica.at(i).size()<0) throw range_error("Dimenzije matrice moraju biti nenegativne!");
			if(matrica.at(i).size()!=matrica.at(k).size())brojac++;
			if (brojac>0) throw domain_error("Matrica nije korektna");
		}
	}
	
	
	if(matrica.size()==0) return novamatrica;
	for(int i=0;i<matrica.at(0).size();i++) if(matrica.at(i).size()==0) return novamatrica;
	
	return novamatrica;
	
}



int main ()
{
	try{
	int m,n;
	cout<<"Unesite dimenzije matrice (m i n): ";
	cin>>m>>n;
	if(m<0 || n<0){
		throw range_error("Dimenzije matrice moraju biti nenegativne!");
	}
	
	vector<vector<double>> mat(m,vector <double> (n));
	vector<vector<double>> rez;
	cout<<"Unesite elemente matrice: "<<endl;
    for(int i=0;i<m;i++){
    	for(int j=0;j<n;j++){
    	 cin>>mat.at(i).at(j);
    	}
    }

	cout<<"Najveca planina unesene matrice: ";
	rez=NajvecaPlaninaMatrice(mat);}
	catch (domain_error izuzetak){cout<<izuzetak.what()<<endl;}
	catch (range_error izuzetak1){cout<<izuzetak1.what()<<endl;}
	return 0;
}