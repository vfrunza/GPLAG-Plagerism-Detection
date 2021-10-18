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
typedef std::deque<std::vector<int>> D;

D BrisiDuple(D dek){
	for(int i=0;i<dek.size();i++){
		for(int j=0;j<dek.at(i).size();j++){
			if(dek.at(i).at(j)==dek.at(i).at(j+1)) 
				dek.at(i).erase(dek.at(i).begin()+j+1);
		}
	}
	return dek;
}
bool StepenDvojke(int a){
	bool vrijednost(false);
	for(int i=0;i<a;i++){
		if((pow(2,i))==a){
			vrijednost=true;
			break;
		}
		if(pow(2,i)>a){
			vrijednost=false;
			break;
		}
	}
	return vrijednost;
}
std::deque<std::vector<int>>MaksimalniPodnizoviStepenaDvojke(std::vector<int>v, Smjer sm){
	D dek;
	if(sm==Rastuci){
		std::vector<int> v1;
		for(int i=0;i<v.size()-1;i++){
			if(StepenDvojke(v.at(i))==true){
				if(StepenDvojke(v.at(i+1))==true){
					if(v.at(i)<v.at(i+1)){
						v1.push_back(v.at(i));
						v1.push_back(v.at(i+1));
					}else{
						dek.push_back(v1);
						v1.resize(0);
					}
				}else{
					dek.push_back(v1);
					v1.resize(0);
				}
			}else{
				dek.push_back(v1);
				v1.resize(0);
			}
		}
	}
	if(sm==Opadajuci){
			std::vector<int> v1;
		for(int i=0;i<v.size()-1;i++){
			if(StepenDvojke(v.at(i))==true){
				if(StepenDvojke(v.at(i+1))==true){
					if(v.at(i) > v.at(i+1)){
						v1.push_back(v.at(i));
						v1.push_back(v.at(i+1));
					}else{
						dek.push_back(v1);
						v1.resize(0);
					}
				}else{
					dek.push_back(v1);
					v1.resize(0);
				}
			}else{
				dek.push_back(v1);
				v1.resize(0);
			}
		}
	}
	return BrisiDuple(dek);
}
int main ()
{
	int varijabla;
	Smjer sm;
	std::vector<int> V;
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		int a;
		std::cin>>a;
		V.push_back(a);
	}
	D novi;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>varijabla;
	if(varijabla==1){
	sm=Rastuci;
	novi=MaksimalniPodnizoviStepenaDvojke(V,sm);
	std::cout<<"Maksimalni rastuci podnizovi:";
	std::cout<<" ";
	for(int i=0;i<novi.size();i++){
		for(int j=0;j<novi.at(i).size();j++){
			std::cout<<novi.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	}
	if(varijabla==2){
	sm=Opadajuci;
	novi=MaksimalniPodnizoviStepenaDvojke(V,sm);
	std::cout<<"Maksimalni opadajuci podnizovi:";
	std::cout<<" ";
	for(int i=0;i<novi.size();i++){
		for(int j=0;j<novi.at(i).size();j++){
			std::cout<<novi.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	}
	return 0;
}