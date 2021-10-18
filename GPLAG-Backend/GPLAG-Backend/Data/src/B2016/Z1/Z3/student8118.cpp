/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
typedef std::vector<std::vector<double>> Matrica;
Matrica RastuciPodnizovi (std::vector<double> v) {
	Matrica a;
	int brojac=0;
	int i;
	if (v.size()!=0) {
		for (i=0; i<v.size()-1; i++) {
			if (v.at(i)<=v.at(i+1)) {
				a.resize(a.size()+1);
				while (i<v.size()-1){
					if(v.at(i)<=v.at(i+1)){
						a[brojac].push_back(v.at(i));
						i++;
					}
					else break;
				}
				a[brojac].push_back(v.at(i));
				brojac++;
			}
		}
	}
	return a;
}
Matrica OpadajuciPodnizovi (std::vector<double> v) {
	Matrica a;
	int brojac=0;
	int i;
	if (v.size()!=0) {
		for (i=0; i<v.size()-1; i++) {
			if (v.at(i)>=v.at(i+1)) {
				a.resize(a.size()+1);
				while (i<v.size()-1) {
					if(v.at(i)>=v.at(i+1)){
						a[brojac].push_back(v.at(i));
						i++;
					}
					else break;
				}
				a[brojac].push_back(v.at(i));
				brojac++;
			}
		}
	}
	return a;
}

int main ()
{
	std::vector<double>v;
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	v.resize(n);
	for (int i=0; i<n; i++) {
		std::cin>>v[i];
	}
	auto a=RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: \n";
	for (int i=0; i<a.size(); i++) {
		for (int j=0; j<a[i].size(); j++) {
			std::cout<<a[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	auto b=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni opadajuci podnizovi: \n";
	 for (int i=0; i<b.size(); i++) {
		for (int j=0; j<b[i].size(); j++) {
			std::cout<<b[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}