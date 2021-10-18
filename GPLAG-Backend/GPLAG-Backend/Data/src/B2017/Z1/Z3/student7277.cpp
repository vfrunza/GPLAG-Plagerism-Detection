/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include<iostream>
#include<vector>
#include<deque>

enum Smjer{Rastuci=1, Opadajuci=2 };

bool StepenDvojke(int broj){
	if(broj<=0)
	return false;
	
	while(broj!=1){
		if(broj%2==1)
		return false;
		broj=broj/2;
	}

	return true;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, enum Smjer a){
	std::deque<std::vector<int>> m(0);
	if(v.size()==0){
		return m;
	}
	
	int brojac(0);
	
	std::vector<int> pomocni1;
	
	if(a==1){
		for(int i=0;i<v.size();i++){
			if(StepenDvojke(v.at(i))){
				if(i==0){
					if(v.at(i)>v.at(i+1))
					continue;
				}
				
				if(i==v.size()-1){
					if(v.at(i)>v.at(i-1) && pomocni1.size()>=1){
						pomocni1.push_back(v.at(i));
						brojac++;
						m.resize(brojac);
						
						for(int j=0;j<pomocni1.size();j++){
							m.at(brojac-1).push_back(pomocni1.at(j));
						}
						break;
					}
					else break;
				}
				
				if(v.at(i)<v.at(i+1)){
					pomocni1.push_back(v.at(i));
					continue;
				}
				
				else if(v.at(i)>v.at(i+1) && v.at(i)<v.at(i-1))
				continue;
				
				else{
					if(pomocni1.size()>=1){
						pomocni1.push_back(v.at(i));
						brojac++;
						m.resize(brojac);
						
						for(int j=0;j<pomocni1.size();j++){
							m.at(brojac-1).push_back(pomocni1.at(j));
						}
						pomocni1.clear();
						continue;
					}
					continue;
				}
			}
			else{
				if(pomocni1.size()>1){
					brojac++;
					m.resize(brojac);
					
					for(int j=0;j<pomocni1.size();j++){
						m.at(brojac-1).push_back(pomocni1.at(j));
					}
					pomocni1.clear();
					continue;
				}
				pomocni1.clear();
				continue;
			}
		}
	}
	else if(a==2){
		
		for(int i=0;i<v.size();i++){
			if(StepenDvojke(v.at(i))){
				if(i==0){
					if(v.at(i)<v.at(i+1))
					continue;
				}
				
				if(i==v.size()-1){
					if(v.at(i)<v.at(i-1) && pomocni1.size()>=1){
						pomocni1.push_back(v.at(i));
						brojac++;
						m.resize(brojac);
						
						for(int j=0;j<pomocni1.size();j++){
							m.at(brojac-1).push_back(pomocni1.at(j));
						}
						break;
					}
					else break;
				}
				if(v.at(i)>v.at(i+1)){
					pomocni1.push_back(v.at(i));
					continue;
				}
				else if(v.at(i)<v.at(i+1) && v.at(i)>v.at(i-1))
				continue;
				
				else{
					if(pomocni1.size()>=1){
						pomocni1.push_back(v.at(i));
						brojac++;
						m.resize(brojac);
						
						for(int j=0;j<pomocni1.size();j++){
							m.at(brojac-1).push_back(pomocni1.at(j));
						}
						pomocni1.clear();
						continue;
					}
					continue;
				}
			}
			else{
				if(pomocni1.size()>1){
					brojac++;
					m.resize(brojac);
					
					for(int j=0;j<pomocni1.size();j++){
						m.at(brojac-1).push_back(pomocni1.at(j));
					}
					pomocni1.clear();
					continue;
				}
				pomocni1.clear();
				continue;
			}
		}
	}
	return m;
}

int main(){
	
	int n, element;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<int> v;
	
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		std::cin>>element;
		v.push_back(element);
	}
	
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int m(0);
	std::cin>>m;
	Smjer a;
	a=Smjer(m);
	
	if(m==1){
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	}
	else if(m==2){
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	}
	
	std::deque<std::vector<int>> d(MaksimalniPodnizoviStepenaDvojke(v,a));
	for(std::vector<int> i:d){
		for(int j:i){
			std::cout<<j<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}