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

enum Smjer{Rastuci, Opadajuci};

bool StepenDvojke(int n){
	int stepen=1;
	for(;;){
		if(n==stepen)return true;
		if(n<stepen)return false;
		stepen*=2;
	}
}
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer monotonost){
		
	std::deque<std::vector<int>> d;
	
	
	
	for(int i(0);i<v.size();i++)
	{		
		std::vector<int> pom;
		if(StepenDvojke(v.at(i))){
			
			pom.push_back(v.at(i));
			
			for(int j(i); j<v.size();j++)
			{
				if(monotonost==Smjer::Rastuci && i!=j){
					if(StepenDvojke(v.at(j)) && pom.at(pom.size()-1)<=v.at(j) )pom.push_back(v.at(j));
					else {
						i=j-1;
						break;
					}
				}
				if(monotonost==Smjer::Opadajuci && i!=j){
					
					if(StepenDvojke(v.at(j)) && pom.at(pom.size()-1)>=v.at(j))
						pom.push_back(v.at(j));
						
					else {
						i=j-1;
						break;
					}
				}
			}
		}
		if(pom.size()>=2) d.push_back(pom);
	}
	return d;
}


int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::vector<int> v(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0);i<n;i++){
		std::cin>>v.at(i);
	}
	int smjer;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>smjer;
	auto d(MaksimalniPodnizoviStepenaDvojke(v,Smjer(smjer-1)));
	
	if(smjer == 1) std::cout<<"Maksimalni rastuci podnizovi: ";
	else std::cout<<"Maksimalni opadajuci podnizovi: ";
	
	for(int i(0);i<d.size();i++){
		std::cout<<std::endl;
		for(int j(0);j<d.at(i).size();j++)
			std::cout<<d.at(i).at(j)<<" ";
	}
	return 0;
}