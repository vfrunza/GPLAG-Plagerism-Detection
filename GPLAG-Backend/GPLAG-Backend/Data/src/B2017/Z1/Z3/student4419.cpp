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

enum Smjer {Rastuci=1, Opadajuci=2};

bool StepenDvojke(int n){
    
    if(n==1) return true;
	if((n%2)!=0) return false;
	
	while((n%2)==0){
		
		n/=2;
	}
	
	if(n==1) return true;
	else
	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer a){
	
	std::deque<std::vector<int>> dek;
	
	if(a==1 && v.size()!=0){
		
		std::vector<int> pomocni;
		
		for(int i=0; i<v.size(); i++){
			
			if(v.size()==1) break;
			
		
		    if(v.size()==2){
					
				if(StepenDvojke(v.at(0))==true && StepenDvojke(v.at(1))==true && v.at(0)<v.at(1)) {
					pomocni.push_back(v.at(0));
					pomocni.push_back(v.at(1));
					dek.push_back(pomocni);
					break;
				}
				else break;
					
				}
			
			
			if(i==(v.size()-1)) {
				if(StepenDvojke(v.at(i))==true && v.at(i)>v.at(i-1)) {
					pomocni.push_back(v.at(i));
					dek.push_back(pomocni);
					break;
			}
			else {
				if(pomocni.size()!=0) dek.push_back(pomocni);
				break;
			}
			}
			
			
			if(StepenDvojke(v.at(i))==false) {
				i++;
				if(i==(v.size()-1)) return dek;
			}
			
			
			if(StepenDvojke(v.at(i))==true ){
				
				if(StepenDvojke(v.at(i+1))==true && v.at(i)<v.at(i+1)) pomocni.push_back(v.at(i));
				
				else{
					pomocni.push_back(v.at(i));
					if(pomocni.size()>1) dek.push_back(pomocni);
					pomocni.resize(0);
				}
			}
			
		}
		
	}
	
	if(a==2 && v.size()!=0){
		
			std::vector<int> pomocni;
		
		for(int i=0; i<v.size(); i++){
			
			if(v.size()==1) break;
			
		
		    if(v.size()==2){
					
				if(StepenDvojke(v.at(0))==true && StepenDvojke(v.at(1))==true && v.at(0)>v.at(1)) {
					pomocni.push_back(v.at(0));
					pomocni.push_back(v.at(1));
					dek.push_back(pomocni);
					break;
				}
				else break;
					
				}
			
			
			if(i==(v.size()-1)) {
				if(StepenDvojke(v.at(i))==true && v.at(i-1)>v.at(i)) {
					pomocni.push_back(v.at(i));
					dek.push_back(pomocni);
					break;
			}
			else {
				if(pomocni.size()!=0) dek.push_back(pomocni);
				break;
			}
			}
			
			
			if(StepenDvojke(v.at(i))==false) {
				i++;
				if(i==(v.size()-1)) return dek;
			}
			
			
			if(StepenDvojke(v.at(i))==true ){
				
				if(StepenDvojke(v.at(i+1))==true && v.at(i)>v.at(i+1)) pomocni.push_back(v.at(i));
				
				else{
					if(pomocni.size()!=0) {
						pomocni.push_back(v.at(i));
						dek.push_back(pomocni);
						pomocni.resize(0);
					}
					
				}
			}
			
		}
		
	}
		
	
	
	return dek;
}

int main ()
{
	int broj;
	int brojElemenata;
	std::vector<int>vektor ;
	std::cout << "Unesite broj elemenata vektora: " ;
	std::cin>>brojElemenata;
	std::cout << "Unesite elemente vektora: " ;
	for(int i=0; i<brojElemenata; i++){
		
    std::cin>> broj;
    vektor.push_back(broj);
	}
	int odabir;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>odabir;
	
	Smjer vrsta=Smjer(odabir);
	
	std::deque<std::vector<int>>rezultat;
	
	rezultat=MaksimalniPodnizoviStepenaDvojke(vektor, vrsta);
	
	if(vrsta==1) {
		std::cout << "Maksimalni rastuci podnizovi: "<<std::endl;
	
	for(int i=0; i<rezultat.size(); i++) {
		for(int j=0; j<rezultat.at(i).size(); j++) {
		std::cout << rezultat.at(i).at(j) << " " ;
		}
		std::cout << std::endl;
	}
	}
	
	else if(vrsta==2){
		std::cout << "Maksimalni opadajuci podnizovi: "<<std::endl ;
			for(int i=0; i<rezultat.size(); i++) {
		for(int j=0; j<rezultat.at(i).size(); j++) {
		std::cout << rezultat.at(i).at(j) << " " ;
		}
		std::cout << std::endl;
	}
	}
	

   
	return 0;
}