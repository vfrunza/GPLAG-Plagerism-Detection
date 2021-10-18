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
#include <iomanip>

typedef std::vector<int> Vektor;
typedef std::deque<Vektor> Dek;
enum Smjer{gore,dole}smjer;

bool DaLiJeStepen(int broj){
	bool djeljivi;
	if (broj == 1) return true;
	while(broj != 0){
		if(broj % 2 == 0) {
		    broj/=2;
		    if(broj == 1) return true;
		}
		else{
		    djeljivi=false;
		    break;
		}
	}
	if(djeljivi==true) return true;
	 return false;
}

Dek MaksimalniPodnizoviStepenaDvojke(Vektor v,Smjer smjer){
    
    Dek dek;
    int m(0), n(0), h(0);
    
    for(int i=0; i<v.size()-1; i++)
	{
		if((smjer==Smjer(0) && v.at(i)<=v.at(i+1) && DaLiJeStepen(v.at(i)) && DaLiJeStepen(v.at(i+1))) || (smjer==Smjer(1) && v.at(i)>=v.at(i+1) && DaLiJeStepen(v.at(i)) && DaLiJeStepen(v.at(i+1))))
		{	
			dek.resize(m+1);
			dek.at(m).resize(n+2);
			dek.at(m).at(n)=v.at(i);
			dek.at(m).at(n+1)=v.at(i+1);
			n++;
			h++;
		}
		else {
			if(h>0)
			{
				m++;
				h=0;
			}
			n=0;
		}
	}    
    return dek;
}

int main ()
{
	int n,unos;
	Vektor v;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		int x;
		std::cin>>x;
		v.push_back(x);
	}
	
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>unos;
	if(unos == 1){
		smjer=Smjer(0);
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	}
	else if(unos == 2){
		smjer=Smjer(1);
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	}
		
	Dek dek(MaksimalniPodnizoviStepenaDvojke(v,smjer));
	for(Vektor red : dek){
		for(int x : red)std::cout<<x<<" ";
		std::cout<<std::endl;
	}
	return 0;
	

}