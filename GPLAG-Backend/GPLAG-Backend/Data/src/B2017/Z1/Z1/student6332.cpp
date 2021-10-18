/*B 2017/2018, Zadaća 1, Zadatak 1
	
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

bool DaLiJeProst(int broj){
	int i;
	for(i=2; i<broj; i++){
		if(broj%i==0)return false;
	}
	if(broj==i)return true;
}

std::vector<int>Prost_Slozen(std::vector<int>v, bool p){
	std::vector<int>novi_prosti;
	std::vector<int>novi_slozeni;
		
	for(int i=0; i<v.size(); i++){
	   for(int j=2; j<=v.at(i); j++){
	   	if(DaLiJeProst(v.at(i))){
	   		novi_prosti.push_back(v.at(i));
	   		break;
	   	}
	   	else if(!DaLiJeProst(v.at(i))){
	   		novi_slozeni.push_back(v.at(i));
	   		break;
	   	}
	   	  }
	}
	if(p==false) return novi_slozeni;
	else return novi_prosti;
	
}

int Simetricni(int broj){
	int okrenut=0;
	while(broj>0){
		okrenut=okrenut*10+broj%10;
		broj=broj/10;
	}
	return okrenut;
}


int PretvoriUTernarni(int broj){
	int ternarni=0;
	int cifra;
	while(broj>0){
		 cifra=broj%3;
	     ternarni=ternarni*10+cifra;
		 broj/=3;
	}
	return Simetricni(ternarni);
}

std::vector<int>IzdvojiSimetricneTernarne(std::vector<int>v, bool p){
	
	std::vector<int>c;
	for(int i=0; i<v.size();i++){
	if ((Simetricni (PretvoriUTernarni(v.at(i))) == PretvoriUTernarni(v.at(i)))) c.push_back(v.at(i));
}
return c;
}

int main (){
	
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int>a;
	for(;;){
		int b;
		std::cin>>b;
		if(b==-1) break;
		a.push_back(b);
		
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int x;
	
	for(;;){
	    
		
	    std::cin>>x;
	    if(x==0 || x==1) break;
		else if(x!=0 || x!=1)std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
   std::vector<int>novi=Prost_Slozen(a,x);
   std::vector<int>d=IzdvojiSimetricneTernarne(novi,x);
   
  
   
   if(x==1){
   	if(d.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
   	if(d.size()!=0){
   std::cout<<"Prosti simetricni brojevi iz vektora su: ";
   for(int i=0; i<d.size()-1; i++){
   	std::cout<<d.at(i)<<", ";
   }
   std::cout<<d.at(d.size()-1)<<".";
     }
   }
   else if(x==0){
   	if(d.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru."; 
   	if(d.size()!=0){
   	std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
   for(int i=0; i<d.size()-1; i++){
   	std::cout<<d.at(i)<<", ";
   }
   std::cout<<d.at(d.size()-1)<<".";
   }
   
   }
   
  
   return 0;
}






