/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>


	std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double>v){
		
		std::vector<std::vector<double>>v1;
		for (int i=0; i < v.size() - 1; i++) { 
			int pocetak = i;
			
			while (i < v.size() - 1 && v[i] <= v[i + 1]) {
				i++;
			}
			
			int kraj = i;
			
			std::vector<double> podniz;
			for (int j = pocetak; j <= kraj; j++) {
				podniz.push_back(v[j]);
			}
			
			if (podniz.size() > 1) {
				v1.push_back(podniz);
			}
		}
		
		return v1;
	}
	
	std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double>v){
		std::vector<std::vector<double>>v2;
		for (int i=0; i < v.size() - 1; i++) { 
			int pocetak = i;
			
			while (i < v.size() - 1 && v[i] >= v[i + 1]) {
				i++;
			}
			
			int kraj = i;
			
			std::vector<double> podniz;
			for (int j = pocetak; j <= kraj; j++) {
				podniz.push_back(v[j]);
			}
			
			if (podniz.size() > 1) {
				v2.push_back(podniz);
			}
		}
		
		return v2;
	}


	

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::vector<double> v(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<v.size();i++){
		std::cin>>v[i];
	}
	
    auto rastuci = RastuciPodnizovi(v);
    
    std::cout<<"Maksimalni rastuci podnizovi:"<<std::endl;
    
    for (int i = 0; i < rastuci.size(); i++) {
    	for (int j = 0; j < rastuci[i].size(); j++) {
    		std::cout << rastuci[i][j] << " ";
    	}
    	std::cout << "\n";
    }
    
    auto opadajuci = OpadajuciPodnizovi(v);
    
    std::cout<<"Maksimalni opadajuci podnizovi:"<<std::endl;
    
    for (int i = 0; i < opadajuci.size(); i++) {
    	for (int j = 0; j < opadajuci[i].size(); j++) {
    		std::cout << opadajuci[i][j] << " ";
    	}
    	std::cout << "\n";
    }

	return 0;
}