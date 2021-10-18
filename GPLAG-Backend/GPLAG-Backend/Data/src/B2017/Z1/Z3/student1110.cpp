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
enum Smjer{Rastuci,Opadajuci};

bool JeLiStepenDvojke (int x) {
	for(int i=1;i<=x;i*=2) 
		if(i==x) return true;
	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v,  Smjer smjer) {
	std::deque<std::vector<int>> podnizovi(0);
	std::vector<int> ve(0);
	std::vector<int> prazan(0);
	for(int i=0; i< v.size();i++) {
		ve=prazan;
	
			if(smjer==(Rastuci)) {
				while(i<v.size()-1 && JeLiStepenDvojke(v.at(i)) && JeLiStepenDvojke(v.at(i+1)) && v.at(i)<v.at(i+1)) {
					
					ve.push_back(v.at(i));
					i++;
				}
				if(ve.size()!=0) ve.push_back(v.at(i));

			}
			else if (smjer==(Opadajuci)) {
				while(i<v.size()-1 && JeLiStepenDvojke(v.at(i)) && JeLiStepenDvojke(v.at(i+1)) && v.at(i)>v.at(i+1)) {
					 
					ve.push_back(v.at(i));
					i++;
				}
				if(ve.size()!=0) ve.push_back(v.at(i));
		
		if(ve.size()!=0 && ve.size()!=1)
			podnizovi.push_back(ve);
		
		
	}
return podnizovi;
}



int main ()
{
	int br(0);
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>br;
	std::cin.clear();
	std::cin.ignore(1000,'\n');
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> v(0);
	int x(0);
	for(int i=0; i<br;i++) {
		std::cin>>x;
		v.push_back(x);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int opcija(0);
	std::cin>>opcija;
	std::deque<std::vector<int>> podnizovi;
	if(opcija==1) {
	 podnizovi=MaksimalniPodnizoviStepenaDvojke(v,Rastuci);
	 if(podnizovi.size()>0) {
		std::cout<<"Maksimalni rastuci podnizovi: ";
		for(int i=0; i<podnizovi.size();i++) {
			for (int j=0; j<podnizovi.at(i).size();j++) {
				std::cout<<podnizovi.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	}
	else std::cout<<"Nema maksimalnih rastucih podnizova!";
	}
	
	else if(opcija==2) {
	 podnizovi=MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
	 if(podnizovi.size()>0) {
		std::cout<<"Maksimalni opadajuci podnizovi: ";
		for(int i=0; i<podnizovi.size();i++) {
			for(int j=0;j<podnizovi.at(i).size();j++) {
				std::cout<<podnizovi.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	} 
	else std::cout<<"Nema maksimalnih opadajucih podnizova!";
	}
	return 0;
}