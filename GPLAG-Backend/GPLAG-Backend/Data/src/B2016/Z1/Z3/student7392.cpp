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
#include <limits>
#include <iomanip>

bool poredi(double x, double y){
	const double eps=1e-10;
	if((x>0 && y<0)||(x<0 && y>0))return false;
	return fabs(x-y)<eps*(fabs(x)+fabs(y));
}

std::vector<std::vector<double> > RastuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double> > r;
	std::vector<double> temp;
	for(int i=0;i<v.size();i++){
		if(i+1==v.size())break;
		while(v[i+1]>v[i] || v[i+1]==v[i] || poredi(v[i], v[i+1])){
			temp.push_back(v[i]);
			i++;
			if(i+1==v.size()){
				break;
			}
		}
		if(temp.size()!=0){
			temp.push_back(v[i]);
			r.push_back(temp);
		}
		temp.clear();
	}
	return r;
}

std::vector<std::vector<double> > OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double> > r;
	std::vector<double> temp;
	for(int i=0;i<v.size();i++){
		if(i+1==v.size())break;
		while(v[i+1]<v[i] || v[i+1]==v[i] || poredi(v[i], v[i+1])){
			temp.push_back(v[i]);
			i++;
			if(i+1==v.size()){
				break;
			}
		}
		if(temp.size()!=0){
			temp.push_back(v[i]);
			r.push_back(temp);
		}
		temp.clear();
	}
	return r;
}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double> a;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		double temp;
		std::cin>>temp;
		a.push_back(temp);
	}
	std::cout<<"Maksimalni rastuci podnizovi: \n";
	std::vector<std::vector<double> > f=RastuciPodnizovi(a);
	for(auto i:f){
		for(auto j:i){
			std::cout<<j<<" ";
		}
		std::cout<<"\n";
	}
	std::cout<<"Maksimalni opadajuci podnizovi: \n";
	f=OpadajuciPodnizovi(a);
	for(auto i:f){
		for(auto j:i){
			std::cout<<j<<" ";
		}
		std::cout<<"\n";
	}
	return 0;
}