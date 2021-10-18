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
#include <stdexcept>
#include <vector>
#include <deque>
#include <iomanip>
#include <type_traits>
enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename Kontejner>
Kontejner PjescaniSat(Kontejner kont, SmjerKretanja smjer)
{
	int duz=kont.size();
	Kontejner sat(duz);
	for(int i=0 ; i<kont.size() ; i++) {
		for(int j=0 ; j<kont.at(i).size() ; j++) {
			if(kont.at(i).at(j).size()!=kont.at(i).size() || kont.at(i).at(j).size()!=kont.size() || kont.at(i).size()!=kont.size())
				throw std::domain_error ("3D matrica nema oblik kocke");
		}
	}
	if(kont.size()==0) return sat;
	if(kont.size()%2==0) throw std::length_error ("3D kontejner ne zadovoljava uvjet neparnosti");

	typename std::remove_reference<decltype(kont.at(0))>::type dva;



	if(smjer==SmjerKretanja::GoreDolje) {
		for(int i=0 ; i<duz ; i++) {
			typename std::remove_reference<decltype(kont.at(0))>::type dva;

			int k(-1),d(duz);
			for(int j=0 ; j<duz ; j++) {
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type v;
				if(j<=duz/2) {
					k += 1;
					d -= 1;
				} else {
					k -= 1 ;
					d +=1;
				}
				int l(k);
				for( ; l<=d ; l++)		v.push_back(kont.at(i).at(j).at(l));
				dva.push_back(v);
			}
			sat.push_back(dva);
		}
	}

	if(smjer==SmjerKretanja::DoljeGore) {
		for(int i=0 ; i<duz ; i++) {
			typename std::remove_reference<decltype(kont.at(0))>::type dva;

			int k(-1),d(duz);
			for(int j=duz-1 ; j>=0 ; j--) {
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type v;
				if(j>=duz/2) {
					k += 1;
					d -= 1;
				} else {
					k -= 1 ;
					d +=1;
				}
				int l(k);
				for( ; l<=d ; l++)	v.push_back(kont.at(i).at(j).at(l));
				dva.push_back(v);
			}
			sat.push_back(dva);
		}
	}

	if(smjer==SmjerKretanja::DesnoLijevo) {
		for(int i=0 ; i<duz ; i++) {
			typename std::remove_reference<decltype(kont.at(0))>::type dva;

			int j(-1),d(duz);
			for(int k=duz-1 ; k>=0 ; k--) {
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type v;
				if(k>=duz/2) {
					j +=1;
					d -=1;
				} else {
					j-=1 ;
					d+=1;
				}
				int l(j);
				for( ; l<=d ; l++)	v.push_back(kont.at(i).at(l).at(k));
				dva.push_back(v);
			}
			sat.push_back(dva);
		}
	}

	if(smjer==SmjerKretanja::LijevoDesno) {
		for(int i=0 ; i<duz ; i++) {
			typename std::remove_reference<decltype(kont.at(0))>::type dva;

			int j(-1),d(duz);
			for(int k=0 ; k<duz ; k++) {
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type v;
				if(k<=duz/2) {
					j +=1;
					d -=1;
				} else {
					j-=1 ;
					d+=1;
				}
				int l(j);
				for( ; l<=d ; l++)	v.push_back(kont.at(i).at(l).at(k));
				dva.push_back(v);
			}
			sat.push_back(dva);
		}
	}

	if(smjer==SmjerKretanja::NaprijedNazad) {
		for(int j=0 ; j<duz ; j++) {
			typename std::remove_reference<decltype(kont.at(0))>::type dva;

			int k(-1),d(duz);
			for(int i=0 ; i<duz ; i++) {
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type v;
				if(i<=duz/2) {
					k +=1;
					d -= 1;
				} else {
					k -=1;
					d += 1;
				}
				int l(k);
				for( ; l<=d ; l++) v.push_back(kont.at(i).at(j).at(l));
				dva.push_back(v);
			}
			sat.push_back(dva);
		}
	}

	if(smjer==SmjerKretanja::NazadNaprijed) {
		for(int j=0 ; j<duz ; j++) {
			typename std::remove_reference<decltype(kont.at(0))>::type dva;

			int k(-1),d(duz);
			for(int i=duz-1 ; i>=0 ; i--) {
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type v;
				if(i>=duz/2) {
					k +=1;
					d -= 1;
				} else {
					k -=1;
					d += 1;
				}
				int l(k);
				for( ; l<=d ; l++) v.push_back(kont.at(i).at(j).at(l));
				dva.push_back(v);
			}
			sat.push_back(dva);
		}
	}
	return sat;
}

int main ()
{
	try {
		std::vector<std::deque<std::deque<int>>> v ;
		std::cout<<"Unesite dimenziju (x/y/z): ";
		int n;
		do {
			std::cin>>n;
			if(n<0) std::cout << "Dimenzija nije ispravna, unesite opet: " ;
		} while(n<0);


		v.resize(n);
		for(int i=0 ; i<n ; i++) v.at(i).resize(n);

		std::cout<<"Unesite elemente kontejnera: ";
		for(int i=0 ; i<n ; i++) {
			for(int j=0 ; j<n ; j++) {
				for(int k=0 ; k<n ; k++) {
					int a;
					std::cin>>a;
					v.at(i).at(j).push_back(a);
				}
			}
		}
		int b;
		std::cout << "Unesite smjer kretanja [0 - 5]: ";
		do {

			std::cin >> b;
			if(b<0 || b>5) std::cout << "Smjer nije ispravan, unesite opet: " ;
		} while(b<0 || b>5);

		SmjerKretanja s(SmjerKretanja::NaprijedNazad);
		if (b == 0)  s = SmjerKretanja::NaprijedNazad;
		else if (b == 1)  s = SmjerKretanja::NazadNaprijed;
		else if (b == 2)  s = SmjerKretanja::GoreDolje;
		else if (b == 3)  s = SmjerKretanja::DoljeGore;
		else if (b == 4)  s = SmjerKretanja::LijevoDesno;
		else if (b == 5)  s = SmjerKretanja::DesnoLijevo;


		std::vector<std::deque<std::deque<int>>> v1 (PjescaniSat(v, s));
		std::cout<< std::endl << "Pjescani sat unesene matrice je:" ;
		for(int i=0 ; i<v1.size() ; i++) {
			for(int j=0 ; j<v1.at(i).size() ; j++) {
				if(j<=n/2) {
					int x(0);
					while(x<j) {
						std::cout<<"    ";
						x++;
					}
				}
				if(j>n/2) {
					int x(n-1);
					while(x>j) {
						std::cout<<"    ";
						x--;
					}
				}

				for(int k=0 ; k<v1.at(i).at(j).size() ; k++) {

					std::cout<<std::setw(4)<<v1.at(i).at(j).at(k);
				}
				std::cout<<std::endl;
			}
			std::cout<<std::endl;
		}
	}

	catch(std::domain_error e) {
		std::cout<<std::endl<<"Izuzetak: "<<e.what();
	} catch(std::length_error e) {
		std::cout<<std::endl<<"Izuzetak: "<<e.what();
	}
	return 0;
}