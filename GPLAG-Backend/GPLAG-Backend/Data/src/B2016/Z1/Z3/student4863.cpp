/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

typedef std::vector<std::vector<double>> vvektor;

vvektor RastuciPodnizovi (std::vector<double> v) {
	vvektor povratni;
	const double eps(1e-12);
	for(int i=0; i<v.size(); i++) {
		if(i<v.size()-1 && v[i]<=v[i+1]) {
			std::vector<double> tmp;
			while(i<v.size()-1 && (v[i]<=v[i+1] || std::fabs(v[i]-v[i+1]) <= eps*(std::fabs(v[i])+std::fabs(v[i+1])))) {
				tmp.push_back(v[i]);
				i++;
			}
			tmp.push_back(v[i]);
			povratni.push_back(tmp);
			i--;
		}
	}
	return povratni;
}

vvektor OpadajuciPodnizovi (std::vector<double> v) {
	vvektor povratni;
	const double eps(1e-12);
	for(int i=0; i<v.size(); i++) {
		if(i<v.size()-1 && v[i]>=v[i+1]) {
			std::vector<double> tmp;
			while(i<v.size()-1 && (v[i]>=v[i+1] || std::fabs(v[i]-v[i+1]) <= eps*(std::fabs(v[i])+std::fabs(v[i+1])))) {
				tmp.push_back(v[i]);
				i++;
			}
			tmp.push_back(v[i]);
			povratni.push_back(tmp);
			i--;
		}
	}
	return povratni;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::vector<double> v(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++)
		std::cin>>v[i];
	vvektor v2=RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: \n";
	for(int i=0; i<v2.size(); i++) {
		for(int j=0; j<v2[i].size(); j++)
			std::cout<<std::setprecision(12)<<v2[i][j]<<" ";
		std::cout<<std::endl;
	}
	v2=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni opadajuci podnizovi: \n";
	for(int i=0; i<v2.size(); i++) {
		for(int j=0; j<v2[i].size(); j++)
			std::cout<<std::setprecision(12)<<v2[i][j]<<" ";
		std::cout<<std::endl;
	}
	return 0;
}
