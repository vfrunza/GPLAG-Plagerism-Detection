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

	std::vector<std::vector<double>> rastuci;
	std::vector<double> vek;
	 
	int a=int(v.size()-1);
	for(int i=0; i<a; i++) {
		if(v[i]<=v[i+1]) {
			while(v[i]<=v[i+1] && i<a) {
				vek.push_back(v[i]);
				i++;
				if(i==a) break;
			}
			if(i!=0 && i!=a+1 && v[i]>=v[i-1]) vek.push_back(v[i]);
			
			else if (i==a+1) vek.push_back(v[i]);
		}
		
		if(vek.size()!=0)
		rastuci.push_back(vek);
		vek.resize(0);
	}
	return rastuci;
	
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v) {
	
	std::vector<std::vector<double>> opadajuci;
	std::vector<double> vek;
	
	int a=int(v.size()-1);
	for(int i=0; i<a; i++) {
		if(v[i]>=v[i+1]) {
			while(v[i]>=v[i+1] && i<a) { 
				vek.push_back(v[i]);
				i++;
				if (i==a) break;
			}
			
			if(i!=0 && i!=a+1) {
				if(i!=0 && v[i]<=v[i-1]) vek.push_back(v[i]);
			}
			else if (i==a+1) vek.push_back(v[i]);
			
			}
		if(vek.size()!=0)
		opadajuci.push_back(vek);
		vek.resize(0);
	}
	return opadajuci;
}


int main ()
{
	
	int n;
	int p;
	std::vector<double> v1;
	std::vector<std::vector<double>> v2;
	std::vector<std::vector<double>> v3;
	
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		std::cin>>p;
		v1.push_back(p);
	}
	
	v2=RastuciPodnizovi(v1);
	v3=OpadajuciPodnizovi(v1);
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	
	for(int i=0; i<v2.size(); i++) {
		for(int j=0; j<v2[i].size(); j++) {
			std::cout<<v2[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl; 
	
	for(int i=0; i<v3.size(); i++) {
		for(int j=0; j<v3[i].size(); j++) {
			std::cout<<v3[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	
	
	
	return 0;
}