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
#include<vector>
#include<deque>
#include<cmath>

enum Smjer {Rastuci=false,Opadajuci=true};

bool daLiJePotencijaDvice(int broj)
{
	if(broj==0 || broj<0) return false;
	while(broj!=1){
		if(broj%2!=0) return false;
		broj/=2;
	}
	return true;
}


std::deque<std::deque<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> vektor_brojeva, Smjer smjer)
{
	std::deque<std::deque<int>> matrica_rastucih_opadajucih;
		std::deque<int> niz_rastucih_opadajucih;
		for(int i=0; i< vektor_brojeva.size()-1; i++)
		{
		 if(smjer == true)
		 {
		 	if(vektor_brojeva.at(i)<vektor_brojeva.at(i+1))
			 {
			 	bool potencijaDvice= true;
			 	do
			 	{
			 		
			 		if(!daLiJePotencijaDvice(vektor_brojeva.at(i))){
			 			potencijaDvice = false;
			 			break;
			 		} 
			 		niz_rastucih_opadajucih.push_back(vektor_brojeva.at(i));
			 		if(i==vektor_brojeva.size()-1 || i==vektor_brojeva.size()) break;
			 		else i++;
			 		
			 	}while(i<vektor_brojeva.size()-1 && vektor_brojeva.at(i)<vektor_brojeva.at(i+1));
			 	
			 	if(daLiJePotencijaDvice(vektor_brojeva.at(i)) && potencijaDvice==true) niz_rastucih_opadajucih.push_back(vektor_brojeva.at(i));
				if(niz_rastucih_opadajucih.size()>1) matrica_rastucih_opadajucih.push_back(niz_rastucih_opadajucih);
			 	niz_rastucih_opadajucih.clear();
			 }
		 }
		 else
		 {
		 	if(vektor_brojeva.at(i)>vektor_brojeva.at(i+1))
			 {
			 	bool potencijaDvice= true;
			 	do
			 	{
			 		
			 		if(!daLiJePotencijaDvice(vektor_brojeva.at(i))){
			 			potencijaDvice = false;
			 			break;
			 		} 
			 		niz_rastucih_opadajucih.push_back(vektor_brojeva.at(i));
			 		if(i==vektor_brojeva.size()-1 || i==vektor_brojeva.size()) break;
			 		else i++;
			 		
			 	}while(i<vektor_brojeva.size()-1 && vektor_brojeva.at(i)>vektor_brojeva.at(i+1));
			 	
			 	if(daLiJePotencijaDvice(vektor_brojeva.at(i)) && potencijaDvice==true) niz_rastucih_opadajucih.push_back(vektor_brojeva.at(i));
				if(niz_rastucih_opadajucih.size()>1) matrica_rastucih_opadajucih.push_back(niz_rastucih_opadajucih);
			 	niz_rastucih_opadajucih.clear();
			 }
		 }
		}	
	
	
	return matrica_rastucih_opadajucih;
	
}


int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	std::vector<int> brojevi ;
	int broj;
	for(int i=0; i<n;i++) 
	{
		std::cin >> broj;
		brojevi.push_back(broj);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> n;
	Smjer s = Smjer(n);
	std::deque<std::deque<int>> vel;
	vel = MaksimalniPodnizoviStepenaDvojke(brojevi, s);
	if(n==1) std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	else std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(int i=0;i<vel.size(); i++)
	{
		for(int j=0; j<vel.at(i).size();j++)
		{
			std::cout << vel.at(i).at(j) <<" ";
		}
		std::cout << std::endl;
	}
	return 0;
}