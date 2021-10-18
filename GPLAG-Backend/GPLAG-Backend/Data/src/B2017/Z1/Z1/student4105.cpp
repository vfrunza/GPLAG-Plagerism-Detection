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
#include <deque>
#include <cmath>

bool DaLiJeProst(int broj)
{
	
	for(int i=2;i<sqrt(broj)+1;i++){
		
	if(broj % i == 0){
		return false;
	}
	
	}
	return true;
}

std::deque<int> Ternarni(int broj)
{
	std::deque<int> NoviBr;
	
	while(broj!=0)
	{
	int ostatak=broj%3;
	broj/=3;
	NoviBr.push_front(ostatak);
	}
	return NoviBr;
}
bool Simetricno(std::deque<int> D1)
{
	for(int i=0;i<D1.size()/2;i++)
	{
		if(D1.at(i)!=D1.at(D1.size()-1-i))
		{
			return false;
		}
	}
	return true;
}

std::vector<int> IzdvojiSimentricneTernarne(std::vector<int> v1, bool tacno)
{
	std::vector<int> v2;
	
	for(int x :  v1)
	{
		if(DaLiJeProst(x)==tacno)
		{
			std::deque<int> D=Ternarni(x);
			if(Simetricno(D)==true) v2.push_back(x);
		}
	}
	return v2;
}

int main ()
{
	int broj;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> Brojevi;
	for(;;)
	{
		std::cin>>broj;
		if(broj==-1) break;
		Brojevi.push_back(broj);
	}
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int ProSl;
	for(;;){
		std::cin>>ProSl;
	if(ProSl==0 || ProSl==1) break;
	else std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	
	std::vector<int> v3;
	v3=IzdvojiSimentricneTernarne(Brojevi, ProSl);
	
    if(ProSl==1){
    if(v3.size()==0)	std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
    else {
    	
    
    	
    
	std::cout << "Prosti simetricni brojevi iz vektora su: ";
    
     {
		for(int i = 0; i<v3.size(); i++){
			if(i == v3.size() - 1 ) std::cout << v3[i] << ".";
		else std::cout << v3[i] << ", ";
	}
	return 0;
    }
    }
    
	}
	else if(ProSl==0)  { if(v3.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else {
		std::cout<<"Slozeni simetricni brojevi iz vektora su: "; 
		for(int i = 0; i<v3.size();i++){
		if(i == v3.size() - 1) std::cout << v3[i] << ".";
		else  std::cout << v3[i] << ", ";
		
	}
	}	
		return 0;
}
}
