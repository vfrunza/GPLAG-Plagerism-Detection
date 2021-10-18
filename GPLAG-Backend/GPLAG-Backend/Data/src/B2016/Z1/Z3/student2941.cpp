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


vector<vector<double> > RastuciPodnizovi(vector<double> v) {
	vector<vector<double> > mat;
	vector<double> podniz;
	if(v.size()==0) return mat;
	for(int i(0);i<v.size()-1;i++) {
		if(v[i]<=v[i+1]) {
			while(v[i]<=v[i+1] && i<v.size()-1){
				podniz.push_back(v[i]);
				i++;
				if(i==v.size()-1) break;
			}
			podniz.push_back(v[i]);
			mat.push_back(podniz);
			podniz.resize(0);
		}
		
	}
	return mat;
}
vector<vector<double> > OpadajuciPodnizovi(vector<double> v) {
	vector<vector<double> > mat;
	vector<double> podniz;
	if(v.size()==0) return mat;
	for(int i(0);i<v.size()-1;i++) {
		if(v[i]>=v[i+1]) {
			while(v[i]>=v[i+1] && i<v.size()-1){
				podniz.push_back(v[i]);
				i++;
				if(i==v.size()-1) break;
			}
			podniz.push_back(v[i]);
			mat.push_back(podniz);
			podniz.resize(0);
		}
		
	}
	return mat;
}
int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int i=0,n,k;
	cin>>k;
	cout<< "Unesite elemente vektora: ";
	vector<double> v;
	while(i<k) {
		cin>>n;
		v.push_back(n);
		i++;
	}
	vector<vector<double> > mat;
	mat=RastuciPodnizovi(v);
	cout<<"Maksimalni rastuci podnizovi: \n";
	for(int i(0);i<mat.size();i++) {
		for(int j(0);j<mat[i].size();j++) {
			cout<<setprecision(12)<<mat[i][j]<<" ";
		}
		cout<< endl;
	}
	mat=OpadajuciPodnizovi(v);
	cout<<"Maksimalni opadajuci podnizovi:\n";
	for(int i(0);i<mat.size();i++) {
		for(int j(0);j<mat[i].size();j++) {
			cout<<setprecision(12)<<mat[i][j]<<" ";
		}
		cout<< endl;
	}
	return 0;
}