/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>

typedef std::vector<std::vector<double>> Matrica;
using std::cin;
using std::cout;
using std::endl;

Matrica RastuciPodnizovi(std::vector<double> v){
	Matrica m;
	if (v.size==0 || v.size==1) return m;
	else {
	std::vector<int> pozicije;
	for (int i=0; i<v.size()-1; i++){
		if (v[i]<=v[i+1]){
			pozicije.push_back(i);
			int br(0);
			int j=i; 
				while(j<v.size()-1 && v[j]<=v[j+1]){ br++; j++;}
				pozicije.push_back(i+br);
				i=i+br;
			}
		}
	int a=pozicije.size()/2;
	m.resize(a);
	for (int i=0; i<a; i++) m[i].resize(pozicije[i*2+1]-pozicije[i*2]+1);
	for (int i=0; i<a; i++){
		int duz=pozicije[i*2+1]-pozicije[i*2]+1;
		for (int j=0; j<duz; j++){
			m[i][j]=v[j+pozicije[2*i]];
		}
	}
	
	return m;
	
}

Matrica OpadajuciPodnizovi(std::vector<double> v){
	Matrica m;
	if (v.size==0 || v.size==1) return m;
	else {
	std::vector<int> pozicije;
	for (int i=0; i<v.size()-1; i++){
		if (v[i]>=v[i+1]){
			pozicije.push_back(i);
			int br(0);
			int j=i; 
				while(j<v.size()-1 && v[j]>=v[j+1]){ br++; j++;}
				pozicije.push_back(i+br);
				i=i+br;
			}
		}
	int a=pozicije.size()/2;
	m.resize(a);
	for (int i=0; i<a; i++) m[i].resize(pozicije[i*2+1]-pozicije[i*2]+1);
	for (int i=0; i<a; i++){
		int duz=pozicije[i*2+1]-pozicije[i*2]+1;
		for (int j=0; j<duz; j++){
			m[i][j]=v[j+pozicije[2*i]];
		}
	}
	
	return m;
	}
}

int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	double broj;
	std::vector<double> v;
	for (int i=0; i<n; i++){
		cin>>broj;
		v.push_back(broj);
	}
	Matrica rastuci=RastuciPodnizovi(v);
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	for(int i=0;i<rastuci.size();i++){
		for(int j=0;j<rastuci[i].size();j++) {cout<<rastuci[i][j]<<" ";}
		cout<<endl;
	}
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	
	Matrica opadajuci=OpadajuciPodnizovi(v);
	for(int i=0;i<opadajuci.size();i++){
		for(int j=0;j<opadajuci[i].size();j++) {cout<<opadajuci[i][j]<<" ";}
		cout<<endl;
	}
	return 0;
}