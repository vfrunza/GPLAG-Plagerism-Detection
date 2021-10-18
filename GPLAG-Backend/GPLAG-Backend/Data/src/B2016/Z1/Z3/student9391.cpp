/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector< double>> Matrica;

Matrica RastuciPodnizovi(std::vector< double> V1) {
	Matrica K, nova;
	K.resize(V1.size());
 double pom;
	bool podniz;
	int j=0, br_podnizova;
	
	pom=V1.at(0);
	podniz=false;
	K.at(0).push_back(pom);
	
	for(int i=1;i<V1.size();i++) {
		if(pom<=V1.at(i)) {
			if(podniz==false) {
				K.at(j).push_back(V1.at(i));
			}
			if(podniz==true) {
				K.at(j).push_back(V1.at(i));
			}
			pom=V1.at(i);
			podniz=true;
		}
		else {
			pom=V1.at(i);
			if(podniz==true) {
				j++;
				if(i<V1.size())
					K.at(j).push_back(pom);
				if(i==V1.size()) {
					K.at(j).erase(K.at(j).begin());
					j--;
				}
			}
			if(podniz==false) {
				K.at(j).erase(K.at(j).begin());
				if(i<V1.size())
				K.at(j).insert(K.at(j).begin(),pom);
			}
			podniz=false;
		}
	}
	if(K.at(j).size()==1)
	br_podnizova=j;
	else
	br_podnizova=j+1;
	
	nova.resize(br_podnizova);
	for(int br=0; br<br_podnizova; br++)
	nova.at(br)=K.at(br);
	
	return nova;
}

Matrica OpadajuciPodnizovi(std::vector<double> V1){
	Matrica K, nova;
	K.resize(V1.size());
	double pom;
	bool podniz;
	int j=0, br_podnizova;
	
	pom=V1.at(0);
	podniz=false;
	K.at(0).push_back(pom);
	for(int i=1;i<V1.size();i++) {
		if(pom>=V1.at(i)) {
			if(podniz==false) {
				K.at(j).push_back(V1.at(i));
			}
			if(podniz==true) {
				K.at(j).push_back(V1.at(i));
			}
			pom=V1.at(i);
			podniz=true;
		}
		else {
			pom=V1.at(i);
			if(podniz==true) {
				j++;
				if(i<V1.size())
				K.at(j).push_back(pom);
				if(i==V1.size()) {
					K.at(j).erase(K.at(j).begin());
					j--;
				}
			}
			if(podniz==false) {
				K.at(j).erase(K.at(j).begin());
				if(i<V1.size())
				K.at(j).insert(K.at(j).begin(),pom);
			}
			podniz=false;
		}
	}
	if(K.at(j).size()==1)
	br_podnizova=j;
	else
	br_podnizova=j+1;
	
	nova.resize(br_podnizova);
	for(int br=0;br<br_podnizova;br++)
	nova.at(br)=K.at(br);
	return nova;
}



int main ()
{
	int n;
	Matrica NizRas, NizOpad;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<double> Vektor1(n);
	std::cout << "Unesite elemente vektora: ";
	for(int i=0;i<n;i++) {
		std::cin >> Vektor1.at(i);
	}
	NizRas=RastuciPodnizovi(Vektor1);
	NizOpad=OpadajuciPodnizovi(Vektor1);
	
	std::cout << "Maksimalni rastuci podnizovi: "<< std::endl;
	for(auto red: NizRas) {
		for(auto x : red) 
		std::cout << std::setprecision(12) << x << " ";
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(int i=0; i<NizOpad.size(); i++) {
		for(int j=0; j<NizOpad[i].size(); j++)
		std::cout << std::setprecision(12) << NizOpad[i][j] << " ";
		std::cout << std::endl;
	}
	return 0;
}