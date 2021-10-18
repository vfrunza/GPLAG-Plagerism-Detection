/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include<iostream>
#include<cmath>
#include<vector>
#include<cmath>
#include<iomanip>
using std::cout;
using std::cin;
using std::endl;
using std:: vector;
/*fja za rastuce*/
vector<vector<double>>RastuciPodnizovi(vector <double> niz)
{
	/*ukoliko je poslat vektor neodgovarajuce velicine izlaz*/
	vector<vector<double>>vektor(niz.size(), vector<double> (niz.size()));
	if(niz.size()<=1)return {};
    int red=0;
	/*ispitivanje clanova vektora i ubacivanje u matricu*/
	for(int i=0; i<niz.size(); i++) {
		int kolona=0;
		if(i!=niz.size()-1) {
			if(niz[i]<=niz[i+1]) {
				while((i+1)<niz.size() && niz[i]<=niz[i+1]) {
					vektor[red][kolona]=niz[i];
					kolona++;
					i++;
				}
				vektor[red][kolona]=niz[i];
				vektor[red].resize(kolona+1);
				red++;
			}
		}
	}
	vektor.resize(red);
	return vektor;
}
/*fja za opadajuce*/
vector<vector<double>>OpadajuciPodnizovi(vector<double> niz)
{
	/*ukoliko je poslat vektor neodgovarajuce velicine izlaz*/
	vector<vector<double>>vektor(niz.size(), vector<double> (niz.size()));
	if(niz.size()<=1)return {};
	int red=0;
	/*ispitivanje clanova vektora i ubacivanje u matricu*/
	for(int i=0; i<niz.size(); i++) {
		int kolona=0;
		if(i!=niz.size()-1) {
			if(niz[i]>=niz[i+1]) {
				while((i+1)<niz.size() && niz[i]>=niz[i+1]) {
					vektor[red][kolona]=niz[i];
					kolona++;
					i++;
				}
				vektor[red][kolona]=niz[i];
				vektor[red].resize(kolona+1);
				red++;
			}
		}

	}
	vektor.resize(red);
	return vektor;
}
int main ()
{
	int n,i=0;
	/*unos dimenzije vektora*/
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	vector<double> niz;
	double broj;
	/*unos elemenata*/
	while(i<n) {
		cin>>broj;
		niz.push_back(broj);
		i++;
	}
	/*promjena velicine*/
	niz.resize(i);
	vector<vector<double>> a;
	/*poziv prve fje*/
	a=RastuciPodnizovi(niz);
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	/*ispis*/
	for(vector<double> podniz : a) {
		for(double x : podniz)
			cout<<std::setprecision(12)<<x<<" ";
		cout<<endl;
	}
	vector<vector<double>> b;
	/*poziv druge fje*/
	b=OpadajuciPodnizovi(niz);
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	/*ispis*/
	for(vector<double> podniz : b) {
		for(double x : podniz)
			cout<<std::setprecision(12)<<x<<" ";
		cout<<endl;
	}
	return 0;
}