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


enum Smjer{Opadajuci, Rastuci};

bool StepenDvojke(int broj){
	if(broj<0) return false;
	while(broj%2==0){
		broj/=2;
	}
	if(broj==1) return true;
	return false;
}


std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> V, Smjer OR){
	std::deque<std::vector<int>> V1;
	
	if(OR==Opadajuci){
		for(int i=0;i<V.size() - 1;i++){
			if(StepenDvojke(V.at(i)) && StepenDvojke(V.at(i+1)) && V.at(i) > V.at(i+1) ){
				std::vector<int> V2;
				V2.push_back(V.at(i));
				while(StepenDvojke(V.at(i)) && StepenDvojke(V.at(i+1)) && V.at(i) > V.at(i+1) && (i+1) < V.size() - 1){
					V2.push_back(V.at(i + 1)); i++;
				}
				if(StepenDvojke(V.at(i)) && StepenDvojke(V.at(i+1)) && V.at(i) > V.at(i+1) && (i+1) == V.size() - 1){
					V2.push_back(V.at(i + 1));
				}
				V1.push_back(V2);
			}
		}
		
	}
	else {
		for(int i=0; i<V.size() - 1; i++){
			if(StepenDvojke(V.at(i)) && StepenDvojke(V.at(i+1)) && V.at(i) < V.at(i+1)){
				std::vector<int> V2;
				V2.push_back(V.at(i));
				while(StepenDvojke(V.at(i)) && StepenDvojke(V.at(i+1)) && V.at(i) < V.at(i+1) && (i+1) < V.size() - 1){
					V2.push_back(V.at(i+1)); i++;
				}
				if(StepenDvojke(V.at(i)) && StepenDvojke(V.at(i+1)) && V.at(i) < V.at(i+1) && (i+1) == V.size() - 1){
					V2.push_back(V.at(i+1));
				}
				V1.push_back(V2);
			}
		}
		
		
	}
	return V1;
}


int main ()
{
	int broj;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>broj;
	std::vector<int> V;
	std::cout<<"Unesite elemente vektora: ";
	for(int i = 0; i < broj; i++){
		int broj2;
		std::cin>>broj2;
		V.push_back(broj2);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int A;
	std::cin>>A;
	Smjer s;
	if(A==1){
		s=Rastuci;
	}
	else if(A==2) s=Opadajuci;
	
	std::deque<std::vector<int>> V1 = MaksimalniPodnizoviStepenaDvojke(V, s);
	if(A==1){
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	}
	else if(A==2) std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	
	for(int i = 0; i<V1.size(); i++ ){
		for(int j = 0; j<V1.at(i).size(); j++){
			std::cout<<V1.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}