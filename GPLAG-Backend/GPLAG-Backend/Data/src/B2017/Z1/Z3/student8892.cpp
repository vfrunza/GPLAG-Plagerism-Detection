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
#include <deque>
#include<vector>
#include <cmath>

typedef std::deque<std::vector<int>> Matrica;

bool StepenDvojke (int za_testiranje){

		for(int j = 0; j < za_testiranje; j ++){
			if(za_testiranje == pow(2, j)) return true;
		}
	
	return false;
}
std::vector<int> Pokusaj (std::vector<int> pokusaj){
	std::vector<int> v;
	for(int i = 0; i < pokusaj.size(); i ++){
		for(int j = 0; j < 10; j++){
			if(pokusaj.at(i) == pow(2,j)) v.push_back(pokusaj.at(i));
		}
	}
	
	return v;
}
enum Smjer {Rastuci, Opadajuci} ;

Matrica MaksimalniPodnizoviStepenaDvojke(std::vector<int> primljeni, Smjer trazeni_smjer){
	
	Matrica m;
	std::vector<int> vektor_stepena_dvojke = primljeni;
//	Smjer trazeni_smjer;
//	if( vrijednost == true) trazeni_smjer = Rastuci;
	int i (0);
	
	if(trazeni_smjer == Rastuci){
		while(i != vektor_stepena_dvojke.size()){
			std::vector<int> pomocni;
			if(i != vektor_stepena_dvojke.size() - 1 && vektor_stepena_dvojke.at(i + 1) >= vektor_stepena_dvojke.at(i) ){
				while(i != vektor_stepena_dvojke.size() - 1 && vektor_stepena_dvojke.at(i + 1) >= vektor_stepena_dvojke.at(i) && StepenDvojke(vektor_stepena_dvojke.at(i))){
					pomocni.push_back(vektor_stepena_dvojke.at(i));
					i++;
					if(i + 1 <= vektor_stepena_dvojke.size() - 1 && vektor_stepena_dvojke.at(i) > vektor_stepena_dvojke.at(i + 1) && vektor_stepena_dvojke.at(i) >= vektor_stepena_dvojke.at(i - 1)){
					 pomocni.push_back(vektor_stepena_dvojke.at(i));
				
					}
					if( i == vektor_stepena_dvojke.size() - 1 && vektor_stepena_dvojke.at(i) >= vektor_stepena_dvojke.at(i - 1)){
					pomocni.push_back(vektor_stepena_dvojke.at(i));
					break;
					}
				}
			pomocni = Pokusaj(pomocni);	
			if(pomocni.size() > 0)
			m.push_back(pomocni);
			}	
			else i ++;
		}
	}
	else {
		
		while(i != vektor_stepena_dvojke.size()){
			std::vector<int> pomocni;
			if(i != vektor_stepena_dvojke.size() - 1 && vektor_stepena_dvojke.at(i + 1) <= vektor_stepena_dvojke.at(i)){
				while(i != vektor_stepena_dvojke.size() - 1 && vektor_stepena_dvojke.at(i + 1) <= vektor_stepena_dvojke.at(i) ){
					pomocni.push_back(vektor_stepena_dvojke.at(i));
					i++;
					if(i + 1 <= vektor_stepena_dvojke.size() - 1 && vektor_stepena_dvojke.at(i) <= vektor_stepena_dvojke.at(i + 1) && vektor_stepena_dvojke.at(i) <= vektor_stepena_dvojke.at(i - 1) ){
						pomocni.push_back(vektor_stepena_dvojke.at(i));
					}
					
					if((i == vektor_stepena_dvojke.size() - 1 && vektor_stepena_dvojke.at(i) <= vektor_stepena_dvojke.at(i - 1))  && StepenDvojke(vektor_stepena_dvojke.at(i))){
						pomocni.push_back(vektor_stepena_dvojke.at(i));
						break;
					}
				
				}
				pomocni = Pokusaj(pomocni);
				m.push_back(pomocni);
			}
			else 
		}
	}
return m;
}

int main(){
	std::cout << "Unesite broj elemenata vektora: ";
	int broj_elemenata;
	std::cin >> broj_elemenata;
	std::cout << "Unesite elemente vektora: ";
	std::vector<int> pocetni;
	
	for(int i = 0; i < broj_elemenata; i++){
		int element;
		std::cin >> element;
		pocetni.push_back(element);
	}
	
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int jedan_ili_dva;
	std::cin >> jedan_ili_dva;
	
	if(jedan_ili_dva == 1){
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		Matrica Rastuci_podnizovi = MaksimalniPodnizoviStepenaDvojke(pocetni, Rastuci);
		for(int i = 0; i < Rastuci_podnizovi.size(); i++){
			for(int j = 0; j < Rastuci_podnizovi.at(i).size(); j++){
				std::cout<< Rastuci_podnizovi.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		Matrica Opadajuci_podnizovi = MaksimalniPodnizoviStepenaDvojke(pocetni, Opadajuci);
		for(int i = 0; i < Opadajuci_podnizovi.size(); i++){
			for(int j = 0; j < Opadajuci_podnizovi.at(i).size(); j++){
				std::cout << Opadajuci_podnizovi.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	}
//	std::cout<< std::endl
	return 0;
}

