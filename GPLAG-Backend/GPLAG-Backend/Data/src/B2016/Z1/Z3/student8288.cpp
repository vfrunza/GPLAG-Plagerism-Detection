#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <stdexcept>

const double eps(1e-10);
typedef std::vector<std::vector<double>> Matrica;

    Matrica RastuciPodnizovi(std::vector<double> v) {
	  Matrica m;
	  int k(0);
	  int i;
	  if(v.size()==0) return Matrica(v.size(),std::vector<double>(v.size()));
	  if(v.size()==1) return Matrica (v.size()-1,std::vector<double>(v.size()-1));
	  for(i=0;i<v.size()-1;i++) {
	       if(v.at(i)-v.at(i+1)<eps) {
	       	  m.resize(m.size()+1);
	         	while(v[i]-v[i+1]<eps) {
	         	m[k].push_back(v[i]);
	              i++;
	              if(i>v.size()-2) break;
	         	}
	         	m[k].push_back(v[i]);
	         	k++;
			}
	  }
	return m;
}

Matrica OpadajuciPodnizovi(std::vector<double> t) {
	Matrica v;
	int g(0);
	int j;
 if(t.size()==0)  return Matrica(t.size(),std::vector<double>(t.size()));
 if(t.size()==1) return Matrica(t.size()-1,std::vector<double>(t.size()-1));
	for(j=0;j<t.size()-1;j++) {
	  if(t.at(j)-t.at(j+1)>(-eps)) {
			v.resize(v.size()+1);
			while(t[j]-t[j+1]>=(-eps)) {
				v[g].push_back(t[j]);
				j++;
				if(j>t.size()-2) break;
			}
			v[g].push_back(t[j]);
			g++;
		}
	}
	return v;
}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	if(n<0) std::cout<<"Broj elemenata vektora mora biti pozitivan!"<<std::endl;
	else {
	std::vector<double> k(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++) {
		std::cin>>k[i];
	}
	try {
	auto a(RastuciPodnizovi(k));
	auto b(OpadajuciPodnizovi(k));
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(std::vector<double> j: a) {
		for(double x: j) {
			std::cout<<x <<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(std::vector<double> z: b) {
		for(double y: z) {
			std::cout<<y<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
	}
		catch(std::out_of_range izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
		}
	}
	return 0;
}