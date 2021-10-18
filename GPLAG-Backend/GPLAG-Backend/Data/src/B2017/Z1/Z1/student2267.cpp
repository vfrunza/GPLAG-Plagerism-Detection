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
#include<cmath>
#include <vector>

bool DaliJeProst(int x)
{
	for(int i=2; i<x; i++) {
		if(x%i==0) return false;

	}
	return true;
}
bool simetricno(int x)
{
	int brojac=0;
	int b=x,i=0;
	std::vector<int> niz;
	while(b>0) {
		niz.push_back(b%10);
		b/=10;
		i++;
	}

	brojac=i;
	i=0;
	
		for(i = 0; i <= brojac/2; i++) {
			if(niz.at(i) != niz.at(brojac-i-1)){
				return false;
			}

		}
		return true;
}

bool ternarni(int x)
{
	int broj=0;
	while(x>0){
		broj *= 10;
		broj += x%3;
		
		x /= 3;
	}
	
	return simetricno(broj); 
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int>vektor , bool v)
{
	std::vector<int>novivektor;
	int n;


	for(int k=0;k<vektor.size()-1;k++){
		for(int m=k+1;m<vektor.size();m++){
			if(vektor.at(k)==vektor.at(m) || vektor.at(m)==0 || vektor.at(m)==1){
				n=m;
				for(int l=n+1;l<vektor.size() ; l++){
					vektor.at(n)=vektor.at(l);
					n++;
					
				}
				vektor.resize(vektor.size()-1);
			}
		}
	}
	
		if(v == true){
			for(int j=0;j<vektor.size();j++){
				if(DaliJeProst(abs(vektor.at(j)))==true && ternarni(abs(vektor.at(j)))== true)
				novivektor.push_back(vektor.at(j));
			}
		}
		else{
			for(int j=0;j<vektor.size();j++){
				if(DaliJeProst(abs(vektor.at(j)))==false && ternarni(abs(vektor.at(j)))==true)
				novivektor.push_back(vektor.at(j));
			}
		}

	

	return novivektor;
}

int main (){
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
   
    std::vector<int>v,v2;
    int n;
    do
    {
    	std::cin>>n;
    	if(n!=-1)
    		v.push_back(n);
    }while(n!=-1);
    
    std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    unos:
    std::cin>>n;
    if(n==1)
    {
    	v2=IzdvojiSimetricneTernarne(v,true);
    	if(v2.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
    	else std::cout<<"Prosti simetricni brojevi iz vektora su: ";
    }
    else if(n==0){
     v2=IzdvojiSimetricneTernarne(v,false);
     if(v2.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
    else  std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
    }
    else {
    	std::cout << "Neispravan unos! Unesite ponovo: ";
    	goto unos;
    }
    
    for (int i = 0; i < v2.size(); i++) {
    	std::cout<<v2.at(i);
    	if(i==v2.size()-1)
    	std::cout<<".";
    	else
    	std::cout<<", ";
    }
    
    return 0;
}