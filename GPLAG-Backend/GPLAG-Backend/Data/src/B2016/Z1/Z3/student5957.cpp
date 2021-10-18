/*B 2016/2017, Zadaća 1, Zadatak 3
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
*/
#include<iostream>
#include<vector>
#include <iomanip>
using std::cout;
using std::cin;
using std::vector;
typedef vector<vector<double>> Matrica;

Matrica IzbaciRed(Matrica a){
	for(int i=0;i<a.size();i++){
		if(a[i].size()<2){
			for(int j=i;j<a.size()-1;j++)
			a[j]=a[j+1];
			a.resize(a.size()-1);
			i--;
		}
	}
	return a;
}

Matrica RastuciPodnizovi(vector<double> v){
	int g(0);
	double n(0);
	Matrica a(0,vector<double>(0));
	if(v.size()>0)
	a.resize(1);
	n=v[0];
	for(int i=0;i<v.size();i++){
		if(v[i]>=n){
			n=v[i];
			a[g].push_back(v[i]);
		}
		else{
			g++;
			a.resize(a.size()+1);
			n=v[i];
			i--;
		}
	}
	a=IzbaciRed(a);
	return a;
}

Matrica OpadajuciPodnizovi(vector<double> v){
	int g(0);
	double n(0);
	Matrica a(0,vector<double>(0));
	if(v.size()>0)
	a.resize(1);
	n=v[0];
	for(int i=0;i<v.size();i++){
		if(v[i]<=n){
			n=v[i];
			a[g].push_back(v[i]);
		}
		else{
			g++;
			a.resize(a.size()+1);
			n=v[i];
			i--;
		}
	}
	a=IzbaciRed(a);
	return a;
}

int main ()
{
	int n(0);
	double g(0);
	vector<double> v;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		cin>>g;
		v.push_back(g);
	}
	Matrica a(0,vector<double>(0));
	a=RastuciPodnizovi(v);
	cout<<"Maksimalni rastuci podnizovi: \n";
	for(int i=0;i<a.size();i++){
	for(int j=0;j<a[i].size();j++)
	cout<<std::setprecision(12)<<a[i][j]<<" ";
	cout<<"\n";
	}
	cout<<"Maksimalni opadajuci podnizovi: \n";
	a=OpadajuciPodnizovi(v);
	for(int i=0;i<a.size();i++){
	for(int j=0;j<a[i].size();j++)
	cout<<std::setprecision(12)<<a[i][j]<<" ";
	cout<<"\n";
	}

	return 0;
}