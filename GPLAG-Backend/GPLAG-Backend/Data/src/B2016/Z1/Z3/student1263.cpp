/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
//#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

/*Matrica KreirajMatricu(int redovi, int kolone) {
   return Matrica(redovi, vector<int>(kolone));
}*/

Matrica RastuciPodnizovi(std::vector<double> v) {
	Matrica x;
	std::vector<double> pomocni;
	//int vel(v.size());
	for(int i=0; i<v.size()-1; i++) {
		if(v[i+1]>=v[i]) pomocni.push_back(v[i]);
		else{
			pomocni.push_back(v[i]);
			if(pomocni.size()>1) x.push_back(pomocni);
			pomocni.resize(0);
		}
	}
	pomocni.push_back(v[v.size()-1]);
	if(pomocni.size()>1) x.push_back(pomocni);
	/*for(int i=0; i<x.size(); i++) {
		if(x[i].size()==1) {
			x.erase(x.begin()+i);
		}
	}*/
	return x;
}

Matrica OpadajuciPodnizovi(std::vector<double> v) {
	Matrica x;
	std::vector<double> pomocni;
	//int vel(v.size());
	for(int i=0; i<v.size()-1; i++) {
		if(v[i+1]<=v[i]) pomocni.push_back(v[i]);
		else{
			pomocni.push_back(v[i]);
			if(pomocni.size()>1) x.push_back(pomocni);
			pomocni.resize(0);
		}
	}
	pomocni.push_back(v[v.size()-1]);
	if(pomocni.size()>1) x.push_back(pomocni);
	/*for(int i=0; i<x.size(); i++) {
		if(x[i].size()<2) {
			x.erase(x.begin()+i);
		}
	}*/
	return x;
}

int main ()
{	int n;
	Matrica a, b;
	std::vector<double> v;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	v.resize(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) std::cin>>v[i];
	a=RastuciPodnizovi(v);
	b=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(std::vector<double> red: a){
		for(double i: red) {
			std::cout<<i<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(std::vector<double> red: b){
		for(double i: red) {
			std::cout<<i<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}