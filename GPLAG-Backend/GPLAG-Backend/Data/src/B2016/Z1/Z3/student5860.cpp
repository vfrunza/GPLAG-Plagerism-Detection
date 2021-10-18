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

std::vector<std::vector<double>> izbaci_praznine(std::vector<std::vector<double>> dobijeni_vektor, int broj_punih){
	std::vector<std::vector<double>> povratni_vektor(broj_punih);
	for(int i=0; i<broj_punih; i++){
		povratni_vektor[i]=dobijeni_vektor[i];
	}
	return povratni_vektor;
}
std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double>vektor){
int prvi_element_pv=0;
	std::vector<std::vector<double>> povratni_vektor(30);
	int length=vektor.size();
	for (int i=0; i<length-1; i++){
		if (vektor[i]>=vektor[i+1]){                                    //polje jedan
			povratni_vektor[prvi_element_pv].push_back(vektor[i]);			//polje dva
			povratni_vektor[prvi_element_pv].push_back(vektor[i + 1]);
			int a=1; 
			int kraj=1;
			for(int j=2+i; j<length; j++){
				if(povratni_vektor[prvi_element_pv][a]>=vektor[j] && kraj==1){    //polje jedan
					povratni_vektor[prvi_element_pv].push_back(vektor[j]);
					a++; i=j;
				}
				else{
					kraj=0;
				}
			}
			prvi_element_pv++;
		}
	}
	std::vector<std::vector<double>>vraceni_vektor=izbaci_praznine(povratni_vektor, prvi_element_pv);
	return vraceni_vektor;
}

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> vektor){
	int prvi_element_pv(0);
	std::vector<std::vector<double>> povratni_vektor(30);
	for(int i=0; i<vektor.size()-1; i++){
		if(vektor[i]<=vektor[i+1]){
			povratni_vektor[prvi_element_pv].push_back(vektor[i]);
			povratni_vektor[prvi_element_pv].push_back(vektor[i+1]);
			int a(1), kraj(1);
			for(int j=i+2; j<vektor.size(); j++){
				if((povratni_vektor[prvi_element_pv][a]<=vektor[j]) && kraj==1){
					povratni_vektor[prvi_element_pv].push_back(vektor[j]);
					a++; i=j;
				}
				else{
					kraj=0;
				}
			}
			prvi_element_pv++;
		}
	}
	std::vector<std::vector<double>> vraceni_vektor(izbaci_praznine(povratni_vektor, prvi_element_pv));
	return vraceni_vektor;
}


int main ()
{
	std::vector<double> vektor;
	int duzina_vektora;
	int unos_u_vektor;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>duzina_vektora;
	for(int i=0; i<duzina_vektora; i++){
		std::cin>>unos_u_vektor;
		vektor.push_back(unos_u_vektor);
	}
    std::cout<<"Unesite elemente vektora: ";
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>> rastuci_vektor(RastuciPodnizovi(vektor));
	for(int I=0; I<rastuci_vektor.size(); I++){
		for(int J=0; J<rastuci_vektor[I].size(); J++){
			std::cout<<rastuci_vektor[I][J]<<" ";
		}
		std::cout<<std::endl;
	}
    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>> finalni_vektor(OpadajuciPodnizovi(vektor));
	for(int i=0; i<finalni_vektor.size(); i++){
		for(int j=0; j<finalni_vektor[i].size(); j++){
			std::cout<<finalni_vektor[i][j]<<" ";
		}
		std::cout<<std::endl;
	}	
	
	return 0;
}