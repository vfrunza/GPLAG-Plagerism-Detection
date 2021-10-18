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
#include <algorithm>


bool DaLiJeProst(int n){
	
	bool b=true;
	int t;
	
	if(n<0){
		t=n;
		t*=-1;
		if(t==1 || t==0) return false;
	
	for(int i = 2; i <=std::sqrt(t); i++){
		if(t%i==0){
			b=false; break;
		}
		
	}
	return b;
	}
	
    else{
	if(n==1 || n==0) return false;
	
	for(int i = 2; i <=std::sqrt(n); i++){
		if(n%i==0){
			b=false; break;
		}
		
	}
	
	return b;
    }
}

std::vector<int> PretvoriUTernarni(int a){
	std::vector<int> l, t;
	if(a==0) return {3};
	int b;
	int u=a;
	while(a){
		b=a%3;
		l.push_back(b);
		a/=3;
	}
	
	for(int i=l.size()-1; i>=0; i--)
		t.push_back(l.at(i));
	
	if(u<0){
		for(int i=0; i<t.size(); i++){
		if(i!=0)
		t.at(i)*=-1;
			
		}
	}
	
	return t;
	}


bool DaLiJeTernarniSimetrican(std::vector<int> h){
	bool a(true);
	for(int i=0; i<h.size(); i++){
		if(h.at(0)<0) h.at(0)*=-1;
		if(h.at(i)!=h.at(h.size()-i-1)) a=false;
	}
	return a;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> a, bool b){
	std::vector<int> vektor_prostih, vektor_slozenih, rez1, rez2;
	
	for(int i: a){
		if(DaLiJeProst(i)) vektor_prostih.push_back(i);
		if((!DaLiJeProst(i)&&(i!=1))||(i==0)) vektor_slozenih.push_back(i);
	}
	
	for(int p: vektor_prostih){
		if(DaLiJeTernarniSimetrican(PretvoriUTernarni(p)))
		rez1.push_back(p);
		}
		
	for(int c: vektor_slozenih){
		if(DaLiJeTernarniSimetrican(PretvoriUTernarni(c)))
		rez2.push_back(c);
	}
	
	for(int i=0; i<rez1.size(); i++)
	for(int j=i+1; j<rez1.size(); j++){
		if(rez1.at(i)==rez1.at(j)){
			rez1.erase(rez1.begin()+j);
			j--;
		}
	}
	
	for(int i=0; i<rez2.size(); i++)
	for(int j=i+1; j<rez2.size(); j++){
		if(rez2.at(i)==rez2.at(j)){
			rez2.erase(rez2.begin()+j);
			j--;
		}
	}
	
	if(b) return rez1;
	return rez2;
}

int main ()
{
	std::vector<int> a;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
    int c, t;
 
    do{
    	std::cin>>c;
    	if(c!=-1) a.push_back(c);
    }while(c!=-1);
    std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    
    Ponovo:
    std::cin>>t;
    if(t!=1 && t!=0){
    	std::cout<<"Neispravan unos! "<<"Unesite ponovo: ";
    	goto Ponovo;
    }
    
    
    if(IzdvojiSimetricneTernarne(a, true).size()==0 && (t)){
    	std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
    	goto Kraj;
    }
    
    if(IzdvojiSimetricneTernarne(a, false).size()==0 && (t==0)){
    	std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
    	goto Kraj;
    }
    
    if(t){
    	std::cout<<"Prosti simetricni brojevi iz vektora su: ";
    	for(int i=0; i<IzdvojiSimetricneTernarne(a, t).size(); i++){
    		std::cout<<IzdvojiSimetricneTernarne(a, t).at(i);
    	    if(i!=IzdvojiSimetricneTernarne(a, t).size()-1) std::cout<<", ";
    	}
      std::cout<<".";
    }
    
    class SabiranjeVektora +operator(std::vector<int> a, std::vector<int> b){
    	std::vector<int> c;
    	for (auto i : a)
    	for (auto j : b)
    	c.push_back(i+j);
    	
    	return c;
    }
    
    class MnozenjeVektora *operator(std::vector<int> a, std::vector<int> b){
    	std::vector<int> c;
    	for(auto i : a)
    	for(auto j : b)
    	c.push_back(i*j);
    	
    	return c;
    }

   class OduzimanjeVektora -operator(std::vector<int> a, std::vector<int> b){
   	std::vector<int> c;
   	for(auto i : a)
   	for(auto j : b)
   	c.push_back(i-j);
   	
   	return c;
   }
   
   class DijeljenjeVektora /operator(std::vector<int> a, std::vector<int> b){
   	std::vector<int> c;
   	for(auto i : a)
   	for(auto j : b)
   	c.push_back(i/j);i++e
   }
    
    else{
    	std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
    	for(int i=0; i<IzdvojiSimetricneTernarne(a, t).size(); i++){
    		std::cout<<IzdvojiSimetricneTernarne(a, t).at(i);
    	    if(i!=IzdvojiSimetricneTernarne(a, t).size()-1) std::cout<<", ";
    	}
      std::cout<<".";
    }
    Kraj:
	return 0;
}