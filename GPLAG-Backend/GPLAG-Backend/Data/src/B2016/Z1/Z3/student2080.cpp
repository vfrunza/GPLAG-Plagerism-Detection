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
typedef std::vector<std::vector<double>> Matrica;
bool DaLiSuJednaki(double x,double y,double EPS=1e-10){
	return std::fabs(x-y)<=EPS*(std::fabs(x)+std::fabs(y));
}
Matrica RastuciPodnizovi(std::vector<double>v){
	Matrica mat;
	int j(1);
	for(int i(0);i<v.size()-1;i++){
		if(v.at(i)<=v.at(i+1) || DaLiSuJednaki(v.at(i),v.at(i+1))){
			std::vector<double>a;
		while(v.at(i)<=v.at(i+1) || DaLiSuJednaki(v.at(i),v.at(i+1))){
			a.push_back(v.at(i));
			i++;
			if(i==v.size()-1)break;
		}a.push_back(v.at(i));
		mat.resize(j);
		for(int k(0);k<a.size();k++){
				mat[j-1].push_back(a.at(k));
				if(k==a.size()) break;
		}
		j++;
		if(i==v.size()-1)break;
	}
	}
	return mat;
}
Matrica OpadajuciPodnizovi(std::vector<double>v){
	Matrica mat;
	int j(1);
	for(int i(0);i<v.size()-1;i++){
		if(v.at(i)>=v.at(i+1) || DaLiSuJednaki(v.at(i),v.at(i+1))){
			std::vector<double>a;
			while(v.at(i)>=v.at(i+1) || DaLiSuJednaki(v.at(i),v.at(i+1))){
				a.push_back(v.at(i));
				i++;
				if(i==v.size()-1)break;
			}
			a.push_back(v.at(i));
			mat.resize(j);
			for(int k(0);k<a.size();k++){
			mat[j-1].push_back(a.at(k));
			if(k==a.size()) break;
			}
			j++;
			if(i==v.size()-1)break;
		}
	}
	return mat;
}
int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::vector<double>v;
	std::cout<<"Unesite elemente vektora: ";
	double element;
	for(int i(0);i<n;i++){
		std::cin>>element;
		v.push_back(element);
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	Matrica a;
	a=RastuciPodnizovi(v);
	for(int j(0);j<a.size();j++){
		for(int k(0);k<a[j].size();k++){
			std::cout<<a[j][k]<<" ";
			if(k==a[j].size()) break;
		}
		if(j==a.size()) break;
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	Matrica b;
	b=OpadajuciPodnizovi(v);
	for(int j(0);j<b.size();j++){
		for(int k(0);k<b[j].size();k++){
			std::cout<<b[j][k]<<" ";
			if(k==b[j].size()) break;
		}
		if(j==b.size()) break;
		std::cout<<std::endl;
	}
	return 0;
}