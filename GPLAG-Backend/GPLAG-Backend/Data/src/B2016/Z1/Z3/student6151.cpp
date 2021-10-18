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

std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> vekt){
	std::vector<std::vector<double>> rez;
	
		
     for(int j=0;j<vekt.size()-1;){
    
		if(vekt[j]<=vekt[j+1]){
			std::vector<double> pomocni;
			pomocni.push_back(vekt[j]);
		while(j<vekt.size()-1 && vekt[j]<=vekt[j+1]){
		 pomocni.push_back(vekt[j+1]);
			j++; 
		}
			rez.push_back(pomocni);
		}
		else j++;
     }
	return rez;
} 

std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> vekt){
	std::vector<std::vector<double>> rez;
		
     for(int j=0;j<vekt.size()-1;){
    
		if(vekt[j]>=vekt[j+1]){
			std::vector<double> pomocni;
			pomocni.push_back(vekt[j]);
		while(j<vekt.size()-1 && vekt[j]>=vekt[j+1]){
		 pomocni.push_back(vekt[j+1]);
			j++; 
		}
			rez.push_back(pomocni);

		}
		else j++;
     }
	return rez;
}

int main ()
{
	
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	
	std::vector<double> vekt;
	std::cout<<"Unesite elemente vektora: ";
	
	int broj;
	for(int i=0;i<n;i++){
	std::cin>>broj;
	vekt.push_back(broj);
	}
	
	std::vector<std::vector<double>> ras;
	ras=RastuciPodnizovi(vekt);
	
	std::vector<std::vector<double>> opd;
	opd=OpadajuciPodnizovi(vekt);


	std::cout<<"Maksimalni rastuci podnizovi: ";
	std::cout<<"\n";
	
	for(int i=0;i<ras.size();i++){
		for(int j=0;j<ras.at(i).size();j++){
			std::cout<<ras[i][j]<<" ";
		}
		std::cout<<"\n";
	}
	
	
	std::cout<<"Maksimalni opadajuci podnizovi: ";
	std::cout<<"\n";
	
		for(int i=0;i<opd.size();i++){
		for(int j=0;j<opd.at(i).size();j++){
			std::cout<<opd[i][j]<<" ";
		}
		std::cout<<"\n";
	} 
	return 0;
}