/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include<iostream>
#include <vector>


// pomocna funkcija u kojoj provjeravamo da li nam je pojedini element prost ili nije

bool DaLiJeProst (int broj){
	bool prost = true;
	for(int i = 2; i < broj; i++ ){
		if (broj % i == 0) {prost = false;
		break;
		}
	}
	
	return prost;
}

//pomocna funkcija u kojoj cemo pretvoriti brojeve u Terarne i provjeriti da li iszlgedaju isto sa obje strane
//vraca logicku vrijednost zavisno od rezultata

bool UTernarne(int broj){
	int ostatak, broj1;
	std::vector<int> vektor_ostataka;

	if (broj < 0) {
		
		broj = - broj;
	}
	broj1 = broj;
	while(broj1 ){
		ostatak = broj1 % 3;
		broj1 = broj1 / 3;
		vektor_ostataka.push_back(ostatak);
		
	}
	std::vector<int> obrnuti;
	for(int i = vektor_ostataka.size() - 1 ; i >= 0; i--){
		obrnuti.push_back(vektor_ostataka.at(i));
		//std::cout << vektor_ostataka[i] << " ";
	}
	bool isti = true;
	for(int i = 0; i < vektor_ostataka.size(); i++){
		if(vektor_ostataka.at(i) != obrnuti.at(i)) isti = false;
	}
	return isti;
}
// trazena funkcija u zadatku 

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool prosti){
	std::vector<int> vektor_prostih, vektor_slozenih;
	
	if(prosti){
		for(int i = 0; i < v.size(); i++){
			bool minus =  false;
			if(v.at(i) < 0){
				minus = true;
				v.at(i) = - v.at(i);
			}
			if(DaLiJeProst(v.at(i)) == true ){
				if(v.at(i) == 1 || v.at(i) == 0)continue;
				if(UTernarne(v.at(i))) {
					if(minus) v.at(i) = - v.at(i);
					vektor_prostih.push_back(v.at(i));
				}
			}
		}
		return vektor_prostih;
	}
	else {
		for(int i = 0; i < v.size(); i++){
			bool minus =  false;
			if(v.at(i) < 0){
				minus = true;
				v.at(i) = - v.at(i);
			}
			if(DaLiJeProst(v.at(i)) == false) {
				if(v.at(i) == 1 || v.at(i) == 0)continue;
				if (UTernarne(v.at(i))) {
					if(minus) v.at(i) = -v.at(i);
					vektor_slozenih.push_back(v.at(i));
				}
				}
			
		}
		return vektor_slozenih;
	}

}
// treba osigurati da nam se unos istih brojeva ne ponavlja prilikom ispisa
//za to cemo koristiti ovu funkciju Ponavljanje 

std::vector<int> Ponavljanje (std::vector<int> pocetni){
	std::vector<int> bez_ponavljanja, bili_vec;
//	bili_vec.push_back(pocetni[0]);
	
	for(int i = 0; i < pocetni.size(); i++){
		int j = 0, brojac = 0;
		bool isti = false;
		if(i == 0){
			bili_vec.push_back(pocetni.at(i));
			bez_ponavljanja.push_back(pocetni.at(i));
			continue;
		}
		do{
			if(bili_vec.at(j) == pocetni.at(i)) {
				isti = true;
				break;
			}
			j++;
			brojac++;
		}while(brojac < bili_vec.size() );
		
		if(isti == false) {bez_ponavljanja.push_back(pocetni.at(i));
		
		 bili_vec.push_back(pocetni.at(i));
		}
		else continue;
	}
	return bez_ponavljanja;
}


int main (){
	
	//unosenje elemenata beskonacnom petljom dok je ne prekinemo sa -1
	
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> pocetni;
	for(;;){
		int element;
		std::cin >> element;
		if(element == -1) break;
		pocetni.push_back(element);
	}
	
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int prost_ili_slozeni;
	for(;;){
	// unos mora biti tano ili jedan ili nula
	std::cin >> prost_ili_slozeni;
	if(prost_ili_slozeni != 1 && prost_ili_slozeni != 0 ) std::cout<< "Neispravan unos! Unesite ponovo: ";
	else break;
	}
	
	std::vector<int> konacni_vektor, vektor_ispisanih;
	konacni_vektor = IzdvojiSimetricneTernarne(pocetni, prost_ili_slozeni);
	
	konacni_vektor = Ponavljanje(konacni_vektor);
	
	if(prost_ili_slozeni == 1){
		if(konacni_vektor.size() < 1){
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout<< "Prosti simetricni brojevi iz vektora su: ";
		for(int i = 0; i < konacni_vektor.size(); i++){
			if(i < konacni_vektor.size() - 1) std::cout<< konacni_vektor.at(i) << ", ";
			else std::cout << konacni_vektor.at(i) << ".";
		}
	}
	else{
		if(konacni_vektor.size() < 1){
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
		}
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i = 0;  i < konacni_vektor.size(); i++){
			if(i < konacni_vektor.size() - 1)std::cout<< konacni_vektor.at(i) <<", ";
			else std::cout <<konacni_vektor.at(i) << ".";
		}
	}
	return 0;
}