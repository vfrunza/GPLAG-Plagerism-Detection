#include <iostream>
#include <vector>
#include <cmath>

std::vector<long long int> DekadneUTernarne(std::vector<long long int> a){
	for (int i = 0; i < a.size(); i++) { //Petn
		long long int broj{0};
		bool istina(false);
		if (a[i] % 3 == 0) istina = true;
		
		int kopija = a[i];
		int brojac(0);
		while(kopija %3 == 0 ){
			brojac++;
			kopija = kopija / 3;
		}

		while (a[i] != 0){
			broj = a[i] % 3 + broj*10;
			a[i]= a[i]/3;
		}
		
		
		
		while (broj != 0){
			a[i] = a[i]*10 + (broj%10);
			broj = broj / 10;
		}
		if(istina) a[i] *= pow(10, brojac); 
	}
	return a;
} //Ova fja radi!

std::vector<long long int> TernarneUDekadne(std::vector<long long int> a){
	for (int i = 0; i < a.size(); i++) { //Petn
		long long int broj{0};
		int brojac(0);
		
		while (a[i] != 0){
			
			broj = (a[i]%10)*(pow(3,brojac++))+(broj);
			a[i]= a[i]/10;
			
		}
		a[i] = broj;
	}
	return a;
	
} //Ova fja radi!

std::vector<int> IzdvojiGadne(std::vector<int> c, bool istinitost){
	std::vector<long long int> b;
	int brojaci[3]{0};
	
	std::vector<long long int> a;
	
	for (auto i : c) {
		a.push_back(i);
	}
	
	a = DekadneUTernarne(a);
	
	for (int i = 0; i < a.size(); i++) { 
		brojaci[0]=0;
		brojaci[1]=0;
		brojaci[2]=0;
		long long int kopija = a[i];
		
		if (a[i] <0) a[i] *= -1; // POPRAVKA ZA NEG BROJEVE

		while(a[i] != 0){ // PODJELA PO CIFRAMA
			long long int broj(a[i] % 10);
			brojaci[broj]++;
			a[i] = a[i] / 10;
		}
	
		if (brojaci[0] % 2 == 0 && brojaci[1] % 2 == 0 && brojaci[2] % 2 == 0 && istinitost) {
			bool istina {false};
			for (int j = 0; j < b.size(); j++) {
				if (kopija == b[j]) {
					istina = true;
					break;
				}
				
			}
			if (!istina){
			
			b.push_back(kopija);
			}
		} // ako je opak OVAJ DIO JE OK
		else if (!istinitost && (brojaci[1] % 2 != 0 || brojaci[1]==0) && (brojaci[2] % 2 != 0 || brojaci[2]==0)){
			if (!(brojaci[0] > 0 && brojaci[0] % 2 == 0)) {
				
		
			
			bool istina {false};
			for (int j = 0; j < b.size(); j++) {
				if (kopija == b[j]) {
					istina = true;
					break;
				}
				
			}
			if (!istina){
			
				b.push_back(kopija);
			}
		
		}
		}
		
	}
	
	b = TernarneUDekadne(b);
	std::vector<int> d;
	for (auto i : b) {
		d.push_back(i);
	}
	return d;
}

int main ()
{
	
	//Predpostavljamo da korisnik unosi prave elemente, ne smece
	std::cout << "Unesite brojeve (0 za prekid unosa): " ;
	long long int n;
	std::cin >> n;
	
	std::vector<int> a;
	
	while(n !=0) {
		a.push_back(n);
		std::cin >> n;
	}

	
	std::vector<int> b = IzdvojiGadne(a, true); // Zelim samo opake brojeve

	std::cout <<"Opaki: ";
	for (auto i : b) {
		std::cout << i << " ";
	}
	std::cout  << std::endl;
	std::vector<int> c = IzdvojiGadne(a, false); // Zelim samo odvratne brojeve

	std::cout << "Odvratni: ";
	
	for (auto i : c) {
		std::cout << i << " ";
	}
	
	return 0;
}