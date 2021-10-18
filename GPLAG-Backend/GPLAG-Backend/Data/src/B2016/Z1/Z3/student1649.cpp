/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include<iostream>
#include<vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> VektorBrojeva){
	std::vector<std::vector<double>> VektorVektora;
	int NoPodniz(0);
	for(int i=0; i<(int(VektorBrojeva.size())-1); i++){
		int kraj;
		if(VektorBrojeva.at(i+1)>=VektorBrojeva.at(i)){
			kraj=i+1;
			while(kraj<(int(VektorBrojeva.size())-1)) if(VektorBrojeva.at(kraj+1)>=VektorBrojeva.at(kraj)) kraj++; else break;
		} else continue;
		VektorVektora.push_back(std::vector<double>());
		while(i<=kraj) VektorVektora.at(NoPodniz).push_back(VektorBrojeva.at(i++));
		NoPodniz++;
		i--;
	}
	return VektorVektora;
}
std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> VektorBrojeva){
	std::vector<std::vector<double>> VektorVektora;
	int NoPodniz(0);
	for(int i=0; i<(int(VektorBrojeva.size())-1); i++){
		int kraj;
		if(VektorBrojeva.at(i+1)<=VektorBrojeva.at(i)){
			kraj=i+1;
			while(kraj<(int(VektorBrojeva.size())-1)) if(VektorBrojeva.at(kraj+1)<=VektorBrojeva.at(kraj)) kraj++; else break;
		} else continue;
		VektorVektora.push_back(std::vector<double>());
		while(i<=kraj) VektorVektora.at(NoPodniz).push_back(VektorBrojeva.at(i++));
		NoPodniz++;
		i--;
	}
	return VektorVektora;
}
int main ()
{
	int br;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>br;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> VektorBrojeva(br);
	for(int i=0;i<VektorBrojeva.size();i++) std::cin>>VektorBrojeva[i];
	auto VektorRastucih(RastuciPodnizovi(VektorBrojeva));
	auto VektorOpadajucih(OpadajuciPodnizovi(VektorBrojeva));
	std::cout<<"Maksimalni rastuci podnizovi: ";
	for(auto x: VektorRastucih){
		std::cout<<"\n";
		for(auto y: x){
			std::cout<<y<<" ";
		}
	}
	std::cout<<"\nMaksimalni opadajuci podnizovi: ";
	for(auto x: VektorOpadajucih){
		std::cout<<"\n";
		for(auto y: x){
			std::cout<<y<<" ";
		}
	}
	return 0;
}