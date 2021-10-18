/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector> 
std::vector<std::vector<double> > RastuciPodnizovi (std::vector<double> v) {
	std::vector<std::vector<double>> mat;
	if(v.size() == 0) return mat;
	std::vector<double> temp;
	for(int j=0; j<v.size()-1; j++){
		if(v[j]<=v[j+1]) {
			temp.push_back(v[j]);
		}
		if(v[j]>v[j+1]) {
			temp.push_back(v[j]);
			if(temp.size() <= 1){ temp.resize(0); continue;}
			mat.push_back(temp);
			temp.resize(0);
		}
	}
	if(v[v.size()-2]<=v[v.size()-1]){
		temp.push_back(v[v.size()-1]);
		if(temp.size() > 1) mat.push_back(temp);
	}
	return mat;
}
std::vector<std::vector<double> > OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double> > mat;
	if(v.size() == 0 ) return mat;
	std::vector<double> temp;
	for(int i=0; i<v.size()-1; i++){
		if(v[i]>=v[i+1]){
			temp.push_back(v[i]);
		}
		if(v[i]<v[i+1]){
			temp.push_back(v[i]);
			if(temp.size() <= 1){ temp.resize(0); continue;}
			mat.push_back(temp);
			temp.resize(0);
		}
	}
	if(v[v.size()-2]>=v[v.size()-1]){
		temp.push_back(v[v.size()-1]);
		if(temp.size() > 1) mat.push_back(temp);
	}
	return mat;
}
int main () 
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> v(n);
	for(int i=0;i<v.size();i++) {
		std::cin>> v[i];
	}
/*	std::cout<<"Vas vektor izgleda: ";
	for(int i=0;i=<v1.size();i++) {
		std::cout<<v1.at(i)<<" ";
	} */
	auto rez=RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0; i<rez.size(); i++){
		for(int j=0; j<rez[i].size(); j++){
			std::cout<<rez[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	auto opadajuci=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0; i<opadajuci.size(); i++){
		for(int j=0; j<opadajuci[i].size(); j++){
			std::cout<<opadajuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}