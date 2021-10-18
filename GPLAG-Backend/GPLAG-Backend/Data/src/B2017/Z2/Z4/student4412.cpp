#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> UnosVektora(int broj_elemenata)
{
	std::vector<int> v(0);
	int brojac(0);
	while(brojac<broj_elemenata) {
		int pomocna;
		std::cin>>pomocna;
		bool duplikat(false);
		for(int i=0; i<v.size(); i++) {
			if(v.at(i)==pomocna) {
				duplikat=true;
				break;
			}
		}
		if(duplikat==false) {
			v.push_back(pomocna);
			brojac++;
		}
	}
	return v;
}

template <typename Tip1, typename Tip2, typename Tip3, typename FunkcijskiTip1, typename FunkcijskiTip2>
void SortirajPodrucjeVrijednosti(Tip1 p1, Tip2 p2, Tip2 p3, Tip3 p4, FunkcijskiTip1 f1, FunkcijskiTip2 f2)
{
	std::sort(p1, p2, f2);														//sortiranje
	Tip1 pomocni_p1(p1);
	int broj_elemenata(0);
	while(pomocni_p1++!=p2) {
		broj_elemenata++;
	}
	std::sort(p3, p3+broj_elemenata, f2); 										//sortiranje
	int brojac(0);
	while(p1!=p2) {
		auto rez_fje(f1(*p1, *p3));
		p1++;
		p3++;
		Tip3 pomocni_p4(p4);
		bool pronadjen(false);
		int i;
		for(i=0; i<broj_elemenata; i++) {
			if(*pomocni_p4==rez_fje) {
				pronadjen=true;
				break;
			}
			pomocni_p4++;
		}
		if(pronadjen==true) {
			Tip3 pozicija(p4);
			for(int j=0; j<brojac; j++) {
				pozicija++;
			}
			auto pomocna(*pozicija);											
			*pozicija=*pomocni_p4;
			*pomocni_p4=pomocna;
		} else																	//bacanje izuzetka
			throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		brojac++;
	}
}

int main ()
{
	std::cout<<"Unesite broj elemenata: ";										//unos
	int broj_elemenata;
	std::cin>>broj_elemenata;
	std::cout<<"Unesite elemente prvog vektora: ";
	std::vector<int> prvi_vektor(UnosVektora(broj_elemenata));
	/*int brojac(0);
	bool duplikat(false);
	while (brojac<broj_elemenata) {
		int pomocna;
		std::cin>>pomocna;
		duplikat=false;
		for(int i=0; i<prvi_vektor.size(); i++) {
			if(prvi_vektor.at(i)==pomocna) {
				duplikat=true;
				break;
			}
		}
		if(duplikat==false) {
			prvi_vektor.push_back(pomocna);
			brojac++;
		}
	}*/
	std::cout<<"Unesite elemente drugog vektora: ";
	std::vector<int> drugi_vektor(UnosVektora(broj_elemenata));
	std::cout<<"Unesite elemente treceg vektora: ";
	std::vector<int> treci_vektor(UnosVektora(broj_elemenata));
	try {
		SortirajPodrucjeVrijednosti(prvi_vektor.begin(), prvi_vektor.end(), 	
			drugi_vektor.begin(), treci_vektor.begin(), [] (int x, int y) {
			return -2*x+y;
		},
		[] (int x, int y) {														//fja kriterija za sortiranje
			int pomocna(x), brojac(2), broj_pf1(0);
			while(brojac<=x) {													//brojanje pf prvog broja
				if(pomocna%brojac==0) {
					broj_pf1++;
					pomocna/=brojac;
				} else brojac++;
				if(pomocna==1) break;
			}

			pomocna=y;
			brojac=2;
			int broj_pf2(0);
			while(brojac<=y) {													//brojanje pf drugog broja
				if(pomocna%brojac==0) {
					broj_pf2++;
					pomocna/=brojac;
				} else brojac++;
				if(pomocna==1) break;
			}

			if(broj_pf1!=broj_pf2) return broj_pf1>broj_pf2;
			else return x>y;
		});
		std::cout<<std::endl													//ispis
			<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "
			<<std::endl;
		for(int i=0; i<broj_elemenata; i++) {
			std::cout<<"f("<<prvi_vektor.at(i)<<", "<<drugi_vektor.at(i)
			<<") = "<<treci_vektor.at(i)<<std::endl;
		}
	} catch (std::logic_error izuzetak) {			
		std::cout<<std::endl<<"Izuzetak: "<<izuzetak.what();
	}
	return 0;
}