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

bool DaLiJeProst(int n){
	if(abs(n)<2) return false;
	for(int i=2; i<=std::sqrt(abs(n)); i++){
		if(abs(n)%i==0) return false;
	}
	return true;
}
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool tacno){
    std::vector<int> prosti,ters,slozeni;
    int d;
    for(int i=0; i<v.size(); i++){
    	if(DaLiJeProst(v.at(i)))
		prosti.push_back(v.at(i));
		else
		slozeni.push_back(v.at(i));
	}
    int b(0),c(0),a(0),p,isti(0);
    if(tacno==true){
    for(int i=0; i<prosti.size(); i++){
    	d=prosti.at(i);
    		do{
    		a=a+((abs(prosti.at(i))%3)*pow(10,b));
    		b++;
    		prosti.at(i)/=3;
    		}
    		while(prosti.at(i)!=0);
    		p=a;
    		do{
    			c=c*10+a%10;
    			a=a/10;
    		}
    		while(a!=0);
    		if(p==c){
    		for(int i=0; i<ters.size(); i++){
    				if(d==ters.at(i)){
    				isti=1;
    				break;
    				}
    			}
    			if(isti==0)
    			ters.push_back(d);
    		}
    		a=0; c=0; b=0; isti=0;
    	}
    }
    if(tacno==false){
    	for(int i=0; i<slozeni.size(); i++){
    	d=slozeni.at(i);
    		do{
    		a=a+((abs(slozeni.at(i)))%3)*pow(10,b);
    		b++;
    		slozeni.at(i)/=3;
    		}
    		while(slozeni.at(i)!=0);
    		p=a;
    		do{
    			c=c*10+a%10;
    			a=a/10;
    		}
    		while(a!=0);
    		if(p==c){
    			for(int i=0; i<ters.size(); i++){
    				if(d==ters.at(i)){
    				isti=1;
    				break;
    				}
    			}
    			if(isti==0)
    			ters.push_back(d);
    		}
    		a=0; c=0; b=0; isti=0;
    	}
    }
    return ters;
}

int main ()
{
	int a,b,s;
	std::vector<int> k,m;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::cin>>a;
	while(a!=-1){
		k.push_back(a);
		std::cin>>a;
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>b;
	while(b!=1 && b!=0){
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>b;
	}
	m=IzdvojiSimetricneTernarne(k,b);
	s=m.size();
	if(s==0 && b==1) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	if(s==0 && b==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		if(b==1 && s>0){
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<s; i++){
			std::cout<<m.at(i);
			if(i!=s-1)
			std::cout<<", ";
			else
			std::cout<<".";
		}
		}
		if(b==0 && s>0){
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<s; i++){
			std::cout<<m.at(i);
			if(i!=s-1)
			std::cout<<", ";
			else
			std::cout<<".";
		}
		}
	return 0;
}