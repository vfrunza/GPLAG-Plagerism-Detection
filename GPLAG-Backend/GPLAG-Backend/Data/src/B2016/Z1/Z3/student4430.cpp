/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using namespace std; 
typedef vector<vector<double>> Matrica;

Matrica RastuciPodnizovi(vector<double> v){
	Matrica izlaz;
	vector<double> pomocni; 
	int brojac=0; 
	for(int i=1; i<v.size(); i++){
		if(pomocni.size()==0)
			pomocni.push_back(v[i-1]); 
		if(i==v.size()-1 && v[i-1]<=v[i] && pomocni.size()>0){
			pomocni.push_back(v[v.size()-1]); 
			brojac++; 
			izlaz.resize(brojac);
			izlaz[brojac-1].resize(pomocni.size()); 
			izlaz[brojac-1]=pomocni; 
			pomocni.resize(0);
			return izlaz; 
		}
		else if(v[i-1]>v[i] && pomocni.size()==1) 
			pomocni.resize(0); 
		else if(v[i-1]<=v[i])
			pomocni.push_back(v[i]); 
		else if(v[i-1]>v[i]){
			brojac++; 
			izlaz.resize(brojac);
			izlaz[brojac-1].resize(pomocni.size()); 
			izlaz[brojac-1]=pomocni; 
			pomocni.resize(0);
		}
	}
	return izlaz; 
}
Matrica OpadajuciPodnizovi(vector<double> v){
	Matrica izlaz;
	vector<double> pomocni; 
	int brojac=0; 
		for(int i=1; i<v.size(); i++){
		if(pomocni.size()==0)
			pomocni.push_back(v[i-1]); 
		if(i==v.size()-1 && v[i-1]>=v[i] && pomocni.size()>0){
			pomocni.push_back(v[v.size()-1]); 
			brojac++; 
			izlaz.resize(brojac);
			izlaz[brojac-1].resize(pomocni.size()); 
			izlaz[brojac-1]=pomocni; 
			pomocni.resize(0);
			return izlaz; 
		}
		else if(v[i-1]<v[i] && pomocni.size()==1) 
			pomocni.resize(0); 
		else if(v[i-1]>=v[i])
			pomocni.push_back(v[i]); 
		else if(v[i-1]<v[i]){
			brojac++; 
			izlaz.resize(brojac);
			izlaz[brojac-1].resize(pomocni.size()); 
			izlaz[brojac-1]=pomocni; 
			pomocni.resize(0);
		}
	}
	return izlaz; 
}

int main ()
{
	int n; 
	cout << "Unesite broj elemenata vektora: "; 
	cin >> n; 
	cout << "Unesite elemente vektora: "; 
	double broj; 
	vector<double> vektor;
	
	 
	for(int i=0; i<n; i++){
		cin >> broj; 
		vektor.push_back(broj); 
	}
	Matrica rastuci=RastuciPodnizovi(vektor); 
	Matrica opadajuci=OpadajuciPodnizovi(vektor);
	
	cout << "Maksimalni rastuci podnizovi: " << endl; 
	for(auto vec : rastuci){
		for(auto x : vec){
			cout << x << " "; 
		}
		cout << endl; 
	}
	
	cout << "Maksimalni opadajuci podnizovi: " << endl;  
	for(auto vec : opadajuci){
		for(auto x : vec){
			cout << x << " "; 
		}
		cout << endl; 
	}
	return 0;
}