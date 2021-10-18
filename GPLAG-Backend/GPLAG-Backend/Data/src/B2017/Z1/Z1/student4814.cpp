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
bool DaLiJeProst(int a){
	a=abs(a);
	for(int i=2;i<=a/2;i++){
		if(a%i==0) return false;
	}
	return true;
}
int Ternarni(int a){
	int x(0),y(0),ter(0);
	while(pow(3,x)<a) x++;
	x--;
	for(int i=x;i>=0;i--){
		while(y*pow(3,i)<=a) y++;
		y--;
		ter=ter*10+y;
		a=a-pow(3,i)*y;
		y=0;
	}
	return ter;
}
int Obrni(int a){
	int x(0),y(0),cifra(0),ret(0);
	x=a;
	while(x>0) {y++; x/=10;}
	y--;
	for(int i=y;i>=0;i--){
		cifra=a%10;
		ret+=cifra*pow(10,i);
		a/=10;
	}
	return ret;
}
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> a, bool x){
	std::vector<int> v1,v2,v;
	/*for(int i=0;i<a.size()-1;i++){
		for(int j=i+1;j<a.size();j++){
			if(a.at(i)==a.at(i+1)){ v.erase(a.begin()+j); j--; }
		}
	}*/
	for(int i=0;i<a.size();i++){
		if(DaLiJeProst(a.at(i))){
			if(a.at(i)!=1) v1.push_back(a.at(i));
		}else{
			v2.push_back(a.at(i));
		}
	}
	if(x){
		v=v1;
	}else{
		v=v2;
	}
	v1.resize(0);v2.resize(0);
	int ter,ter2;
	for(int i=0;i<v.size();i++){
		ter=Ternarni(abs(v.at(i)));
		ter2=Obrni(ter);
		if(ter!=ter2) {v.erase(v.begin()+i);i--;}
	}
/*	for(int i=0;i<v.size()-1;i++){
		for(int j=i+1;j<v.size();j++){
			if(v.at(i)==v.at(j)){ v.erase(v.begin()+j); j--;}
		}
	}*/
	return v;
}
int main ()
{
	int temp(5);
	std::vector<int> v,v2;
	bool x;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	while(temp!=-1){
		std::cin>>temp;
		if(temp!=-1) v.push_back(temp);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>temp;
	while(temp!=1 && temp!=0) {std::cout<<"Neispravan unos! Unesite ponovo: "; std::cin>>temp;}
	x=temp;
	v2=IzdvojiSimetricneTernarne(v,x);
	if(v2.size()==0){
		if(x) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	}else{
		if(x) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0;i<v2.size();i++){
			if(i!=v2.size()-1) std::cout<<v2.at(i)<<", ";
			else std::cout<<v2.at(i)<<".";
		}
	}
	
	return 0;
}