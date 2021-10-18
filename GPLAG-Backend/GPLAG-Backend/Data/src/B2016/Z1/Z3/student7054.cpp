/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
typedef std::vector<double> Vektor;
typedef std::vector<std::vector<double>> Matrica;

void IspisiMatricu(Matrica m)
{
	for(int i = 0; i <m.size(); i++) {
		for(int j = 0; j < m[i].size(); j++)
			std::cout << m[i][j]<<" ";
		std::cout << std::endl;
	}
}
Matrica RastuciPodnizovi(Vektor v)
{
	Matrica konacna;
	Matrica rezultat;
	Vektor red;
	for(int i=0; i<int(v.size()-1); i++) {
		if(v[i]<=v[i+1]) {
			red.push_back(v[i]);
			if(i==v.size()-2) {
				red.push_back(v[i+1]);
				rezultat.push_back(red);
			}
		}
		else {
			red.push_back(v[i]);
			if(red.size()>=2) {
				rezultat.push_back(red);
				red.resize(0);
			}
		}
	}
	for(int i=0; i<rezultat.size(); i++) {
		bool ubaci =true;
		for(int j=0; j<rezultat[i].size()-1; j++) {
			if(rezultat[i][j]>rezultat[i][j+1]) {
				ubaci=false;
			}
		}
		if(ubaci) konacna.push_back(rezultat[i]);
	}
	return konacna;
}
Matrica OpadajuciPodnizovi(Vektor v)
{
	Matrica konacna;
	Matrica rezultat;
	Vektor red;
	for(int i=0; i<int(v.size()-1); i++) {
		if(v[i]>=v[i+1]) {
			red.push_back(v[i]);
			if(i==v.size()-2) {
				red.push_back(v[i+1]);
				rezultat.push_back(red);
			}
		} else {
			if(red.size()>=2) {
				red.push_back(v[i]);
				rezultat.push_back(red);
				red.resize(0);
			} else if(!(v[i]<v[i+1])) {
				red.push_back(v[i]);
			}
		}
	}
	return rezultat;
}

int main ()
{
	int n, broj;
	try {
		std::cout<<"Unesite broj elemenata vektora: ";
		std::cin>>n;
		if(n<0) throw std::range_error("TEKST2");
		std::cout<<"Unesite elemente vektora: ";
		Vektor v;
		for(int i=0; i<n; i++) {
			std::cin>>broj;
			v.push_back(broj);
		}
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		Matrica r=RastuciPodnizovi(v);
		IspisiMatricu(r);
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		Matrica o=OpadajuciPodnizovi(v);
		IspisiMatricu(o);
	} catch(std::range_error e) {
		std::cout<<e.what();
	}


	return 0;
}