/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
//**************************************************************NAPOMENA***************************************************************
//Dio koda izmedu 32. i 44. linije je gotovo identican kodu izmedu 46. i 58. linije(u pitanju je izmjena vece/manje) pa je zato kopiran.
#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
enum Smjer {Rastuci=1, Opadajuci=2};
bool DaLijeStepenDvojke(int v){
	int i(0);
		while(pow(2,i)<=v){
			if(pow(2,i)==v) return true;
			i++;
		}
		return false;
}
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v,enum Smjer a){
	std::deque<std::vector<int>> d;
	std::vector<int> v2;
	int y,z;
	if(a==Rastuci){
		for(int i=0;i<v.size()-1;i++){
			if(DaLijeStepenDvojke(v.at(i)) && DaLijeStepenDvojke(v.at(i+1)) && (v.at(i)<v.at(i+1))){
				y=i;z=y;
				while(v.at(i)<v.at(i+1) && DaLijeStepenDvojke(v.at(i)) && DaLijeStepenDvojke(v.at(i+1)) && i<v.size()-1){
					i++;
					if(i==v.size()-1) break;
				}
				for(int j=0;j<=(i-y);j++){
					v2.push_back(v.at(z++));
				}
				d.push_back(v2); v2.resize(0);
			}
		}
	}else{
				for(int i=0;i<v.size()-1;i++){
			if(DaLijeStepenDvojke(v.at(i)) && DaLijeStepenDvojke(v.at(i+1)) && (v.at(i)>v.at(i+1))){
				y=i;z=y;
				while(v.at(i)>v.at(i+1) && DaLijeStepenDvojke(v.at(i)) && DaLijeStepenDvojke(v.at(i+1)) && i<v.size()-1){
					i++;
					if(i==v.size()-1) break;
				}
				for(int j=0;j<=(i-y);j++){
					v2.push_back(v.at(z++));
				}
				d.push_back(v2); v2.resize(0);
			}
		}
	}
	return d;
}
int main (){
	std::deque<std::vector<int>> d;
	std::vector<int> v,v2,v3,v4;
	int x,y;
	//enum Smjer {Rastuci=1, Opadajuci=2};
	enum Smjer s;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>x;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<x;i++){
		std::cin>>y;
		v.push_back(y);
	}
std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>x;
	if(x==1) s=Rastuci;
	else s=Opadajuci;
	if(s==Rastuci) {std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl; d=MaksimalniPodnizoviStepenaDvojke(v,Rastuci);}
	else {std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl; d=MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);}

	for(int i=0;i<d.size();i++){
		for(int j=0;j<d.at(i).size();j++){
			if(j!=(d.at(i).size()-1)) std::cout<<d.at(i).at(j)<<" ";
			else std::cout<<d.at(i).at(j)<<" "<<std::endl;
		}
	}
	return 0;
}