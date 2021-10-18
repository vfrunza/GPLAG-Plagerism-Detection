#include <iostream>
#include <cmath>
#include <vector>
typedef std::vector<int> Vektor;
bool Da_li_je_prost (int n){
	if (n==0) return false;
	if (n<0) n=n*(-1);
	for (int i=2;i<=n;i++){
	if (n%i==0 && i!=n)
	return false;
	}
	return true;
}
int Pretvori_u_ternarni (int n){
	int ternarni=0,br, k=0, cifra=n;
	if (n<0) n=n*(-1);
	while(n!=0){
		br=n%3;
		n=n/3;
		ternarni=ternarni + br*pow(10,k);
		k++;
	} 
	if (cifra<0)
	ternarni=ternarni*(-1);
	return ternarni;
}
bool Da_li_je_simetrican (int n){
	if (n<0) n=n*(-1);
	int k=0, temp=Pretvori_u_ternarni(n), br, cifra=0,probni=Pretvori_u_ternarni(n);
	while (probni!=0){
		probni=probni/10;
		k++;}
		
	while (temp!=0){
		k--;
		br=temp%10;
	    temp=temp/10;
	    cifra=cifra + br*pow(10,k);
	}
	if (cifra==Pretvori_u_ternarni(n)) return true;
	else  
	return false;
}
Vektor IzdvojiSimetricneTernarne (Vektor v, bool prosti){
	Vektor povratni, zavrsni;
	for (int i=0;i<v.size();i++){
		if (v.at(i)!=1&& v.at(i)!=(-1)){
				if(prosti && Da_li_je_prost(v.at(i))&& Da_li_je_simetrican(v.at(i))){
					povratni.push_back (v.at(i)); }
			else if (prosti==0 && Da_li_je_prost(v.at(i))==0 && Da_li_je_simetrican(v.at(i))==1){
						povratni.push_back(v.at(i));
			}
	}
		}
		if (povratni.size()==0 ) return povratni;
		zavrsni.push_back(povratni.at(0));
		for (int i=1; i<povratni.size(); i++){
			for (int j=0; j<i; j++){
				if (povratni.at(j)==povratni.at(i)) 
				break;
				if (j==i-1) 
				zavrsni.push_back(povratni.at(i));
			}
		}
return zavrsni;
}
int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	Vektor v,s;
    int i=0;
    int j;
		do{
		int cifra;
		std::cin>>cifra;
		if (cifra==-1) break;
		v.push_back(cifra);
		i++;
		}while (v.at(i-1)!=(-1));
		std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	    std::cin>>j;
		while (j!=0 &&j!=1){
			std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>j;
		}
		if (j==1){
			s=IzdvojiSimetricneTernarne(v,j);
			if (s.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
			else{ 
				std::cout<<"Prosti simetricni brojevi iz vektora su: ";
				for (int i=0; i<s.size();i++){
					if (i==(s.size()-1)) std::cout<<s.at(i)<<".";
					else
				std::cout<<s.at(i)<<", ";
			}
		} }
		
		else if (j==0){
			s=IzdvojiSimetricneTernarne(v,j);
			if (s.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			else{ 
				std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
				for (int i=0;i< s.size();i++){
					if (i==(s.size()-1)) std::cout<<s.at(i)<<".";
					else
				     std::cout<<s.at(i)<<", ";
			} }}
		return 0;
}