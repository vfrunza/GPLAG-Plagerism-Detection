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

int Stepenuj(int n, int k)
{
	int broj(1);
	for(int i=1; i<=k; i++)
		broj *=n;
	return broj;
}

bool DaLiJeProst(int n){
	if (n<2) return false;
	int korijen_broja(std::sqrt(n));
	for(int i=2; i<=korijen_broja; i++){
		if(n%i==0)
			return false;
	}
	return true;
}


int  PretvoriUTernarne(int broj)
{
	
	int predznak(1);
	if(broj<0) {
		predznak = -1;
		broj *= -1;
	}
	
	int novi_broj(0), broj_cifara_novog(0); 
	while(broj!=0) {
		novi_broj = novi_broj*10 + broj%3;
		broj_cifara_novog++;
		broj /=3;
	}
	
	//treba okrenuti broj
	int ternarni(0), broj_cifara_ternarnog(0);;
	while(novi_broj!=0) {
		ternarni *= 10;
		ternarni += novi_broj%10;
		novi_broj /= 10;
		broj_cifara_ternarnog++;
	}
	if(broj_cifara_ternarnog < broj_cifara_novog) 
		ternarni *= Stepenuj(10, broj_cifara_novog-broj_cifara_ternarnog);
	return ternarni * predznak;
}


bool Simetrican(int ternarni)
{
	int br_cifara_ternarnog(0), br_cifara_naopakog(0), kopija(ternarni);
	while (kopija!=0) {
		kopija/=10;
		br_cifara_ternarnog++;
	}
	int naopak(0);
	
	kopija = ternarni;
	while(kopija!=0) {
		naopak = naopak * 10 + kopija%10;
		kopija /= 10;
	}
	
	kopija = naopak;
	while (kopija!=0) {
		kopija/=10;
		br_cifara_naopakog++;
	}
	
	if(naopak == ternarni &&  br_cifara_naopakog==br_cifara_ternarnog) return true;

	return false;
}


std::vector<int> IzdvojiSimetricneTernarne(std::vector<int>v, bool simetrican){ 
	if(v.size() == 0) return v; //ne smije 'ulaziti' u vektor koji je prazan
	//izbacuje elemente koji se ponavljaju
	for (int i=0; i<= v.size()-2; i++){
		if(v.size() == 1) break;
		for (int j=i+1; j<= v.size()-1; j++){
			if(j==i) j++;
			if(v.at(i) == v.at(j)) {
				v.erase(v.begin()+j);
				j--;
				
			}
		}
	}
	
	std::vector<int>a ;
	for (int x: v){
		if(x==1) continue; //ovo nisu ni prosti ni slozeni
		if(DaLiJeProst(std::abs(x))==simetrican)
			if(Simetrican(PretvoriUTernarne(x)))
				a.push_back(x);
	}
	return a;
}


int main ()
{
	int broj, izbor_broj;
	bool izbor;
	std::vector<int>v,x;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	
	std::cin>> broj;
	while(broj != -1){
		v.push_back(broj);
		std::cin>> broj;
	}
	
	
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> izbor_broj;
	while(izbor_broj !=0 && izbor_broj !=1){
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> izbor_broj;
	}
	izbor = izbor_broj;
	if(izbor){
		x = IzdvojiSimetricneTernarne(v,izbor);
		if(x.size() != 0) std::cout << "Prosti simetricni brojevi iz vektora su: ";
		else std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	}
	else{
		x = IzdvojiSimetricneTernarne(v,izbor);
		if(x.size() != 0) std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		else std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	}
	
	for(int i=0; i<x.size(); i++){
		if(i!=0) std::cout << ", ";
		std::cout << x.at(i);
		if(i==x.size()-1) std::cout << ".";
	}
	return 0;
}