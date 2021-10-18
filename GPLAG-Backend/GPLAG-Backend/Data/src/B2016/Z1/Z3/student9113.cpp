/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>

std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> v){
	std::vector<std::vector<double>> v1;
	for (int i = 0 ; i<v.size() ; i++) {
		for (int j = i+1; j<v.size(); j++){
			if (v[i]<v[j]) v1.push_back(v);
			else v1.push_back();
		}
	}
	return v1;
}
std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> v2){
	std::vector<std::vector<double>> v3;
	for (int i = 0; i<v2.size();i++){
		for (int j = i+1; j<v2.size();j++){
			if (v2[j] > v2[i]) v3.push_back(v2);
			else v3.push_back();
			}
		}
		return v3;
	}

int main ()
{
	std::vector<double> v;
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<std::endl<<"Unesite elemente vektora: ";
	double m;
	for (int i = 0;i<n;i++){
		std::cin>>m;
		v.push_back(m);
	}
	std::vector<std::vector<double>> niz;
	niz = RastuciPodnizovi(v);
	std::vector<std::vector<double>> niz1;
	niz1 = OpadajuciPodnizovi(v);
	for (int i = 0; i<niz.size();i++){
		for(int j = 0; j<niz[0].size();j++){
			std::cout<<niz[i][j];
		}
	}
	
	return 0;
}