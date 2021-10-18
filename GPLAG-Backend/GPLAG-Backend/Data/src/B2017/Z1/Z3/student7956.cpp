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
#include <cmath>
#include <vector>
enum Smjer {Rastuci,Opadajuci};

bool Potencija(int a){
	for(int i=0;i<a;i++){
		if(int(pow(2,i))==a) return true;
	}
	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int>brojevi, Smjer s){
	std::deque<std::vector<int>> rastuci_podnizovi;
	std::deque<std::vector<int>> opadajuci_podnizovi;
	std::vector<int> podniz;
	
	if(brojevi.size()==0) return rastuci_podnizovi;
	
	for(int i=0;i<brojevi.size()-1;i++){
		
		if(brojevi.at(i)<brojevi.at(i+1) && Potencija(brojevi.at(i+1))==true) {
			if(podniz.size()==0 && Potencija(brojevi.at(i))==true) podniz.push_back(brojevi.at(i));
			podniz.push_back(brojevi.at(i+1));
			if(i==brojevi.size()-2 && podniz.size()>1) rastuci_podnizovi.push_back(podniz);
		}
		else {
			if(podniz.size()>1) rastuci_podnizovi.push_back(podniz);
			podniz.resize(0);
		}
		
	}
	
	for(int i=0;i<brojevi.size()-1;i++){
		if(brojevi.at(i)>brojevi.at(i+1) && Potencija(brojevi.at(i+1))==true){
			if(podniz.size()==0 && Potencija(brojevi.at(i))==true) podniz.push_back(brojevi.at(i));
			podniz.push_back(brojevi.at(i+1));
			if(i==brojevi.size()-2 && podniz.size()>1) opadajuci_podnizovi.push_back(podniz);
		}
		else {
			if(podniz.size()>1) opadajuci_podnizovi.push_back(podniz);
			podniz.resize(0);
		}
	}
	
	if(s==Opadajuci) return opadajuci_podnizovi;
	else return rastuci_podnizovi;
	
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::vector<int>cijeli;
	int a;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		std::cin>>a;
		cijeli.push_back(a);
	}
	
	std::deque<std::vector<int>> nizovi;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	
	int s;
	std::cin>>s;
	
	Smjer tip;
	if(s==1) tip=Rastuci;
	else if(s==2)  tip=Opadajuci;
	
	nizovi=MaksimalniPodnizoviStepenaDvojke(cijeli,tip);
	if(nizovi.size()>0){
		if(s==1) std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		else std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	}
	
	for(int i=0;i<nizovi.size();i++){
		
		for(int j=0; j<nizovi.at(i).size(); j++){
			std::cout<<nizovi.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}