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
#include <cmath>
#include <deque>
#include <vector>

int BrojRedova(std::deque<std::vector<int>>d){
	return d.size();
}
enum Smjer{R,O}monotoni;
bool StepenDvojke(int n){
	int i(0);
	bool a(true);
	if(n<0){
		a=false;
		return a;
	}
	for(; ;){
		int broj(pow(2,i));
		if(broj==n){
			return a;
		}else if(broj>n){
			a=false;
			return a;
		}else{
			i++;
			continue;
		}
		i++;
	}
}
std::deque<std::vector<int>>MaksimalniPodnizoviStepenaDvojke(std::vector<int>v,enum Smjer monotoni){
	std::vector<int>v1;
	std::vector<int>v2;
	std::deque<std::vector<int>>d;
	int br(1);
	if(monotoni==R){
	for(int i(0);i<v.size();i++){
		if(i<(v.size()-1) && v.at(i)<=v.at(i+1) && StepenDvojke(v.at(i))){
			v2.push_back(v.at(i));
			br+=1;
		}else if(i<(v.size()-1) && br>1 && (v.at(i)>=v.at(i+1) || v.at(i)>=v.at(i-1))){
			if(StepenDvojke(v.at(i))){
				v2.push_back(v.at(i));
			}
			if(v2.size()>1){
			d.push_back(v2);
			}
			v2.clear();
			br=1;
		}else if(i==(v.size()-1)){
			if(v.at(i)<v.at(i-1))break;
			if(StepenDvojke(v.at(i))){
				v2.push_back(v.at(i));
				br+=1;
			}
			if(v2.size()>1){
			d.push_back(v2);
			}
			v2.clear();
		}else{
			continue;
		}
	}	
}else{
	for(int i(0);i<v.size();i++){
		if(i<(v.size()-1) && v.at(i)>=v.at(i+1) && StepenDvojke(v.at(i))){
			v2.push_back(v.at(i));
			br+=1;
		}else if(i<(v.size()-1) && br>1 && (v.at(i)<=v.at(i+1) || v.at(i)<=v.at(i-1))){
			if(StepenDvojke(v.at(i))){
			v2.push_back(v.at(i));
			}
			if(v2.size()>1){
			d.push_back(v2);
			}
			v2.clear();
			br=1;
		}else if(i==(v.size()-1)){
			if(v.at(i)>v.at(i-1))break;
			if(StepenDvojke(v.at(i))){
			v2.push_back(v.at(i));
			br+=1;
			}
			if(v2.size()>1){
			d.push_back(v2);
			}
	     	v2.clear();
		}else{
			continue;
		}
   }
}
 return d;
}

int main ()
{
    int n,broj;
    std::vector<int>v;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>n;
    std::cout<<"Unesite elemente vektora: ";
    for(int i(0);i<n;i++){
    	int broj;
    	std::cin>>broj;
    	v.push_back(broj);
    }
    std::deque<std::vector<int>>d;
    std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    std::cin>>broj;
    if(broj==1){
    	monotoni=R;
    d=MaksimalniPodnizoviStepenaDvojke(v,monotoni);
    std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;;
    }else{
    	monotoni=O;
    	d=MaksimalniPodnizoviStepenaDvojke(v,monotoni);
    	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    }
    for(auto x: d){
    	for(auto y: x){
    		std::cout<<y<<" ";
    	}
    std::cout<<std::endl;
    }
	return 0;
}