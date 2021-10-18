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

typedef std::vector<std::vector<double>> Matrica ;

Matrica RastuciPodnizovi(std::vector<double> v1) {
	std::vector<double> pomocni;
	int s(0);
	Matrica m(10);
	for(int i(0); i<v1.size(); i++) {
		
	while(i!=v1.size()-1 && v1[i]<=v1[i+1]) {
		pomocni.push_back(v1[i]);
		i++;
	}pomocni.push_back(v1[i]);
	if(pomocni.size()==1) pomocni.resize(0);
	for(int j(0); j<pomocni.size();j++)
		{
			m[s].push_back(pomocni[j]);
}

if(pomocni.size()!=0) s++;
pomocni.resize(0);
}
m.resize(s);
return m;
}

Matrica OpadajuciPodnizovi(std::vector<double> v1) {
	std::vector<double> pomocni;
	int s(0);
	Matrica m(10);
	for(int i(0); i<v1.size(); i++) {
	while(i!=v1.size()-1 && v1[i]>=v1[i+1]) {
		pomocni.push_back(v1[i]);
		i++;
	}pomocni.push_back(v1[i]);
	if(pomocni.size()==1) pomocni.resize(0);
	for(int j(0); j<pomocni.size();j++)
		{
			m[s].push_back(pomocni[j]);
}

if(pomocni.size()!=0) s++;
pomocni.resize(0);
}
m.resize(s);
return m;
}

int main ()
{
	Matrica m;
	std::vector<double> v;
	double n;
	int br;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>br;
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0); i<br; i++)
	{
		std::cin>>n;
		v.push_back(n);
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
 	m=RastuciPodnizovi(v);
 	
 	for(int i(0); i<m.size(); i++) {
 		for(int j(0); j<m[i].size();j++) {
 			std::cout<<m[i][j]<<" ";
 		}
 		std::cout<<std::endl;
 	}
 	Matrica m2;
 	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
 	m2=OpadajuciPodnizovi(v);
 	for(int i(0); i<m2.size(); i++) {
 		for(int j(0); j<m2[i].size();j++) {
 			std::cout<<m2[i][j]<<" ";
 		}
 		std::cout<<std::endl;
 	}
	return 0;
}