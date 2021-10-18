/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <iomanip>

void IspisiMatricu(std::vector<std::vector<double>> m){
	
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[0].size(); j++)
		std::cout<<m[i][j]<<" ";
		std::cout<<std::endl;
	}
}

std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> v){
	std::vector<std::vector<double>> izlaznamatrica;	
		std::vector<double> red;
			
	for(int i=0; i<v.size()-1; i++){
		
		if(v[i+1]>=v[i]){
			red.push_back(v[i]);
		}
		
		else{
			if(red.size()>=1){
				red.push_back(v[i]);
				izlaznamatrica.push_back(red);
			}
		red.clear();
		}
	}
	
	
	//ispisivanje posljednjeg reda 
	if(red.size()>=1){
    	red.push_back(v[v.size()-1]);
	    	izlaznamatrica.push_back(red);
		}
	
	return izlaznamatrica;
}

std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> v){
	std::vector<std::vector<double>> izlaznamatrica;	
		std::vector<double> red;
			
	for(int i=0; i<v.size()-1; i++){

		
		if(v[i+1]<=v[i]){
			red.push_back(v[i]);
		}
		
		else{
			if(red.size()>=1){
				red.push_back(v[i]);
				izlaznamatrica.push_back(red);
		}
		red.clear();
		}
	}
	
	
	//ispisivanje posljednjeg reda 
	if(red.size()>=1){
    	red.push_back(v[v.size()-1]);
	    	izlaznamatrica.push_back(red);
		}
	
	return izlaznamatrica;
}

int main ()
{
	std::vector<double> v;
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		int k;
		std::cin>>k;
		v.push_back(k);
	}
	
	
	
	auto opadajuci = OpadajuciPodnizovi(v);
	auto rastuci = RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: ";
	std::cout<<std::endl;
	IspisiMatricu(rastuci);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	IspisiMatricu(opadajuci);

	return 0;
}