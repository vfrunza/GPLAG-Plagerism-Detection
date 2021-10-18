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
typedef vector<vector<double>> Matrica;

int Redovi(vector<double> v){
	int brojac(0);
	for(int i(0);i<v.size();i++){
		int poc(i);
		while(i<v.size()-1 and v[i]<=v[i+1]) i++;
		if(i==v.size()-2) {
			i++;
			break;
		}
		int kraj(i);
		if(kraj!=poc) brojac++;
	}
	return brojac;
} 

Matrica KreirajMatricu(int a, int b) {
   return Matrica (a,vector<double>(b));
}

Matrica RastuciPodnizovi(vector <double> v){
	int b(Redovi(v));
	Matrica m=KreirajMatricu(b,0);
	for(int j(0);j<b;j++){
		int poc,kraj;
		for(int i(0);i<v.size();i++){
			poc=i;
			while(i<v.size()-1 and v[i]<=v[i+1]){ 
			if(i==v.size()-2) {
			i++;
			break;
		}
			i++;
				
			}
			kraj=i;
			if(kraj==poc)continue;
		
			for(int k(poc);k<=kraj;k++){
				m[j].push_back(v[k]);
			}
			j++;
			if(j==b)break;
		}
	}
	return m;
}

int Redovi2(vector<double> v){
	int brojac(0);
	for(int i(0);i<v.size();i++){
		int poc(i);
		while(i<v.size()-1 and v[i]>=v[i+1]) i++;
		if(i==v.size()-2) {
			i++;
			break;
		}
		int kraj(i);
		if(kraj!=poc) brojac++;
	}
	return brojac;
} 

Matrica OpadajuciPodnizovi(vector <double> v){
	int b(Redovi2(v));
	Matrica m=KreirajMatricu(b,0);
	for(int j(0);j<b;j++){
		int poc,kraj;
		for(int i(0);i<v.size();i++){
			poc=i;
			while(i<v.size()-1 and v[i]>=v[i+1]){
			if(i==v.size()-2) {
			i++;
			break;
		}
		i++;
		}
			 kraj=i;
			 if(kraj==poc)continue;
		
		
			for(int k(poc);k<=kraj;k++){
				m[j].push_back(v[k]);
			}
			j++;
			if(j==b)break;
		}
	}
	return m;
}


int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int brelem;
	cin>>brelem;
	cout<<"Unesite elemente vektora: ";
	vector<double> m;
	double elem,i(0);
	while(i<brelem){
		cin>>elem;
		m.push_back(elem);
		i++;
	}
	Matrica c(RastuciPodnizovi(m));
	Matrica d(OpadajuciPodnizovi(m));
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	for(int i(0);i<c.size();i++){
		for(int j(0);j<c[i].size();j++){
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"Maksimalni opadajuci podnizovi:"<<endl;
	for(int i(0);i<d.size();i++){
		for(int j(0);j<d[i].size();j++){
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return 0;
}