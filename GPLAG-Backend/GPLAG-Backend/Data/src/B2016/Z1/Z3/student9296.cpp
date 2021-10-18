/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> niz){
	std::vector<std::vector<double>> tp_mi_uzima_zivot;
	int i(0), j(1);
	while(1){
		std::vector<double> pomoc;
		while(niz[i]<=niz[j]){
			pomoc.push_back(niz[i]);
			i++;
			j++;
			if(i>=niz.size() || j>=niz.size()) break;
		}
		pomoc.push_back(niz[i]);
		i=j;
		j=i+1;
		if(pomoc.size()>1) tp_mi_uzima_zivot.push_back(pomoc);
		if(i>=niz.size() || j>=niz.size()) break;
	}
	return tp_mi_uzima_zivot;
}
std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> niz){
	int i(0), j(1);
	std::vector<std::vector<double>> opadajuci;
	for(;;){
		std::vector<double> pom;
		while(niz[i]>=niz[j]){
			pom.push_back(niz[i]);
			i++;
			j++;
			if(i>=niz.size() || j>=niz.size()) break;
		}
		pom.push_back(niz[i]);
		i=j;
		j=i+1;
		if(pom.size()>1) opadajuci.push_back(pom);
		if(i>=niz.size() || j>=niz.size()) break;
	}
	return opadajuci;
}
int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> vektor;
	for(int i=0; i<n; i++){
		double element;
		std::cin>>element;
		vektor.push_back(element);
	}
	std::vector<std::vector<double>>rastuci(RastuciPodnizovi(vektor));
	std::vector<std::vector<double>>opadajuci(OpadajuciPodnizovi(vektor));
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0; i<rastuci.size(); i++){
		for(int j=0; j<rastuci[i].size(); j++){
			std::cout<<rastuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0; i<opadajuci.size(); i++){
		for(int j=0; j<opadajuci[i].size(); j++){
			std::cout<<opadajuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}