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
#include <stdexcept>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::setw;

typedef vector<vector<double>> Matrica;

Matrica Kreiraj (double red, double kolona) {
	return Matrica(red, vector<double> (kolona));
}

Matrica RastuciPodnizovi (vector<double> v) {
	Matrica a;
	vector <double> n;
	if(v.size()==0) return a;
	if(v.size()==1) return a;
	else{
	for(int i=0; i<v.size()-1; i++) {
		
		if (v[i]<=v[i+1] ) {
			n.push_back(v[i]);
		}
		
		else {
			if(n.size()!=0) {
				n.push_back(v[i]);
				a.push_back(n);
			}
			n.clear();
		
		}
	}
	if(v[v.size()-2]<=v[v.size()-1]) {
		n.push_back(v[v.size()-1]);
		a.push_back(n);
	}
	
	
	return a;
		
	}
}


Matrica OpadajuciPodnizovi (vector<double> v) {
	Matrica a;
	vector <double> n;
	if(v.size()==0) return a;
	if(v.size()==1) return a;
	else{
	for(int i=0; i<v.size()-1; i++) {
		
		
		if (v[i]>=v[i+1] ) {
			n.push_back(v[i]);
		}
		
		else {
			if(n.size()!=0) {
				n.push_back(v[i]);
				a.push_back(n);
			}
			n.clear();
		
		}
	
		
	}
	if(v[v.size()-2]>=v[v.size()-1]) {
		n.push_back(v[v.size()-1]);
		a.push_back(n);
	}
	

	
	
	return a;
		
	}
}





int main ()
{
	
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	vector <double> v;
	double a;
	for(int i=0; i<n; i++) {
		cin>>a;
		v.push_back(a);
		
	} 
	
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	for(int i=0; i<RastuciPodnizovi(v).size(); i++) {
		for(int j=0; j<RastuciPodnizovi(v)[i].size(); j++)
		cout<<RastuciPodnizovi(v)[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	for(int i=0; i<OpadajuciPodnizovi(v).size(); i++) {
		for(int j=0; j<OpadajuciPodnizovi(v)[i].size(); j++)
		cout<<OpadajuciPodnizovi(v)[i][j]<<" ";
		cout<<endl;
	}
	
	
	
	
	return 0;
}