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
#include <cmath>
#include <vector>



int Ternarni(int n){
	if(n<0) n=-n;
	int broj(0);
	int i(1);
	while(n!=0){
		
		broj=broj+(n%3)*i;
	n/=3;
		i=i*10;
	}
	return broj;
} 
/*
bool Simetrican(int n){
	int broj(0);
	int i(1);
	int b=Ternarni(n);
	int c=Ternarni(n);
	while(b!=0){
		broj+=(b%10)*i;
		b/=10;
		i*=10;
		
	}
	 if(broj==c) return true;
 	 return false;
	}
	*/
	bool Simetrican(int a){
		int n=Ternarni(a);
		if(n%10==0) return 0;
		int r=0;
		while(r<n){
			r=10*r+n%10;
			n/=10;
		}
		return n==r || n==r/10;
	}
	
	bool JeLiProst(int n){
		if(n<=1) return false;
		for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return false;
		}
		return true;
	}
	
	std::vector<int> PonavljaLiSe(std::vector<int> v){
		
		for(int i=0;i<v.size();i++){
			for(int j=i+1;j<v.size();j++){
				if(v.at(i)==v.at(j)){
					
					v.erase(v.begin()+j);				}
			}
		}
		return v;
	}
	std::vector<int> Prosti(std::vector<int> v){
		std::vector<int> a=PonavljaLiSe(v);
		std::vector<int> b;
		if(v.size()==0) return b;
		for(int i=0;i<a.size();i++){
			if(Simetrican(a.at(i)) && JeLiProst(a.at(i)))
			b.push_back(a.at(i));
		}
		
		return b;
	}
	
		std::vector<int> Slozeni(std::vector<int> v){
		std::vector<int> a=PonavljaLiSe(v);
		std::vector<int> b;
		if(v.size()==0) return b;
		for(int i=0;i<a.size();i++){
			if(Simetrican(a.at(i)) && !(JeLiProst(a.at(i))))
			b.push_back(a.at(i));
		}
		
		return b;
	}
	
	
	std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool a){
		std::vector<int> c;
		 if (a) 
		 c=Prosti(v);
		 else c=Slozeni(v);
		 return c;
		
	}
	
	
	
int main ()
{

	std::vector<int> Vektor;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	for(;;){
		int a;
		std::cin>>a;
		if(a && a!=-1)
		Vektor.push_back(a);
		else break;
	}
	if(Vektor.size()==0) return 0;
	int b;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
		std::cin>>b;
	if(!(b==0 || b==1))	for(;;){
		
		if(b==1) break;
		if(b==0) break;
		else std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>b;
		}
	/*
		if(b!=0 || b!=1) 		
		std::cin.ignore(1000,'\n');
		std::cout<<"Neispravan unos! Unesite ponovo: ";

		while(b!=0 || b!=1){
			std::cin>>b;
			if(b==0 || b==1) break;
			std::cin.clear();
			std::cin.ignore(10000,'\n');
		}
		*/
	
	
	std::vector<int> c;
	if(b==1) {
		
	c=Prosti(Vektor);
	bool vel=c.size();
	if(vel){
	std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		int i;
		for(i=0;i<c.size()-1;i++) std::cout<<c.at(i)<<", ";
		std::cout<<c.at(i)<<".";
	}
	else std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	}
	else if(b==0){
		
		c=Slozeni(Vektor);
		bool velicina=c.size();
		if(velicina){
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		int i;
		for(i=0;i<c.size()-1;i++) std::cout<<c.at(i)<<", ";
		std::cout<<c.at(i)<<".";
		}
		else std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	}
	
	/*
	bool b;

	std::vector<int> niz;
	if(b) niz=Prosti(Vektor);
	else niz=Slozeni(Vektor);
	
	 bool s=niz.size();
	if(!s && b) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else if(!s && !b) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else if(s && b) 
	{
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		int i;
		for(i=0;i<niz.size()-1;i++) std::cout<<niz[i];
		std::cout<<niz[i];
	}
	else if(!s && !b)
	{
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		int j;
		for(j=0;j<niz.size()-1;j++) std::cout<<niz[j];
		std::cout<<niz[j];
	}
	
 	int n;
	std::cout<<"Unesi n:";
	std::cin>>n;
	int a=Ternarni(n);
	bool b=Simetric(n);
	bool c=JeLiProst(n);
	std::cout<<a<<", "<<b<<", "<<c<<"; "<<sim(n);
	*/
	return 0;
}