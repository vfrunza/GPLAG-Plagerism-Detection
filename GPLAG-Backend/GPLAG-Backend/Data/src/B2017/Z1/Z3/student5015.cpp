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


enum Smjer {Rastuci,Opadajuci};

bool ProvjeriStepen(int n)
{
	
	if(n==0) return false;
	return !(n &(n-1));
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v,Smjer a)
{
    std::deque<std::vector<int>> neka_matrica;
    int i(0),j(0),k(0),brojac(1);
    if(a==Rastuci){
    	for(i=0;i<v.size()-1;i++){
    		k=i+1;
    		if(v.at(k)>v.at(i) && ProvjeriStepen(v.at(k)) && ProvjeriStepen(v.at(i))){
    			neka_matrica.resize(brojac);
    			neka_matrica.at(j).push_back(v.at(i));
    			neka_matrica.at(j).push_back(v.at(k));
    			if(k<v.size()-1 && i<v.size()-1){
    				if(i==v.size()-1 || i==v.size() || k==v.size()) break;
    				k++;
    				i++;
    				if(k==v.size()-1 && ProvjeriStepen(v.at(k)) && ProvjeriStepen(v.at(i)) && v.at(k)>v.at(i)) neka_matrica.at(j).push_back(v.at(k));
    				while(k<v.size()-1 && i<v.size()-2 && v.at(k)>v.at(i)){
    					if(ProvjeriStepen(v.at(k)) && ProvjeriStepen(v.at(i))) neka_matrica.at(j).push_back(v.at(k));
    					k++;
    					i++;
    				}
    			}
    			brojac++;
    			j++;
    			if(i==v.size() || i==v.size()-1 || k==v.size()) break;
    		}
    		
    	}
    	
    }
    else {
    	brojac=1;
    	for(i=0;i<v.size()-1;i++){
    		k=i+1;
    		if(v.at(k)<v.at(i) && ProvjeriStepen(v.at(k))==true && ProvjeriStepen(v.at(i))==true){
    			neka_matrica.resize(brojac);
    			neka_matrica.at(j).push_back(v.at(i));
    			neka_matrica.at(j).push_back(v.at(k));
    			if(k<v.size() && i<v.size()-1){
    				if(i==v.size()-1 || i==v.size() || k==v.size()) break;
    				k++;
    				i++;
    			    if(k==v.size()-1 && ProvjeriStepen(v.at(k)) && ProvjeriStepen(v.at(i)) && v.at(k)<v.at(i)) neka_matrica.at(j).push_back(v.at(k));
    				while(k<v.size()-1 && i<v.size()-2 && v.at(k)<v.at(i)){
    					if(ProvjeriStepen(v.at(k)) && ProvjeriStepen(v.at(i))) neka_matrica.at(j).push_back(v.at(k));
    					k++;
    					i++;
    				}
    			}
    			brojac++;
    			j++;
    			if(i==v.size() || i==v.size()-1 || k==v.size()) break;
    		}
    	}
    }
    
	return neka_matrica;
}

int main ()
{
	int broj_elemenata,broj,rastuci_il_opadajuci;
	std::vector<int> vektor;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>broj_elemenata;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<broj_elemenata; i++) {
		std::cin>>broj;
		vektor.push_back(broj);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>rastuci_il_opadajuci;
	if(rastuci_il_opadajuci==1) {
		std::deque<std::vector<int>> matrica1;
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		matrica1=MaksimalniPodnizoviStepenaDvojke(vektor,Rastuci);
		for(int i=0; i<matrica1.size(); i++) {
			for(int j=0; j<matrica1.at(i).size(); j++) {
				std::cout<<matrica1.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	} else {
		std::deque<std::vector<int>> matrica2;
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		matrica2=MaksimalniPodnizoviStepenaDvojke(vektor,Opadajuci);
		for(int i=0; i<matrica2.size(); i++) {
			for(int j=0; j<matrica2.at(i).size(); j++) {
				std::cout<<matrica2.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	}
	return 0;
}