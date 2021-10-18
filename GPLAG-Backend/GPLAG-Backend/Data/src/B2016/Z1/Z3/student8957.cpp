/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9. 
	
*/
#include <iostream>
#include <vector>
#include <iomanip>

std::vector<std::vector<double>>OpadajuciPodnizovi(std::vector<double>v){
	std::vector<std::vector<double>>mat;
	std::vector<double>pomocni;
	int brojredova(0);
	for (int i=0;i<int(v.size())-1;i++){
		pomocni.resize(0);
		 while (i<int(v.size())-1 && v[i]>=v[i+1]){
		 	pomocni.push_back(v[i]);
		 	i++;
		 }
		
		 if (pomocni.size()>=1){
		 	pomocni.push_back(v[i]);
		 	mat.resize(mat.size()+1);
		 	mat[brojredova].resize(pomocni.size());
		 	mat[brojredova]=pomocni;
		 	brojredova++;
		 }
	}
	return mat;
}
std::vector<std::vector<double>>RastuciPodnizovi(std::vector<double>v){
	std::vector<std::vector<double>>mat;
	std::vector<double> pomocni;
	int brojredova(0);
	for (int i=0;i<int(v.size())-1;i++) {
		pomocni.resize(0);
		while (i<int(v.size())-1 && v[i]<=v[i+1]){
			pomocni.push_back(v[i]);
			i++;
		}
		
		if (pomocni.size()>=1){
			pomocni.push_back(v[i]);
			mat.resize(mat.size()+1);
			mat[brojredova].resize(pomocni.size());
			mat[brojredova]=pomocni;
			brojredova++;
		}
	}
	return mat;
}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double>v;
	double broj;
	for (int i=0;i<n;i++){
		std::cin>>broj;
		v.push_back(broj);
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>>rastu(RastuciPodnizovi(v));
	for (int i=0;i<rastu.size();i++){
		for (int j=0;j<rastu[i].size();j++){
			std::cout<<std::setprecision(12)<<rastu[i][j]<<" ";
		} 
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>>opadaju(OpadajuciPodnizovi(v));
	for (int i=0;i<opadaju.size();i++){
		for (int j=0;j<opadaju[i].size();j++){
			std::cout<<std::setprecision(12)<<opadaju[i][j]<<" ";
		}
		std::cout<<std::endl;
	}

	return 0;
}