/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<vector<double>> RastuciPodnizovi(vector<double> v)
{
	vector<vector<double>> matrica;

	for(int i=0; i<v.size();i++) {
		vector<double> niz;
		if(i+1<v.size() && v[i]<=v[i+1]) {
			while(i+1<v.size() && v[i]<=v[i+1]) {
				niz.push_back(v[i]);
				i++;
			}
			niz.push_back(v[i]);
			matrica.push_back(niz);
		}
	}

	return matrica;
}

vector<vector<double>> OpadajuciPodnizovi(vector<double> v)
{
	vector<vector<double>> matrica;

	for(int i=0; i<v.size(); i++) {
		vector<double> niz;
		if(i+1<v.size() && v[i]>=v[i+1]) {
			while(i+1<v.size() && v[i]>=v[i+1]) {
				niz.push_back(v[i]);
				i++;
			}
			niz.push_back(v[i]);
			matrica.push_back(niz);
		}

	}

	return matrica;
}



int main ()
{
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	if(n==0) {
		return 0;
	}

	double m;
	cout<<"Unesite elemente vektora: ";
	vector<double> vektor;
	for(int i=0; i<n; i++) {
		cin>>m;
		vektor.push_back(m);
	}

	vector<vector<double>> v1=RastuciPodnizovi(vektor);
	vector<vector<double>> v2=OpadajuciPodnizovi(vektor);

	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	for(int i=0; i<v1.size(); i++) {
		for(int j=0; j<v1[i].size(); j++) {
			cout<<v1[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	for(int i=0; i<v2.size(); i++) {
		for(int j=0; j<v2[i].size(); j++) {
			cout<<v2[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}