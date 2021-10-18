#include <iostream>
#include <vector>
#include <cmath>

int maxstepen(int broj){
	broj=abs(broj);
	int brojac(0);
	while(broj!=0){
		broj/=3;
		if(broj==0)
			return brojac;
		brojac++;
	}
	return brojac;
}

std::vector<int> IzbaciIste(std::vector<int> v){
	for(int i(0);i<v.size();i++){
		for(int j(i+1);j<v.size();j++){
			if(v.at(i)==v.at(j)){
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	return v;
}
bool DaLiJeProst(int broj){
	if(broj<0)
		broj=abs(broj);
	if(broj<2||broj%2==0)
		return false;
	if(broj==2)
		return true;
	for(int i(3);i<broj;i+=2){
		if(broj%i==0)
			return false;
	}
	return true;
}
std::vector<int> IzdvojiPoProstoci(std::vector<int> v,bool B){
	std::vector<int> v1,v2;
	for(int i(0);i<v.size();i++){
		if(DaLiJeProst(v.at(i)))
			v1.push_back(v.at(i));
		else
			v2.push_back(v.at(i));
	}
	if(B)
		return v1;
	return v2;
}
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v,bool B){
	std::vector<int> finalni;
	v=IzbaciIste(v);
	v=IzdvojiPoProstoci(v,B);
	for(int i(0);i<v.size();i++){
		int broj=v.at(i);
		int stepen=maxstepen(broj);
		std::vector<int> ternarni;
		while(stepen!=-1){
			int x=broj/pow(3,stepen);
			ternarni.push_back(x);
			broj=broj-x*pow(3,stepen);
			stepen--;
		}
		if(ternarni.size()==2)
			finalni.push_back(v.at(i));
		else{	
		bool b(true);
		for(int j(0);j<=ternarni.size()/2;j++){
			if(ternarni.at(j)!=ternarni.at(ternarni.size()-1-j)){
				b=false;
				break;
			}
		}
		if(b)
			finalni.push_back(v.at(i));
		}	
	}
	return finalni;
}
int main ()
{
	std::vector<int> v;
	int x;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do{
		std::cin>>x;
		if(x==-1)
			break;
		v.push_back(x);	
	}while(x!=-1);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int a;
	do{
		std::cin>>a;
		if(a==1||a==0)
			break;
		else
			std::cout<<"Neispravan unos! Unesite ponovo: ";
		}while(1);
	v=IzdvojiSimetricneTernarne(v,a);
	if(a){
		if(v.size()==0)
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else{
			std::cout<<"Prosti simetricni brojevi iz vektora su:";
			for(int i(0);i<v.size();i++){
				if(i<v.size()-1)
					std::cout<<" "<<v.at(i)<<",";
				else
					std::cout<<" "<<v.at(i)<<".";
			}
		}
	}
	else{
		if(v.size()==0)
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else{
			std::cout<<"Slozeni simetricni brojevi iz vektora su:";
			for(int i(0);i<v.size();i++){
				if(i<v.size()-1)
					std::cout<<" "<<v.at(i)<<",";
				else
					std::cout<<" "<<v.at(i)<<".";
			}
		}
	}
	return 0;
}