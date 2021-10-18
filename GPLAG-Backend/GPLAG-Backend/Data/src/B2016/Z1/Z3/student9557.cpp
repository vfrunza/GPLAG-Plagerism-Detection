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
#include <iomanip>

const double k=0.000000001;

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double>v){

	std::vector<std::vector<double>> m;
	std::vector<double> novi;
	
	for(int i=0;i<v.size()-2;i++ ){
		
		if((v[i]-v[i+1])<k) {
			while(  i+1<v.size() && ((v[i]-v[i+1])<k) ){
				if(novi.size()==0) 
				novi.push_back(v[i]);
				novi.push_back(v[i+1]);
				i++;
		
			}
		if (novi.size()>1)
		m.push_back(novi);
		novi.resize(0);
		
		}
	
	
   	novi.resize(0);
	}
	
	return m;
}

std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> v){

	std::vector<std::vector<double>> m;
	std::vector<double> novi;
	
	
	for (int i=0; i<v.size()-1;i++){
		
		if((v[i]-v[i+1])>=0){
			while( i+1<v.size() && (v[i]-v[i+1])>=0){
				if(novi.size()==0) 
				novi.push_back(v[i]);
				novi.push_back(v[i+1]);
				i++;
			}
		
		m.push_back(novi);
		novi.resize(0);
		
		}
	
	
   	novi.resize(0);
	}
	
	return m;
}

int main ()
{
	std::vector<double> v;
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	
    for(int i=0;i<n;i++){
    	double broj;
    	std::cin>>broj;
    	v.push_back(broj);
    }
	
	
	std::vector<std::vector<double>> m ;
	m=RastuciPodnizovi(v);
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int k=0;k<m.size();k++){
	for(int l=0;l<m[k].size();l++){
		std::cout<<std::setprecision(12)<<m[k][l]<<" ";
		
	}
	std::cout<<std::endl;
	}
	
    
	std::vector<std::vector<double>> u;
	u=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int k=0;k<u.size();k++){
		for(int l=0;l<m[k].size();l++){
			std::cout<<std::setprecision(12)<<u[k][l]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}