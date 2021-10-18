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

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> matrica;
	const double eps(1e-10);
	if(v.size()>1){
		for(int i=0;i<v.size()-1;i++){
			if(v[i]<v[i+1] || std::fabs(v[i]-v[i+1])<=eps*(std::fabs(v[i]) + std::fabs(v[i+1]))){
				matrica.resize(matrica.size()+1);
				int j=matrica.size()-1;
				while(i<v.size()-1 && (v[i]<v[i+1] ||  std::fabs(v[i]-v[i+1])<=eps*(std::fabs(v[i])+std::fabs(v[i+1])))){
					matrica[j].push_back(v[i]);
					i++;
				}
				if(i==v.size()) break;
				matrica[j].push_back(v[i]);
			}
		}
	}
	return matrica;
}

std::vector<std::vector<double>>OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> mat;
	const double eps(1e-10);
	if(v.size()>1){
		for(int i=0;i<v.size()-1;i++){
			if(v[i]>v[i+1] || std::fabs(v[i]-v[i+1])<=eps*(std::fabs(v[i]) + std::fabs(v[i+1]))){
				mat.resize(mat.size()+1);
				int j=mat.size()-1;
				while(i< v.size()-1 && (v[i]>v[i+1] || std::fabs(v[i]-v[i+1])<=eps*(std::fabs(v[i])+std::fabs(v[i+1])))){
					mat[j].push_back(v[i]);
					i++;
				}
				if(i==v.size()) break;
				mat[j].push_back(v[i]);
			}
		}
	}
	return mat;
}
int main ()
{
	std::cout<< "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	if(!std::cin){
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		return 0;
	}
	if(!(std::cin.peek()=='\n' || std::cin.peek()== ' ')) return 0;
	if(n<=1) return 0;
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> v;
	for(int i=0;i<n;i++){
		double x;
		std::cin >> x;
		v.push_back(x);
	}
	std::vector<std::vector<double>> v1=RastuciPodnizovi(v);
	std::vector<std::vector<double>> v2=OpadajuciPodnizovi(v);
	std::cout << "Maksimalni rastuci podnizovi: "<< std::endl;
	for(int i=0;i<v1.size();i++){
		for(int j=0;j<v1[i].size();j++){
			std::cout << v1[i][j] << " ";
		}
			std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: "<< std::endl;
	for(int i=0;i<v2.size();i++){
		for(int j=0;j<v2[i].size();j++){
			std::cout << v2[i][j] << " ";
		}
			std::cout << std::endl;
	}
	return 0;
}