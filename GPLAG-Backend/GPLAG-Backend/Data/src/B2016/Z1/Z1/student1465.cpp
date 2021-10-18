/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream> 
#include <vector>
#include <cmath>

//funckija koja pretvara broj iz decimalnog u ternarni i vraća ternarni u vektoru
std::vector<long int> dec2ter(int n) {
	std::vector<long int> t;
	int ostatak{0};
	int i{1};
	
	while(n != 0) {
		ostatak = abs(n % 3);
		n /= 3;
		t.push_back(ostatak);
		i = i*10;
	}
	return t;
}

//funkcija koja provjerava da li je broj opak
bool opaki_broj(int n) {
	std::vector<long int> a;
	a = dec2ter(n);
	std::vector<int> cifre(3);
	
	for(int i = 0; i < a.size(); i++) {
		cifre[a[i]]++;
	}
	for(int i = 0; i < cifre.size(); i++) {
		if(cifre[i] == 0) continue;
		if(cifre[i] % 2 != 0) {
			return false;
		}
	}
	return true;
}
 
//funckija koja provjerava da li je broj odvratan
bool odvratan_broj(int n) {
	std::vector<long int> a;
	a = dec2ter(n);
	std::vector<int> cifre(3);
	for(int i = 0; i < a.size(); i++) {
		cifre[a[i]]++;
	}
	for(int i = 0; i < cifre.size(); i++) {
		if(cifre[i] == 0) continue;
		if(cifre[i] % 2 == 0) {
			return false;
		}
	}
	return true;
}

std::vector<int>IzdvojiGadne(std::vector<int> vektor, bool vrijednost) {
	std::vector<int> konacni;
	if(vrijednost) {
		for(int i = 0; i < vektor.size(); i++) {
			if(vektor[i] == 0) continue;
			if(opaki_broj(vektor[i])) konacni.push_back(vektor[i]);
			if(i == vektor.size()) break;
		}
	}
	else {
		for(int i = 0; i < vektor.size(); i++) {
			if(vektor[i] == 0) konacni.push_back(0);
			if(odvratan_broj(vektor[i])) konacni.push_back(vektor[i]);
			if(i == vektor.size()) break;
		}
	}
	
	for(int i = 0; i < konacni.size(); i++) {
		for(int j = i+1; j < konacni.size(); j++) {
			if(konacni[i] == konacni[j]) {
				konacni.erase(konacni.begin() + j);
				j--;
			}
		}
	}
	return konacni;
}

int main ()
{
	std::vector<int> vektor;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	for(;;) {
		int broj;
		std::cin >> broj;
		if(broj == 0) break;
		if(std::cin)
			vektor.push_back(broj);
		else 
		{
			std::cout << std::endl << "Neispravan unos.";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
	
	std::vector <int> opaki;
	std::vector <int> odvratni;
	
	opaki = IzdvojiGadne(vektor, true);
	odvratni = IzdvojiGadne(vektor, false);
	
	std::cout << "Opaki: ";
	for(int x: opaki) std::cout << x << " ";
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	for(int x: odvratni) std::cout << x << " ";
	return 0;
}