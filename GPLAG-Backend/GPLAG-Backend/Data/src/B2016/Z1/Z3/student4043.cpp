/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> VektorVektora;

VektorVektora RastuciPodnizovi(std::vector<double> v) {
	VektorVektora rastuci;
	for(int i(1);i<v.size();i++) {
		std::vector<double> temp;
		temp.push_back(v[i-1]);
		while(i<v.size() && v[i-1]<=v[i]) {
			temp.push_back(v[i]);
			i++;
		}
		if(temp.size()>1) {
			rastuci.push_back(temp);
		}
	}
	return rastuci;
}

VektorVektora OpadajuciPodnizovi(std::vector<double> v) {
	VektorVektora opadajuci;
	for(int i(1);i<v.size();i++) {
		std::vector<double> temp;
		temp.push_back(v[i-1]);
		while(i<v.size() && v[i-1]>=v[i]) {
			temp.push_back(v[i]);
			i++;
		}
		if(temp.size()>1) {
			opadajuci.push_back(temp);
		}
	}
	return opadajuci;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> v;
	double element;
	for(int i(0);i<n;i++) {
		std::cin>>element;
		v.push_back(element);
	}
	VektorVektora rastuci;
	rastuci=RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: \n";
	for(int i(0);i<rastuci.size();i++) {
		for(int j(0);j<rastuci[i].size();j++) {
			std::cout<<rastuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	VektorVektora opadajuci;
	opadajuci=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni opadajuci podnizovi:\n";
	for(int i(0);i<opadajuci.size();i++) {
		for(int j(0);j<opadajuci[i].size();j++) {
			std::cout<<opadajuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}