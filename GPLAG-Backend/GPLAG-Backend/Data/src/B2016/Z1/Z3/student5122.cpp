/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>



std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> m;
	if(v.size()==0) return std::vector<std::vector<double>>(v.size(),std::vector<double>(v.size()));
	if(v.size()==1) return std::vector<std::vector<double>>(v.size()-1,std::vector<double>(v.size()-1));
	int brojac(0);
	const double EPS(1e-16);
	for(int i=0; i<v.size(); i++){
		std::vector<double> t;
		for(int j=brojac; j<v.size()-1; j++){
				brojac++;
			if(v[j]-v[j+1]<EPS){
				t.push_back(v[j]);
			}
			else if(j!=0){
			if(v[j]-v[j+1]>=EPS && v[j]-v[j-1]>EPS){
				t.push_back(v[j]); 
				brojac++; break;
				} 
	
			}
			if(j==v.size()-2){
				if(v[j]-v[j+1]<EPS){
					t.push_back(v[j+1]);
				}
			}
		
		}
		if(t.size()!=0){
		m.push_back(t);
		}
	
	
	} return m;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> m;
	if(v.size()==0) return std::vector<std::vector<double>>(v.size(),std::vector<double>(v.size()));
	if(v.size()==1) return std::vector<std::vector<double>>(v.size()-1,std::vector<double>(v.size()-1));
	int brojac=0;
	const double EPS(1e-16);
	for(int i=0; i<v.size(); i++){
		std::vector<double> t;
		for(int j=brojac; j<v.size()-1; j++){
			brojac++;
			if(v[j]-v[j+1]>=(-EPS)){
				t.push_back(v[j]);
			}
			else if(j!=0){
			if(v[j]-v[j+1]<=(-EPS) && v[j]-v[j-1]<(-EPS)){
				t.push_back(v[j]);
				brojac++;
			
			}
			}
			if(j==v.size()-2){
				if(v[j]-v[j+1]>=(-EPS)){
					t.push_back(v[j+1]);
				}
			}
		
			
		}
		if(t.size()!=0){
		m.push_back(t);
		}
	} return m;
}
int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> v;
	int br;
	for(int i=0; i<n; i++){
		std::cin>>br;
		v.push_back(br);
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>> m1=RastuciPodnizovi(v);
		for(std::vector<double> x:m1){
			for(int y:x){
				std::cout<<y<<" ";
			} std::cout<<std::endl;
		}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>> m2=OpadajuciPodnizovi(v);
		for(std::vector<double> x:m2){
			for(int y:x){
				std::cout<<y<<" ";
			} std::cout<<std::endl;
		}

	
	return 0;
}