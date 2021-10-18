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

typedef std::vector<std::vector<double>> Matrica;
Matrica RastuciPodnizovi(std::vector<double> v){
	Matrica n(v.size());
	int a=0;
	for(int i=0; i<v.size(); i++){
		
		if((i<(v.size()-1) && (v[i]<v[i+1] || fabs(v[i]-v[i+1])<0.0000000001)) || (i<(v.size()-1) && v[i]>v[i+1]) || (i==(v.size()-1) && (v[i]>v[i-1] || fabs(v[i]-v[i-1])<0.0000000001))) n[a].push_back(v[i]);
		if((i<(v.size()-1) && v[i]>v[i+1])) a++;
		
	} n.resize(a+1);
	for(int i=0; i<n.size(); i++){
		if(n[i].size()==1 || n[i].size()==0){
			n.erase(n.begin() + i);
			i--;
		}
	}
	return n;
}

Matrica OpadajuciPodnizovi(std::vector<double> v){
	Matrica n(v.size());
	int a=0;
	for(int i=0; i<v.size(); i++){
		if((i<(v.size()-1) && (v[i]>v[i+1] || fabs(v[i]-v[i+1])<0.0000000001)) || (i<(v.size()-1) && v[i]<v[i+1]) || (i==(v.size()-1) && (v[i]<v[i-1] || fabs(v[i]-v[i-1])<0.0000000001))) n[a].push_back(v[i]);
		if((i<(v.size()-1) && v[i]<v[i+1])) a++;
		
	} n.resize(a+1);
	for(int i=0; i<n.size(); i++){
		if(n[i].size()==1 || n[i].size()==0){
			n.erase(n.begin() + i);
			i--;
		}
	}
	return n;
}

int main ()
{	
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	int b=0;
	std::cout<<"Unesite elemente vektora: ";
	double x;
	std::vector<double> v;
	do{
		std::cin>>x;
		v.push_back(x);
		b++;
	}while(b<n);
	Matrica p;
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	p=RastuciPodnizovi(v);
	for(int i=0; i<p.size(); i++){
		for(int j=0; j<p[i].size(); j++){
			std::cout<<p[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	Matrica m;
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	m=OpadajuciPodnizovi(v);
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++){
			std::cout<<m[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}