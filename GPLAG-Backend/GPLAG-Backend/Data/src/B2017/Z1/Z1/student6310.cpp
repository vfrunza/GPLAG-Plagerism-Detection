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

bool SimentricanTernarniBroj (int broj){
	std::vector<int> a;
	int pomocna = broj;
	int temp(0);
	while(pomocna!=0){
		temp*=10;
		temp+=pomocna%3;
		pomocna/=3;
	}
	int n=temp;
	int temp2(0);
	while(n!=0){
		temp2*=10;
		temp2+=n%10;
		n/=10;
	}
	if(temp==temp2) return true;
	return false;
}

bool DaLiJeProst (int n){
	if(n<=1) n=abs(n);
	for(int i=2; i<=(std::sqrt(n)); i++){
		if(n%i==0) return false;
	}  
	return true; 
}

std::vector<int> OdstraniDuplikate (std::vector<int> v){
	bool brojac;
	std::vector <int> v_bez_duplikata;
	for(int x : v){
		brojac=false;
		for(int i=0; i<int(v_bez_duplikata.size()); i++)
		if (x==v_bez_duplikata.at(i)) brojac=true;
		if(brojac==false) v_bez_duplikata.push_back(x);
	}
	return v_bez_duplikata;
}
std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool logicka){
	std::vector<int> novi_vektor;
	for(int x : v){
		if(logicka==true){
			if(DaLiJeProst(x) && SimentricanTernarniBroj(x)) novi_vektor.push_back(x);
		} 
		else if(logicka==false){
			if(!(DaLiJeProst(x)) && SimentricanTernarniBroj(x)) novi_vektor.push_back(x);
		}
	}
	novi_vektor=OdstraniDuplikate(novi_vektor);
	return novi_vektor;
	
}

void IspisiMatricu (std::vector<int> v){
	if(v.size()==0){
		std::cout<< std::endl;
	}
	else{
		std::cout<< v.at(0);
		for(int i=1; i<v.size(); i++){
			std::cout<< ", " << v.at(i);
		}
	}
	std::cout<< ".";
	std::cout<< std::endl;
}
int main ()
{
	std::cout<< "Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> a;
	int broj;
	do{
		std::cin>> broj;
		if (broj!=-1) a.push_back(broj);
	} while (broj!=-1);
	
	
	int logicka;
	std::cout<< "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do{
		std::cin>> logicka;
		if(logicka!=0 && logicka !=1) std::cout<< "Neispravan unos! Unesite ponovo: ";
	} while (logicka!=0 && logicka!=1);
	
	
	std::vector<int> b = IzdvojiSimetricneTernarne(a, logicka);
	if (logicka==true){
		if(b.size()==0){
			std::cout<< "Nema prostih simetricnih brojeva u vektoru.";
		}else{
			std::cout<< "Prosti simetricni brojevi iz vektora su: ";
			IspisiMatricu(b);
		}
	} else if (logicka==false){
		if(b.size()==0){
			std::cout<< "Nema slozenih simetricnih brojeva u vektoru.";
		}else {
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
			IspisiMatricu(b);
		}
	}
	return 0;
}