#include <iostream>
#include <vector>
#include <type_traits>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
typedef std::vector<std::vector<std::vector<double>>> Triplevector; 

enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo };

template<typename tip>
bool ProvjeraIspravnosti(tip &ref)
{
	int vel = ref.size();
	if(vel == 0) return false;
	for(int i = 0; i < ref.size(); i++) {
		if(ref.at(i).size() != vel) return false;
		for(int j = 0; j < ref.at(i).size(); j++) {
			if(ref.at(i).at(j).size() != vel) return false;
		}
	}
	return true;
}

/*template<typename tipelem>
void Unos(tipelem nekitip, int n)
{
	for(int i = 0; i < n; i++) {
		nekitip.at(i).resize(n);
		for(int j = 0; j < n; j++) {
			 nekitip.at(i).at(j).resize(n);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				std::cin >> nekitip.at(i).at(j).at(k);
			}
		}
	}
}*/

template <typename Kocka>
Kocka PjescaniSat(Kocka &kocka, SmjerKretanja S_K)
{
	
	if(ProvjeraIspravnosti(kocka) == false) throw std::domain_error("3D matrica nema oblik kocke");
	if(kocka.size()%2 == 0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	Kocka kocka1 = kocka;
	int brojac1,brojac2;
	for(int i = 0; i < kocka1.size(); i++) {
		brojac1 = 1;
		brojac2 = kocka1.size()-1;
		for(int j = 1; j < kocka1.at(i).size()-1; j++) {
			for(int k = 0; k < kocka1.at(i).at(j).size(); k++) {
				if(brojac1 < brojac2) {
					std::copy(kocka1.at(i).at(j).begin() + brojac1, kocka1.at(i).at(j).begin() + brojac2, kocka1.at(i).at(j).begin());
					kocka1.at(i).at(j).resize(brojac2 - brojac1);
					
				} else {
					std::copy(kocka1.at(i).at(j).begin() + brojac2 - 1, kocka1.at(i).at(j).begin() + brojac1 + 1, kocka1.at(i).at(j).begin());
					kocka1.at(i).at(j).resize(brojac1 +2 - brojac2);
				
				}
			}
			brojac1++;
			brojac2--;
		}
	}
	return kocka1;
}

int main ()
{
	int n;
	bool nijeispravna = false;
	Triplevector vvv,vvv2;
	
	do {
	if(!nijeispravna) {
		std::cout << "Unesite dimenziju (x/y/z): ";
	}
	nijeispravna = false;
	std::cin >> n;
	if(n < 1) {
		std::cout << "Dimenzija nije ispravna, unesite opet: ";
		nijeispravna = true;
	}
	} while (n < 1);

	double x;
	vvv.resize(n);
	std::cout << "Unesite elemente kontejnera: ";
		for(int i = 0; i < n; i++) {
		vvv.at(i).resize(n);
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
			 std::cin >> x;
			 vvv.at(i).at(j).push_back(x);
			}
				
		}
	}
	
//	Unos(vvv,n);
	nijeispravna = false;
	do {
	if(!nijeispravna) {
		std::cout << "Unesite smjer kretanja [0 - 5]: ";
	}
	nijeispravna = false;
	std::cin >> n;
	if(n < 0 || n > 5) {
		std::cout << "Smjer nije ispravan, unesite opet: ";
		nijeispravna = true;
	}
	} while (n < 0 || n > 5);
	try{
	vvv2 = PjescaniSat(vvv, SmjerKretanja(n));
	for(int i = 0; i < vvv2.size(); i++) {
		for(int j = 0; j < vvv2.at(i).size(); j++) {
			for(int k = 0; k < vvv2.at(i).at(j).size(); k++) {
			  std::cout << std::setw(4) <<vvv2.at(i).at(j).at(k);
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	} catch(std::domain_error izuzetak1) {
		std::cout << std::endl << "Izuzetak: "<< izuzetak1.what();
	} catch(std::length_error izuzetak2) {
		std::cout << std::endl << "Izuzetak: " << izuzetak2.what();
	}
	return 0;
}