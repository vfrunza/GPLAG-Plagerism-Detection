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

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	int n(v.size());
	std::vector<std::vector<double>> povratni;
	
	/*for(int i=0;i<n;i++){
		if(v[i+1]<v[i]){
			br++;
			if(br>=2){
				if(br==2){
					povratni[br1][br-2]=v[i-1];
				}
				povratni[br1][br-1]=v[i];
			}
		}
		if(v[i+1]==v[i] && br>=2){
			if(v[i]<v[i-1]){
				br++;
				povratni[br1][br-1]=v[i];
			}
		}
		if(v[i]<v[i+1] && br>=2){
			if(v[i]<v[i-1]){
				br++;
				povratni[br1][br-1]=v[i];
			}
			if(v[i]<v[i+1] && v[i+1]>=v[i+2]){
			povratni[br1].resize(br);
			br1++;
			br=0;
			}
		}
	}
	povratni.resize(br1);
	*/
	int pocetakOpadajuci;
	std::vector<double> storage;
	for(int i=0;i<n-1;i++){
		pocetakOpadajuci=i;
		if(v[i]>=v[i+1]){
			while(v[i]>=v[i+1] && i<n-2) i++;
			int krajOpadajuci(i);
			
			
			if(i==n-2) krajOpadajuci++;
			for(int j=pocetakOpadajuci;j<=krajOpadajuci;j++){
				storage.push_back(v[j]);
				
			}
			povratni.push_back(storage);
			storage.resize(0);
		}
	}
	
	return povratni;
}
std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	int n(v.size()), br(0), br1(0);
	std::vector<std::vector<double>> povratni(n, std::vector<double>(n));
	
	
	for(int i=0;i<n;i++){
		if(v[i+1]>v[i]){
			br++;
			if(br>=2){
				if(br==2){
					povratni[br1][br-2]=v[i-1];
				}
				povratni[br1][br-1]=v[i];
			}
		}
		if(v[i+1]==v[i]){
			if(v[i]>v[i-1]){
				br++;
				povratni[br1][br-1]=v[i];
			}
		}
		if(v[i]>v[i+1]){
			if(v[i]>v[i-1]){
				br++;
				povratni[br1][br-1]=v[i];
			}
		}
		if(v[i]>v[i+1] && v[i+1]<=v[i+2]){
			povratni[br1].resize(br);
			br1++;
			br=0;
		}
	}
	povratni.resize(br1);
/*	for(int i=0;i<povratni.size();i++){
		for(int j=0;j<povratni[i].size();j++){
			std::cout<<povratni[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	for(int i=0;i<povratni.size();i++){
	std::cout<<"velicina i: "<<povratni.size()<<" velicina j: "<<povratni[i].size()<<std::endl;
	}*/
	return povratni;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> v(n);
	
	for(int i=0;i<n;i++){
		std::cin>>v[i];
	}
	
	std::vector<std::vector<double>> Rastuci;
	Rastuci=RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0;i<Rastuci.size();i++){
		for(int j=0;j<Rastuci[i].size();j++){
			std::cout<<Rastuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>> Opadajuci;
	Opadajuci=OpadajuciPodnizovi(v);
	
	for(int i=0;i<Opadajuci.size();i++){
		for(int j=0;j<Opadajuci[i].size();j++){
			std::cout<<Opadajuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	return 0;
}