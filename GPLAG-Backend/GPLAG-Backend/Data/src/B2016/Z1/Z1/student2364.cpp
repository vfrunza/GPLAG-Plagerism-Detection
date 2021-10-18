#include <iostream>
#include <vector>

bool DaLiJeOpak (int broj){
	std::vector <int> vektor;
	int cifra;
	
	do{
		cifra = broj % 3;
		vektor.push_back(cifra);                             // Nije nam bitan raspored cifara ternarnog broja
		broj /= 3;                                           
	}while(broj != 0);
	
	int brojac(0);
	
	for(int i(0); i < vektor.size(); i++){                  // Poredimo svaku cifru sa svakom drugom i sa samom sobom radi provjere ponavljanja
		for(int j(0); j < vektor.size(); j++){              
			if(vektor[i] == vektor[j]) brojac++;            // Posto nam ionako treba paran broj u promjenjivoj brojac ne moramo ga
		}                                                   // resetirati pri svakom ponovnom izvrsavanju prve petlje
		if(brojac % 2 != 0) return false;      
	}
	
	return true;
}

bool DaLiJeOdvratan(int broj){
	std::vector <int> vektor;
	int cifra;
	                                                       
	do{
		cifra = broj % 3;
		vektor.push_back(cifra);
		broj /= 3;
	}while(broj != 0);
	
	int brojac(0);
	
	for(int i(0); i < vektor.size(); i++){                 // Postupak isti kao i u funkciji DaLiJeOpak samo ovaj put resetiramo brojac zbog
		brojac = 0;
		for(int j(0); j < vektor.size(); j++){
			if(vektor[i] == vektor[j]) brojac++;
		}
		if(brojac % 2 == 0) return false;
	}
	return true;
}

std::vector <int> IzdvojiGadne (std::vector <int> vektor, bool istina){
	std::vector <int> Opaki, Odvratni;
	bool ponovljen(true);
	
	for(int i(0); i < vektor.size(); i++){
		ponovljen = true;
		if(DaLiJeOpak(vektor.at(i))){                                          // Idemo redom kroz proslijedjeni vektor i provjeravamo da li je broj opak ili odvratan
			for(int j(0); j < Opaki.size(); j++){
				if(vektor[i] == Opaki[j]){
					ponovljen = false;                                         // Provjeravamo da li smo vec unijeli isti opaki broj u vektor
					break;
				}
				
			}
			if(ponovljen) Opaki.push_back(vektor[i]);                         
		}
		
		else if(DaLiJeOdvratan(vektor.at(i))){
			for(int k(0); k < Odvratni.size(); k++){
				if(vektor[i] == Odvratni[k]){
					ponovljen = false;                                          // Provjera da li smo vec unijeli isti odvratan broj u vektor
					break;
				}
			}
			if(ponovljen) Odvratni.push_back(vektor[i]);
		}
	}
	if(istina)return Opaki;
	else return Odvratni;
}

int main (){
	
	double element;
	std::vector <int> v;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	
	while(std::cin >> element, element != 0){
		if(int(element) == element)
		v.push_back(static_cast <int>(element));
	}
	
	
	std::vector <int> a(IzdvojiGadne(v, 1));
	std::vector <int> b(IzdvojiGadne(v, 0));
	
	std::cout << "Opaki: ";
	for(int x : a)std::cout << x << " ";
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	for(int x : b)std::cout << x << " "; 

	return 0;
	
}