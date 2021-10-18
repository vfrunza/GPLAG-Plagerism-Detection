#include <iostream>
#include<cmath>
#include<iomanip>
#include<deque> 
#include<limits>
#include<stdexcept>
bool provjeri(std::vector<int> a){
	std::vector<int> b;
	for(int i=0;i<a.size();i++){
		b.insert(b.begin(), a.at(i));
	}
	if(a==b)return true;
	
	return false;
}
std::vector<int> pretvori(int n){
	std::vector<int> a;
	while(n>0){
		int u;
		u=n%3;
		a.insert(a.begin(), u);
		n=n/3;
	}
	return a;
}

bool DaLiJeProst(int n){
	if(n<2)return false;
    int a=0;
    bool c=true;
    for(int i=2;i<=std::sqrt(n);i++){
        if(n%i==0)a++;
       
    }
    if(a>0)c=false;
    
    return c;
}
std::vector<int> IzbaciDuplikate (std::vector<int> a){
	for(int i=0;i<a.size();i++){
		for(int j=i+1;j<a.size();j++){
			if(a.at(i)==a.at(j))a.erase(a.begin()+j);
		}
	}
	return a;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v,bool a){
	std::vector<int> cyka;
	std::vector<int> cyka2;
	if(a==true){
		for(int i=0;i<v.size();i++){
			if(v.at(i)==1)continue;
			if(DaLiJeProst(v.at(i))==true){
			cyka.push_back(v.at(i));
			}
		}
	}else {
		for(int i=0;i<v.size();i++){
			if(v.at(i)==1)continue;
			if(DaLiJeProst(v.at(i))==false){
			cyka.push_back(v.at(i));
			}
		}
	}
	
	for(int i=0;i<cyka.size();i++){
		if(provjeri(pretvori(cyka.at(i)))==true){
			cyka2.push_back(cyka.at(i));
		}
	}
	
	return cyka2;
}
int main (){
	std::vector<int> v;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	do{int a;
		std::cin>>a	;
		if(a==-1)break;
		v.push_back(a);
	}	while (1) ;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: " ;
	bool b;
	v=IzbaciDuplikate(v);
	int c;
	do{
	std::cin>>c;
	if(c==0||c==1)break;
	std::cout << "Neispravan unos! Unesite ponovo: ";
	}while(1);
	b=c;
	auto v1 = IzdvojiSimetricneTernarne(v,b);
	if(v1.size()==0&&b==1){
		std::cout << "Nema prostih simetricnih brojeva u vektoru." ;
	}
	if(v1.size()==0&&b==0){
		std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	}
	if(v1.size()>0&&b==1){
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for(int i=0;i<v1.size();i++){
			if(i==v1.size()-1)std::cout <<v1.at(i)<<".";
			else std::cout <<v1.at(i) <<", ";
		}
		
	} if(v1.size()>0&&b==0){
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0;i<v1.size();i++){
			if(i==v1.size()-1)std::cout <<v1.at(i)<<".";
			else std::cout <<v1.at(i) <<", ";
		}
	}
	return 0;
}


