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
#include <cmath>


std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool p){
	std::vector<int> a;
	if(p==true){
	  for(int x : v){
		int y=abs(x);
		bool prost(true);
		for(int i=2;i<y;i++){
			if(y%i==0){
				prost=false;
				break;
			}
		}
		if(prost==true && x!=1) a.push_back(x);
	  }
	}
	else{
		for(int x : v){
		int y=abs(x);
		bool prost(true);
		for(int i=2;i<y;i++){
			if(y%i==0){
				prost=false;
				break;
			}
		}
		if(prost==false && x!=1) a.push_back(x);
	  }
	}
		
std::vector<int>b;
for(int m=0;m<a.size();m++)	{
	int n=abs(a.at(m));
	int niz[100],i(0),broj(0),obrnut(0);
	while(n!=0){
		niz[i]=n%3;
		i++;
		n=n/3;
	}
	int s=i-1;
	for(int k=0;k<i;k++){
		obrnut+=niz[k]*pow(10,s);
		s--;
	}
	
	for(int j=i-1;j>=0;j--){
		broj+=niz[j]*pow(10,j);
	}
	
	if(broj==obrnut) b.push_back(a.at(m));
}


	return b;
}


int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	int n;
	do{
	   std::cin>>n;
	   if(n==-1) break;
	   else v.push_back(n);
	}while(n!=-1);
    
    int prost;	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
   
	std::cin>>prost;
	while(prost!=1 && prost!=0){
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>prost;
	}

	std::vector<int> a(IzdvojiSimetricneTernarne(v,prost));
	if(a.size()==0){
	  if(prost==1) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	  else std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	}
	else{
	  if(prost==1) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	  else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	  for(int i=0;i<a.size();i++){
		if(i!=a.size()-1) std::cout<<a.at(i)<<", ";
		else std::cout<<a.at(i)<<".";
	  } 
	}
	return 0;
}