/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<double>> RastuciPodnizovi(vector<double> v){
	vector<vector<double>> m;
	int broj_redova = 0;
	int pocetak = 0;
	int kraj = 0;
	for(int i = 1 ; i < v.size() ; i++){
		if(v[i] >= v[i - 1]){
			kraj = i;
		}
		else if(kraj - pocetak > 0){
			broj_redova++;
			m.resize(broj_redova);
			for(int j = pocetak ; j <= kraj ; j++){
				m[broj_redova - 1].push_back(v[j]);
			} 
			pocetak = i;
		}
		else{
			pocetak = i;
		}
	}
	//zadnji rastuci niz ukoliko ga ima
	if(kraj - pocetak != 0){
		broj_redova++;
		m.resize(broj_redova);
		for(int j = pocetak ; j <= kraj ; j++){
			m[broj_redova - 1].push_back(v[j]);
		} 
	}
	
	return m;
}

vector<vector<double>> OpadajuciPodnizovi(vector<double> v){
	vector<vector<double>> m;
	int broj_redova = 0;
	int pocetak = 0;
	int kraj = 0;
	for(int i = 1 ; i < v.size() ; i++){
		if(v[i] <= v[i - 1]){
			kraj = i;
		}
		else if(kraj - pocetak > 0){
			broj_redova++;
			m.resize(broj_redova);
			for(int j = pocetak ; j <= kraj ; j++){
				m[broj_redova - 1].push_back(v[j]);
			} 
			pocetak = i;
		}
		else{
			pocetak = i;
		}
	}
	//zadnji rastuci niz ukoliko ga ima
	if(kraj - pocetak != 0){
		broj_redova++;
		m.resize(broj_redova);
		for(int j = pocetak ; j <= kraj ; j++){
			m[broj_redova - 1].push_back(v[j]);
		} 
	}
	
	return m;
}

int main ()
{
	
	//vector<double> elementi = {10,1,2,3,4,3,2,1,2,3,4};
	int n;
	cout << "Unesite broj elemenata vektora: ";
	cin >> n;
	vector<double> elementi(n);
	
	cout << "Unesite elemente vektora: ";
	for(int i = 0 ; i < n ; i++){
		cin >> elementi[i];
	}
	
	cout << "Maksimalni rastuci podnizovi:" << endl;
	vector<vector<double>> m = RastuciPodnizovi(elementi);
	for(int i = 0 ; i < m.size() ; i++){
 		for(int j = 0 ; j < m[i].size() ; j++){
 			cout << m[i][j] << " ";
 		}
 		cout << endl;
 	}
 	
 	cout << "Maksimalni opadajuci podnizovi:" << endl;
 	m = OpadajuciPodnizovi(elementi);
 	for(int i = 0 ; i < m.size() ; i++){
 		for(int j = 0 ; j < m[i].size() ; j++){
 			cout << m[i][j] << " ";
 		}
 		cout << endl;
 	}
	
	return 0;
}