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
#include <deque>
#include <limits>


bool Prost(int a){
	if(a%2==0 && a!=2 && a!=-2) return false;
	a=std::abs(a);
	int kor=std::sqrt(a);
	for(int i=3;i<=kor;i+=2) if(a%i==0) return false;
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool p){
	std::vector<int> povratni;
	if(p){
		for(int i=0;i<v.size();i++){
			if(Prost(v.at(i)) && v.at(i)!=1 && v.at(i)!=-1){
				std::deque<int> ternarni;
				std::deque<int> ternarniNaopako;
				int broj(v.at(i));
				do{
					int s(0);
					s=std::abs(broj%3);
					ternarni.push_back(s);
					ternarniNaopako.push_front(s);
					broj/=3;
				}while(broj);
				if(ternarni==ternarniNaopako){
					int j=0;
					for(j=0;j<povratni.size();j++) if(v.at(i)==povratni.at(j)) break;
					if(j==povratni.size()) povratni.push_back(v.at(i));
				}
				/*unsigned long long int ternarni(0), ternarniNaopako(0);
				int k(1);
				int broj(v.at(i));
				while(broj){
					unsigned long long int s(0);
					s=abs(broj%3);
					ternarni+=s*k;
					ternarniNaopako+=s;
					ternarniNaopako*=10;
					k*=10;
					broj/=3;
				}
				ternarniNaopako/=10;
				if(ternarni==ternarniNaopako){
					int j=0;
					for(j=0;j<povratni.size();j++) if(v.at(i)==povratni.at(j)) break;
					if(j==povratni.size()) povratni.push_back(v.at(i));
				}
				ternarni=0;
				ternarniNaopako=0;
				k=1;*/
			}
		}
	}
	else {
		for(int i=0;i<v.size();i++){
			if(!Prost(v.at(i)) && v.at(i)!=1 && v.at(i)!=-1){
				std::deque<int> ternarniNaopako;
				std::deque<int> ternarni;
				int broj(v.at(i));
				do{
					int s(0);
					s=std::abs(broj%3);
					ternarni.push_back(s);
					ternarniNaopako.push_front(s);
					broj/=3;
				}while(broj);
				if(ternarni==ternarniNaopako){
					int j=0;
					for(j=0;j<povratni.size();j++) if(v.at(i)==povratni.at(j)) break;
					if(j==povratni.size()) povratni.push_back(v.at(i));
				}
			/*	unsigned long long int ternarni(0), ternarniNaopako(0);
				int k(1);
				int broj(v.at(i));
				while(broj){
					int s(0);
					s=abs(broj%3);
					ternarni+=s*k;
					ternarniNaopako+=s;
					ternarniNaopako*=10;
					k*=10;
					broj/=3;
				}
				ternarniNaopako/=10;
				if(ternarni==ternarniNaopako) {
					int j=0;
					for(j=0;j<povratni.size();j++) if(v.at(i)==povratni.at(j)) break;
					if(j==povratni.size()) povratni.push_back(v.at(i));
				}
				ternarni=0;
				ternarniNaopako=0;
				k=1;*/
			}
		}
	}
	return povratni;
}
int main ()
{
/*
	std::vector<int> a; 
	std::vector<int> c;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int x(0);
	bool unos(true);
	int b(0);
	
	while(std::cin>>x && x!=-1) a.push_back(x);
		
		
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
		
	while(unos){
		std::cin>>b;
		if(b==1 || b==0) unos=false;
		else std::cout<<"Neispravan unos! Unesite ponovo: ";
		
	}

	
	
	c=IzdvojiSimetricneTernarne(a, b);
	unsigned long long int velicina(c.size());
	if(b && velicina) {
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(unsigned long long int i=0;i<velicina;i++){
			if(i!=velicina-1)std::cout<<c.at(i)<<", ";
			else std::cout<<c.at(i)<<".";
		}
	}
	else if(b && velicina ==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else if(!b && velicina){
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(unsigned long long int i=0;i<velicina;i++){
			if(i!=velicina-1)std::cout<<c.at(i)<<", ";
			else std::cout<<c.at(i)<<".";
		}
	}
	else std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	return 0;*/
//AT16 (neaktivni): vektor koji sadrzi INT_MIN
//RATIONALE: posto funkcija treba da uzme u obzir i negativne brojeve
//           to znaci da se moze napraviti greska kod: n = abs (n).
//           Znamo da su predznacni brojevi vecinom asimetricni, tj.
//           smatra se 0 kao pozitivna. Pa imamo npr tipove sa opsegom
//           [-128, 127]. Ako je maksimalan pozitivan broj koji moze stati
//           u taj tip npr 127, onda NE SMIJEMO raditi n = abs (n) za n < 0
//           jer bismo dobili: n = abs (-128) sto bi bilo +128, ali to
//           NE MOZE stati u taj tip jer mu je maksimum 127. Isto je i sa int
//ISPRAVNO RJESNJE: uopste NE TREBA negirati broj, nego samo brojeve koji 
//          predstavljaju njegove cifre (koji mogu biti negativni).
//          Znamo da je c negativan u izrazu c = a % b kad je a < 0 ^ b > 0, npr:
//                 -16 % 3 = -1
//          pa je onda potrebno negirati (uzeti apsolutni vrijednost) SAMO
//          te jedne cifre, npr:
//          do 
//              {
//                 int cifra = std::abs (n % 3); //<---- OVDJE
//                 ...
//                 n /= 3;
//              }
//          while (n != 0);

    int mini = std::numeric_limits<int>::min();
    std::vector<int> v = {mini, mini, mini, mini, 0, 1, 2, 3, 4, 5, 6, -7, -8, mini};
    auto v1 = IzdvojiSimetricneTernarne(v, true), v2 = IzdvojiSimetricneTernarne(v, false);
    for (const auto &x : v1) 
        std::cout << x << " ";
    for (const auto &x : v2)
        std::cout << x << " ";
	
	
	
	return 0;
}
// -2147474068 -1