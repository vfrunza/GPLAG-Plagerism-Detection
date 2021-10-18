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
#include <type_traits>
#include <iomanip>

enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template<typename Kontejner>

Kontejner PjescaniSat (Kontejner x, SmjerKretanja Smjer)
{
	decltype(x) Konacni;
	if(x.size()%2==0) {
		throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
		return Konacni;
	}
	for(int i=0; i<x.size(); i++) {
		auto Trenutna = x.at(i);
		bool JeLiKvadratna(true);
		for(int j=0; j<Trenutna.size(); j++) {
			if(Trenutna.size()!=Trenutna.at(j).size()) {
				JeLiKvadratna = false;
				break;
			}
		}
		if(!JeLiKvadratna) {
			throw std::domain_error("3D matrica nema oblik kocke");

		}

	}

	int red;
	if(Smjer == SmjerKretanja::GoreDolje) {
		for(int i=0; i<x.size(); i++) {
			auto Trenutna = x.at(i);
			red=Trenutna.size();
			typename std::remove_reference<decltype (x.at(i))>::type PjescaniKontejner;
			PjescaniKontejner.resize(Trenutna.size());
			for(int j=0; j<Trenutna.size()/2; j++) {
				for(int k=j; k<red; k++) {
					PjescaniKontejner.at(j).push_back(Trenutna.at(j).at(k));
				}
				red-=2;
			}
			PjescaniKontejner.at(Trenutna.size()/2).push_back(Trenutna.at(Trenutna.size()/2).at(Trenutna.size()/2));
			for(int j=Trenutna.size()/2; j<Trenutna.size(); j++) {
				for(int k=x.size()-j-1; k<red; k++) {
					PjescaniKontejner.at(j).push_back(Trenutna.at(j).at(k));
				}
				red+=2;
			}
			Konacni.push_back(PjescaniKontejner);
		}

	}
	if(Smjer == SmjerKretanja::DoljeGore) {
		for(int i=0; i<x.size(); i++) {
			auto Trenutna = x.at(i);
			red=Trenutna.size();
			typename std::remove_reference<decltype (x.at(i))>::type PjescaniKontejner;
			PjescaniKontejner.resize(Trenutna.size());
			for(int j=0; j<Trenutna.size()/2; j++) {
				for(int k=j; k<red; k++) {
					PjescaniKontejner.at(j).push_back(Trenutna.at(j).at(k));
				}
				red-=2;
			}
			PjescaniKontejner.at(Trenutna.size()/2).push_back(Trenutna.at(Trenutna.size()/2).at(Trenutna.size()/2));
			for(int j=Trenutna.size()/2; j<Trenutna.size(); j++) {
				for(int k=x.size()-j-1; k<red; k++) {
					PjescaniKontejner.at(j).push_back(Trenutna.at(j).at(k));
				}
				red+=2;
			}
			for (int i = 0; i < PjescaniKontejner.size()/2; i++)
				swap(PjescaniKontejner.at(i), PjescaniKontejner.at(PjescaniKontejner.size() - i - 1));
			Konacni.push_back(PjescaniKontejner);
		}

	}
	if(Smjer == SmjerKretanja::LijevoDesno) {
		for(int i=0; i<x.size(); i++) {
			auto Trenutna = x.at(i);
			red=Trenutna.size();
			typename std::remove_reference<decltype (x.at(i))>::type PjescaniKontejner;
			PjescaniKontejner.resize(Trenutna.size());
			for(int j=0; j<Trenutna.size()/2; j++) {
				for(int k=j; k<red; k++) {
					PjescaniKontejner.at(j).push_back(Trenutna.at(k).at(j));
				}
				red-=2;
			}

			PjescaniKontejner.at(Trenutna.size()/2).push_back(Trenutna.at(Trenutna.size()/2).at(Trenutna.size()/2));
			for(int j=Trenutna.size()/2; j<Trenutna.size(); j++) {
				for(int k=x.size()-j-1; k<red; k++) {
					PjescaniKontejner.at(j).push_back(Trenutna.at(k).at(j));
				}
				red+=2;
			}
			Konacni.push_back(PjescaniKontejner);
		}
	}
	if(Smjer == SmjerKretanja::DesnoLijevo) {
		for(int i=0; i<x.size(); i++) {
			auto Trenutna = x.at(i);
			red=Trenutna.size();
			typename std::remove_reference<decltype (x.at(i))>::type PjescaniKontejner;
			PjescaniKontejner.resize(Trenutna.size());
			for(int j=0; j<Trenutna.size()/2; j++) {
				for(int k=j; k<red; k++) {
					PjescaniKontejner.at(j).push_back(Trenutna.at(k).at(j));
				}
				red-=2;
			}
			PjescaniKontejner.at(Trenutna.size()/2).push_back(Trenutna.at(Trenutna.size()/2).at(Trenutna.size()/2));
			for(int j=Trenutna.size()/2; j<Trenutna.size(); j++) {
				for(int k=x.size()-j-1; k<red; k++) {
					PjescaniKontejner.at(j).push_back(Trenutna.at(k).at(j));
				}
				red+=2;
			}
			for (int i = 0; i < PjescaniKontejner.size()/2; i++)
				swap(PjescaniKontejner.at(i), PjescaniKontejner.at(PjescaniKontejner.size() - i - 1));
			Konacni.push_back(PjescaniKontejner);
		}
	}
	if(Smjer == SmjerKretanja::NaprijedNazad) {
		for(int i=0; i<x.size(); i++) {
			red = x.size();
			auto Trenutna = x.at(i);
			typename std::remove_reference<decltype (x.at(i))>::type PjescaniKontejner;
			PjescaniKontejner.resize(Trenutna.size());
			for(int j=0; j<x.size()/2; j++) {
				auto Trenutna = x.at(j);
				for(int k=j; k<red; k++) {
					PjescaniKontejner.at(j).push_back(Trenutna.at(i).at(k));
				}
				red-=2;
			}
			Trenutna = x.at(x.size()/2);
			PjescaniKontejner.at(Trenutna.size()/2).push_back(Trenutna.at(i).at(x.at(i).size()/2));
			for(int j=x.size()/2; j<x.size(); j++) {
				auto Trenutna = x.at(j);
				for(int k=x.size()-j-1; k<red; k++) {
					PjescaniKontejner.at(j).push_back(Trenutna.at(i).at(k));
				}
				red+=2;
			}
			Konacni.push_back(PjescaniKontejner);
		}
	}
	if(Smjer == SmjerKretanja::NazadNaprijed) {
		for(int i=0; i<x.size(); i++) {
			red = x.size();
			auto Trenutna = x.at(i);
			typename std::remove_reference<decltype (x.at(i))>::type PjescaniKontejner;
			PjescaniKontejner.resize(Trenutna.size());
			for(int j=0; j<x.size()/2; j++) {
				auto Trenutna = x.at(j);
				for(int k=j; k<red; k++) {
					PjescaniKontejner.at(j).push_back(Trenutna.at(i).at(k));
				}
				red-=2;
			}
			Trenutna = x.at(x.size()/2);
			PjescaniKontejner.at(Trenutna.size()/2).push_back(Trenutna.at(i).at(x.at(i).size()/2));
			for(int j=x.size()/2; j<x.size(); j++) {
				auto Trenutna = x.at(j);
				for(int k=x.size()-j-1; k<red; k++) {
					PjescaniKontejner.at(j).push_back(Trenutna.at(i).at(k));
				}
				red+=2;
			}
			for (int i = 0; i < PjescaniKontejner.size()/2; i++)
				swap(PjescaniKontejner.at(i), PjescaniKontejner.at(PjescaniKontejner.size() - i - 1));
			Konacni.push_back(PjescaniKontejner);
		}
	}
	return Konacni;
}

int main ()
{
	std::vector<std::deque<std::deque<int>>> Probni;
	int n;
	std::cout<<"Unesite dimenziju (x/y/z): ";
	std::cin>>n;
	while(n<=0) {
		std::cout<<"Dimenzija nije ispravna, unesite opet: ";
		std::cin>>n;
	}
	Probni.resize(n);
	std::cout<<"Unesite elemente kontejnera: ";
	for(int i=0; i<n; i++) {
		std::deque<std::deque<int> > Dek ;
		for(int j=0; j<n; j++) {
			std::deque<int> tmpDek;
			int tmp;
			for(int k=0; k<n; k++) {
				std::cin>>tmp;
				tmpDek.push_back(tmp);
			}
			Dek.push_back(tmpDek);
		}
		Probni.at(i) = Dek;
	}
	int smjer;
	std::cout<<"Unesite smjer kretanja [0 - 5]: ";
	std::cin>>smjer;
	while(smjer>=6 || smjer<0) {
		std::cout<<"Smjer nije ispravan, unesite opet: ";
		std::cin>>smjer;
	}
	
	std::vector<std::deque<std::deque<int>>> ispis;
	try {
		ispis = PjescaniSat(Probni, SmjerKretanja(smjer));
	} catch(std::range_error izuzetak) {
		std::cout<<std::endl <<"Izuzetak: " << izuzetak.what() << std::endl;
		return 0;
	} catch(std::length_error izuzetak) {
		std::cout <<std::endl<<"Izuzetak: "<< izuzetak.what() << std::endl;
		return 0;
	}
	std::cout<<std::endl<<"Pjescani sat unesene matrice je:"<<std::endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<ispis.at(i).size(); j++) {
			for(int k=0; k<ispis.at(i).at(j).size(); k++) {
				if(k==0) {
					if(j!=((ispis.at(i).size()/2)))
						std::cout<<std::setw(4)<<std::fixed<<ispis.at(i).at(j).at(k);
					else std::cout<<std::setw(4*(ispis.at(i).size()/2 + 1))<<std::fixed<<ispis.at(i).at(j).at(k);
				} else {
					if(j!=((ispis.at(i).size()/2)))
						std::cout<<std::setw(4)<<std::fixed<<ispis.at(i).at(j).at(k);
					else std::cout<<std::setw(4*(ispis.at(i).size()/2 + 1)+1)<<std::fixed<<ispis.at(i).at(j).at(k);
				}

			}
			std::cout<<std::endl;
		}
		std::cout<<std::endl<<std::endl;
	}
	return 0;
}