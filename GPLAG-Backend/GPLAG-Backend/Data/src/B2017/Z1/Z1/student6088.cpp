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
	bool prost=0;
	int i;
	
	for(i=2; i<abs(n); i++)
	if(n%i==0) break;
	
	if(i==abs(n))
	prost=1;
	return prost;
	
}

int DecimaltoTernary(int x){
	int ternarni = 0;
	int ostatak, i=1, korak = 1;
	
	while(x!=0){
		ostatak=x%3;
		x/=3;
		ternarni+=ostatak*i;
		i*=10;
	}
	return ternarni;
}

int reverse (int x){
	int obrnuti = 0, ostatak;
	
	while(x!=0){
		ostatak=x%10;
		obrnuti=obrnuti*10 + ostatak;
		x/=10;
		}
		return obrnuti;
}


std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> niz, bool kakav){
	
	std::vector<int> prosti;
	std::vector<int> slozeni;
	
	//pravljenje vektora prostih i slozenih brojeva
	
	for(int x : niz){
		if(DaLiJeProst(x))
		prosti.push_back(x);
		else
		slozeni.push_back(x);
	}
	
	std::vector<int> prosti1;
	std::vector<int> slozeni1;
	
	//pravljenje vektora prostih i slozenih simetricnih
	
	for(int x : prosti)
	if(DecimaltoTernary(x)==reverse(DecimaltoTernary(x)))
	prosti1.push_back(x);
		
	for(int x : slozeni)
	if(DecimaltoTernary(x)==reverse(DecimaltoTernary(x)))
	slozeni1.push_back(x);
		
	
	
	
	if(kakav==0)
		return slozeni1;
	
	else
	return prosti1;
	
	
}

int main ()
{
	
	std::vector<int> niz;
	int x;
	
	//unos elemenata vektora
	
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	for(;;){
		std::cin>>x;
		if(x==-1)
		break;
		if(std::find(niz.begin(), niz.end(), x) !=niz.end()) continue;
		niz.push_back(x);
	}
	
	
	
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	
	int y;
	
	//unos logičke konstante
	
	for(;;){
	std::cin >> y;
	if(y==1 || y==0)
	break;
	std::cout << "Neispravan unos! Unesite ponovo: ";
	}
	
	std::vector<int>nizprosti=IzdvojiSimetricneTernarne(niz, y);
	std::vector<int>nizslozeni=IzdvojiSimetricneTernarne(niz, y);
	
	//ispisi vektora
	
	if(y==1 && nizprosti.size()!=0){
	std::cout << "Prosti simetricni brojevi iz vektora su: ";
	

	
	for(int i=0;i<nizprosti.size();i++){
		std::cout << nizprosti.at(i);
		if(i!=nizprosti.size()-1)
		std::cout << ", ";
	}
	std::cout << ".";
	}
	
	
	
	else if(nizprosti.size()==0 && y==1)
	std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	
	if(y==0 && nizslozeni.size()!=0){
	std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	

	
	for(int i=0;i<nizslozeni.size();i++){
		std::cout << nizslozeni.at(i);
		if(i!=nizslozeni.size()-1)
		std::cout << ", ";
		
	}
	std::cout << ".";
	}
	
	else if(nizslozeni.size()==0 && y==0)
	std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	
	
	
	
	return 0;
}