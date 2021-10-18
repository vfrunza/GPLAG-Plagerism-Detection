/*B 2017/2018, Zadaća 1, Zadatak 1
	
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
#include <cmath>

bool Prost(int n){
	bool a(true);
	if(n<0){
	n=fabs(n);
	}
	for(int i(2);i<n;i++){
		if(n%i==0){
			a=false;
			break;
		}
	}
	return a;
}

std::vector<int>Ternarni(int n){
	std::vector<int>v;
	if(n<0){
		n=fabs(n);
	}
	int ostatak;
	int rezultat(n);
	while(rezultat!=0){
		ostatak=rezultat%3;
		rezultat=rezultat/3;
	    v.push_back(ostatak);
	}
	return v;
}

std::vector<int>IzdvojiSimetricneTernarne(std::vector<int>v,bool log_vr){
	std::vector<int>v1;
	std::vector<int>v2;
	std::vector<int>v3;
	bool a(true);
	for(int i(0);i<v.size();i++){
		v1=Ternarni(v.at(i));
		if(Prost(v.at(i))){
			a=true;
			for(int j(0);j<v1.size();j++){
		            if(v1.size()%2!=0 && j==(v1.size())/2){
						break;
				}else if(v1.at(j)!=v1.at(v1.size()-1-j)){
					a=false;
					break;
				}
		}if(a){
			int d(true);
				for(int t(0);t<v3.size();t++){
					if(v.at(i)==v3.at(t)){
						d=false;
						break;
					}
				}if(d){
				v3.push_back(v.at(i));
				}
	    } 
	}else{
		a=true;
		for (int l(0);l<v1.size();l++){
			if(v1.size()%2!=0 && l==(v1.size())/2){
				break;
			}else if(v1.at(l) != v1.at(v1.size()-1-l)){
					a=false;
					break;
			}
       }if(a){
			bool d(true);
			for(int o(0);o<v2.size();o++){
				if(v2.at(o)==v.at(i)){
				d=false;
				break;
			}
		}if(d){
			v2.push_back(v.at(i));
			}
		}
	}
	}
if(log_vr){
	return v3;
}else{
	return v2;
}
}

int main ()
{
	int br;
	std::vector<int>v;
	std::vector<int>v1;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	for(; ;){
		int broj;
		std::cin>>broj;
		if(broj==(-1)){
			break;
		}else{
			v.push_back(broj);
		}
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>br;
   for(; ;){
   	if(br==1 || br==0){
   		break;
   	}else{
   		std::cout<<"Neispravan unos! Unesite ponovo: ";
   		std::cin>>br;
   	}
   }
	if(br==1){
		v1=IzdvojiSimetricneTernarne(v,true);
		if(v1.size()==0){
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}else{
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i(0);i<v1.size();i++){
			if(i==(v1.size()-1)){
				std::cout<<v1.at(i)<<".";
			}else{
			std::cout<<v1.at(i)<<", ";
			}
		 }
	   }
     }else{
		v1=IzdvojiSimetricneTernarne(v,false);
		if(v1.size()==0){
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}else{
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i(0);i<v1.size();i++){
			if(i==(v1.size()-1)){
				std::cout<<v1.at(i)<<".";
			}else{
				std::cout<<v1.at(i)<<", ";
			}
		}
	}
  }
	return 0;
}