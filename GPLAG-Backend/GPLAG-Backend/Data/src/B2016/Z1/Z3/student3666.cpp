/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iomanip>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<vector<double>> Matrica;
Matrica RastuciPodnizovi(vector<double> v){
	int br_elemenata=v.size();
	int broj_redova=0;
	
	for(int i(0); i<br_elemenata-1; i++){
		int j=i+1;
		while(j<br_elemenata && j>=0 && v[j-1]<=v[j])
		 j++;
		if(j-i>1){ 
			broj_redova++;
			i=j-1;}
	}
	
	Matrica vrati(broj_redova);
	int popunjeno=0;
	for (int i=0; i<br_elemenata-1; i++) {
		int j=i+1;
		if(v[j]<v[j-1]) continue;
		int br=1;
		while (j<br_elemenata && j>=0 && v[j-1]<=v[j]) {
			br++;
			j++;
		}
		if(br>1){
			while(i<j){
			vrati[popunjeno].push_back(v[i]);
			i++;
			}
			popunjeno++;
			br=1;
			i--;
		}
	}
	
	
	return vrati;
}

Matrica OpadajuciPodnizovi(vector<double> v){
	int br_elemenata=v.size();
	int broj_redova=0;
	
	for(int i=0; i<br_elemenata-1; i++){
		int j=i+1;
		if(v[j]>v[j-1]) continue;
		while(j<br_elemenata-1 && v[j]<=v[j-1])
			j++;
		if(j-i>1){
			broj_redova++;
			i=j-1;
		}
	}
	
	Matrica vrati(broj_redova);
	int popunjeno=0;
	for(int i=0; i<br_elemenata-1; i++){
		int j=i+1;
		
		if(v[j]>v[j-1]) continue;
		int br=1;
		while (j<br_elemenata && j>=0 && v[j]<=v[j-1]) {
			j++;
			br++;
		}
		if(br>1){
			while (i<j && popunjeno<broj_redova ) {
				vrati[popunjeno].push_back(v[i]);
				i++;
			}
			popunjeno++;
			br=1;
			i--;
		}
	}
	
	
	return vrati;
}




int main()
{
	
	int vel;
	Matrica mat, pat;
	
	cout << "Unesite broj elemenata vektora: ";
	cin >> vel;
	
	vector<double>vek(vel);
	cout << "Unesite elemente vektora: ";
	for(int i=0; i<vel; i++){
		cin >> vek[i];
	}
	
	cout << "Maksimalni rastuci podnizovi: " << endl;
	mat=RastuciPodnizovi(vek);

	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[i].size(); j++){
			cout <<  mat[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "Maksimalni opadajuci podnizovi: " << endl;
	pat=OpadajuciPodnizovi(vek);
	
	for(int i=0; i<pat.size(); i++){
		for(int j=0; j<pat[i].size(); j++){
			cout << pat[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}