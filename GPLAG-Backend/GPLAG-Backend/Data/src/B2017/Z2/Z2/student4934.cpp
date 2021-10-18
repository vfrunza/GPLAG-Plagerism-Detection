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
#include <deque>
#include <vector>
#include <stdexcept>

typedef std::vector<std::deque<std::deque<int>>> vekdekdek;

enum class SmjerKretanja {
	NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};


bool DaLiJeNeparan(int broj){
	if(broj % 2 != 0) return true;
	return false;
}

template<typename KontejnerskiTip>
KontejnerskiTip PjescaniSat(const KontejnerskiTip &kont, SmjerKretanja smjer){
	KontejnerskiTip vracanje;
	if(kont.size() != kont.at(0).size() || kont.at(0).size() != kont.at(0).at(0).size()) throw std::domain_error("3D matrica nema oblik kocke");
	if(!DaLiJeNeparan(kont.size())) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	
	return vracanje;
}

int main ()
{
	int broj,smjer,element;
	std::cout<<"Unesite dimenziju (x/y/z): ";
	do{
	std::cin>>broj;
	if(broj <= 0){
		std::cout<<"Dimenzija nije ispravna, unesite opet: ";
	}
	}while(broj <= 0);
	vekdekdek d(broj,std::deque<std::deque<int>>(broj));
	std::cout<<"Unesite elemente kontejnera: ";
	for(int i(0); i < broj; i++){
		for(int j(0); j < broj; j++){
			for(int k(0); k < broj; k++){
				std::cin>>element;
				d.at(i).at(j).push_back(element);
			}
		}
	}
	std::cout<<"Unesite smjer kretanja [0 - 5]: ";
	do{
	std::cin>>smjer;
	if(smjer < 0 || smjer > 5) std::cout<<"Smjer nije ispravan, unesite opet: ";
	}while(smjer < 0 || smjer > 5);
	SmjerKretanja Smjer;
	Smjer = SmjerKretanja(smjer);
	try{
	PjescaniSat(d,Smjer);
	}
	catch(std::domain_error izuzetak){
		std::cout<<std::endl<<"Izuzetak: "<<izuzetak.what();
	}
	catch(std::length_error izuzetak){
		std::cout<<std::endl<<"Izuzetak: "<<izuzetak.what();
	}
	return 0;
}