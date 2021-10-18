
#include <iostream>
#include <vector>
#include<stdexcept>
#include<iomanip>

using std::vector;
typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(vector<double> v) {
	Matrica m(0);
	int i;
	std::vector<double> vektor;
	for (i=0; i<v.size()-1; i++) {
		vektor.resize(0);
		while(v[i]<=v[i+1]) {
			vektor.push_back(v[i]);
			i++;
			if(i==v.size()-1) break;
		}
		if(vektor.size()!=0) {
			vektor.push_back(v[i]);
			m.push_back(vektor);
		}
	}
return m;
}

Matrica OpadajuciPodnizovi(vector<double> v) {
	Matrica m(0);
	int i;
	std::vector<double> vektor;
	for (i=0; i<v.size()-1; i++) {
		vektor.resize(0);
		while(v[i]>=v[i+1]) {
			vektor.push_back(v[i]);
			i++;
			if(i==v.size()-1) break;
		}
		if(vektor.size()!=0) {
		vektor.push_back(v[i]);
		m.push_back(vektor);
		}
	}
return m;
}


int main ()
{
	vector<double> v;
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	v.resize(n);
	for(int i=0; i<n; i++) {
		std::cin>>v[i];
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	Matrica m=RastuciPodnizovi(v);
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m[i].size(); j++)
			std::cout<<std::setprecision(12)<<m[i][j]<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	Matrica op=OpadajuciPodnizovi(v);
	for(int i=0; i<op.size(); i++)  {
		for(int j=0; j<op[i].size(); j++)
			std::cout<<std::setprecision(12)<<op[i][j]<<" ";
		std::cout<<std::endl;
}
	return 0;
}