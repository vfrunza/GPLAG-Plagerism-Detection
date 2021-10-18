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
#include <vector>
#include <cmath>


enum Smjer {Rastuci, Opadajuci};

bool DaLiStepenDvojke(int broj){

	 	if (broj<1) return false;
	 	if (broj==1) return true;
	 	do {
	 		int ostatak(fabs(broj%2));
	 		if (ostatak!=0)
	 			return false;
	 		broj/=2;
	 	} while(broj!=1 && broj!=-1);
	 	return true;
	 
}

// slati element svakog vektora i vracati broj koji oznacava koliko je velik maksimalan podniz OD TOG ELEMENTA pa nadalje
int BrojElemUMaxPodnizuTrelementa (std::vector<int> v, int i, Smjer smjer){    
	int brojac(0);
	if (!DaLiStepenDvojke(v.at(i))) return 0;
	else {
	 brojac++;
	 i++;
	}



if(smjer==Rastuci){
	while(i<v.size() && DaLiStepenDvojke(v.at(i)) && (v.at(i) >= v.at(i-1))){
		brojac++;
		i++;
		
}
}
if(smjer==Opadajuci){
	while(i<v.size() && DaLiStepenDvojke(v.at(i)) && (v.at(i) <= v.at(i-1))){
		brojac++;
		i++;
		
	}
	
}

return brojac;
}


//glavna funkcija
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer smjer){

int velicinadeka=0;
std::deque<std::vector<int>> DEK;
for(int i=0; i < v.size()-1; i++){
	if(BrojElemUMaxPodnizuTrelementa(v, i, smjer) >= 2){
		velicinadeka++;
		DEK.resize(velicinadeka);
		for(int j=i; j < i+BrojElemUMaxPodnizuTrelementa(v,i,smjer); j++)
			DEK.at(velicinadeka-1).push_back(v.at(j));
		i+=BrojElemUMaxPodnizuTrelementa(v,i,smjer)-1;
}
}

	return DEK;
}

int main ()
{
	
	int  broj;
	std::cout<< "Unesite broj elemenata vektora: ";
	std::cin>> broj;
	
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> vektor;
		int broj1;

	for(int i=0; i<broj; i++){
		std::cin>> broj1;
		vektor.push_back(broj1);
		
	}

	 std::deque<std::vector<int>> novi_dek;
		int smjer1;
		std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
		std::cin>>smjer1;
		
		Smjer smjer;
		if (smjer1==1) smjer=Rastuci;
		if (smjer1==2) smjer=Opadajuci;
		
		novi_dek = MaksimalniPodnizoviStepenaDvojke(vektor, smjer);
		
		
		if(smjer1==Rastuci+1) {
			
		if(novi_dek.size()==0) std::cout<<"Nema maximalnih rastucih podnizova u vektoru.";
		else {
			std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
			
			for(std::vector<int> red : novi_dek){
				for(int x : red) std::cout<<x<<" ";

				std::cout <<std::endl;
			}
		
		
		}
		}	
		
		else{
			if(novi_dek.size()==0) std::cout<<"Nema maximalnih opadajucih podnizova u vektoru.";
			else{
				std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
			
					for(auto red: novi_dek){
						for(auto x : red) std::cout<<x<<" ";
						std::cout << std::endl;
					}
			}
		}
		
		return 0;
	}
	
	
	
	
	
