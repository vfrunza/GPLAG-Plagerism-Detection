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
#include <cstdio>
#include <cmath>

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v,bool a){
	
	std::vector<int> c;
	if(a==true){
		for(int i=0;i<v.size();i++){
				int l=1;
				int temp=v.at(i);
			for(int j=2;j<v.at(i);j++){
				if(v.at(i)<0){
					v.at(i)=v.at(i)*(-1);
				}
				if(v.at(i)%j==0){
					l=0;
					break;
			}
			}
			if(l==1){
			c.push_back(temp);}
	}
	}
	else if(a==false){
		for(int i=0;i<v.size();i++){
			int temp=v.at(i);
			for(int j=2;j<v.at(i);j++){
				if(v.at(i)<0){
					v.at(i)=v.at(i)*(-1);
				}
				if(v.at(i)%j==0){
					c.push_back(temp);
					break;
				}
			}
		}
	}
	std::vector <int> p;
	for(int i=0;i<c.size();i++){
		int r=c.at(i);
		int x;
		int broj=0;
		while(r!=0){
		x=r%3;
		broj=(broj*10)+x;
		r=r/3;}
		p.push_back(broj);
	}
	std::vector <int> kon;
	for(int i=0;i<p.size();i++){
		int M=c.at(i);
		int n=p.at(i);
		int rj=0;
		int y;
		while(n!=0){
			y=n%10;
			rj=rj*10+y;
			n=n/10;
		}
		if(rj<0){
			rj=rj*-1;
		}
		if(p.at(i)==rj && ((rj)/10)>0){
			kon.push_back(M);
		}
	}
	return kon;
}

int main ()
{
	std::vector<int> k;
	bool b;
	int r;
	int n;
	std::cout << "Unesite elemente vektora (-1 za kraj):";
	do{
		std::cin>>n;
		if(n!=-1){
		k.push_back(n);}
	}while(n!=-1);
	std::cout << " Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do{
		std::cin>>r;
		if(r==1 || r==0){
			break;}
		std::cout << "Neispravan unos! Unesite ponovo: ";
	}while(r!=0 && r!=1);
	if(r==1){
		b=true;
	}
	else if(r==0){
		b=false;
	}
	std::vector<int> final(IzdvojiSimetricneTernarne(k,b));
	if(final.size()==0 && r==1){
		std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	}
	else if(final.size()==0 && r==0){
		std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	}
	else{
		if(r==1){
			std::cout << "Prosti simetricni brojevi iz vektora su: ";}
		else if(r==0){
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		}
		for(int i=0;i<final.size();i++){
			std::cout << final.at(i);
		if(i!=final.size()-1){
			std::cout << ", ";
		}
		else{
			std::cout <<".";
		}
	}}
	return 0;
}