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

Matrica DodajUMatricu(Matrica m, std::vector<double> v) {
	m.resize(m.size()+1);
	for(int i=0; i<v.size(); i++) {
		m[m.size()-1].push_back(v[i]);
	}
	return m;
}

Matrica RastuciPodnizovi(std::vector<double> v) {
	Matrica m;
	std::vector<double> novi;
	
	for(int i=0; i<v.size(); i++) {
		if(i<v.size()-1 && (v[i]<=v[i+1] || v[i]>v[i+1])) {
			novi.push_back(v[i]);
		}
		if(novi.size()>0 && novi[0]>novi[novi.size()-1]) {
			novi.resize(0);
			i--;
			continue;
		}
		if(i+1==v.size()-1 && v[i]<=v[i+1])
				novi.push_back(v[i+1]);
		if(i==0)
			continue;
		else if(i==v.size()-1 && novi.size()>1)
			m=DodajUMatricu(m, novi);
		else if(i<v.size()-1 && v[i]>v[i+1] && novi.size()>1 && novi[0]<=novi[novi.size()-1]) {
			m=DodajUMatricu(m,novi);
			novi.resize(0);
		}
		
	}
	return m;
}

Matrica OpadajuciPodnizovi(std::vector<double> v) {
	Matrica m;
	std::vector<double> novi;
	
	for(int i=0; i<v.size(); i++) {
		if(i<v.size()-1 && (v[i]>=v[i+1] || v[i]<v[i+1])) {
			novi.push_back(v[i]);
		}
		if(novi.size()>0 && novi[0]<novi[novi.size()-1]) {
			novi.resize(0);
			i--;
			continue;
		}
		if(i+1==v.size()-1 && v[i]>=v[i+1])
				novi.push_back(v[i+1]);
		if(i==0)
			continue;
		else if(i==v.size()-1 && novi.size()>1)
			m=DodajUMatricu(m, novi);
		else if(i<v.size()-1 && v[i]<v[i+1] && novi.size()>1 && novi[0]>=novi[novi.size()-1]) {
			m=DodajUMatricu(m,novi);
			novi.resize(0);
		}
	}
	return m;
}

int main ()
{
	
	Matrica R, O;
	std::vector<double> v;
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		int clan;
		std::cin>>clan;
		v.push_back(clan);
	}
	R=RastuciPodnizovi(v);
	O=OpadajuciPodnizovi(v);
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	
	for(int i=0; i<R.size(); i++) {
		for(int j=0; j<R[i].size(); j++)
			std::cout<<R[i][j]<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	
	for(int i=0; i<O.size(); i++) {
		for(int j=0; j<O[i].size(); j++)
			std::cout<<O[i][j]<<" ";
		std::cout<<std::endl;
	}
	
	return 0;
}