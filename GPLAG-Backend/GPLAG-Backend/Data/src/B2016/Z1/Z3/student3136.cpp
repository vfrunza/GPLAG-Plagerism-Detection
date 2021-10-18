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
typedef std::vector<std::vector<double>>Matrica;
void IspisiMatricu(Matrica m) {
	for(int i(0); i<m.size(); i++) {
		for(int j(0); j<m[0].size(); j++) {
			std::cout<<m[i][j];
		//	std::cout<<std::endl;
		}
	}
}

Matrica RastuciPodnizovi(std::vector<double> v) {
	std::vector<double> v1;
	Matrica nova;
	for(int i=0; i<v.size(); i++) {
	
		
		while(v[i]<=v[i+1]) {
		v1.push_back(v[i]);
		i++;
		//if(v[i]>v[i+1]) break;
		}
		nova.push_back(v1);	
	}
	return nova;
}
Matrica OpadajuciPodnizovi(std::vector<double> v) {
	std::vector<double> v1;
	Matrica nova;
	
	for(int i=0; i<v.size(); i++) {
		while (v[i]>=v[i+1]) {
			v1.push_back(v[i]);
			i++;
	}
		nova.push_back(v1);
	}
 	
 return nova;
}
int main () {
	int n,i(0);
	std::vector<double>v;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	while(i<n) {
		std::cin>>i;
		v.push_back(i);
		i++;
	}
	std::cout<<"Maksimalni rastuci podnizovi: \n";
    IspisiMatricu(RastuciPodnizovi(v));
    std::cout<<"\nMaksimalni opadajuci podnizovi: \n";
   IspisiMatricu(OpadajuciPodnizovi(v));
	
	return 0;
}