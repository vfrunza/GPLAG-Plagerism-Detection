/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v) {
	std::vector<std::vector<double>> podnizovi;
	int k(0);
	for(int i=0;i<v.size()-1;i++) {
		if(v[i]<=v[i+1]) {
			podnizovi.resize(podnizovi.size()+1);
			podnizovi[k].push_back(v[i]);
			while(i!=v.size()-1 && v[i]<=v[i+1]) {
				i++;
				podnizovi[k].push_back(v[i]);
			}
			k++;
		}
	}
	return podnizovi;
}
std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v) {
	std::vector<std::vector<double>> opadajuci;
	int k(0);
	for(int i=0;i<v.size()-1;i++) {
		if(v[i]>=v[i+1]) {
			opadajuci.resize(opadajuci.size()+1);
			opadajuci[k].push_back(v[i]);
			while(i!=v.size()-1 && v[i]>=v[i+1]) {
				i++;
				opadajuci[k].push_back(v[i]);
			}
			k++;
		}
	}
	return opadajuci;
}
int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::vector<double> v(n); 
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++) {
		std::cin>>v[i];
	}
	std::cout<<"Maksimalni rastuci podnizovi: \n";
	std::vector<std::vector<double>> rastuci(RastuciPodnizovi(v));
	for(int i=0;i<rastuci.size();i++) {
		for(int j=0;j<rastuci[i].size();j++) {
			std::cout<<rastuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: \n";
	std::vector<std::vector<double>> opadajuci(OpadajuciPodnizovi(v));
	for(int i=0;i<opadajuci.size();i++) {
		for(int j=0;j<opadajuci[i].size();j++) {
			std::cout<<opadajuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}