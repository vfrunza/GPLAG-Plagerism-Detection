/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>

std::vector<std::vector<double>>RastuciPodnizovi(std::vector<double>polazni){
	std::vector<std::vector<double>>matrica;
	std::vector<double>pomocni;
	pomocni.push_back(polazni[0]);
	for(int i=1;i<polazni.size();i++){
		if(polazni[i]>=polazni[i-1]) 
		pomocni.push_back(polazni[i]);
		else{
			if(pomocni.size()>1) matrica.push_back(pomocni);
			
			pomocni.resize(0);
			pomocni.push_back(polazni[i]);
		}
	}
	if(pomocni.size()>1) matrica.push_back(pomocni);
	return matrica;
}

std::vector<std::vector<double>>OpadajuciPodnizovi(std::vector<double>polazni){
	std::vector<std::vector<double>>matrica;
	std::vector<double>pomocni;
	pomocni.push_back(polazni[0]);
	for(int i=1;i<polazni.size();i++){
		if(polazni[i]<=polazni[i-1])
		pomocni.push_back(polazni[i]);
		else{
			if(pomocni.size()>1) matrica.push_back(pomocni);
			
			pomocni.resize(0);
			pomocni.push_back(polazni[i]);
		}
	}
	if(pomocni.size()>1) matrica.push_back(pomocni);
	return matrica;
}

int main ()
{
	int n;
	double k;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double>v;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		std::cin>>k;
		v.push_back(k);
	}
	std::vector<std::vector<double>>mat1,mat2;
	mat1=RastuciPodnizovi(v);
	mat2=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: ";
	std::cout<<std::endl;
	for(int i=0;i<mat1.size();i++){
		for(int j=0;j<mat1[i].size();j++){
			std::cout<<mat1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: ";
	std::cout<<std::endl;
	for(int i=0;i<mat2.size();i++){
		for(int j=0;j<mat2[i].size();j++){
			std::cout<<mat2[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	
	
	
	return 0;
}