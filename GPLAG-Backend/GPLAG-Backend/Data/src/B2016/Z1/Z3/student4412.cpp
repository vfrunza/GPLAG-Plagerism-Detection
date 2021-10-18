/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica ;

Matrica RastuciPodnizovi(std::vector<double> x){
	Matrica k;
	for(int i=0; i<x.size()-1; i++){
		if(x[i]<=x[i+1]){
			std::vector<double> y;
			y.push_back(x[i]);
			while(x[i]<=x[i+1] && i<x.size()-2){
				y.push_back(x[i+1]);
				i++;
			}
			if(i==x.size()-2 && x[i]<=x[i+1]){
				y.push_back(x[i+1]);
			}
			k.push_back(y);
		}
	}
	return k;
}

Matrica OpadajuciPodnizovi(std::vector<double> x){
	Matrica k;
	for(int i=0; i<x.size()-1; i++){
		if(x[i]>=x[i+1]){
			std::vector<double> y;
			y.push_back(x[i]);
			while(x[i]>=x[i+1] && i<x.size()-2){
				y.push_back(x[i+1]);
				i++;
			}
			if(i==x.size()-2 && x[i]>=x[i+1]){
				y.push_back(x[i+1]);
			}
			k.push_back(y);
		}
	}
	return k;
}

int main ()
{
	std::vector<double> v;
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		int broj;
		std::cin>>broj;
		v.push_back(broj);
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	Matrica a=RastuciPodnizovi(v);
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a[i].size(); j++){
			std::cout<<a[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	Matrica b=OpadajuciPodnizovi(v);
	for(int i=0; i<b.size(); i++){
		for(int j=0; j<b[i].size(); j++){
			std::cout<<b[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}