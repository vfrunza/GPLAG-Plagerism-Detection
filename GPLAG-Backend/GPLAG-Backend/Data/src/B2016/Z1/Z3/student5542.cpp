#include <iostream>
#include <vector>
 
 
std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> v) {
	
	int j(0), z(0);
	
	std::vector<std::vector<double>> vv;
	std::vector<double> red; 
	
	for(int i(0); i<v.size()-1; i++) {
		  
		if(v[i+1]>=v[i] && i!=v.size()-1) {
			vv.push_back(red);
		  while(v[i+1]>=v[i]) {
			if(z==0) {
			vv[j].push_back(v[i]);
			
			vv[j].push_back(v[i+1]);
			
			z++;
			}
			
			else 
			vv[j].push_back(v[i+1]);
			
			i++;
			if(i==v.size()-1) {i--; break;}
			
		  }
		  j++;
		z=0;
		
		}
		  
	}

	return vv;
}


std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v) {
	int j(0), z(0);
	std::vector<std::vector<double>> vv;
	std::vector<double> red;
	
	
    for(int i(0); i<v.size()-1; i++) {
		
		if(v[i+1]<=v[i] && i!=v.size()-1) {
			vv.push_back(red);
		  while(v[i+1]<=v[i] && i!=v.size()-1) {
			if(z==0) {
			vv[j].push_back(v[i]);
			vv[j].push_back(v[i+1]);
			z++;
			}
			else 
			vv[j].push_back(v[i+1]);
			i++;
			if(i==v.size()-1) {i--; break;}
			
		  }
		  	j++;
		z=0;
		}
		
	}
	return vv;
	
}
int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	std::vector<double> v;
	double element;
	std::cout << "Unesite elemente vektora: ";
	for(int i(0); i<n; i++) {
		std::cin >> element;
		v.push_back(element);
	}
	
	std::vector<std::vector<double>> v1, v2;
	
	v1=RastuciPodnizovi(v);
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(int i(0); i<v1.size(); i++) {
		for(int j(0); j<v1[i].size(); j++) {
			std::cout << v1[i][j] << " ";
		}
		std::cout << std::endl;
	}
	v2=OpadajuciPodnizovi(v);
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	
	for(int i(0); i<v2.size(); i++) {
		for(int j(0); j<v2[i].size(); j++) {
			std::cout << v2[i][j]  << " ";
		}
		std::cout << std::endl;
	}
	
	
	
	return 0;
}