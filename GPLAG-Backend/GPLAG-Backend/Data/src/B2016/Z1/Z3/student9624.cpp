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
typedef std::vector<double> vektor;
typedef std::vector<std::vector<double>> matrica;
matrica OpadajuciPodnizovi( vektor v){
	matrica m;
	int x(0);
	for(int i=0 ; i<v.size()-1 ; i++){
		if(((i>0 && i!=v.size()-2) && v[i]<=v[i-1] && v[i]<v[i+1]) || (i==v.size()-2 && v[i+1]<=v[i])){
			x++;
		}
	}
	m.resize(x);
	x=0;
	for(int i=0 ; i<v.size()-1 ; i++){
	   	if(v[i]>=v[i+1]) {
			m[x].push_back(v[i]);
		}
		if(i==v.size()-2 && v[i]>=v[i+1] ) m[x].push_back(v[i+1]);
		if(i>0 && v[i]<=v[i-1] && v[i]<v[i+1]) {
			m[x].push_back(v[i]);
			x++;
		}
		
		
	}
	return m;
}

matrica RastuciPodnizovi( vektor v){
	matrica m;
	int x(0);
	for(int i=0 ; i<v.size()-1 ; i++){
		if(((i>0 && i!=v.size()-2) && v[i]>=v[i-1] && v[i]>v[i+1]) || (i==v.size()-2 && v[i+1]>=v[i])){
			x++;
		}
	}
	m.resize(x);
	x=0;
	for(int i=0 ; i<v.size()-1 ; i++){
	   	if(v[i]<=v[i+1]) {
			m[x].push_back(v[i]);
		}
		if(i==v.size()-2 && v[i]<=v[i+1] ) m[x].push_back(v[i+1]);
		if(i>0 && v[i]>=v[i-1] && v[i]>v[i+1]) {
			m[x].push_back(v[i]);
			x++;
		}
		
		
	}
	return m;
}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	vektor v;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0 ; i<n ; i++){
		int x;
		std::cin>>x;
		v.push_back(x);
	}
	matrica m1 = RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: ";
	std::cout<<std::endl;
			for(int i=0 ; i<m1.size() ; i++){
					for(int j=0 ; j<m1[i].size() ; j++){
						std::cout<<std::setprecision(12)<<m1[i][j]<<" ";
					}
					std::cout<<std::endl;
			}
		
			matrica m2 = OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni opadajuci podnizovi: ";
	std::cout<<std::endl;
			for(int i=0 ; i<m2.size() ; i++){
					for(int j=0 ; j<m2[i].size() ; j++){
						std::cout<<std::setprecision(12)<<m2[i][j]<<" ";
					}
					std::cout<<std::endl;
			}
	return 0;
}