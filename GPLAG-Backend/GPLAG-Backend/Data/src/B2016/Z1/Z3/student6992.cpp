/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include <vector>
std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> v1;
	std::vector<double> pomocni;
	int k=0;
	for(int i=0;i<v.size();i++){
		if(i!=0 && v[i]<v[i-1]){
			if(pomocni.size()>1){
				v1.resize(v1.size()+1);
				for(int j=0;j<pomocni.size();j++)
				v1[k].push_back(pomocni[j]);
				k++;
			}
			pomocni.resize(0);
		}
		pomocni.push_back(v[i]);
		if(i==v.size()-1 && pomocni.size()>1){
			v1.resize(v1.size()+1);
			for(int j=0;j<pomocni.size();j++)
			v1[k].push_back(pomocni[j]);
		}
	}
	return v1;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> v1;
	std::vector<double> pomocni;
	int k=0;
	for(int i=0;i<v.size();i++){
		if(i!=0 && v[i]>v[i-1]){
			if(pomocni.size()>1){
				v1.resize(v1.size()+1);
				for(int j=0;j<pomocni.size();j++)
				v1[k].push_back(pomocni[j]);
				k++;
			}
			pomocni.resize(0);
		}
		pomocni.push_back(v[i]);
		if(i==v.size()-1 && pomocni.size()>1){
			v1.resize(v1.size()+1);
			for(int j=0;j<pomocni.size();j++)
			v1[k].push_back(pomocni[j]);
		}
	}
	return v1;
}
int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double>v(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++)
	std::cin>>v[i];
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>> v1;
	v1=RastuciPodnizovi(v);
	for(int i=0;i<v1.size();i++){
	for(int j=0;j<v1[i].size();j++){
	std::cout<<v1[i][j]<<" ";
	}
	std::cout<<std::endl;
	}
	std::cout<<std::endl;
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>> v2;
	v2=OpadajuciPodnizovi(v);
	for(int i=0;i<v2.size();i++)
	for(int j=0;j<v2[i].size();j++)
	std::cout<<v2[i][j]<<" ";
	
	return 0;
}