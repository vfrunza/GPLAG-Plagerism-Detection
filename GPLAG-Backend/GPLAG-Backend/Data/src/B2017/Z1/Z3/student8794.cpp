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
#include <cmath> 


enum Smijer {Rastuci=1, Opadajuci=2};

bool DaLiJeStepenBroja2(int broj){
	if (broj <= 0 ) return false;
	
	for (int i=0; i<31; i++){
		if (pow(2,i)==broj) return true;
	}
	return false;
}


std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smijer smijer ){

	std::deque<std::vector<int>> vrati;

	if (smijer == Rastuci){

 	//Rastuci 
 	std::vector<int> pomocniVektor;

		for (int i=0; i<v.size()-1; i++){
			if (DaLiJeStepenBroja2(v.at(i))) {
					std::vector<int>pomocniVektor;
					pomocniVektor.push_back (v.at(i));
					i++;
				if (DaLiJeStepenBroja2(v.at(i))==false || v.at(i)<v.at(i-1)){
				i--;
			
				continue;
			}
		
			while (i<v.size()-1 && DaLiJeStepenBroja2(v.at(i)) == true && v.at(i)>v.at(i-1)){
				pomocniVektor.push_back(v.at(i));
				i++;
			
				if (DaLiJeStepenBroja2(v.at(i)) == false || v.at(i)<v.at(i-1)){
					vrati.push_back(pomocniVektor);
				
					break;
				}
			}
			i--;
		}
	}
		
}

//Opadajuci
	else {
		for (int i=0; i<v.size()-1; i++){
			if (DaLiJeStepenBroja2(v.at(i))){
				std::vector<int>pomocniVektor;
				pomocniVektor.push_back(v.at(i));
			 	 if (i<v.size()-1) i++;
				
				if (i<v.size()-1 && (DaLiJeStepenBroja2(v.at(i))==false || v.at(i)>v.at(i-1))){
					i--;
					continue;
				}
				while (i<v.size()-1 && DaLiJeStepenBroja2(v.at(i)) == true && v.at(i)<v.at(i-1)){
					
					pomocniVektor.push_back(v.at(i));
			
				if (i<v.size()-1)	i++;
					
				
					if  ( DaLiJeStepenBroja2(v.at(i)) == false || v.at(i)>v.at(i-1)){
						vrati.push_back(pomocniVektor);
						break;
					}
				}
				i--;
			}
		}
	
	}
	return vrati;
}




int main ()
{
	int brElemenata;
	std::vector<int> v;
	
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>brElemenata;
	std::cout<<"Unesite elemente vektora: ";
	int element;
	for (int i=0; i<brElemenata; i++){
		std::cin>>element;
		v.push_back(element);
		
	}
	
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	
		int opcija;
	while(std::cin>>opcija){
		if (opcija == 1 || opcija == 2) break;
		else std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	
	if (opcija==1)
	{
		Smijer smijer=Smijer(opcija);
		std::deque<std::vector<int>> v1 = MaksimalniPodnizoviStepenaDvojke(v, smijer);
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
			for (int i=0; i<v1.size(); i++){
				for (int j=0; j<v1.at(i).size(); j++){
					std::cout<<v1.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	}
	
	
	else 
	{
		 Smijer smijer=Smijer(opcija);
		std::deque<std::vector<int>> v2 = MaksimalniPodnizoviStepenaDvojke(v, smijer);
			std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
			for (int i=0; i<v2.size(); i++){
				for (int j=0; j<v2.at(i).size(); j++){
					std::cout<<v2.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	}
	
	return 0;
}