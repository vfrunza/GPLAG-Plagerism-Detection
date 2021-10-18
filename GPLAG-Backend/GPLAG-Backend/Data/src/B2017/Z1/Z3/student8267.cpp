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
#include <cmath>

enum Smjer{Rastuci=1,Opadajuci=2};
typedef std::vector<int> Vektor;

bool StepenDvojke(int x)
{
	int p(1);
		for(int i(0);i<=30;i++){
		if(x==p) return true;
		p=p*2;
		}
        return false;
}
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(Vektor v,Smjer smjer)
{
	Vektor v2;
	Vektor v3;
	std::deque<std::vector<int>> dek;
	if(v.size()==0) return dek;
	if(smjer==Rastuci){
	for(int i(0);i<v.size()-1;i++)
	{
		v3.clear();
		if(StepenDvojke(v.at(i))) v3.push_back(v.at(i));
		else continue;
		if(v.at(i)<=v.at(i+1)&&StepenDvojke(v.at(i+1))) v3.push_back(v.at(i+1));
		else continue;
		i++;
		while(i<v.size()-1&&v.at(i)<v.at(i+1)&&StepenDvojke(v.at(i+1)))
		{
			v3.push_back(v.at(i+1));
			i++;
		}
	    dek.push_back(v3);
	}
	}
	if(smjer==Opadajuci){
	for(int j(0);j<v.size()-1;j++)
	{
		v3.clear();
		if(StepenDvojke(v.at(j))) v3.push_back(v.at(j));
		else continue;
		if(v.at(j)>=v.at(j+1)&&StepenDvojke(v.at(j+1))) v3.push_back(v.at(j+1));
		else continue;
		j++;
		while(j<v.size()-1&&v.at(j)>v.at(j+1)&&StepenDvojke(v.at(j+1)))	
		{
			v3.push_back(v.at(j+1));
			j++;
		}
		dek.push_back(v3);
	}
	}

	return dek;
	
}
int main ()
{
	Vektor v;
	int broj_clanova;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>broj_clanova;

	int unos;
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0);i<broj_clanova;i++)
	{
	std::cin>>unos;
	v.push_back(unos);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    int smjer_naziv;
    std::cin>>smjer_naziv;
	if(smjer_naziv==1) 
	{
		std::cout<<"Maksimalni rastuci podnizovi: ";
		std::cout<<std::endl;
		std::deque<std::vector<int>> dek(MaksimalniPodnizoviStepenaDvojke(v,Rastuci));
		for(int i(0);i<dek.size();i++){
		 if(dek.at(i).size()>1){
		 for(int j(0);j<dek.at(i).size();j++)
		  std::cout<<dek.at(i).at(j)<<" ";	
		  std::cout<<std::endl;
		 }
		 }
	}
	if(smjer_naziv==2)
	{
		std::cout<<"Maksimalni opadajuci podnizovi: ";
		std::cout<<std::endl;
		std::deque<std::vector<int>> dek(MaksimalniPodnizoviStepenaDvojke(v,Opadajuci));
		for(int k(0);k<dek.size();k++){
		 if(dek.at(k).size()>1){
		 for(int l(0);l<dek.at(k).size();l++)
		 	std::cout<<dek.at(k).at(l)<<" ";
		 	std::cout<<std::endl;
		 }
		 }
    }
	return 0;
}