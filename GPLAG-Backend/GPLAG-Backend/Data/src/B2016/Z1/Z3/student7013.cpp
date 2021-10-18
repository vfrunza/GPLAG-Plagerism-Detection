/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> niz) {
	std::vector<std::vector<double>> rez;
	std::vector<double> tmp;
	int i(0);
	while(i<niz.size()-1) {
		while(i<niz.size()-1 && niz[i]<=niz[i+1]) {
			tmp.push_back(niz[i]);
			i++;
		}
		tmp.push_back(niz[i]);
		if(tmp.size()>1) rez.push_back(tmp);
		tmp.resize(0);
		i++;
	}
	return rez;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> niz) {
	std::vector<std::vector<double>> rez;
	std::vector<double> tmp;
	int i(0);
	while(i<niz.size()-1) {
		while(i<niz.size()-1 && niz[i]>=niz[i+1]) {
			tmp.push_back(niz[i]);
			i++;
		}
		tmp.push_back(niz[i]);
		if(tmp.size()>1) rez.push_back(tmp);
		tmp.resize(0);
		i++;
	}
	return rez;
}

int main ()
{
	int n;
	double x;
	std::vector<double> v;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0);i<n;i++) {
		std::cin>>x;
		v.push_back(x);
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	auto p = RastuciPodnizovi(v);
	for(int i(0);i<p.size();i++){
		for(int j(0);j<p[i].size();j++)
			std::cout<<p[i][j]<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	auto y = OpadajuciPodnizovi(v);
	for(int i(0);i<y.size();i++){
		for(int j(0);j<y[i].size();j++)
			std::cout<<y[i][j]<<" ";
		std::cout<<std::endl;
	}
	return 0;
}