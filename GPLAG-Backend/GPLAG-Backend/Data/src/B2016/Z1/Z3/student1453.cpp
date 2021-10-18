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

Matrica RastuciPodnizovi(std::vector<double> v){
	Matrica m;
	if(v.size()==0) return m;
	int brojac(1);
	for(int i=0;i<v.size()-1;i++){
		if(v[i]>v[i+1]) continue;
		m.resize(brojac);
		while(v[i+1]>=v[i]){
			m[brojac-1].push_back(v[i]); // 1 2 3 4 3 2 1 2 3 4
			i++;
			if(i==v.size()-1) break;
		}
		m[brojac-1].push_back(v[i]);
		brojac++;
	}
	return m;
}
Matrica OpadajuciPodnizovi(std::vector<double> v){
	Matrica m;
	if(v.size()==0) return m;
	int brojac(1);
	for(int i=0;i<v.size()-1;i++){
		if(v[i]<v[i+1]) continue;
		m.resize(brojac);
		while(v[i+1]<=v[i]){
			m[brojac-1].push_back(v[i]); 
			i++;
			if(i==v.size()-1) break;
		}
		m[brojac-1].push_back(v[i]);
		brojac++;
	}
	return m;
}
int main (){
	std::cout << "Unesite broj elemenata vektora: ";
	int broj;
	std::cin >> broj;
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> v;
	for(int i=0;i<broj;i++){
		double element;
		std::cin >> element;
		v.push_back(element);
	}
	
	std::cout << "Maksimalni rastuci podnizovi: \n";
	Matrica rastuci(RastuciPodnizovi(v));
	
	int max_size=0;
	for(int i=0;i<rastuci.size();i++)
		if(rastuci[i].size()>max_size) max_size=rastuci[i].size();
	
	for(int i=0;i<rastuci.size();i++){
		if(rastuci[i].size()==max_size){
			for(int j=0;j<max_size;j++){
				std::cout<<rastuci[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
		
	}
	
	
	std::cout << "Maksimalni opadajuci podnizovi: \n";
	Matrica opadajuci(OpadajuciPodnizovi(v));
	
	int max_size2=0;
	for(int i=0;i<opadajuci.size();i++)
		if(opadajuci[i].size()>max_size2) max_size2=opadajuci[i].size();
	
	for(int i=0;i<opadajuci.size();i++){
		if(opadajuci[i].size()==max_size2){
			for(int j=0;j<max_size2;j++){
				std::cout<<opadajuci[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
		
	}
	
	return 0;
}