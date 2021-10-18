/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#define EPS 0.0000001

std::vector <std::vector <double>>RastuciPodnizovi (std::vector<double> v)
{
	std::vector <std::vector<double>> a;
	int k=0;
	a.resize(k+1);
	for(int i=0; i<int(v.size())-1; i++) {
		bool ubacen(false), ubacen1(false), ubacen2(false);
		if(v.at(i)<v.at(i+1) || v.at(i)-v.at(i+1)<EPS) {
			a[k].push_back(v[i]);
			ubacen=true;
		}
		if(i==int(v.size())-2 && (v.at(i)<v.at(i+1) || v.at(i)-v.at(i+1)<EPS)) {
			a[k].push_back(v.at(i+1));
			ubacen1=true;
		}
		if(i>=1 && v.at(i)>v.at(i+1) && (v.at(i-1)<v.at(i) || v.at(i)-v.at(i+1)<EPS)){ 
			a[k].push_back(v.at(i));
			ubacen2=true;
		}
		if(ubacen==false) {
			if(ubacen1==false && ubacen2==false) continue;
			k++;
			a.resize(k+1);
		}

	}

return a;
}

std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> v){
		std::vector <std::vector<double>> a;
	int k=0;
	a.resize(k+1);
	for(int i=0; i<int(v.size())-1; i++) {
		bool ubacen(false), ubacen1(false), ubacen2(false);
		if(v.at(i)>v.at(i+1) || v.at(i+1)-v.at(i)<EPS) {
			a[k].push_back(v[i]);
			ubacen=true;
		}
		if(i==int(v.size())-2 && (v.at(i)>v.at(i+1) || v.at(i+1)-v.at(i)<EPS)) {
			a[k].push_back(v.at(i+1));
			ubacen1=true;
		}
		if(i>=1 && v.at(i)<v.at(i+1) && (v.at(i-1)>v.at(i) || v.at(i+1)-v.at(i)<EPS)){ 
			a[k].push_back(v.at(i));
			ubacen2=true;
		}
		if(ubacen==false) {
			if(ubacen1==false && ubacen2==false) continue;
			k++;
			a.resize(k+1);
			
		}

	}
	return a;
}
int main ()
{
	int n;
	std::cout <<"Unesite broj elemenata vektora: ";
	std::cin >>n;
	if(n<=0) {
		std::cout <<"Broj elemenata mora biti veci od 0!";
		return 0;
	}
	std::cout <<"Unesite elemente vektora: ";
	std::vector<double> v;
	double element;
	for(int i=0; i<n; i++) {
		std::cin >>element;
		v.push_back(element);
	}
	auto  a=RastuciPodnizovi(v);

	std::cout <<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0; i<a.size(); i++) {
		for(int j=0; j<a[i].size(); j++) {
			std::cout <<a[i][j]<< " ";
		}
		std::cout << std::endl;
	}
	
	 std::cout <<"Maksimalni opadajuci podnizovi: "<<std::endl ;
	 auto b=OpadajuciPodnizovi(v);
	 for(int i=0; i<b.size(); i++) {
		for(int j=0; j<b[i].size(); j++) {
			std::cout <<b[i][j]<< " ";
		}
		std::cout << std::endl;
	}

	return 0;
}