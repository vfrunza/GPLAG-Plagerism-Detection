/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>

std::vector<std::vector<double>>OpadajuciPodnizovi(std::vector<double> niz) {
	std::vector<std::vector<double>> pad;
	std::vector<double> pomoc;
	for(int i=0;i<niz.size();i++) {
		if(i==niz.size()) break;
		if(i<niz.size()-1 && niz.at(i)>=niz.at(i+1)) {
			pomoc.push_back(niz.at(i));
			continue;
		}
		if(pomoc.size()>0) {
			pomoc.push_back(niz.at(i));
			pad.push_back(pomoc);
		}
		pomoc.resize(0);
	}
	pad.push_back(pomoc);
	return pad;
}

std::vector<std::vector<double>>RastuciPodnizovi(std::vector<double> niz) {
	std::vector<std::vector<double>> rast;
	std::vector<double> pomoc;
	for(int i=0;i<niz.size();i++) {
		if(i==niz.size()) break;
		if(i<niz.size()-1 && niz.at(i)<=niz.at(i+1)) {
			pomoc.push_back(niz.at(i));
			continue;
		}
		if(pomoc.size()>0) {
			pomoc.push_back(niz.at(i));
			rast.push_back(pomoc);
		}
		pomoc.resize(0);
	}
	rast.push_back(pomoc);
	return rast;
}
int main () 
{	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	if(n<=0) return 0;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> v(n);
	for(int i=0;i<n;i++) std::cin>>v.at(i);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>> rastuci{RastuciPodnizovi(v)};
	for(int i=0;i<rastuci.size();i++) {
		if(i==rastuci.size()) break;
		for (int j=0;j<rastuci.at(i).size();j++) {
			std::cout<<rastuci.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>> opadajuci{OpadajuciPodnizovi(v)};
	for(int i=0;i<opadajuci.size();i++) {
		if(i==opadajuci.size()) break;
		for (int j=0;j<opadajuci.at(i).size();j++) {
			std::cout<<opadajuci.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}