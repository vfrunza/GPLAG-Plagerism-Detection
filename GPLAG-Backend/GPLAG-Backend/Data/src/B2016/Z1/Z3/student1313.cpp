/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>


std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> v) {
	
	std::vector<std::vector<double>> konacna;
	std::vector<double> vek;
	
	for (int i=0; i<v.size()-1; i++) {
	  if (v[i+1]>=v[i]) {
	  	
	  while (v[i+1]>=v[i]) {
	  	vek.push_back(v[i]); i++;
	    if (i==v.size()-1) break; 
	  }
	  
	  vek.push_back(v[i]);
	  konacna.push_back(vek);
	  vek.resize(0);
	  }
	}
	

return konacna;
}
	 

std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> v) {
	
	std::vector<std::vector<double>> konacna;
	std::vector<double> vek;
	
	for (int i=0; i<v.size()-1; i++) {
		if (v[i+1]<=v[i]) {
			
		while (v[i+1]<=v[i]) {
			vek.push_back(v[i]); i++;
			if (i==v.size()-1) break;
		}
		vek.push_back(v[i]);
		konacna.push_back(vek);
		vek.resize(0);
		}
	}
return konacna;
	}



int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	
	std::vector<double> v; //double x;
	std::cout << "Unesite elemente vektora: ";
	for (int i=0; i<n; i++) {
		double br{};
		std::cin >> br;
		v.push_back(br);
	}
	std::vector<std::vector<double>> mat;
	mat=RastuciPodnizovi(v);
	
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	
	for (auto x: mat) {
		for (auto y: x) std::cout << y <<" ";
		std::cout<<std::endl;
	}
	
	mat=OpadajuciPodnizovi(v);
	
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for (auto x:mat) {
		for (auto y: x) std::cout << y <<" ";
		std::cout <<std::endl;
	}
	
	return 0; // 1,  3,  2,  6,  7,  9,  10,  4,  3,  1  i 7
}