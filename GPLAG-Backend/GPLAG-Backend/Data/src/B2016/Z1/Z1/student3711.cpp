/*B 2016/2017, Zadaća 1, Zadatak 2 */

#include <iostream>
#include <vector>
#include <cmath>

// OSTALO:
// rp!
// Prazni vektori !
// Ogranicavanje unosa i parametara fcija !

std::vector<int> VratiListuCifri (int N){
	std::vector<int> vrste_brojeva{0, 0, 0};
	int broj = abs(N);
	do{
		int cifra = broj % 3;
		vrste_brojeva[cifra] += 1;
		broj = broj / 3;
	} while(broj!=0);
	return vrste_brojeva;
} 

std::vector<int> IzdvojiGadne(std::vector<int> VEKTOR, bool istina){
	if(VEKTOR.size() == 0){
		return VEKTOR;
	}
	//BRISANJE
	for(int i=0; i<VEKTOR.size()-1; i++){
        for(int j=i+1; j<VEKTOR.size(); j++){
            if(VEKTOR[i] == VEKTOR[j]){
                VEKTOR.erase(VEKTOR.begin() + j);
                j--;
            }
        }
	}
	// Opaki brojevi TRUE
	if(istina == true){
		std::vector<int> opaki;
		bool da_li_je_opak(false);
		for(int i=0; i<VEKTOR.size(); i++){
			// vraca vektor od tri elementa, koliko se koja cifra ponavlja
			std::vector<int>vrste_brojeva = VratiListuCifri(VEKTOR[i]);
			for(int i=0; i<vrste_brojeva.size(); i++){
				if(vrste_brojeva[i] == 0){
					continue;
				}
				else if(vrste_brojeva[i] % 2 == 0){
					da_li_je_opak = true;
				}
				else {
					da_li_je_opak = false;
					break;
				}
			}
			if(da_li_je_opak == true){
				opaki.push_back(VEKTOR[i]);
			}
		}
		return opaki;
	}	
	// Odvratni brojevi FALSE
	else {
		std::vector<int> odvratni;
		bool da_li_je_odvratan(false);
		for(int i=0; i<VEKTOR.size(); i++){
			// vraca vektor od tri elementa, koliko se koja cifra ponavlja
			std::vector<int>vrste_brojeva = VratiListuCifri(VEKTOR[i]);
			for(int i=0; i<vrste_brojeva.size(); i++){
				if(vrste_brojeva[i] == 0){
					continue;
				}
				else if(vrste_brojeva[i] % 2 != 0){
					da_li_je_odvratan = true;
				}
				else {
					da_li_je_odvratan = false;
					break;
				}
			}
			if(da_li_je_odvratan == true){
				odvratni.push_back(VEKTOR[i]);
			}
		}
		return odvratni;
		
	}	
}

void IspisiVektor(std::vector<int> vektor_za_ispis){
	for(int i=0; i<vektor_za_ispis.size(); i++){
		std::cout << vektor_za_ispis[i] << " ";	
	}
}

int main (){
	std::vector<int> VEKTOR ;
	int unos_elemenata;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	for(;;){
		std::cin >> unos_elemenata;
		if(unos_elemenata == 0){
			break;
		}
		VEKTOR.push_back(unos_elemenata);
	}
  	
	std::vector<int> opaki = IzdvojiGadne(VEKTOR, true);
	std::vector<int> odvratni = IzdvojiGadne(VEKTOR, false);

	std::cout << "Opaki: ";
	IspisiVektor(opaki);
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	IspisiVektor(odvratni);
	return 0;
}