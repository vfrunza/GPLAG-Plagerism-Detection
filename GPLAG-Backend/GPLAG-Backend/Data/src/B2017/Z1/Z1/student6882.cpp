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
#include<vector>
#include<deque>
#include<cmath>
bool DaLiJeProst(int n)
{
	if(n<1)
	n=fabs(n);
	
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		return false;
	}
	return true;
}

std::vector<int>PretvorbaUTenarni(std::vector<int>v1)
{
	int t;
	std::deque<int>ternarni;
	std::vector<int> lista_ternarnih;
	int desetica = 10, novi_broj=0, parcaj=0;
	std::vector<int>simetricni;
	for(int x:v1)
	{
		// std::cout << "broj: "<<x << std::endl;
		if(x<0) parcaj = x*(-1);
		else parcaj = x;
		 do
		 {
		 	t=parcaj%3;
		 	ternarni.push_front(t);
		 	parcaj=parcaj/3;
		 }
		 while(parcaj!=0);
		 
		 //for(int i=0; i<ternarni.size();i++) std::cout << ternarni.at(i) << " ";
		 //std::cout << std::endl;

		int broj=ternarni.size()-1;
		bool jest_simetrican = true;
		for(int i=0;i<ternarni.size()/2;i++)
		{
		   	if(ternarni.at(i)!=ternarni.at(broj-i))
		   	{
		   		jest_simetrican = false;
		   	}
		}
		// std::cout << "jest simetrican:" << jest_simetrican << std::endl;
		if(jest_simetrican) simetricni.push_back(x);
		ternarni.clear();
	}
	return simetricni;
	
}


std::vector<int>IzdvojiSimetricneTernarne(std::vector<int>v,bool f)
{
	std::vector<int>prosti;
	std::vector<int>slozeni;
	for(int x:v)
	{
		if(DaLiJeProst(x))
		prosti.push_back(x);
		
		else
		slozeni.push_back(x);
	}
	if(f) return PretvorbaUTenarni(prosti);
	else return PretvorbaUTenarni(slozeni);
}


int main ()
{
	std::vector<int>vektor;
	int n;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do
	{
		std::cin>>n;
		if(n!=-1) vektor.push_back(n);
	}
	while(n!=-1);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int br;
	do
	{
		
		std::cin>>br;
		if(br!= 0 && br!=1) std::cout << "Neispravan unos! Unesite ponovo: ";
	}while(br!=1 && br!=0);
	
	std::vector<int>brojevi=IzdvojiSimetricneTernarne(vektor,br);
	
	if(brojevi.size()==0 && br==1) {
		std::cout <<  "Nema prostih simetricnih brojeva u vektoru."<< std::endl; 
		return 0;
	}
	if(brojevi.size()==0 && br==0){
	std::cout <<  "Nema slozenih simetricnih brojeva u vektoru."<< std::endl; 
	return 0;
	} 
	
	if(br == 1) std::cout << "Prosti simetricni brojevi iz vektora su: ";
	else std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	for(int i=0; i<brojevi.size();i++)
	{
		if(i==brojevi.size()-1) std::cout << brojevi.at(i)<<".";
		else std::cout<< brojevi.at(i)<<", ";
	}
	std::cout << std::endl;


	
	
	return 0;
}