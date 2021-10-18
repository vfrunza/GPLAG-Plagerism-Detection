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
#include <iomanip>
#include <cmath>


bool DaLiJeProst (int n){
	if(n<=0 || n==1) return false;
	for(int i(2);i<n;i++){
		if(n%i==0) return false;
	} return true;
}


int PretvoriUTernarni (int n){
     int terarnibr=0;
     
     do{
     	 int p;
     	 p=n%3;
     	 terarnibr=terarnibr*10+p;
     	 n/=3;
     	
     } while(n!=0);
 return terarnibr;
}

bool DaLiJeSimetrican (int broj){
	std::vector<int> cifrice;
	broj=PretvoriUTernarni(broj);
	while(broj!=0){
		int c=broj%10;
		cifrice.push_back(c);
		broj/=10;
	} std::vector<int>Obrnuto(cifrice.size());
	  int broj_cifara=cifrice.size();
	  for( int i(0);i<broj_cifara;i++){
	    Obrnuto.at(i)=cifrice.at(broj_cifara-1-i);
	    if(Obrnuto.at(i)!=cifrice.at(i)) return false;
	  }
	     return true;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int>a,bool prost_je){
	std::vector<int> t;
	
	if(prost_je==true) {
		for(int i(0);i<a.size();i++){
			if(DaLiJeSimetrican(a.at(i))==true  && DaLiJeProst(a.at(i))==true ) t.push_back(a.at(i));
		} 
	}
	 if(prost_je==false) {
		for(int i(0);i<a.size();i++){
			if(DaLiJeSimetrican(a.at(i))==true && DaLiJeProst(a.at(i))==false)
				t.push_back(a.at(i));
		} 
	}  return t;
}


int main ()
{
	int n;
	std::vector<int>a;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
    do{
    	std::cin>>n;
    	if(n!=-1) a.push_back(n);
    } while(n!=-1);
    int k;
    std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    std::cin>>k;
    while(k!=0 && k!=1){
     std::cout<<"Neispravan unos! ";	
     std::cout<<"Unesite ponovo: ";
     std::cin>>k;
    }
    if(k==1){
    	if(IzdvojiSimetricneTernarne(a,true).size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru";
    	else
    std::cout<<"Prosti simetricni brojevi iz vektora su: ";
    for(int i(0);i<IzdvojiSimetricneTernarne(a,true).size();i++){
    	if(i==IzdvojiSimetricneTernarne(a,true).size()-1)
    	std::cout<<IzdvojiSimetricneTernarne(a,true)[i];
    	else std::cout<<IzdvojiSimetricneTernarne(a,true)[i]<<", ";
    } 
    std::cout<<".";
    std::cout<<std::endl;
    }
    
     if(k==0){
     if(IzdvojiSimetricneTernarne(a,false).size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru";
     else
    std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
    for(int i(0);i<IzdvojiSimetricneTernarne(a,false).size();i++){
    	if(i==IzdvojiSimetricneTernarne(a,false).size()-1)
    	std::cout<<IzdvojiSimetricneTernarne(a,false)[i];
    	else std::cout<<IzdvojiSimetricneTernarne(a,false)[i]<<", ";
    } 
    std::cout<<".";
    std::cout<<std::endl;
   }
	return 0;
}