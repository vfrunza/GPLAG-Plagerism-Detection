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

bool provjeraMatrice(vector<vector<double>> matrica){
	for(int i = 1 ; i < matrica.size() ; i++){
		if(matrica[i - 1].size() != matrica[i].size()){
			return false;
		}
	}
	return true;
}

vector<vector<double>> vratiHorizontalnu(vector<vector<double>> m){
	
	int broj_kolona = m[0].size();
	for(int i = 0 ; i < m.size() ; i++){
		for(int j = 0 ; j < m[0].size() / 2 ; j++){
			double p = m[i][j];
			m[i][j] = m[i][broj_kolona - 1 - j];
			m[i][broj_kolona - 1 - j] = p; 
		}
	}
	return m;
}

vector<vector<double>> vratiVertikalnu(vector<vector<double>> m){

	int broj_redova = m.size();
	for(int i = 0 ; i < m.size() / 2 ; i++){
		for(int j = 0 ; j < m[0].size() ; j++){
			double p = m[i][j];
			m[i][j] = m[broj_redova - 1 - i][j];
			m[broj_redova - 1 - i][j] = p;
		}
	}

	return m;	
}

vector<vector<double>> OgledaloMatrica(vector<vector<double>> matrica){
	
	if(matrica.size() == 0){
		return matrica;
	}
	
	if(provjeraMatrice(matrica) == false){
		throw domain_error("Matrica nije korektna");
	}
	
	vector<vector<double>> pomocna(matrica.size() * 3 , vector<double>(matrica[0].size() * 3));
	vector<vector<double>> horizontalna = vratiHorizontalnu(matrica);
	vector<vector<double>> vertikalna = vratiVertikalnu(matrica);
	vector<vector<double>> kombinacija = matrica;
	kombinacija = vratiHorizontalnu(kombinacija);
	kombinacija = vratiVertikalnu(kombinacija);

	int broj_redova = matrica.size();
	int broj_kolona = matrica[0].size();
	for(int i = 0 ; i < kombinacija.size() ; i++){
		for(int j = 0 ; j < kombinacija[0].size() ; j++){
			
			pomocna[i][j] = kombinacija[i][j];
			pomocna[i][j + 2 * broj_kolona] = kombinacija[i][j];
			pomocna[i + 2 * broj_redova][j] = kombinacija[i][j];
			pomocna[i + 2 * broj_redova] [j + 2 * broj_kolona] = kombinacija[i][j];
		
			pomocna[i][j + broj_kolona] = vertikalna[i][j];
			pomocna[i + 2 * broj_redova][j + broj_kolona] = vertikalna[i][j];
			
			pomocna[i + broj_redova][j] = horizontalna[i][j];
			pomocna[i + broj_redova][j + 2 * broj_kolona] = horizontalna[i][j];
			
			pomocna[i + broj_redova][j + broj_kolona] = matrica[i][j];
			
		}
	}	
	
	return pomocna;
}

int main ()
{

 	//vector<vector<double>> m = {{3,2} , {123 , 321} , {-12 , 0} , {456 , -7}};
 	//m = OgledaloMatrica(m);
 	//vector<vector<double>> m(5 , vector<double>(5));
 	
 	int m,n;
 	cout << "Unesite dimenzije matrice (m n): ";
 	cin >> m;
 	cin >> n;
    if(m < 0 || n < 0) {
 		cout << "Dimenzije matrice moraju biti nenegativne!" << endl;
 		return 0;
 	}
 	
 	cout << "Unesite elemente matrice:" << endl;
 	vector<vector<double>> matrica(m , vector<double>(n));
	for(int i = 0 ; i < m ; i++){
 		for(int j = 0 ; j < n ; j++){
 			cin >> matrica[i][j];
		}
 	}
 	
 	//vector<vector<double>> matrica = {{3,2} , {123,321} , {-12,0} , {456,-7}};
 	
 	matrica = OgledaloMatrica(matrica);
 	
 	//ispis
 	cout << "Rezultantna matrica:" << endl;
 	for(int i = 0 ; i < matrica.size() ; i++){
 		for(int j = 0 ; j < matrica[0].size() ; j++){
 			cout << setw(4) <<matrica[i][j] ;
 		}
 		cout << endl;
 	}
 	
 	
	return 0; 
}
