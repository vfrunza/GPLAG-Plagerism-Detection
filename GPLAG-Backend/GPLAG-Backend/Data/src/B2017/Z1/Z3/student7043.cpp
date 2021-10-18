/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <deque>

enum Smjer {Rastuci=1,Opadajuci=2};
typedef std::deque<std::vector<int> > dek_vektora;

bool je_stepen_broja_dva(int a){
	if (a<=0){
		return 0;
	}else {
		return !(a & (a-1));
	}
}

dek_vektora MaksimalniPodnizoviStepenaDvojke(std::vector<int> v,Smjer mono ){
	std::vector<int> v1;
	dek_vektora dv;
	for(int i=0;i<v.size();i++){
		if (mono==Rastuci){
		if (i==v.size()-1){
			if (v.at(v.size()-1)>v.at(v.size()-2) && je_stepen_broja_dva(v.at(v.size()-1)) && je_stepen_broja_dva(v.at(v.size()-2))){
				v1.push_back(v.at(v.size()-1));
				dv.push_back(v1);
				return dv;
			} else{
				
			}       
		} else 
		if (v.at(i)<v.at(i+1) && je_stepen_broja_dva(v.at(i)) && je_stepen_broja_dva(v.at(i+1))){ 
			v1.push_back(v.at(i));
			}else {
				if (v1.size()>=1 && je_stepen_broja_dva(v.at(i))){
				v1.push_back(v.at(i));
				dv.push_back(v1);
				}
				v1.clear();
			}
		}
	}
	for(int i=0;i<v.size();i++){
		if (mono==Opadajuci)
		{
			if (i==v.size()-1)
			{
				if (v.at(v.size()-1)<v.at(v.size()-2) && je_stepen_broja_dva(v.at(v.size()-1)) && je_stepen_broja_dva(v.at(v.size()-2)))
				{
					v1.push_back(v.at(v.size()-1));
					dv.push_back(v1);
					return dv;
				} 
				else
				{
					
				}       
			} 
			else if (v.at(i)>v.at(i+1) && je_stepen_broja_dva(v.at(i)) && je_stepen_broja_dva(v.at(i+1)))
			{ 
				v1.push_back(v.at(i));
			}
			else 
			{
				if (v1.size()>=1 && je_stepen_broja_dva(v.at(i))){
				v1.push_back(v.at(i));
				dv.push_back(v1);
				}
				v1.clear();
			}
			
		}
	}
}


int main ()
{                      
    Smjer mono;
	std::vector<int> v;
	dek_vektora dv;
	std::cout <<"Unesite broj elemenata vektora: ";
	int broj_elemenata;
	std::cin >> broj_elemenata;
	std::cout <<"Unesite elemente vektora: ";
	for (int i=0;i<broj_elemenata;i++){
		int unos;
		std::cin >> unos;
		v.push_back(unos);                                                                            
	}
	std::cout <<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int tip_podniza;
	std::cin >> tip_podniza;
	if (tip_podniza==1) mono=Rastuci;
	else mono=Opadajuci;
	dv=MaksimalniPodnizoviStepenaDvojke(v,mono);
	if (tip_podniza==1)
	std::cout <<"Maksimalni rastuci podnizovi: "<<std::endl;
	else std::cout <<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for (auto i:dv){
		for (auto j : i){
			std::cout <<j<<" ";
		}
		std::cout <<std::endl;
	}
	return 0;
}