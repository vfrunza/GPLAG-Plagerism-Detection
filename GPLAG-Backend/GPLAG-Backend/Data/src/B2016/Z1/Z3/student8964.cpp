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

vector<vector<double>>RastuciPodnizovi(const vector<double>&v)
{
	vector<vector<double>>rastuci;
	if(v.size()<=1) return rastuci;
	int k=0,novi_red=0;
	rastuci.resize(1);
	/*if(v.size()==1) {
		rastuci[0].push_back(v[0]);
		return rastuci;
	}*/
	for(int i=0; i<v.size()-1; i++) {
		if(v[i]<=v[i+1]) {
			if(novi_red==0) rastuci[k].push_back(v[i]);
			rastuci[k].push_back(v[i+1]);
			novi_red=1;
		} else if(novi_red==1) {
			novi_red=0;
			rastuci.resize(rastuci.size()+1);
			k++;
		}
	}
	return rastuci;
}
vector<vector<double>>OpadajuciPodnizovi(const vector<double>&v)
{
	vector<vector<double>>opadajuci;
	if(v.size()<=1) return opadajuci;
	int k=0,novi_red=0;
	opadajuci.resize(1);
	/*if(v.size()==1) {
		opadajuci[0].push_back(v[0]);
		return opadajuci;
	}*/
	for(int i=0; i<v.size()-1; i++) {
		if(v[i]>=v[i+1]) {
			if(novi_red==0) opadajuci[k].push_back(v[i]);
			opadajuci[k].push_back(v[i+1]);
			novi_red=1;
		} else if(novi_red==1) {
			novi_red=0;
			opadajuci.resize(opadajuci.size()+1);
			k++;
		}
	}
	return opadajuci;
}
int main ()
{
	int n;
	vector<vector<double>>a;
	vector<vector<double>>b;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	vector<double>v(n);
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<v.size(); i++) {
		cin>>v[i];
	}
	a=RastuciPodnizovi(v);
	cout<<"Maksimalni rastuci podnizovi: ";
	for(int i=0; i<a.size(); i++) {
		cout<<endl;
		for(int j=0; j<a[i].size(); j++) {
			cout<<a[i][j]<<" ";
		}
	}
	b=OpadajuciPodnizovi(v);
	cout<<endl<<"Maksimalni opadajuci podnizovi: ";
	for(int i=0; i<b.size(); i++) {
		cout<<endl;
		for(int j=0; j<b[i].size(); j++) {
			cout<<b[i][j]<<" ";
		}
	}

	return 0;
}