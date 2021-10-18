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
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <cmath>

int BrojProstihFaktora(int x){
	std::vector<int> faktori;
	x=fabs(x);
	if(x<=1) return 1;
	for(int i=2; i<=x; i++) while(x%i==0){
		faktori.push_back(i);
		x/=i;
	} 
	return int(faktori.size());
}


template <typename Tip1, typename Tip2, typename Tip3>
void SortirajPodrucjeVrijednosti(Tip1 blok1_p, Tip1 blok1_k, Tip2 blok2, Tip3 blok3, decltype(*blok3+*blok3) (*f)(decltype(*blok1_p+*blok1_k), decltype(*blok2+*blok2)), bool (*g)(decltype(*blok1_p+*blok1_k), decltype(*blok2+*blok2))){
		std::sort(blok1_p, blok1_k, g);
		auto p(blok1_p);
		int broj_elemenata(0), brojac(0);
		while(p++!=blok1_k) broj_elemenata++;
		std::sort(blok2, blok2+broj_elemenata, g);
		while(blok1_p!=blok1_k){
			auto vrijednost(f(*blok1_p, *blok2));
			auto pozicija(blok3);
			int i;
			for(i=brojac; i<broj_elemenata; i++){
				if(vrijednost==*(blok3+i)){
					auto temp=*(blok3+i);
					*(blok3+i)=*(blok3+brojac);
					*(blok3+brojac)=temp;
					brojac++;
					break;
				}
			}
			if(i==broj_elemenata) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
			blok1_p++;
			blok2++;
		}
}

int f1(int x, int y){ return y-2*x; }

bool f2(int x, int y){
	if(BrojProstihFaktora(x)>BrojProstihFaktora(y)) return true;
	else if(BrojProstihFaktora(x)==BrojProstihFaktora(y) && x>y) return true;
	return false;
}

int main ()
{
	std::cout << "Unesite broj elemenata: ";
	int broj_elemenata;
	std::cin >> broj_elemenata;
	std::cout << "Unesite elemente prvog vektora: ";
	std::vector<int> prvi;
	for(;;){
		int broj;
		std::cin >> broj;
		bool vec_unesen_broj=false;
		for(int i=0; i<int(prvi.size()); i++){
			if(broj==prvi.at(i)) vec_unesen_broj=true;
		}
		if(!vec_unesen_broj) prvi.push_back(broj);
		if(int(prvi.size())==broj_elemenata) break;
	}
	std::cout << "Unesite elemente drugog vektora: ";
	std::vector<int> drugi;
	for(;;){
		int broj;
		std::cin >> broj;
		bool vec_unesen_broj=false;
		for(int i=0; i<int(drugi.size()); i++){
			if(broj==drugi.at(i)) vec_unesen_broj=true;
		}
		if(!vec_unesen_broj) drugi.push_back(broj);
		if(int(drugi.size())==broj_elemenata) break;
	}
	std::cout << "Unesite elemente treceg vektora: ";
	std::vector<int> treci;
	for(;;){
		int broj;
		std::cin >> broj;
		bool vec_unesen_broj=false;
		for(int i=0; i<int(treci.size()); i++){
			if(broj==treci.at(i)) vec_unesen_broj=true;
		}
		if(!vec_unesen_broj) treci.push_back(broj);
		if(int(treci.size())==broj_elemenata) break;
	}
	try{
		SortirajPodrucjeVrijednosti(prvi.begin(), prvi.end(), drugi.begin(), treci.begin(), f1, f2);
		std::cout << "\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke:\n";
		for(int i=0; i<broj_elemenata; i++){
			std::cout << "f(" << prvi.at(i) << ", " << drugi.at(i) << ") = " << treci.at(i) << std::endl;
		}
	}
	catch(std::logic_error e){
		std::cout << std::endl <<"Izuzetak: "<< e.what() << std::endl;
	}
	return 0;
}