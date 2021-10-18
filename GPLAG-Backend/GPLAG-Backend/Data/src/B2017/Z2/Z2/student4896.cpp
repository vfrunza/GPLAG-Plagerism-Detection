/*B 2017/2018, Zadaća 2, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <stdexcept>

enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename Kontejner>

Kontejner KreirajKont(Kontejner &kont)
{
	Kontejner Povratni;
	Povratni.resize(kont.size());

	for(int i=0; i<kont.size(); i++) {
		auto &K(Povratni.at(i));
		Povratni.at(i).resize(kont.size());
		int br1(0);
		for(int j=Povratni.at(i).size()/2; j>=0; j--) {
			K.at(j).resize(2*br1+1);
			br1++;
		}
		int br2(0);
		for(int l=K.size()/2; l<K.size(); l++) {
			K.at(l).resize(2*br2+1);
			br2++;
		}
	}
	return Povratni;
}


template <typename TipKontejner>

TipKontejner PjescaniSat(TipKontejner &kont, SmjerKretanja SK)
{
	TipKontejner Novi_kont(KreirajKont(kont));

	if(SK==SmjerKretanja::GoreDolje) {
		for(int i=0; i<kont.size(); i++) {
			for(int j=0; j<=kont.at(i).size()/2; j++) {
				for(int k=0; k<Novi_kont.at(i).at(j).size(); k++) {
					Novi_kont.at(i).at(j).at(k)=kont.at(i).at(j).at(k+j);
				}
			}
			int p(0);
			for(int j=kont.at(i).size()-1; j>kont.at(i).size()/2; j--) {
				for(int k=0; k<Novi_kont.at(i).at(j).size(); k++) {
					Novi_kont.at(i).at(j).at(k)=kont.at(i).at(j).at(k+p);
				}
				p++;
			}
		}
	} else if(SK==SmjerKretanja::DoljeGore) {
		for(int i=0; i<kont.size(); i++) {
			auto &Mat(kont.at(i));
			for(int j=0; j<=Mat.size()/2; j++) {
				for(int k=0; k<Novi_kont.at(i).at(j).size(); k++) {
					Novi_kont.at(i).at(j).at(k)=Mat.at(Mat.size()-j-1).at(k+j);
				}
			}
			int p(0);
			for(int j=Mat.size()-1; j>Mat.size()/2; j--) {
				for(int k=0; k<Novi_kont.at(i).at(j).size(); k++) {
					Novi_kont.at(i).at(j).at(k)=Mat.at(p).at(k+p);
				}
				p++;
			}
		}
	} else if(SK==SmjerKretanja::DesnoLijevo) {
		for(int i=0; i<kont.size(); i++) {
			auto &Mat(kont.at(i));
			int l(0);
			for(int k=Mat.at(i).size()-1; k>=Mat.at(i).size()/2; k--) {
				int p(0);
				for(int j=l; j<Mat.size()-l; j++) {
					Novi_kont.at(i).at(l).at(p)=Mat.at(j).at(k);
					p++;
				}
				l++;
			}
			int p(0);
			for(int k=0; k<Mat.at(i).size()/2; k++) {
				int m(0);
				for(int j=p; j<Mat.size()-p; j++) {
					Novi_kont.at(i).at(Mat.size()-1-p).at(m)=Mat.at(j).at(k);
					m++;
				}
				p++;
			}
		}
	} else if(SK==SmjerKretanja::LijevoDesno) {
		for(int i=0; i<kont.size(); i++) {
			auto &Mat(kont.at(i));
			int p(0);
			for(int k=Mat.at(i).size()-1; k>=Mat.at(i).size()/2; k--) {
				int m(0);
				for(int j=p; j<Mat.size()-p; j++) {
					Novi_kont.at(i).at(Mat.size()-1-p).at(m)=Mat.at(j).at(k);
					m++;
				}
				p++;
			}
			int l(0);
			for(int k=0; k<Mat.at(i).size()/2; k++) {
				int p(0);
				for(int j=l; j<Mat.size()-l; j++) {
					Novi_kont.at(i).at(l).at(p)=Mat.at(j).at(k);
					p++;
				}
				l++;
			}
		}
	} else if(SK==SmjerKretanja::NaprijedNazad) {
		int p(0);
		for(int i=0; i<kont.size(); i++) {
			int l(0);
			for(int n=0; n<=kont.size()/2; n++) {
				int j(0);
				for(int k=l; k<kont.at(n).at(p).size()-l; k++) {
					Novi_kont.at(i).at(l).at(j)=kont.at(l).at(p).at(k);
					j++;
				}
				l++;
			}
			l=kont.size()-1;
			for(int n=kont.size()-1; n>kont.size()/2; n--) {
				int j(0),m(0);
				for(int k=m; k<kont.at(n).at(p).size()-m; k++) {
					Novi_kont.at(i).at(n).at(j)=kont.at(l).at(p).at(k);
					j++;
				}
				m++;
				l--;
			}
			p++;
		}
	} else if(SK==SmjerKretanja::NazadNaprijed) {
		int p(0);
		for(int i=0; i<kont.size(); i++) {
			int l(0),m=kont.size()-1;
			for(int j=0; j<=kont.at(p).size()/2; j++) {
				int n(0);
				for(int k=l; k<kont.at(j).at(p).size()-l; k++) {
					Novi_kont.at(i).at(m).at(n)=kont.at(l).at(p).at(k);
					n++;
				}
				m--;
				l++;
			}
			m=0,l=0;
			int r=kont.size()-1;
			for(int j=kont.size()-1; j>kont.size()/2; j--) {
				int n(0);
				for(int k=l; k<kont.at(j).at(p).size()-l; k++) {
					Novi_kont.at(i).at(m).at(n)=kont.at(r).at(p).at(k);
					n++;
				}
				r--;
				m++;
				l++;
			}
			p++;
		}
	}
	return Novi_kont;
}


int main ()
{
	try {
		int a(0);
		std::cout << "Unesite dimenziju (x/y/z): " ;
		do {
			std::cin >> a;
			if(a>=0) break;
			if(a<0) std::cout << "Dimenzija nije ispravna, unesite opet: ";
		} while(a<=0);
		std::cout << "Unesite elemente kontejnera: ";
		std::vector<std::deque<std::deque<int>>> Vec;
		Vec.resize(a);
		for(int i=0; i<a; i++) {
			Vec.at(i).resize(a);
			for(int j=0; j<a; j++) {
				Vec.at(i).at(j).resize(a);
				for(int k=0; k<a; k++) {
					std::cin >> Vec.at(i).at(j).at(k);
				}
			}
		}

		std::cout << "Unesite smjer kretanja [0 - 5]: ";
		int sk(0);
		do {
			std::cin >> sk;
			if(sk<0 || sk>5) std::cout << "Smjer nije ispravan, unesite opet: ";
			else break;
		} while(sk<0 || sk>5);
		std::cout << std::endl;
		int kocka(Vec.size());
		for(int i=0; i<Vec.size(); i++) {
			auto M(Vec.at(i));
			int br_red_kol(M.size());
			if(br_red_kol!=kocka) throw std::domain_error("Izuzetak: 3D matrica nema oblik kocke");
			for(int j=0; j<M.size(); j++) {
				if(br_red_kol!=M.at(j).size()) {
					throw std::domain_error("Izueztak: 3D matrica nema oblik kocke");
				}
			}
			if(i==Vec.size()-1) {
				if(a%2==0) throw std::length_error("Izuzetak: 3D kontejner ne zadovoljava uvjet neparnosti");
			}
		}
		std::vector<std::deque<std::deque<int>>> Novi(PjescaniSat(Vec,SmjerKretanja(sk)));
		std::cout << "Pjescani sat unesene matrice je:" << std::endl;
		std::cout << std::endl;
		for(int i=0; i<Novi.size(); i++) {
			int l=4;
			for(int j=0; j<Novi.at(i).size(); j++) {
				for(int k=0; k<Novi.at(i).at(j).size(); k++) {
					if(k==0 && j<=Novi.at(i).size()/2) {
						std::cout << std::setw(l) << Novi.at(i).at(j).at(k);
						l+=4;
					} else if(k==0 && j>Novi.at(i).size()/2) {
						l-=4;
						std::cout << std::setw(l-4) << Novi.at(i).at(j).at(k);
					} else std::cout << std::setw(4) << Novi.at(i).at(j).at(k);
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	} catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	} catch(std::length_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	} catch (...) {
	}
	return 0;
}