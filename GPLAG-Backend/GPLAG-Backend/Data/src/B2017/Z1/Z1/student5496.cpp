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

//Pomocna f-ja koja vraca 1 ako je broj prost, 0 ako nije
bool DaLiJeProst(int n){
	if(n<=1) return 0;
	for(int i(2); i<=std::sqrt(n); i++){
		if(n==2) return 1;
		else if(n%i==0) return 0;
	}
	return 1;
}

//Pomocna f-ja koja pretvara u ternarni broj
int Ternarni(int n){
	int x=0;
	while(n!=0){
    	int n1=n%3;
	    x=x*10+n1;
	    n/=3;
	}
	int tern_br=0;
	while(x!=0){
		tern_br=tern_br*10+x%10;
		x/=10;
	}
	return tern_br;
}

//Pomocna f-ja koja poredi da li je broj simetrican
bool DaLiJeSimetrican(int n){
	int stari(n); //cuvam broj poslan kao parametar radi poredjenja
	int novi=0;
	while(n!=0){
		novi=novi*10+n%10;
		n/=10;
	}
	if(novi==stari) return 1;
	return 0;
}

// F-ja IzdvojiSimetricneTernarne
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool x){
	std::vector<int> novi;
	//izdvajamo proste ili slozene brojeve u ovisnosti od drugog parametra kojeg smo poslali f-ji
	if(x){
		for(int i(0); i<v.size(); i++){
			int znak=1;
			if(v.at(i)<0) znak=-1;
			if((DaLiJeProst(v.at(i)*znak)) && (DaLiJeSimetrican(Ternarni(v.at(i))))) novi.push_back(v.at(i));
		}
	}
	else {
		for(int i(0); i<v.size(); i++){
			int znak=1;
			if(v.at(i)<0) znak=-1;
			if((!DaLiJeProst(v.at(i)*znak)) && (DaLiJeSimetrican(Ternarni(v.at(i))))) novi.push_back(v.at(i));
		}
	}
	return novi;
}

int main ()
{
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int x;
	do{
		std::cin>>x;
		if(x==-1) break;
		v.push_back(x);
	}while(x!=-1);
	int broj;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for(;;){
		std::cin>>broj;
		if(broj==0 || broj==1)  break;
		else std::cout<<"Neispravan unos! Unesite ponovo: ";
	} 
	std::vector<int> novi=IzdvojiSimetricneTernarne(v,broj);
	if(novi.size()==0 && broj==1){
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		return 0;
	}
	else if(novi.size()!=0 && broj==1){
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i(0); i<novi.size()-1; i++)
	    std::cout<<novi.at(i)<<", ";
	    std::cout<<novi.at(novi.size()-1)<<".";
	}
	else if(novi.size()==0 && broj==0){
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
        return 0;	
	}
	else if(novi.size()!=0 && broj==0){
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i(0); i<novi.size()-1; i++)
		std::cout<<novi.at(i)<<", ";
		std::cout<<novi.at(novi.size()-1)<<".";
	}
	return 0;
}