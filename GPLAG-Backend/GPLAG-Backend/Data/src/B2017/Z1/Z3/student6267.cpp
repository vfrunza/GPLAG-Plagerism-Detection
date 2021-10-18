/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
//15 1 4 2 4 32 16 10 4 8 4 2 1 2 1 7 1
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

typedef std::vector<int> Vektor;
typedef std::deque<std::vector<int>> DekVektora;

enum Smjer {Rastuci,Opadajuci};
bool StepenDvojke (int broj){
	for(int i(0);i<=std::sqrt(broj)+1;i++){
		if(broj==std::pow(2,i)) return true;
	}
	return false;
}

DekVektora MaksimalniPodnizoviStepenaDvojke(Vektor v, Smjer s){
	DekVektora dekv;
	int pocetak(-1);
	int kraj(-1);
	for(int i(0);i<v.size();i++){
		int brojac(0);
		if(StepenDvojke(v.at(i))) {
			pocetak=i;
			brojac++;
			for(int j=i+1;j<v.size();j++){
				if(s==0){
				if(StepenDvojke(v.at(j)) && v.at(j-1)<=v.at(j)) brojac++;
				else break;
				}
				else{
					if(StepenDvojke(v.at(j)) && v.at(j-1)>=v.at(j)) brojac++;
				else break;
				}
			}
			if(brojac>=2){
				
				kraj=pocetak+brojac;
				Vektor pom;
				for(int k(pocetak);k<kraj;k++){
					pom.push_back(v.at(k));
				}
				dekv.push_back(pom);
				i=kraj-1;
			}
		}
	}
	return dekv;
}


int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int br_elemenata(0);
	std::cin>>br_elemenata;
	std::cout<<"Unesite elemente vektora: ";
	Vektor v(br_elemenata);
	for(int i(0);i<br_elemenata;i++){
		std::cin>>v.at(i);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int smjer;
	std::cin>>smjer;
	DekVektora dek;
	if(smjer==1){
		dek=MaksimalniPodnizoviStepenaDvojke(v,Rastuci);
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	}
	else {
		dek=MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	}
	for(int i(0);i<dek.size();i++){
		for(int j(0);j<dek.at(i).size();j++){
			std::cout<<dek.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	
		
	
	return 0;
}