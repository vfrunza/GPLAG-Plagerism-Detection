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

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::setw;
 typedef vector<vector<double>> matrica;
 typedef vector<double> vec;

matrica RastuciPodnizovi(vec v){
 	
 	matrica m;
 	if(v.size()<2)return m;
 	int red_matrice=0;
 	int isti_su=0;
 	m.resize(1);
 	
 	for(int i=0; i<v.size()-1; i++){
 		if(v[i]==v[i+1])isti_su++;
 	}
 	
 	if(isti_su==v.size()-1){m.push_back(v);return m;}
 	for(int i=0; i<v.size()-1; i++){
 		int p;
 		if(v[i+1]>=v[i]){
 			int j=i; p=i;
 			
 			while(j<v.size()-1 && v[j+1]>=v[j]){p++; j++;}
 			for(int k=i; k<=p; k++){
 				m.resize(red_matrice+1);//Bitno!!! Ako ovo ne deklarises, matrica je prazna, nema uopce redova
 				m[red_matrice].push_back(v[k]);//A ovdje pristupas tim redovima
 				
 			}
 			red_matrice++;
 		}
 		else continue;
 		i=p;
 	}
 	
 	return m;
}

matrica OpadajuciPodnizovi(vec v){
	
		matrica m;
		if(v.size()<2)return m;
 	int red_matrice=0;
 	int isti_su=0;
 	m.resize(1);
 	
 	for(int i=0; i<v.size()-1; i++){
 		if(v[i]==v[i+1])isti_su++;
 	}
 	
 	if(isti_su==v.size()-1){m.push_back(v);return m;}
 	
 	
 	for(int i=0; i<v.size()-1; i++){
 		int p;
 		if(v[i+1]<=v[i]){
 			int j=i; p=i;
 			
 			while(j<v.size()-1 && v[j+1]<=v[j]){p++; j++;}
 			for(int k=i; k<=p; k++){
 				m.resize(red_matrice+1);
 				m[red_matrice].push_back(v[k]);
 				
 			}
 			red_matrice++;
 		}
 		else continue;
 		i=p;
 	}
 	
 	return m;
	
}



int main ()
{
	vec v;
	int n;
	double broj;
	matrica m;
	matrica b;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		cin>>broj;
		v.push_back(broj);
	}
	
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	
	m=RastuciPodnizovi(v);
	
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	b=OpadajuciPodnizovi(v);
	
	for(int i=0; i<b.size(); i++){
		for(int j=0; j<b[i].size(); j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}