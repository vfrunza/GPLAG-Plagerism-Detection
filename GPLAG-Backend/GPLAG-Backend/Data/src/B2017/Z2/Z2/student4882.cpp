#include <iomanip>
#include <stdexcept>
#include <deque>
#include <string>
#include <vector>
#include <iostream>
#include <limits>

enum class SmjerKretanja {
	NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename Name>
auto PjescaniSat (Name kont, SmjerKretanja smjer) -> Name {
	Name p=kont;
	Name t=p;
	int n=kont.size();
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (p.at(i).at(j).size()!=n) throw std::domain_error("3D matrica nema oblik kocke");
			if (j==n-1) break;
		}
		if (p.at(i).size()!=n) throw std::domain_error("3D matrica nema oblik kocke");
		if (i==n-1) break;
	}
	if (n%2==0) {throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");}
	// trostrukom petljom kreiramo pjescane satove
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int k=0; k<n; k++) {
				if (smjer==SmjerKretanja::GoreDolje) t.at(i).at(j).at(k)=p.at(i).at(j).at(k);
				if (smjer==SmjerKretanja::DoljeGore) t.at(i).at(j).at(k)=p.at(i).at(n-1-j).at(k);
				if (smjer==SmjerKretanja::NaprijedNazad) t.at(i).at(j).at(k)=p.at(j).at(i).at(k);
				if (smjer==SmjerKretanja::NazadNaprijed) t.at(i).at(j).at(k)=p.at(n-1-j).at(i).at(k);
				if (smjer==SmjerKretanja::DesnoLijevo) t.at(i).at(j).at(k)=p.at(i).at(k).at(n-1-j);
				if (smjer==SmjerKretanja::LijevoDesno) t.at(i).at(j).at(k)=p.at(i).at(k).at(j);
				if (k==n-1) break;
			}
			if (j==n-1) break;
		}
		if (i==n-1) break;
	}
	// stvaramo nove varijable kako bismo kreirali novu 3D matricu zadanog tipa
	Name q (n);
	typename std::remove_reference<decltype(kont.at(0))>::type Kolona;
	typename std::remove_reference<decltype(kont.at(0).at(0))>::type Red;
	for (int i=0; i<n; i++) {
		q.push_back(Kolona);
		int b=0;
		for (int j=0; j<n/2; j++) {
			q.at(i).push_back(Red);
			for (int k=0; k<n-b; k++) {
				q.at(i).at(j).push_back(0);
				if (k==(n-b-1)) break;
			}
			b=b+2;
			if (j==(n-1)) break;
		}
		for (int j=n/2; j<n; j++) {
			q.at(i).push_back(Red);
			for (int k=0; k<n-b; k++) {
				q.at(i).at(j).push_back(0);
				if (k==(n-b-1)) break;
			}
			b=b-2;
			if (j==(n-1)) break;
		}
		if (i==(n-1)) break;
	}
	// u novokreiranu 3D matricu ubacujemo zeljene elemente
	int kk(0);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			kk=0;
			for (int k=0; k<n; k++) {
				if ((j>k and j<(n-k-1)) or (j<k and j>(n-k-1))) continue;
				else q.at(i).at(j).at(kk)=t.at(i).at(j).at(k);
				kk++;
				if (k==n-1) break;
			}
			if (j==n-1) break;
		}
		if (i==n-1) break;
	}
	return q;
}

int main ()
{
	try {
		std::vector<std::vector<std::vector<int>>> v, q;
		int n;
		std::cout << "Unesite dimenziju (x/y/z): ";
		while (1) {
			std::cin >> n;
			if (n>=0) break;
			else std::cout << "Dimenzija nije ispravna, unesite opet: ";
		}
		std::cout << "Unesite elemente kontejnera: ";
		int k;
		for (int i=0; i<n; i++) {
			v.resize(i+1);
			for (int j=0; j<n; j++) {
				v.at(i).resize(j+1);
				for (int l=0; l<n; l++) {
					std::cin >> k;
					v.at(i).at(j).push_back(k);
				}
			}
		}
		int p;
		std::cin.ignore(10000, '\n');
		std::cout << "Unesite smjer kretanja [0 - 5]: ";
		while (1) {
			std::cin >> p;
			if (p>=0 and p<=5) break;
			else std::cout << "Smjer nije ispravan, unesite opet: ";
		}
		std::cout << "\n";
		SmjerKretanja s=static_cast<SmjerKretanja> (p);
		q=PjescaniSat(v, s);
		std::cout << "Pjescani sat unesene matrice je:" << std::endl;
		for (int i=0; i<n; i++) {
			for (int j=0; j<int(n/2); j++) {
				for (int l=0; l<q.at(i).at(j).size(); l++) {
					int f=q.at(i).at(j).size();
					if (l==0 and l!=(f-1)) std::cout << std::right << std::setw(4+4*j) << q.at(i).at(j).at(l);
					else if (l==(f-1)) std::cout << std::right << std::setw(4) << q.at(i).at(j).at(l);
					else std::cout << std::right << std::setw(4) << q.at(i).at(j).at(l);
				}
				std::cout << std::endl;
			}
			for (int j=int(n/2); j<n; j++) {
				for (int l=0; l<q.at(i).at(j).size(); l++) {
					int f=q.at(i).at(j).size();
					if (j==int(n/2)) std::cout << std::right << std::setw(4+4*(n-j-1)+(n-j-1)-int(n/2)) << q.at(i).at(j).at(l);
					else if (l==0 and l!=(f-1)) std::cout << std::right << std::setw(4+4*(n-j-1)) << q.at(i).at(j).at(l);
					else if (l==(f-1)) std::cout << std::right << std::setw(4) << q.at(i).at(j).at(l);
					else std::cout << std::right << std::setw(4) << q.at(i).at(j).at(l);
 				}
 				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	}
	catch (std::domain_error izuzetak1) {
		std::cout << "Izuzetak: " << izuzetak1.what() << std::endl;
	}
	catch (std::length_error izuzetak2) {
		std::cout << "Izuzetak: " << izuzetak2.what() << std::endl;
	}
	return 0;
}
