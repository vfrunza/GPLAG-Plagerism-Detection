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
#include <vector>
#include <cmath>
#include <deque>

typedef std::vector<int> vektor;
enum Smjer {Opadajuci, Rastuci};

bool JesuLiJednaki(double x, double y, double Eps = 1e-10) //funkcija kojom poredimo jednakost dva broja tipa double
{
	return ( std::fabs(x-y) <= Eps*(std::fabs(x)+std::fabs(y)) );
}

bool StepenDvojke(int n) //funkcija koja vraća "true" ukoliko je broj "n" stepen dvojke
{
	if(n==0) return false;
	int x;
	double y;
	y = (std::log(n))/(std::log(2));
	x = y;
	return JesuLiJednaki(x, y);
}

std::deque<vektor> MaksimalniPodnizoviStepenaDvojke( vektor v, Smjer t)
{
	std::deque<vektor> d;
	vektor pomocni;
	int brojac(0);    //koristimo ga kao indikaciju da trebamo dodati elemenat na vec postojeci vektor od deka
	int k(0);         //sa "k" prolazimo kroz vektore deka "d"
	int velicina(1);  //koristimo je za "resize" deka
	if(t==Rastuci) {
		for(int i=0; i<int(v.size()); i++) {
			if( (i+1)<int(v.size()) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1)) && brojac==0 && v.at(i)<=v.at(i+1) ) { //provjera da li se poslije trenutnog elementa nalazi još jedan, da li su brojevi na "i-tom" i "i+1-om" mjestu stepeni dvojke, da li je prvi manji od drugog
				d.resize(velicina);
				(d.at(k)).push_back(v.at(i));
				(d.at(k)).push_back(v.at(i+1));
				brojac++;
			} else if( (i+1)<int(v.size()) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1)) && brojac!=0 &&  v.at(i)<=v.at(i+1) ) {
				(d.at(k)).push_back(v.at(i+1));
			} else if(brojac!=0) {
				brojac=0;
				velicina++;
				k++;
			}
		}
	} else if(t==Opadajuci) { //sve je isto kao i za rastuci niz, osim znaka "<"
		for(int i=0; i<int(v.size()); i++) {
			if( (i+1)<int(v.size()) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1)) && brojac==0 && v.at(i)>=v.at(i+1) ) {
				d.resize(velicina);
				(d.at(k)).push_back(v.at(i));
				(d.at(k)).push_back(v.at(i+1));
				brojac++;
			} else if( (i+1)<int(v.size()) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1)) && brojac!=0 &&  v.at(i)>=v.at(i+1) ) {
				(d.at(k)).push_back(v.at(i+1));
			} else if(brojac!=0) {
				brojac=0;
				velicina++;
				k++;
			}
		}
	}
	return d;
}


int main ()
{
	vektor v; //prvi parametar koji šaljemo u funkciju
	bool t; //drugi parametar koji šaljemo u funkciju
	std::deque<vektor> d;
	std::cout<<"Unesite broj elemenata vektora: ";
	double vel;
	for(;;) {
		std::cin>>vel;
		if(std::cin) {
			int provjera;
			provjera = vel;
			if(vel<0 || !JesuLiJednaki(provjera, vel)) std::cout<<"Neispravan unos! Unesite ponovo: ";
			else break;
		} else {
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
	v.resize(vel);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<vel; i++) {
		for(;;) {
			std::cin>>v.at(i);
			if(std::cin) break;
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	double testni;
	for(;;) {
		std::cin>>testni;
		if(std::cin) {
			if(JesuLiJednaki(testni, 1)) {
				t = true;
				break;
			} else if(JesuLiJednaki(testni,2)) {
				t = false;
				break;
			} else std::cout<<"Neispravan unos! Unesite ponovo: ";
		} else {
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
	d = MaksimalniPodnizoviStepenaDvojke(v, Smjer(t));
	if(d.size()==0) {
		if(t) std::cout<<"Ulazni vektor ne sadrzi nijedan monotono rastuci podniz ciji su svi elementi stepeni dvojke.";
		else std::cout<<"Ulazni vektor ne sadrzi nijedan monotono opadajuci podniz ciji su svi elementi stepeni dvojke.";
	} else {
		if(t) std::cout<<"Maksimalni rastuci podnizovi: \n";
		else std::cout<<"Maksimalni opadajuci podnizovi: \n";
		for(vektor a:d) {
			for(int b:a) std::cout<<b<<" ";
			std::cout<<"\n";
		}
	}
	return 0;
}