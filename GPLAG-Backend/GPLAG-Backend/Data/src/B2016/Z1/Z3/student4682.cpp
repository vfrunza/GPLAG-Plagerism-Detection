/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> matrica;

matrica RastuciPodnizovi(std::vector<double> v) {
	matrica povratna;
	for(int i=0; i<v.size()-1; i++) {
		
		std::vector<double> pom;
		    while(v[i]<=v[i+1]) {
				pom.push_back(v[i]);
				i++;
				if(i>=v.size()-1) break;
			}
			if(i==0) continue;
			if(i!=0) {
				if(v[i]>=v[i-1]) pom.push_back(v[i]);
			}
		povratna.push_back(pom);
	for(int k=0; k<pom.size(); k++) {
		pom.erase(pom.begin()+k);
	}
	
	}
	return povratna;
}

matrica OpadajuciPodnizovi(std::vector<double> v) {
	matrica povratna;
	for(int i=0; i<v.size()-1; i++) {
		if(i==v.size()-1) break;
		std::vector<double> pom;
		while(v[i]>=v[i+1]) {
			pom.push_back(v[i]);
			i++;
			if(i>=v.size()-1) break;
		}
		if(i==0) continue;
		if(i!=0) {
		if(v[i]<=v[i-1]) pom.push_back(v[i]);
		}
		povratna.push_back(pom);
		for(int k=0; k<pom.size(); k++) {
			pom.erase(pom.begin()+k);
		}

	}
	
	return povratna;
}


int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double> a;
	std::cout<<"Unesite elemente vektora: ";
	double broj;
	for(int i=0; i<n; i++) {
		std::cin>>broj;
		a.push_back(broj);
	}
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	matrica rastuci;
	rastuci=RastuciPodnizovi(a);
	for(auto x : rastuci) {
		for(auto y : x) {
			std::cout<<y<<" ";
		}
		std::cout<<std::endl;
	}
	
	std::cout<<"Maksimalni opadajuci podnizovi: ";
	matrica opadajuci;
	opadajuci=OpadajuciPodnizovi(a);
	for(auto x : opadajuci) {
		for(auto y : x) {
			std::cout<<y<<" ";
		}
		std::cout<<std::endl;
	}
	
	return 0;
}