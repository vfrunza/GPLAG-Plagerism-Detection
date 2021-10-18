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
#include<deque>
#include<vector>
#include<cmath>
enum Smjer { Rastuci=1,Opadajuci};

std::deque<std::vector<int>>MaksimalniPodnizoviStepenaDvojke(std::vector<int>vec,enum Smjer s){
	std::deque<std::vector<int>>rastuci;
	std::deque<std::vector<int>>opadajuci;
	std::vector<int>pomocni;
	for(int i=1;i<vec.size();i++){
		if(i==vec.size()) break;
		if(s==1){
			if(vec.at(i-1)<vec.at(i)){
				pomocni.push_back(vec.at(i-1));
				pomocni.push_back(vec.at(i));
				if(i==vec.size()-1){
					for(int j=0;j<pomocni.size();j++){
						for(int z=j+1;z<pomocni.size();z++)
						if(pomocni.at(j)==pomocni.at(z)){
							for(int k=z;k<pomocni.size()-1;k++)
							pomocni.at(k)=pomocni.at(k+1);
							z--;
							pomocni.resize(pomocni.size()-1);
						}
					}
					std::vector<int>v;
					for(int k=0;k<pomocni.size();k++){
						if((pomocni.at(k)%2==0 || pomocni.at(k)==1) && pomocni.at(k)!=0 && pomocni.at(k)>0) v.push_back(pomocni.at(k));
					}
					if(v.size()>=2) rastuci.push_back(v);
				}
			}
			else{ 
				for(int j=0;j<pomocni.size();j++){
					for(int z=j+1;z<pomocni.size();z++)
					if(pomocni.at(j)==pomocni.at(z)){
						for(int k=z;k<pomocni.size()-1;k++)
						pomocni.at(k)=pomocni.at(k+1);
						z--;
						pomocni.resize(pomocni.size()-1);
					}
				}
				std::vector<int>v;
				for(int k=0;k<pomocni.size();k++){
					if((pomocni.at(k)%2==0 || pomocni.at(k)==1) && pomocni.at(k)!=0 && pomocni.at(k)>0) v.push_back(pomocni.at(k));
				}
				
				if(v.size()>=2) rastuci.push_back(v);
				pomocni.resize(0);
			}
		}
		
		if(s==2){
			if(vec.at(i)<vec.at(i-1)){
				pomocni.push_back(vec.at(i-1));
				pomocni.push_back(vec.at(i));
				if(i==vec.size()-1){
					for(int j=0;j<pomocni.size();j++){
						for(int z=j+1;z<pomocni.size();z++)
						if(pomocni.at(j)==pomocni.at(z)){
							for(int k=z;k<pomocni.size()-1;k++)
							pomocni.at(k)=pomocni.at(k+1);
							z--;
							pomocni.resize(pomocni.size()-1);
						}
					}
					std::vector<int>v;
					for(int k=0;k<pomocni.size();k++){
						if(k<pomocni.size()-1 && pomocni.at(k)/2==pomocni.at(k+1) && pomocni.at(k)!=0 && pomocni.at(k+1)!=0 && pomocni.at(k)>0 && pomocni.at(k+1)>0){
							v.push_back(pomocni.at(k));
							v.push_back(pomocni.at(k+1));
						}
					}
					
					for(int j=0;j<v.size();j++){
						for(int z=j+1;z<v.size();z++)
						if(v.at(j)==v.at(j+1)){
							for(int k=z;k<v.size()-1;k++)
							v.at(k)=v.at(k+1);
							z--;
							v.resize(v.size()-1);
						}
					}
					
					if(v.size()>=2) opadajuci.push_back(v);
				}
			}
			else {
				for(int j=0;j<pomocni.size();j++){
					for(int z=j+1;z<pomocni.size();z++)
					if(pomocni.at(j)==pomocni.at(z)){
						for(int k=z;k<pomocni.size()-1;k++)
						pomocni.at(k)=pomocni.at(k+1);
						z--;
						pomocni.resize(pomocni.size()-1);
					}
				}
				
				std::vector<int>v;
				for(int k=0;k<pomocni.size();k++){
					if(k<pomocni.size()-1 && pomocni.at(k)/2==pomocni.at(k+1) && pomocni.at(k)!=0 && pomocni.at(k+1)!=0 && pomocni.at(k)>0 && pomocni.at(k+1)>0){
						v.push_back(pomocni.at(k));
						v.push_back(pomocni.at(k+1));
					}
					
				}
				for(int j=0;j<v.size();j++){
					for(int z=j+1;z<v.size();z++)
					if(v.at(j)==v.at(z)){
						for(int k=z;k<v.size()-1;k++)
						v.at(k)=v.at(k+1);
						z--;
						v.resize(v.size()-1);
					}
				}
				
				if(v.size()>=2) opadajuci.push_back(v);
				pomocni.resize(0);
			}
		}
	}
	if(s==1) return rastuci;
	return opadajuci;
}
int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int>vec(n);
	for(int i=0;i<vec.size();i++) std::cin>>vec.at(i);
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	enum Smjer s;
	int m;
	std::cin>>m;
	s=Smjer(m);
	std::deque<std::vector<int>>maksimalni(MaksimalniPodnizoviStepenaDvojke(vec,s));
	if(s==1)
{	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	int j;
	for(int i=0;i<maksimalni.size();i++){
		for(j=0;j<maksimalni[i].size()-1;j++)
		std::cout<<maksimalni.at(i).at(j)<<" ";
		std::cout<<maksimalni.at(i).at(j)<<" "<<std::endl;
	
}
}

if(s==2){
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	int j;
	for(int i=0;i<maksimalni.size();i++){
		for(j=0;j<maksimalni[i].size()-1;j++)
		std::cout<<maksimalni.at(i).at(j)<<" ";
		std::cout<<maksimalni.at(i).at(j)<<" "<<std::endl;
	}
}
return 0;
}
