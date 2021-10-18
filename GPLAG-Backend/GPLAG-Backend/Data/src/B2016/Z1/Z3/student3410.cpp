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
#include <cmath>
#define epsilon 0,0000000000000000000000001
std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v) {
	std::vector<double> pom;
	std::vector<std::vector<double>> vrati;
	if(v[0]<=v[1]) pom.push_back(v[0]);
	for(int i=1; i<v.size(); i++){
		if(v[i]>=v[i-1] && v[i-1]<=v[i]){//veci od prethodnog
			pom.push_back(v[i]);
			
			
		}
		else {
			if(pom.size()>=2){
				vrati.push_back(pom);
			}
			pom.resize(0);
			pom.push_back(v[i]);
		}
		
		
	}
	if(pom.size()>=2) vrati.push_back(pom);
	return vrati;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	std::vector<double> pom;
	std::vector<std::vector<double>> vrati;
	pom.push_back(v[0]);
	for(int i=1; i<v.size(); i++){
		if(v[i]<=v[i-1]){//veci od prethodnog
			pom.push_back(v[i]);
		}
		
		else {
			if(pom.size()>=2) vrati.push_back(pom);
			pom.resize(0);
			pom.push_back(v[i]);
		}
		
	}
	if( pom.size()>=2) vrati.push_back(pom);
	return vrati;
}
int main ()
{
	std::vector<std::vector<double>> m;
	std::vector<double> v;
	std::cout<<"Unesite broj elemenata vektora: ";
	int x;
	int y;
	std::cin>>x;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<x; i++){
		std::cin>>y;
		v.push_back(y);
	}
	std::cout<<"Maksimalni rastuci podnizovi:\n";
	m=RastuciPodnizovi(v);
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++){
			std::cout<<m[i][j]<<" ";
		}
		std::cout<<"\n";
	}
	std::cout<<"Maksimalni opadajuci podnizovi:\n";
m=OpadajuciPodnizovi(v);
for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++){
			std::cout<<m[i][j]<<" ";
		}
		std::cout<<"\n";
	}
	return 0;
}