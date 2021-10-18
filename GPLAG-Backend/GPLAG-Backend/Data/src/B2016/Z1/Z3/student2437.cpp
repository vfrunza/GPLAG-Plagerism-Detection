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

typedef std::vector<std::vector<double>> matrica;

	matrica RastuciPodnizovi(std::vector<double>v){
		matrica rastuci;
		if(v.size()==0 || v.size()==1) return rastuci;
		for(int i=0; i<v.size()-1; i++){
			std::vector<double>b;
				while(v[i+1]>=v[i] && i<v.size()-1){
					b.push_back(v[i]);
					i++;
					if(i==v.size()-1) break;
				}
			 if(i>0 && v[i]>=v[i-1]) b.push_back(v[i]);
			if(b.size() != 0) rastuci.push_back(b);
		}
		return rastuci;
	}
	
	matrica OpadajuciPodnizovi(std::vector<double>v){
		matrica opadajuci;
		if(v.size()==0) return opadajuci;
		for(int i=0; i<v.size()-1; i++){
			std::vector<double>b;
			while(v[i]>=v[i+1] && i<v.size()-1){
				b.push_back(v[i]);
				i++;
				if(i==v.size()-1) break;
			}
			if(i>0 && v[i]<=v[i-1]) b.push_back(v[i]);
			if(b.size() != 0) opadajuci.push_back(b);
		}
		return opadajuci;
	}
	
int main (){
		int n;
		std::vector<double>vektor;
		std::cout<< "Unesite broj elemenata vektora: ";
		std::cin>>n;
		vektor.resize(n);
		std::cout<< "Unesite elemente vektora: ";
		for(int i=0; i<n; i++){
			double tmp;
			std::cin>>tmp;
			vektor[i] = tmp;
		}
		auto p = RastuciPodnizovi(vektor);
		std::cout<< "Maksimalni rastuci podnizovi: "<<std::endl;
		for(int i=0; i<p.size(); i++){
			for(int j=0; j<p[i].size(); j++){
				std::cout<< p[i][j]<< " ";
			}
			std::cout<<std::endl;
		}
		auto q = OpadajuciPodnizovi(vektor);
		std::cout<< "Maksimalni opadajuci podnizovi: "<<std::endl;
		for(int i=0; i<q.size(); i++){
			for(int j=0; j<q[i].size(); j++){
				std::cout<<q[i][j]<< " ";
			}
			std::cout<<std::endl;
		}
	return 0;
}