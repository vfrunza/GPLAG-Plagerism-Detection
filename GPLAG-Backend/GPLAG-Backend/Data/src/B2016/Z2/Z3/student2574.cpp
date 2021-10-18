#include <deque>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <type_traits>
#include <stdexcept>
#include <algorithm>
#include <vector>


int SumaCifara (long long int broj ) {
	int suma(0);
	while (broj!=0) {
		int temp;
		temp=broj%10;
		suma+=temp;
		broj/=10;
	}
	return suma;
}

int SumaDjelilaca (long long int broj) {
	int suma_d(0);
	for (int i=1; i<=std::abs(broj); i++) 
		if (std::abs(broj)%i==0)
			suma_d+=i;
	return suma_d;
}

bool Savrsen (long long int broj) {
	long long int zbir_d(0);
	for (long long int i(1); i<broj; i++) {
		if (broj%i==0)
			zbir_d+=i;
	}
	if (zbir_d==broj) 
		return true;
	return false;
}

int BrojProstihFaktora (long long int broj) {
	int brojpf(0);
	for (int i=2; i<=broj; i++) {
		if (broj%i==0) {
			broj/=i;
			i--;
			brojpf++;
		}
	}
	return brojpf;
}

int BrojSavrsenihDjelilaca (long long int broj) {
	int brojsd(0);
	if (broj==1) return 0;
	for (long long int i=2; i<=broj; i++) {
		if (Savrsen(i)==true && broj%i==0)
			brojsd++;
	}
	return brojsd; 
}

bool duplikat (int broj, std::deque<int> d, int index) {
	for (int j=0; j<index; j++) 
		if (broj==d.at(j))
			return true;
	return false;
}

template <typename IterTip, typename IterTip2>
	auto UvrnutaRazlika (IterTip pok1, IterTip pok2, IterTip2 pok3, IterTip2 pok4) 
																	-> typename std::remove_reference<std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type>>>::type {
		
		std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type>> Vracam_ovu_matricu;
		IterTip pocetakprvog = pok1;
		IterTip2 pocetakdrugog = pok3;
		while (pocetakprvog!=pok2) {
			std::vector<typename std::remove_reference<decltype(*pocetakprvog)>::type> trpam_elemente;
			auto imalduplih (std::count(pok3,pok4,*pocetakprvog));
			if (imalduplih == 0) {
				int x (std::binary_search(pok3,pok4,*pocetakprvog));
				if (x==0) {
					trpam_elemente.push_back(*pocetakprvog);
					trpam_elemente.push_back(0);
					Vracam_ovu_matricu.push_back(trpam_elemente);
				}
			}
			pocetakprvog++;
		}
		while (pocetakdrugog!=pok4) {
			std::vector<typename std::remove_reference <decltype (*pocetakdrugog)>::type> trpam_elemente; 
			auto imalduplih1 (std::count(pok1,pok2,*pocetakdrugog));
			if (imalduplih1 == 0) {
				int x (std::binary_search(pok1,pok2,*pocetakdrugog));
				if (x==0) {
					trpam_elemente.push_back(*pocetakdrugog);
					trpam_elemente.push_back(0);
					Vracam_ovu_matricu.push_back(trpam_elemente);
				}
			}
			pocetakdrugog++;
		}
		std::sort(Vracam_ovu_matricu.begin(),Vracam_ovu_matricu.end(), [] (std::vector<typename std::remove_reference<decltype(*pok1)>::type> prvi, std::vector<typename std::remove_reference<decltype(*pok1)>::type> drugi) {
																			if (prvi.at(0)>drugi.at(0))
																				return true;
																			return false;
																		});
		return Vracam_ovu_matricu;
	}
	
template <typename IterTip, typename IterTip2>
	auto UvrnutaRazlika (IterTip pok1, IterTip pok2, IterTip2 pok3, IterTip2 pok4, int funkcija (long long int))
														-> typename std::remove_reference<std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type>>>::type {
		
		std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type>> Vracam_ovu_matricu;
		IterTip2	pocetakdrugog (pok3); //Kopiram pokzavivač/iterator koji pokazuje na početak drugog bloka
		IterTip 	pocetakprvog (pok1);
		while (pocetakprvog!=pok2) {
			std::vector<typename std::remove_reference<decltype(*pocetakprvog)>::type> trpam_elemente; 
			int broj(0);
			pocetakdrugog=pok3;
			while (pocetakdrugog!=pok4) {
				if (funkcija(*pocetakprvog)==funkcija(*pocetakdrugog))
					broj++;
				pocetakdrugog++;
			}
			if (broj==0) {
				trpam_elemente.push_back(*pocetakprvog);
				trpam_elemente.push_back(funkcija(*pocetakprvog));
				Vracam_ovu_matricu.push_back(trpam_elemente);	
				}
			pocetakprvog++;
		}
		pocetakdrugog=pok3;
		pocetakprvog=pok1;
		while (pocetakdrugog!=pok4) {
			std::vector<typename std::remove_reference<decltype(*pok1)>::type> trpam_elemente;
			int broj(0);
			pocetakprvog=pok1;
			while (pocetakprvog!=pok2) {
				if(funkcija(*pocetakdrugog)==funkcija(*pocetakprvog)) 
					broj++;
				pocetakprvog++;
			}
			if (broj == 0) {
				trpam_elemente.push_back(*pocetakdrugog);
				trpam_elemente.push_back(funkcija(*pocetakdrugog));
				Vracam_ovu_matricu.push_back(trpam_elemente);
			}
			pocetakdrugog++;
		}
		std::sort(Vracam_ovu_matricu.begin(),Vracam_ovu_matricu.end(), [] (std::vector<typename std::remove_reference<decltype(*pok1)>::type> prvi, std::vector<typename std::remove_reference<decltype(*pok1)>::type> drugi) {
																			if (prvi.at(1)==drugi.at(1) && prvi.at(0)<drugi.at(0))
																				return false;
																			else if (prvi.at(0)<drugi.at(0))
																				return false;
																			return true;
																			} );
		return Vracam_ovu_matricu;
	}

template <typename IterTip, typename IterTip2> //BEZ FUNKCIJE
	auto UvrnutiPresjek (IterTip pok1, IterTip pok2, IterTip2 pok3, IterTip2 pok4) -> typename std::remove_reference<std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type>>>::type {
		std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type>> Vracam_ovu_matricu;
		IterTip2 pocetakdrugog = pok3;
		IterTip pocetakprvog = pok1;
		while (pok1!=pok2) {
			std::vector<typename std::remove_reference<decltype(*pocetakprvog)>::type> trpam_elemente;
			pocetakdrugog=pok3;
			while (pocetakdrugog!=pok4) {
				if (*pok1==*pocetakdrugog) {
					trpam_elemente.push_back(*pok1);
					trpam_elemente.push_back(0);
					trpam_elemente.push_back(0);
					Vracam_ovu_matricu.push_back(trpam_elemente);
				}
				pocetakdrugog++;
			}
			pok1++;
		}
		std::sort(Vracam_ovu_matricu.begin(), Vracam_ovu_matricu.end(), [] (std::vector<typename std::remove_reference<decltype(*pok1)>::type> prvi, std::vector<typename std::remove_reference <decltype(*pok1)>::type> drugi) {
																			if (prvi.at(0)>drugi.at(0))
																				return false;
																			return true;
																		});
		return Vracam_ovu_matricu;
	}
	
template <typename IterTip, typename IterTip2>
	auto UvrnutiPresjek (IterTip pok1, IterTip pok2, IterTip2 pok3, IterTip2 pok4, int funkcija (long long int)) -> typename std::remove_reference<std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type>>>::type {
		std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type>> Vracam_ovu_matricu;
		IterTip2 pocetakdrugog = pok3;
		while (pok1!=pok2) {   //trpaj sve elemente koji se slažu
			std::vector<typename std::remove_reference<decltype(*pok1)>::type> trpam_elemente;
			pocetakdrugog = pok3;
			while (pocetakdrugog!=pok4) {
				if (funkcija(*pok1) == funkcija(*pocetakdrugog)) {
					trpam_elemente.clear();
					trpam_elemente.push_back(*pok1);
					trpam_elemente.push_back(*pocetakdrugog);
					trpam_elemente.push_back(funkcija(*pok1));
					Vracam_ovu_matricu.push_back(trpam_elemente);
				}
				pocetakdrugog++;
			}
			pok1++;
		}
		std::sort(Vracam_ovu_matricu.begin(), Vracam_ovu_matricu.end(),	[] (std::vector<typename std::remove_reference<decltype(*pok1)>::type> prvi, std::vector<typename std::remove_reference<decltype(*pok1)>::type> drugi) {
																			if (prvi[2]<drugi[2])
																				return true;
																			else if (prvi[2]==drugi[2] && prvi[0]==drugi[0] && prvi[1]<drugi[1])
																				return true;
																			else if (prvi.at(2)==drugi.at(2) && prvi.at(0)<drugi.at(0))
																				return true;
																			return false;
																		} );
		return Vracam_ovu_matricu;
	}
	
		
int main ()	{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int broj_el_prvi (0);
	std::cin>>broj_el_prvi;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int> prvi_dek;
	for (int i(0); i<broj_el_prvi; i++) {
		int element(0);
		std::cin>>element;
		if (i>0) 
			if (duplikat(element, prvi_dek, i)) {
				i--;
				continue;
			}
		prvi_dek.push_back(element);
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int broj_el_drugi(0);
	std::cin>>broj_el_drugi;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<int> drugi_dek;
	for (int i(0); i<broj_el_drugi; i++) {
		int element(0);
		std::cin>>element;
		if (i>0)
			if (duplikat(element,drugi_dek,i)) {
				i--;
				continue;
			}
		drugi_dek.push_back(element);
	}
	std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	std::vector<std::vector<int>> presjek (UvrnutiPresjek(prvi_dek.begin(),prvi_dek.end(),drugi_dek.begin(),drugi_dek.end(),SumaCifara));
	for (auto red: presjek) {
		for (auto broj : red) {
			std::cout<<std::setw(6)<<broj<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl<<"Uvrnuta razlika kontejnera: "<<std::endl;
	std::vector<std::vector<int>> razlika (UvrnutaRazlika(prvi_dek.begin(), prvi_dek.end(), drugi_dek.begin(), drugi_dek.end(), BrojProstihFaktora));
	for (auto red : razlika) {
		for (auto broj : red ) 
			std::cout<<std::setw(6)<<broj<<" ";
		std::cout<<std::endl;
	} 
	std::cout<<std::endl<<"Dovidjenja!";
	return 0;
}	