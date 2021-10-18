/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>


const double eps(1e-10);

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v){
	Matrica grbava;
	int i=0,brojacRedova=0,j=0;
	std::vector<double> pomocni;
	
	while (i < int(v.size())-1 && j < int(v.size())) {
		j = i+1;
		if((v[i] - v[j])< eps){
			while(((v[i] - v[j])< eps) && j < int(v.size()) )  { 
			if(pomocni.size() ==0) pomocni.push_back(v[i]);
			pomocni.push_back(v[j]);
				i++;
				j++;
				if(j == int(v.size())){ j--; break;}
			}
		
		 if( ((v[i] - v[j]) >= eps && j < int(v.size()) && pomocni.size() > 1) || (i == int(v.size())-1 && pomocni.size() > 1) ){
				brojacRedova++;
		     	grbava.resize(brojacRedova);
		    	grbava[brojacRedova-1].resize(pomocni.size());
			
			for(int p=0; p < int(pomocni.size()); p++) grbava[brojacRedova-1][p] = pomocni[p];
			pomocni.resize(0);
				
			}
			}
		i++;
	if(grbava.size() != 0) pomocni.resize(0);
	}
	
	return grbava;
}


Matrica OpadajuciPodnizovi(std::vector<double> v){
Matrica grbava;
	int i=0,brojacRedova=0,j=0;
	std::vector<double> pomocni;
	
	while (i < int(v.size())-1 && j+1 < int(v.size())) {
		j = i+1;
		if( v[i]-v[j] >= 0){
			
			while( v[i]-v[j] >= 0 && j < int(v.size()) )  {
			if(pomocni.size() ==0) pomocni.push_back(v[i]);
			pomocni.push_back(v[j]);
				i++;
				j++;
				if(j == int(v.size())){ j--; break;}
			}
		
		 if( ((v[i] - v[j]) <= eps && j < int(v.size()) && pomocni.size() > 1) || (i == int(v.size())-1 && pomocni.size() > 1) ){
				brojacRedova++;
		     	grbava.resize(brojacRedova);
		    	grbava[brojacRedova-1].resize(pomocni.size());
			
			for(int p=0; p < int(pomocni.size()); p++) grbava[brojacRedova-1][p] = pomocni[p];
			pomocni.resize(0);
				
				} 
				}
		i++;
	if(grbava.size() != 0) pomocni.resize(0);
	}
	
	return grbava;
}



int main ()
{
	std::vector<double> v;
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	double element;
	do{
		std::cin>>element;
		if(std::fabs(element - 0) < eps) break;
		v.push_back(element);
		n--;
	}while(n);
	
	
	Matrica m = OpadajuciPodnizovi(v);
	Matrica dva = RastuciPodnizovi(v);
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(std::vector<double> red: dva){
		for(double e : red) std::cout << e <<" ";
		std::cout<<std::endl;
	}
	
	
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(std::vector<double> red : m){
		for(double el : red) std::cout<<el << " ";
		std::cout<<std::endl;
	}
	
	return 0;
}