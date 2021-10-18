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


	bool DaLiJeProst(int broj){
 if (broj<=1)return false;
   for (int i=2; i<=sqrt(broj); i++){
   if(broj%i==0) return true;
    }
    return false;
    }
    
int Uterarni(int broj){
 int znak=1;
     if(broj<0) znak=-1;
     if(broj==0) return 0;
     broj*=znak;
     int rez=0;
     int cifra;
     int i=0;
    while(broj!=0){
    cifra=broj%3;
    rez+=cifra*pow(10,i);
    i++;
    broj/=3;
    }
    return rez*znak;
}

	
	bool DaLiJeSimetrican (int n) {
		if(n<0) n*=-1;
		int t=n, broj=0;
		while(t>0) {
			broj*=10;
			broj+=t%10;
			t/=10;
		}
		if(broj==n) return true;
		return false;
	}



std::vector<int> IzdvojiSimetricneTernarne (std::vector<int>v, bool prost) {
		std::vector<int>d;
	std::vector<int>e;
	for(int i=0; i<v.size(); i++) {
		if(DaLiJeProst(v.at(i))==true) {
			  int temp=Uterarni(v.at(i));
			 if((DaLiJeSimetrican(temp))==true) {
			 	d.push_back(v.at(i)); 
			 }
			 return d;
		    } 
		if(DaLiJeProst(v.at(i))==false) {
			int temp=Uterarni(v.at(i));
				if((DaLiJeSimetrican(temp))==true) {
					e.push_back(v.at(i));
				}
				return e;
			}
		}
	} 

	
int main () {
std::vector<int>a;
int unos;
std::cout << "Unesite elemente vektora (-1 za kraj) : ";
do {
	std::cin>> unos;
	if(unos!=-1) a.push_back(unos);
} while(unos!=-1);

int n;
std:: cout << "Unesite 1 - za proste brojeve, 0 - za slozene brojeve: ";
for(;;) {
std::cin >> n;
if(n!=1 || n!=0) break;
std::cout << "Neispravan unos! Unesite ponovo: ";
std::cin.clear();
std::cin.ignore(1000, '\n');
}

if(n==1) {
		std::vector<int>b=IzdvojiSimetricneTernarne(a, true);
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<int (b.size()); i++) {
		if(i==b.size()-1) 
	    std::cout << b.at(i) << "."; 
		else if(i!=b.size()-1) std::cout<< b.at(i) << ",";
		else std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	} 
} 

else if(n==0) {
	std::vector<int>c=IzdvojiSimetricneTernarne(a, false);
	std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	for(int i=0; i< int (c.size()); i++) {
		if(i==c.size()-1) 
		std::cout << c.at(i) << "."; 
		else if(i!=c.size()-1) std::cout<< c.at(i) << ",";
		else std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	} 
	
}
	return 0;
}