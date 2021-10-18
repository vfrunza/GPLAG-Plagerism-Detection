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

bool DaLiJeProst(int n)
{
	bool prost(true);
	
	if(n<0) n*=(-1);
	
	if(n==0 || n==1){
		prost=false;
		return prost;
	}
	
	if(n==2) return prost;
	
	for(int i=2; i<=std::sqrt(n); i++){
		if(n%i==0){
		prost=false;
		break;
	}
	 }
	 
	 return prost;
	
}

int PretvoriUTernarni (int n){
	
	int zapamtiZnak(0);
	
	if(n<0) {
		n*=(-1);
		zapamtiZnak=1;
	}
	
	int baza(1);
	int broj=n;
	int brojac(0);
	
	while( (broj/=3) > 0){
		brojac++;
	}
	
	for(int i(0); i<brojac; i++){
		baza*=3;
	}
	
	int cifra(0), ternarni(0);
	
	while(baza!=0){
		
		cifra=n/baza;
		ternarni+=cifra;
		ternarni*=10;
		n=n%baza;
		baza/=3;
	}
	
	ternarni/=10;
	
	if(zapamtiZnak==1) ternarni*=(-1);
	
	return ternarni;
}

bool Simetrican (int n){
	int obrnuti(0);
	int broj=n;
	int cifra;
	
	do{ 
		cifra=n%10;
	obrnuti=(obrnuti*10)+cifra;
	n=n/10;
	
	} while(n!=0);
	
	if(broj==obrnuti) return true;
	else
	return false;
 	
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int>v , bool a){
	
	std::vector<int>noviVektor;
	int brojElemenata(0);
	
	if(a==true) {
		for(int i=0; i<v.size(); i++){
			if(DaLiJeProst(v.at(i))==true && Simetrican(PretvoriUTernarni(v.at(i)))==true) {
			
			noviVektor.push_back(v.at(i));
			brojElemenata++;
			
			if(brojElemenata>1){
			for(int j=0; j<brojElemenata-1; j++){
				
				if(noviVektor.at(j)==noviVektor.at(brojElemenata-1)) {
					noviVektor.resize(brojElemenata-1);
				}
	}
 }
	brojElemenata=noviVektor.size();
}
}
}
		
	else if(a==false){
		for(int i=0; i<v.size(); i++){
			if(DaLiJeProst(v.at(i))==false && Simetrican(PretvoriUTernarni(v.at(i)))==true) {
			
			noviVektor.push_back(v.at(i));
			brojElemenata++;
			if(brojElemenata>1){
			for(int j=0; j<brojElemenata-1; j++){
				
				if(noviVektor.at(j)==noviVektor.at(brojElemenata-1)) {
					noviVektor.resize(brojElemenata-1);
				}
	}
 }
	brojElemenata=noviVektor.size();
}
}
}
return noviVektor;
    
}
int main ()
{
	std::vector<int>vektor;
	std::vector<int>novi ;
	int broj;
	int vrsta;
	std::cout << "Unesite elemente vektora (-1 za kraj): " ;
	
	for(;;){
	std::cin>>broj;
	if(broj==(-1)) break;
	vektor.push_back(broj);
	}
	
    std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    std::cin>>vrsta;
    if(vrsta!=0 && vrsta!=1){
    do{
    	std::cout << "Neispravan unos! Unesite ponovo: ";
        std::cin>>vrsta;
    } while(vrsta!=0 && vrsta!=1 );
    
    }
	
	vrsta=bool(vrsta);
	novi=IzdvojiSimetricneTernarne(vektor, vrsta);
	
	if(vrsta==true){
		if(novi.size()==0) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		
		else{
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
	
	for(int i=0; i<novi.size(); i++){
		if(i==novi.size()-1) std::cout << novi.at(i) <<"." ;
	else 	std::cout << novi.at(i) << ", ";
	}
	}
	}
	
	else if(vrsta==false){
		
		if(novi.size()==0) std::cout << "Nema slozenih simetricnih brojeva u vektoru." ;
		else{
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		
			for(int i=0; i<novi.size(); i++){
		if(i==novi.size()-1) std::cout << novi.at(i) <<"." ;
	else 	std::cout << novi.at(i) << ", ";
	}
	}
	}
	return 0;
}