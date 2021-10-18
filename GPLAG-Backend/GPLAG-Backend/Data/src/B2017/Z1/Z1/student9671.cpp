#include <iostream>
#include<vector>
#include<cmath>
#include<deque>
typedef std::vector<int> Vektor ;
typedef std::deque<int> Deque ;




int KoverzijaIzDekadnogUTernarni (int p)
{
    if(p<0) p=-p ;
	int rem,sum {0},i {1} ;
	while(p!=0){
		rem=p%3;
		sum=sum + (i*rem);
		p=p/3;
		i=i*10;


	}  ;
	return sum ;
}



int DaLiJeBrojSimetrican(int v)
{
	int z=KoverzijaIzDekadnogUTernarni(v) ;
    int s ;
	Deque t ;
	Deque k ;
	
	 while(z!=0){
		s=z%10 ;
		t.push_front(s) ;
		k.push_back(s) ;
		z/=10 ;
	} ;

	if (t==k) return true  ;
	else return false ;
}

bool DaLiJeProst (int n) {

	
		bool prost {true} ;
	
		for(int i=2; i<=std::abs(sqrt(n));i++) {

			if(abs(n)%i==0) prost=false ;
			
		}
			return prost ;
	}
	
void IzbaciPonavljanja(Vektor &s) {
	
	
	for(int i{0};i<s.size()-1;i++) {
		for(int j{i+1}; j<s.size();j++) {
			
		
		
		if(s.at(i)==s.at(j)){ s.erase(s.begin()+j); j--; }
       }
	}
}
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int>v,bool n)

{
	Vektor x ;
         if(n == 1) {  for(int i(0); i<v.size(); i++) {
           
		if(DaLiJeProst(v.at(i)) && abs(v.at(i)>1)&& DaLiJeBrojSimetrican(abs(v.at(i)))) x.push_back(v.at(i)) ;
		
	}}
	if (n == 0){for(int i(0); i<v.size(); i++) {
           
		if(DaLiJeProst(v.at(i)) == (false) && DaLiJeBrojSimetrican(abs(v.at(i)))) x.push_back(v.at(i)) ;
		
	}}
	if(x.size()!=0) 
	IzbaciPonavljanja(x) ;
	
	return x ;
}



int main ()
{
	int broj,n;
	Vektor v ;

	std::cout<<"Unesite elemente vektora (-1 za kraj):" ;
	do {
		std::cin>>broj;
		if(broj!=(-1)) v.push_back(broj) ;
	}  while(broj!=(-1)) ;


	std::cout<<" Unesite: 1 - za proste brojeve, 0 - za slozene brojeve:" ;
	do{
		std::cin>>n;
		if(n!=0 && n!=1) std::cout<<" Neispravan unos! Unesite ponovo:" ;
		else break ;
	} while(1) ;
	
	if(n==1) {
		
		Vektor S (IzdvojiSimetricneTernarne(v,1)) ;
		if(S.size()!=0) {
         std::cout<<" Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<S.size(); i++) {
				std:: cout <<S.at(i) ;
				if(i!=S.size()-1) {
					std::cout<<", " ;
				}
				
			}std::cout<<"." ;
		} else
			std::cout<<" Nema prostih simetricnih brojeva u vektoru." ;

	} else if(n==0) {
	
	Vektor D(IzdvojiSimetricneTernarne(v,0));

	if(D.size()!=0) {
   	std::cout<<" Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<D.size(); i++) {
			std:: cout <<D.at(i) ;
			if(i!=D.size()-1) {
				std::cout<<", " ;
			}
			
		}std::cout<<"." ;
	} else
		std::cout<<" Nema slozenih simetricnih brojeva u vektoru." ;
}

	return 0 ;
}