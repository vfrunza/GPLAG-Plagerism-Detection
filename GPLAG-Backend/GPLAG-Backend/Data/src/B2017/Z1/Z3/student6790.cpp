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
enum Smjer {Rastuci=1, Opadajuci};


bool DaLiJeStepenDvojke (int a) {
	
	if(a==0) return false;
	if(a==1) return true;
	do{
		if(a%2!=0) return false;
		
		a=a/2;
	}while(a!=1);
	
	return true;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v,Smjer s) {
	std::deque<std::vector<int>> dek;
	int pocetak(0),pocetak1(0);
	std::vector<int> elementi_reda;
	
	if(s==Rastuci) {
		while(pocetak<v.size()-1) {
			for(int j=pocetak;j<v.size();j++) {
				pocetak1=j;
				if(elementi_reda.size()==0){
					if(j<v.size()){	
						if(DaLiJeStepenDvojke(v.at(j))&& DaLiJeStepenDvojke(v.at(j+1))&& (v.at(j)<v.at(j+1)))  {
							elementi_reda.push_back(v.at(j));
						}
					}
				}
				
				else{
					if(DaLiJeStepenDvojke(v.at(j))) {
						elementi_reda.push_back(v.at(j));
					}
				}
				
				if (j!=v.size()-1) {
					if(v.at(j)>=v.at(j+1) || DaLiJeStepenDvojke(v.at(j+1))==false) {
						//pocetak=pocetak1+1;
						if(elementi_reda.size()>1)
							dek.push_back(elementi_reda);
						elementi_reda.resize(0);
						break;
					}
				}
				
				if(j==v.size()-1){
					if(elementi_reda.size()>1)
						dek.push_back(elementi_reda);
					elementi_reda.resize(0);
					break;
				}
			}
			pocetak=pocetak1+1;
		}
	}
	
	else {
		while(pocetak<v.size()-1) {
			for(int j=pocetak;j<v.size();j++) {
				pocetak1=j;
				if(elementi_reda.size()==0){
					if(j<v.size()){	
						if(DaLiJeStepenDvojke(v.at(j)) && DaLiJeStepenDvojke(v.at(j+1)) && (v.at(j)>v.at(j+1)))  {
							elementi_reda.push_back(v.at(j));
						}
					}
				}
				
				else{
					if(DaLiJeStepenDvojke(v.at(j))) {
						elementi_reda.push_back(v.at(j));
					}
				}
				
				if (j<v.size()-1) {
					if(v.at(j)<=v.at(j+1) || DaLiJeStepenDvojke(v.at(j+1))==false) {
						//pocetak=pocetak1+1;
						
						if(elementi_reda.size()>1)
							dek.push_back(elementi_reda);
						elementi_reda.resize(0);
						break;
					}
				}
				if(j==v.size()-1){
					if(elementi_reda.size()>1)
						dek.push_back(elementi_reda);
					elementi_reda.resize(0);
					break;
				}
			}
			pocetak=pocetak1+1;
		}
	}
	return dek;
}


int main () {
	
	std::cout<<"Unesite broj elemenata vektora: ";
	int duzina_vektora;
	std::cin>>duzina_vektora;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> vektor;
	int broj;
	for(int i(0);i<duzina_vektora;i++) {
		std::cin>>broj;
		vektor.push_back(broj);
	}
	
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int a;
	for(;;) {
		std::cin>>a;
		if(a==1 || a==2) break;
		std::cout<<"Ponovi unos: ";
	}
	
	if(a==1){
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		std::deque<std::vector<int>> dek_vek(MaksimalniPodnizoviStepenaDvojke(vektor,Smjer(Rastuci)));
		for(int i(0);i<dek_vek.size();i++) {
			for(int j(0);j<dek_vek[i].size();j++){
			std::cout<<dek_vek.at(i).at(j)<<" ";
			}
		std::cout<<"\n";
		}
	}
	else {
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		std::deque<std::vector<int>> dek_vek(MaksimalniPodnizoviStepenaDvojke(vektor,Smjer(Opadajuci)));
		for(int i(0);i<dek_vek.size();i++) {
			for(int j(0);j<dek_vek[i].size();j++){
			std::cout<<dek_vek.at(i).at(j)<<" ";
			}
		std::cout<<"\n";
		}
	}
	
	return 0;
}