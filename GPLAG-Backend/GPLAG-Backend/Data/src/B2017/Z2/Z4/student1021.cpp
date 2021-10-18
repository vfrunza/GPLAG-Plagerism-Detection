/*B 2017/2018, Zadaća 2, Zadatak 4
	
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
#include <type_traits>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <iterator>

int BrojProstihFaktora (int n) {
	int brojac(0);
	if (n==0 || n==1) return 0;
	int i(2);
	while (n%i==0) {
		brojac++;
		n/=i;
	}
	i=3;
	while (n>1) {
		while (n%i==0) {
			brojac++;
			n/=i;
		}
		i+=2;
	}
	return brojac;
}

bool Kriterij(int x, int y) {
	int broj1=BrojProstihFaktora(x);
	int broj2=BrojProstihFaktora(y);
	if (broj1==broj2) return (x<y);
	return (broj1<broj2);
}

int Funkcija(int x, int y) {
	return (-2*x+y);
}

template <typename Tip1, typename Tip2, typename Tip3>
void SortirajPodrucjeVrijednosti (Tip1 p1, Tip1 p2, Tip2 p3, Tip3 p4, typename std::remove_reference<decltype(*p4)>::type fun1(typename std::remove_reference<decltype(*p1)>::type, typename std::remove_reference<decltype(*p1)>::type), bool fun2(typename std::remove_reference<decltype(*p1)>::type, typename std::remove_reference<decltype(*p1)>::type)) {
	//typedef typename std::remove_reference<decltype(*p1)>::type TipPrvog;
	typedef typename std::remove_reference<decltype(*p4)>::type TipTreceg;
	int vel(0);
	auto pomp1(p1), krajp3(p3), krajp4(p4);
	while (pomp1!=p2) {
		vel++;
		pomp1++;
	}
	for (int i=0; i<vel; i++) {
		krajp3++;
	}
	for (int i=0; i<vel; i++) {
		krajp4++;
	}
	
	std::sort(p1, p2, fun2(*p1,*p2));
	std::sort(p3, krajp3, fun2(*p3, *krajp3));
	
	int index1(0), index2(0);
	while (p1!=p2) {
		auto rezultat=fun1(*p1,*p3);
		auto pomp4(p4);
		bool sadrzan(false);
		while (pomp4!=krajp4) {
			if (*pomp4==rezultat) {
				sadrzan=true;
				break;
			}
			pomp4++; index2++;
		}
		if (sadrzan==false) {
			throw std::logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
		}
		else {
			if (index1!=index2) {
				TipTreceg pom=*pomp4;
				*pomp4=*p1;
				*p1=pom;
			}
		}
		p1++; p3++; index1++;
	}
}

int main () {
	
	int broj_elemenata;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>broj_elemenata;
	
	std::vector<int>v1;
	std::vector<int>v2;
	std::vector<int>v3;
	
	std::cout<<"Unesite elemente prvog vektora: ";
	for (int i=0; i<broj_elemenata; i++) {
		int broj;
		bool sadrzan(false);
		std::cin>>broj;
		for (int j=0; j<v1.size(); j++) {
			if (broj==v1.at(j)) {
				sadrzan=true;
				break;
			}
		}
		if (!sadrzan) v1.push_back(broj);
	}
	
	std::cout<<"Unesite elemente drugog vektora: ";
	for (int i=0; i<broj_elemenata; i++) {
		int broj;
		bool sadrzan(true);
		std::cin>>broj;
		for (int j=0; j<v2.size(); j++) {
			if (broj==v2.at(j)) {
				sadrzan=true;
				break;
			}
		}
		if (!sadrzan) v2.push_back(broj);
	}
	
	std::cout<<"Unesite elemente treceg vektora: ";
	for (int i=0; i<broj_elemenata; i++) {
		int broj;
		bool sadrzan(false);
		std::cin>>broj;
		for (int j=0; j<v3.size(); j++) {
			if (broj==v3.at(j)) {
				sadrzan=true;
				break;
			}
		}
		if (!sadrzan) v3.push_back(broj);
	}
	
	try {
		SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), Funkcija, Kriterij);
	
		std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: ";
		std::cout<<std::endl;
		for (int i=0; i<broj_elemenata; i++) {
			std::cout<<"f(" << v1.at(i) << ", "<< v2.at(i) <<") = " << v3.at(i) << std::endl;
		}
	} 
	catch (std::logic_error izuzetak1) {
		std::cout<< "Izuzetak: " << izuzetak1.what() << std::endl;
	}
	catch (...) {
		std::cout << "at je negdje bacio izuzetak";
	}
	
	return 0;
	
}