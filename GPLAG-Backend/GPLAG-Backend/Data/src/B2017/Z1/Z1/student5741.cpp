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

bool Prost(int a){
	for(int i(2); i*i <= a; i++){
		if(a%i==0) return false;
	}
	return true;
}

std::vector<int> NapraviTernarne(std::vector<int> v){
	std::vector<int> pomocni;
	for(int i(0); i < v.size(); i++){
		int broj(v.at(i)), koef(1), suma(0);
		while(abs(broj)!=0){
			suma += (abs(broj)%3)*koef;
			broj/=3;
			koef *=10;
		}
		pomocni.push_back(suma);
	}
	return pomocni;
}

bool Simetrican(int n){
	std::vector<int> v1;
	std::vector<int> v2;
	int cifra;
	while(n!=0){
		cifra = n%10;
		v1.push_back(cifra);
		v2.push_back(cifra);
		n = n/10;
	}
	for(int i(0); i < v1.size()/2; i++){
		if(v1.at(i) != v2.at(v2.size()-i-1)) return false;
	}
	return true;
}

std::vector<int> Ponavljanje(std::vector<int> v){
	int i(0);
	while(i < v.size()-1){
		for(int j(i+1); j < v.size(); j++){
			if(v.at(i) == v.at(j)){
				v.erase(v.begin()+j);
				j--;
			}
		}
		i++;
	}
	return v;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool pv){
	std::vector<int> pomocni(NapraviTernarne(v));
	std::vector<int> pomocni2;
	int brojac(0);
	if(pv){
		for(int i(0); i < pomocni.size(); i++){
			if(Simetrican(pomocni.at(i)) && Prost(v.at(i))) {
				brojac++;
				pomocni2.resize(brojac);
				pomocni2.at(brojac-1)=v.at(i);
			}
		}
	} else {
		for(int i(0); i < pomocni.size(); i++){
			if(Simetrican(pomocni.at(i)) && !Prost(v.at(i))) {
				brojac++;
				pomocni2.resize(brojac);
				pomocni2.at(brojac-1)=v.at(i);
				
			}
		}
	}
	if (pomocni2.size()==0)
		return pomocni2;
	pomocni2 = Ponavljanje(pomocni2);
	return pomocni2;
}

int main ()
{
	int k(0);
	int pv;
	std::vector<int> v;
	std::vector<int> v1;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	while(k!=-1){
		std::cin >> k;
		if(k==-1) break;
		v.push_back(k);
	}
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do{
		std::cin >> pv;
		if(pv!=0 && pv!=1) std::cout << "Neispravan unos! Unesite ponovo: ";
		else break;
	}while(true);
	v1 = IzdvojiSimetricneTernarne(v, pv);
	if(pv){
		if(v1.size()==0) {std::cout << "Nema prostih simetricnih brojeva u vektoru."; return 0;}
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for(int i(0); i < v1.size(); i++){
			if(i==v1.size()-1) std::cout << v1.at(i) << ".";
			else std::cout << v1.at(i) << ", ";
		}
	} else {
		if(v1.size()==0) {std::cout << "Nema slozenih simetricnih brojeva u vektoru."; return 0;}
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i(0); i < v1.size(); i++){
			if(i==v1.size()-1) std::cout << v1.at(i) << ".";
			else std::cout << v1.at(i) << ", ";
		}
	}
	return 0;
}