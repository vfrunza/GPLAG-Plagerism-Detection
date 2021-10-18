/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

#include<iostream>
#include<vector>
#include<cmath>
#include <iomanip>

bool JesuLiJednaki(double x, double y, double Eps=1e-10){
	return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
if((x<0 && y>0 )|| (x>0 && y<0)) return false;
}

std::vector<std::vector<double>>RastuciPodnizovi(std::vector<double>v)
{
	std::vector<std::vector<double>>mat;
	if(v.size()!=0){
	for(int i=0; i<v.size()-1; i++) {
		int b=0;
		std::vector<double>novi;
		while((v[i]<=v[i+1]|| JesuLiJednaki(v[i],v[i+1])) && i<v.size()-1) {
			b++;
			if(b==1) novi.push_back(v[i]);
			novi.push_back(v[i+1]);
			if(i==v.size()-2)break;
			i++;
		}
		if(novi.size()>1)
			mat.push_back(novi);
	}
	}
	return mat;
}


std::vector<std::vector<double>>OpadajuciPodnizovi(std::vector<double>v)
{
	std::vector<std::vector<double>>mat;
  if(v.size()!=0){
	for(int i=0; i<v.size()-1; i++) {
		std::vector<double>novi;
		int b {0};
		while((v[i]>=v[i+1] || JesuLiJednaki(v[i],v[i+1])) && i<v.size()-1) {
			b++;
			if(b==1)novi.push_back(v[i]);
			novi.push_back(v[i+1]);
			if(i==v.size()-2)break;
			i++;
		}
		if(novi.size()>1)
			mat.push_back(novi);
	}
  }
	return mat;
}



int main ()
{
	int m;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>m;
	std::vector<double>v(m);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<m; i++)std::cin>>v[i];
	auto matrica1=RastuciPodnizovi(v);
	auto matrica2=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(std::vector<double> red: matrica1) {
		for(double x : red)std::cout<<std::setprecision(12)<<x<<" ";
		std::cout<<std::endl;
	}

	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(std::vector<double> red : matrica2) {
		for(double x : red) std::cout<<std::setprecision(12)<<x<<" ";
		std::cout<<std::endl;
	}
	return 0;
}