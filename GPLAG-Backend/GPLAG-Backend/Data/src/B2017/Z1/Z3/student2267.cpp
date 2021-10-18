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
#include<vector>

enum Smjer{Rastuci,Opadajuci};
bool stepenDvice(int broj){
	if(broj<1) return false;
	while(broj>1){
		if(broj%2!=0) return false;
		broj/=2;
	}
	return true;
}

std::deque<std::vector<int>>MaksimalniPodnizoviStepenaDvojke(std::vector<int> brojevi,Smjer smjer) {
	std::deque<std::vector<int>> podnizovi;
	int broj1,broj2,broj3;
	int i;
	std::vector<int> pomocni;
	
	if(smjer==Smjer::Rastuci)	{
		for(i=0; i<brojevi.size();i++) {
			broj1=brojevi.at(i);
			if(stepenDvice(broj1)==true && i!=brojevi.size()-1){
				broj2=brojevi.at(i+1);
				pomocni.resize(0);
				if(stepenDvice(broj2)==true && (broj2>=broj1)) {
					pomocni.push_back(broj1);
					pomocni.push_back(broj2);
					for(i=i+2;i<brojevi.size();i++)
					{
						broj3=brojevi.at(i);
						if(stepenDvice(broj3)==true && broj2<=broj3) {
							pomocni.push_back(broj3);
							broj2=broj3;
						}
						else break;
					}
					i--;
				}
				if (pomocni.size()>1) {
					podnizovi.push_back(pomocni);
				}
				
			}
		}
	}
	if(smjer==Smjer::Opadajuci) {
					
		for(i=0;i<brojevi.size();i++)
			{
			broj1=brojevi.at(i);
			if(stepenDvice(broj1)==true && i!=brojevi.size()-1) {
				broj2=brojevi.at(i+1);
				pomocni.resize(0);
				if(stepenDvice(broj2)==true && broj1>=broj2) {
					pomocni.push_back(broj1);
					pomocni.push_back(broj2);
					for(i=i+2;i<brojevi.size(); i++) {
						broj3=brojevi.at(i);
						if(stepenDvice(broj3)==true && broj2>=broj3) {
							pomocni.push_back(broj3);
							broj2=broj3;
							}
						else break;
						}
					i--;
					}
					if(pomocni.size()>1) {
						podnizovi.push_back(pomocni);
					}
				}
			}
		}
	return podnizovi;				
}				

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	
	std::vector<int> elementi;
	std::deque<std::vector<int>> podnizovi;
	int n,a,broj;
	Smjer m;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++)
	{
		std::cin>>broj;
		elementi.push_back(broj);
	
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>a;
	if(a==1) m=Rastuci;
	else if(a==2) m=Opadajuci;
	else std::cout<<"Pogresan unos";
	
	podnizovi=MaksimalniPodnizoviStepenaDvojke(elementi,m);
	if(podnizovi.size()==0)
	std::cout<<"Dati niz nema podnnizove";
	else
	{
		if(a==1) std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		else if(a==2) std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		for(int i=0; i<podnizovi.size();i++)
		{
			for(int j=0; j<podnizovi.at(i).size(); j++)
			{
				std::cout<<podnizovi.at(i).at(j)<<" ";
		
			}
			std::cout<< std::endl;
		}
	}
	
	
	return 0;
}