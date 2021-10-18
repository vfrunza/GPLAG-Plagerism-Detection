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
#include <iomanip>

std::vector<int> Vektor(std::vector<int> v)
{
	std::vector<int> c;
	for(int i=0; i<v.size(); i++) {
		for(int j=i+1; j<v.size(); j++) {
			if(v.at(j)==v.at(i)) {
				v.erase(v.begin()+j);
			}
		}
		c.push_back(v.at(i));
	}
	return c;
}


bool DaLiJeProst(int broj)
{
	bool logicka(true);
	for(int i=2; i<std::abs(broj); i++) {
		if(std::abs(broj)%i==0) {
			logicka=false;
			break;
		}
	}
	return logicka;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool logicka)
{
	std::vector<int> s;
	if(logicka) {

		for(int i=0; i<v.size(); i++) {
			int d(v.at(i));
			int y(v.at(i));
			bool l(DaLiJeProst(v.at(i)));
			if(l==true) {
				//brojanje cifara, ternarna reprezentacija
				int br(0);
				std::vector<int> b;
				do {
					int ostatak=std::abs(d%3);
					b.push_back(ostatak);
					d/=3;
					br++;
				} while(d!=0);
				//broj u ternarnoj
				int ternarna(0);
				for(int j=0; j<b.size(); j++) {
					ternarna+=b.at(j)*pow(10, br-1);
					br--;
				}

				//da li je simetrican;
				int m(0);
				int n(0);
				n=ternarna;
				while(ternarna!=0) {
					int z=ternarna%10;
					ternarna=ternarna/10;
					m=m*10+z;
				}
				if(m==n) {
					s.push_back(y);
				}
			}
		}
	} else { //ako je logicka(false), uzima slozene brojeve
		for(int i=0; i<v.size(); i++) {
			int x(v.at(i));
			int d(v.at(i));
			int k=DaLiJeProst(v.at(i));
			if(k==false) {
				//ternarna
				int br(0);
				std::vector<int> a; //vektor formiran od ostataka
				do {
					int ostatak=std::abs(d%3);
					a.push_back(ostatak);
					br++;
					d=d/3;
				} while(d!=0);

				//broj u ternarnoj reprezentaciji
				int ternarna(0);
				for(int k=0; k<a.size(); k++) {
					ternarna+=a.at(k)*pow(10, br-1);
					br--;
				}

				//Da li je simetrican
				int m(0);
				int n(0);
				n=ternarna;
				while(ternarna!=0) {
					int z=ternarna%10;
					ternarna=ternarna/10;
					m=m*10+z;
				}
				if(m==n) {
					s.push_back(x);
				}
			}
		}
	}

	return s;
}
int main ()
{

	std::vector<int> v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int unos;
	do {
		std::cin>>unos;
		if(unos!=-1) {
			v.push_back(unos);
		}
	} while(unos!=(-1));
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int b;
	std::cin>>b;
	if(b!=1 && b!=0) {
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>b;
	}

	if(b==1) {
		std::vector<int> a, m(Vektor(v));

		a=IzdvojiSimetricneTernarne(m, 1);
		if(a.size()==0) {
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		} else if(a.size()!=0) {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<a.size(); i++) {
				if(i==a.size()-1) {
					std::cout<<a.at(i)<<".";
				} else {
					std::cout<<a.at(i)<<", ";
				}
			}
		}

	}

	else if(b==0) {
		std::vector<int> b, p(Vektor(v));
		b=IzdvojiSimetricneTernarne(p, 0);
		if(b.size()==0) {
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		} else if(b.size()!=0) {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<b.size(); i++) {
				if(i==b.size()-1) {
					std::cout<<b.at(i)<<".";
				} else {
					std::cout<<b.at(i)<<", ";
				}
			}

		}
	}
	return 0;
}