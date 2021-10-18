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
#include <cmath>
#include <deque>
#include <vector>

typedef std::deque<std::vector<int>>DekVektora;

bool DaLiJeStepenDvojke(int broj){
    int i;
    
    for(i=1; i<broj; i*=2){
    	if(broj==pow(2,i) ) return true; 
    	
}
if(broj==i)return true;
return false;
}

std::vector<int>Vektor_Stepen_Dvojke(std::vector<int>v){
	std::vector<int>v1;
	
	for(int i=0; i<v.size(); i++){
		if(DaLiJeStepenDvojke(v[i])==true) v1.push_back(v[i]);
	}
	return v1;
}

DekVektora MaksimalniPodnizoviStepenaDvojke(std::vector<int>v, bool ind ){
	DekVektora rastuci;
    DekVektora opadajuci;
	std::vector<int> v1=Vektor_Stepen_Dvojke(v); 
    
    //int a=0;
    
    for(int i=0; i<=v.size(); i++){
    	for(int j=i+1; j<=v.size(); j++){
    		if(v[j]>v[i]) { rastuci.push_back(v[i]); break; }
    	  }
    }
    
    
   /*  for(int i=0; i<rastuci.size(); i++){
    	for(int j=i+1; j<rastuci.size(); j++){
    		if(rastuci[i]==rastuci[j]) {  rastuci.erase(rastuci.begin()+j); i--;  break;}
    	}
    }*/
   
    
    return rastuci;
    
	
	
}

int main (){
	int broj;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>broj;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int>y;
	
	for(int i=0; i<broj; i++){
		int x;
		std::cin>>x;
		y.push_back(x);
	}
	int n;
    std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    std::cin>>n;
   enum Smjer {Rastuci=1, Opadajuci=0};
   // MaksimalniPodnizoviStepenaDvojke(y,n);
    
	//std::cout<<DaLiJeStepenDvojke(broj);
    //std::vector<int>v1=Vektor_Stepen_Dvojke(y);
    DekVektora<int>z;
  //  z=MaksimalniPodnizoviStepenaDvojke(y,1);
    //std::vector<int>z=Vektor_Stepen_Dvojke(y);
    
   
    
    for(int i=0; i<z.size(); i++){
    	std::cout<<MaksimalniPodnizoviStepenaDvojke([i])<<" ";
    }
    
    
	return 0;
}