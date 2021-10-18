/*B 2017/2018, Zadaća 1, Zadatak 1 */
#include <iostream>
#include <vector>
#include <cmath>

// ako se fciji da nesto sto ne treba PAZITI
// PRAZAN VEKTOR
// STRINGOVI KAO UNOS I DOUBLE

bool JeLiProst (int broj){
	int apsolutna_vrijednost_broja = std::abs(broj);
	for(int i=2; i<=sqrt(apsolutna_vrijednost_broja); i++){
		if(apsolutna_vrijednost_broja % i == 0){
			return false;
		}
	}
	return true;
}
std::vector<int> CiscenjeDuplihBrojeva (std::vector<int> SPREMNIK){
	for(int i=0; i<SPREMNIK.size()-1; i++){
		for(int j=i+1; j<SPREMNIK.size(); j++){
			if(SPREMNIK.at(i) == SPREMNIK.at(j)){
				SPREMNIK.erase(SPREMNIK.begin()+j);
			}
		}
	}
	return SPREMNIK;
}
int KonvertujUTrinarne (int broj){
	// Ako je broj negativan
	bool negativan_broj(false);
	if(broj<0){
		negativan_broj = true;
	}
	int dekatni_broj = std::abs(broj);
	// RACUN
	std::vector<int> ternarne_cifre;
	int cifra(0);
	while(dekatni_broj != 0){
		cifra = dekatni_broj % 3;
		dekatni_broj = dekatni_broj / 3;
		ternarne_cifre.push_back(cifra);
	}
	int ternarni_broj(0);
	for(int i=0; i<ternarne_cifre.size(); i++){
		ternarni_broj = ternarni_broj + (ternarne_cifre[i] * pow(10, i));
	}
	// Ako je broj bio negativan
	if(negativan_broj == true){
		ternarni_broj = ternarni_broj*(-1);
	}
	return ternarni_broj;
}
bool JeLiSimetrican (int broj){
	// Ako je negativan
	if(broj<0){
		broj = std::abs(broj);
	}
	std::vector<int> cifre;
	int cifra;
	while(broj != 0){
		cifra = broj%10;
		cifre.push_back(cifra);
		broj = broj/10;
	}
	for(int i=0, j=cifre.size()-1; i<cifre.size()/2; i++, j--){
		if(cifre.at(i) != cifre.at(j)){
			return false;
		}
	}
	return true;
}
std::vector<int> KonvertujUDekadne (std::vector<int> SPREMNIK){
	std::vector<int> BROJEVI;
	for(int i=0; i<SPREMNIK.size(); i++){
		int broj, cifra, dekatni_broj=0;
		std::vector<int> cifre;
		bool negativan(false);
		if(SPREMNIK.at(i)<0){
			negativan = true;
		}
		broj = std::abs(SPREMNIK[i]);
		while(broj!=0){
			cifra = broj%10;
			cifre.push_back(cifra);
			broj = broj/10;
		}
		for(int j=0; j<cifre.size(); j++){
			dekatni_broj = dekatni_broj + (cifre.at(j) * pow(3, j));
		}
		if(negativan == true){
			dekatni_broj = dekatni_broj * -1;
		}
		BROJEVI.push_back(dekatni_broj);
	}
	return BROJEVI;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> SPREMNIK, bool OPCIJA){
	std::vector<int> BROJEVI, OCISCENI_BROJEVI, TRINARNI, DEKATNI;
	std::vector<int> prazan(0);
	if(SPREMNIK.size()==0){
		return prazan;
	}
	// ***** PROSTI *****
	if(OPCIJA == true){
		// Zapis PROSTIH brojeva
		for(int i=0; i<SPREMNIK.size(); i++){
			if(JeLiProst(SPREMNIK.at(i)) == true){
				BROJEVI.push_back(SPREMNIK.at(i));
			} else {
				continue;
			}
		}
		// CISCENJE duplih brojeva
		std::vector<int> tmp = CiscenjeDuplihBrojeva(BROJEVI);
		OCISCENI_BROJEVI = tmp;
		// KONVERTOVANJE u trinarne
		for(int i=0; i<OCISCENI_BROJEVI.size(); i++){
			int tmp = KonvertujUTrinarne(OCISCENI_BROJEVI.at(i));
			TRINARNI.push_back(tmp);
		}
		// CISCENJE ONIH KOJI NISU SIMETRICNI
		for(int i=0; i<TRINARNI.size(); i++){
			if(JeLiSimetrican(TRINARNI.at(i)) == false){
				TRINARNI.erase(TRINARNI.begin()+i);
				i--;
			}
		}
		// KONVERTOVANJE U DEKATNI
		std::vector<int> konvertovani = KonvertujUDekadne(TRINARNI);
		for(int i=0; i<konvertovani.size(); i++){
			DEKATNI.push_back(konvertovani.at(i));
		}
		
	// ***** SLOZENI *****
	} else if (OPCIJA == false){
		// Zapis SLOZENIH brojeva
		for(int i=0; i<SPREMNIK.size(); i++){
			if(JeLiProst(SPREMNIK.at(i)) == false){
				BROJEVI.push_back(SPREMNIK.at(i));
			} else {
				continue;
			}
		}
		// CISCENJE duplih brojeva
		std::vector<int> tmp = CiscenjeDuplihBrojeva(BROJEVI);
		OCISCENI_BROJEVI = tmp;
		// KONVERTOVANJE u trinarne
		for(int i=0; i<OCISCENI_BROJEVI.size(); i++){
			int tmp = KonvertujUTrinarne(OCISCENI_BROJEVI[i]);
			TRINARNI.push_back(tmp);
		}
		// CISCENJE ONIH KOJI NISU SIMETRICNI
		for(int i=0; i<TRINARNI.size(); i++){
			if(JeLiSimetrican(TRINARNI.at(i)) == false){
				TRINARNI.erase(TRINARNI.begin()+i);
				i--;
			}
		}
		// KONVERTOVANJE U DEKATNI
		std::vector<int> konvertovani = KonvertujUDekadne(TRINARNI);
		for(int i=0; i<konvertovani.size(); i++){
			DEKATNI.push_back(konvertovani.at(i));
		}
	}
	return DEKATNI;
}

int main (){
	/* std::vector<int> BROJEVI = {191,233,43,-313,142,13,121,678,-151,23,-12,727,173};
	std::vector<int> SIMETRICNI = IzdvojiSimetricneTernarne(BROJEVI, true);
	for(int i=0; i<SIMETRICNI.size(); i++){
		std::cout << SIMETRICNI[i] << " ";
	} */
	
	std::vector<int> BROJEVI;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	for(;;){
		int tmp;
		std::cin >> tmp;
		if(tmp == -1){
			break;
		}
		BROJEVI.push_back(tmp);
	}
	
	int opcija;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while(1){
		std::cin >> opcija;
		if(opcija == 0 || opcija == 1){
			break;
		}
		std::cout << "Neispravan unos! Unesite ponovo: ";
	}

	if(opcija == 1){ //prosti
		std::vector<int> PROSTI = IzdvojiSimetricneTernarne(BROJEVI, opcija);
		if(PROSTI.size() == 0){
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<PROSTI.size()-1; i++){
			std::cout << PROSTI.at(i) << ", ";
		}
		std::cout << PROSTI[PROSTI.size()-1] << ".";
	} else if (opcija == 0){ // slozeni
		std::vector<int> SLOZENI = IzdvojiSimetricneTernarne(BROJEVI, opcija);
		if(SLOZENI.size() == 0){
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<SLOZENI.size()-1; i++){
			std::cout << SLOZENI.at(i) << ", ";
		}
		std::cout << SLOZENI[SLOZENI.size()-1] << ".";
	} 
	return 0;
}