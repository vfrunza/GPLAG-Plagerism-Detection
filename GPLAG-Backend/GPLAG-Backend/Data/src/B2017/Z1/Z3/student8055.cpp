/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <deque>
#include <vector> 
enum Smjer {Opadajuci, Rastuci};
typedef std::vector<int> vektor;
std::vector<vektor> Monotonost (vektor v, int p, Smjer s){
int temp(v.at(p));
vektor pomocni;
int brojac(1);
for (int i=p+1; i<v.size(); i++)
    {
    if (s) {
    if (v.at(i)>=temp) {
        temp = v.at(i);
        brojac++;
    }
    else  {
    break;
    }
    }
    if (!s) {
    if (v.at(i)<=temp) {
        temp = v.at(i);
        brojac++;
    }
    else  {
    break;
    }
    }



    }
    std::vector<vektor> finalni;
    while  (brojac != 1){
    pomocni.resize(0);
    for (int i=p; i<p+brojac; i++){   //udari enter ako nije...
        pomocni.push_back(v.at(i)); }
        finalni.push_back(pomocni);
    
        brojac--;
        
    }

return finalni;
}

bool StepenDvojke (int x){
for (;;){
if (x<=0) return 0;
if (x==1) return 1;
if (x%2 != 0) return 0;
x=x/2;
}
}

bool validacija (vektor v) {
	if (v.size()) {
	for (int i=0; i<v.size(); i++)
		if (!StepenDvojke(v.at(i))) return false;
	} 
return true; 
}
bool uporedi (vektor a, vektor b) {
	int j;
	for (int k=0; k<b.size(); k++) {
	int i(0);
	j = k; 
	int pogodak(0);
	  while (i<a.size() && j<b.size()){
	  	if (a.at(i)==b.at(j)) { 
	  		i++; 
	  		j++; 
	  		pogodak++;
	  		if (pogodak == a.size()) return true;
	  	} 
	  	else break; 
	  }
	}
	  return false;
}
bool provjeriDaLiSeSarzi (vektor v, int p, vektor pomocni, int q){
		int x(p+v.size());
		int y (q+pomocni.size()); 
	for (int k=0; k<pomocni.size(); k++){
	int a(p);
	int b(q+k); 
	int i(0);
	int j(k);
	int pogodak(0);
	while (a<x && b<y && i<v.size() && j<pomocni.size()){
		if (a==b && v.at(i) == pomocni.at(j)){
			a++; 
			b++;
			i++;
			j++; 
			pogodak++; 
		}
		else break; 
		if (pogodak==v.size()) return true;
	}
		
}
	return false;
}
bool daLiJePodniz (vektor v, int p, std::deque<vektor> pomocni, vektor indeks, int j  ){
	for (int i=0; i<pomocni.size(); i++){
		if (i ==j) continue; 
		if (provjeriDaLiSeSarzi(v, p, pomocni.at(i), indeks.at(i)) )  return true;
	}
	return false; 
}

std::deque<vektor> MaksimalniPodnizoviStepenaDvojke (vektor v, Smjer smjer) {
	std::deque<vektor> pomocni, dek;
	vektor pozicija; 
	for (int i=0; i<v.size(); i++){
		for (int j=0; j<Monotonost(v,i,smjer).size(); j++) {
			if (validacija(Monotonost(v,i,smjer).at(j))) {
				pomocni.push_back(Monotonost(v,i,smjer).at(j));
				pozicija.push_back(i);
			}
		}
	}

	if (pomocni.size()){
		for (int i=0; i<pomocni.size(); i++)
			{
				if (!daLiJePodniz(pomocni.at(i), pozicija.at(i), pomocni, pozicija, i)) dek.push_back(pomocni.at(i)); 
			}
	}
return dek; 
}
int main ()
{
	
int x,z;
std::cout<<"Unesite broj elemenata vektora: "; 
std::cin>>x;
vektor y;
std::cout<<"Unesite elemente vektora: ";
for (int i=0; i<x; i++)
	{
		std::cin>>z;
		y.push_back(z);
	}
std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
int k;
std::cin>>k;
Smjer smjer;
if(k==1) smjer = Rastuci ;
else smjer=Opadajuci; 
auto final (MaksimalniPodnizoviStepenaDvojke (y, smjer));
std::cout<<"Maksimalni ";
if (k==1) std::cout<<"rastuci "; 
else std::cout<<"opadajuci "; 
std::cout<<"podnizovi: \n"; 
for (int i=0; i<final.size(); i++){
	for (auto q : final.at(i)) std::cout<<q<<" "; 
std::cout<<std::endl;
}
 
 
 

	return 0;
}