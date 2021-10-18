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
bool ternarni (int x){
    long long int a (x); 
    if (a<0) a=-a;
    
    std::vector<int> t;
    for (;;){
        if (!a) break;
        t.push_back(a%3);
        a/=3;
    }
    int i(0);
    int j(int(t.size())-1);
    bool simetrican(1);
    while (i<j){
        if (t.at(i)!=t.at(j)) {simetrican=0; break;}
        i++;
        j--;
    }

    return simetrican;
}

bool prost (int x){
    long long int a (x);
    if (a<0) a=-a; 
    if (x==0) return false;
    for (int i=2; i<=std::sqrt(a); i++) {
        if (a%i==0) return false;
    }
return true;
}

bool daLiJeTu (std::vector<int> v, int x){
    for (int i=0; i<v.size(); i++)
        if (v.at(i)==x) return true;
    return false;
}


std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> vektor, bool logika){
    std::vector<bool> simetricni;
    for (int i=0; i<vektor.size(); i++){
        simetricni.push_back(ternarni(vektor.at(i)));
    }

    for (int i=0; i<vektor.size(); i++){
              if (simetricni.at(i)) {
                if (logika){
                    if (!prost(vektor.at(i)) || vektor.at(i)==1 || vektor.at(i)==-1) simetricni.at(i)=0;
                }
                if (!logika) {
                    if (prost(vektor.at(i)) || vektor.at(i)==1 || vektor.at(i)==-1) simetricni.at(i)=0;
                }
              }
        }
    std::vector<int> rezultat;
    for (int i=0; i<vektor.size(); i++) {
        if (simetricni.at(i) && !daLiJeTu(rezultat, vektor.at(i))) {  rezultat.push_back(vektor.at(i)); }
    }

return rezultat; 

}
int main()
{
std::vector<int> vektor; 
std::cout<<"Unesite elemente vektora (-1 za kraj): ";
int x;
for (;;)
{
    std::cin>>x; 
    if (x==-1) break;
    vektor.push_back(x); 
}
int logika;
std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
for (;;) {
std::cin>>logika;
if (logika !=0 && logika != 1) {std::cout<<"Neispravan unos! Unesite ponovo: ";} else break;
}

auto rezultat = IzdvojiSimetricneTernarne(vektor, logika);
if (!rezultat.size() && logika) {std::cout<<"Nema prostih simetricnih brojeva u vektoru."; return 0;}
if (!rezultat.size() && !logika) {std::cout<<"Nema slozenih simetricnih brojeva u vektoru."; return 0;}
if (logika) std::cout<<"Prosti";
else std::cout<<"Slozeni";
std::cout<<" simetricni brojevi iz vektora su: ";
bool zarez(0); 
for (auto y : rezultat ) { if (zarez) {std::cout<<", ";} std::cout<<y; zarez=1;}
std::cout<<".";





    return 0;
}
