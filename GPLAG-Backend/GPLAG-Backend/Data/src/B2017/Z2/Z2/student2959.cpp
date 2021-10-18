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
#include <type_traits>
#include <iomanip>
#include <stdexcept>

enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename kont>

kont PjescaniSat(kont a, SmjerKretanja s)
{
	kont p;
	if(a.size()==0) return p;
	int dimenzija=a.size();
	for(int i=0; i<dimenzija; i++) {
		if(a.at(i).size()!=dimenzija) throw std::domain_error ("3D matrica nema oblik kocke");
		for(int j=0; j<dimenzija; j++)
			if(a.at(i).at(j).size()!=dimenzija) throw std::domain_error ("3D matrica nema oblik kocke");
	}
	if(dimenzija%2==0) throw std::length_error ("3D kontejner ne zadovoljava uvjet neparnosti");

	if(s==SmjerKretanja::GoreDolje || s==SmjerKretanja::DoljeGore) {
		for(int i=0; i<dimenzija; i++) {
			p.push_back(typename std::remove_reference<decltype(a.at(i))>::type(1));
			for(int j=0; j<dimenzija; j++) {
				p.at(i).push_back(typename std::remove_reference<decltype(a.at(i).at(j))>::type(1));
				int put(0);
				for(int k=0; k<dimenzija; k++) {
					if(j<dimenzija/2+1) {
						if(k>=j && k<=dimenzija-1-j) {
							if(put==0 && j!=0) p.at(i).at(j).at(put)=a.at(i).at(j).at(k);
							else p.at(i).at(j).push_back(a.at(i).at(j).at(k));
							put++;
						}
					} else {
						if(k>=dimenzija-1-j && k<=j) {
							if(put==0 && j!=0) p.at(i).at(j).at(put)=a.at(i).at(j).at(k);
							else p.at(i).at(j).push_back(a.at(i).at(j).at(k));
							put++;
						}
					}

				}
			}
		}
	} else if(s==SmjerKretanja::LijevoDesno || s==SmjerKretanja::DesnoLijevo) {
		for(int i=0; i<dimenzija; i++) {
			p.push_back(typename std::remove_reference<decltype(a.at(i))>::type(1));
			for(int j=0; j<dimenzija/2+1; j++) {
				p.at(i).push_back(typename std::remove_reference<decltype(a.at(i).at(j))>::type(1));
				int put(0);
				for(int k=j; k<dimenzija-j; k++) {
					if(put==0 && j!=0) p.at(i).at(j).at(put)=a.at(i).at(k).at(j);
					else  p.at(i).at(j).push_back(a.at(i).at(k).at(j));
					put++;
				}
			}
			for(int j=dimenzija/2+1; j<dimenzija; j++) {
				p.at(i).push_back(typename std::remove_reference<decltype(a.at(i).at(j))>::type(1));
				int put(0);
				for(int k=dimenzija-j-1; k<=j; k++) {
					if(put==0 && j!=0) p.at(i).at(j).at(put)=a.at(i).at(k).at(j);
					else  p.at(i).at(j).push_back(a.at(i).at(k).at(j));
					put++;
				}
			}
		}
	} else if(s==SmjerKretanja::NaprijedNazad || s==SmjerKretanja::NazadNaprijed) {
		for(int i=0; i<dimenzija; i++) {
			p.push_back(typename std::remove_reference<decltype(a.at(i))>::type(1));
			for(int j=0; j<dimenzija/2+1; j++) {
				p.at(i).push_back(typename std::remove_reference<decltype(a.at(i).at(j))>::type(1));
				int put(0);
				for(int k=j; k<dimenzija-j; k++) {
					if(put==0 && j!=0) p.at(i).at(j).at(put)=a.at(j).at(i).at(k);
					else  p.at(i).at(j).push_back(a.at(j).at(i).at(k));
					put++;
				}
			}
			for(int j=dimenzija/2+1; j<dimenzija; j++) {
				p.at(i).push_back(typename std::remove_reference<decltype(a.at(i).at(j))>::type(1));
				int put(0);
				for(int k=dimenzija-j-1; k<=j; k++) {
					if(put==0 && j!=0) p.at(i).at(j).at(put)=a.at(j).at(i).at(k);
					else  p.at(i).at(j).push_back(a.at(j).at(i).at(k));
					put++;
				}
			}
		}
	}

	if(s==SmjerKretanja::DoljeGore || s==SmjerKretanja::DesnoLijevo || s==SmjerKretanja::NazadNaprijed) {
		for(int i=0; i<dimenzija; i++) {
			for(int j=0; j<dimenzija/2; j++) {
				for(int k=0; k<p.at(i).at(j).size(); k++) {
					auto temp=p.at(i).at(j).at(k);
					p.at(i).at(j).at(k)=p.at(i).at(dimenzija-1-j).at(k);
					p.at(i).at(dimenzija-1-j).at(k)=temp;
				}
			}
		}
	}
	return p;
}


int main ()
{
	try {
		std::cout<<"Unesite dimenziju (x/y/z): ";
		int d;
		do {
			std::cin>>d;
			if(d<0) std::cout<<"Dimenzija nije ispravna, unesite opet: ";
		} while(d<0);

		std::cout<<"Unesite elemente kontejnera: ";
		std::vector<std::deque<std::deque<int>>> v;
		for(int i=0; i<d; i++) {
			v.push_back(std::deque<std::deque<int>>(0));
			for(int j=0; j<d; j++) {
				v.at(i).push_back(std::deque<int>(0));
				for(int k=0; k<d; k++) {
					int broj;
					std::cin>>broj;
					v.at(i).at(j).push_back(broj);
				}
			}
		}
		std::cout<<"Unesite smjer kretanja [0 - 5]: ";
		int g;
		do {
			std::cin>>g;
			if(g<0 || g>5) std::cout<<"Smjer nije ispravan, unesite opet: ";
		} while(!(g>=0 && g<=5));
		SmjerKretanja s;
		if(g==0) s=SmjerKretanja::NaprijedNazad;
		else if(g==1) s=SmjerKretanja::NazadNaprijed;
		else if(g==2) s=SmjerKretanja::GoreDolje;
		else if(g==3) s=SmjerKretanja::DoljeGore;
		else if(g==4) s=SmjerKretanja::LijevoDesno;
		else s=SmjerKretanja::DesnoLijevo;
		auto p=PjescaniSat(v,s);
		std::cout<<std::endl<<"Pjescani sat unesene matrice je:"<<std::endl;
		for(int i=0; i<d; i++) {
			std::cout<<std::endl;
			for(int j=0; j<d; j++) {
				int razlika=d-p.at(i).at(j).size();
				for(int x=0; x<razlika/2; x++) std::cout<<"    ";
				for(int k=0; k<p.at(i).at(j).size(); k++) std::cout<<std::setw(4)<<p.at(i).at(j).at(k);
				for(int x=0; x<razlika/2; x++) std::cout<<"    ";
				std::cout<<std::endl;
			}
		}
	} catch(std::domain_error e) {
		std::cout<<std::endl<<"Izuzetak: "<<e.what();
	} catch(std::length_error e) {
		std::cout<<std::endl<<"Izuzetak: "<<e.what();
	}
	return 0;
}