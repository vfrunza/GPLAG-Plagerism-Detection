/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cstring>

#define pb push_back


std::vector<int> IzdvojiGadne(std::vector<int> vect, bool Kontrolna) {
	std::vector<int> Vracam;
	Kontrolna = !Kontrolna;
	int N = vect.size(); 
		for (int i = 0; i < N; i++) {
			int TrenutniBroj = vect.at(i);
			int x1(0), x2(0), x3(0);
			
			bool Manji = TrenutniBroj < 0;
			while (TrenutniBroj) {
				int cifra = TrenutniBroj % 3;
				cifra = std::max(cifra, -cifra);
				
				if (cifra == 0) x1++;
				else if (cifra == 1) x2++;
				else x3++;
				
				if (Manji) { TrenutniBroj /= (-3); Manji = 0;}
				else TrenutniBroj /= 3;
			}
			
			int koliko_nula(0), koliko_djeljivih(0);
			if (x1 == 0) koliko_nula++; 
			if (x2 == 0) koliko_nula++;
			if (x3 == 0) koliko_nula++;
			if (x1 != 0 && x1 % 2 == Kontrolna) koliko_djeljivih++;
			if (x2 != 0 && x2 % 2 == Kontrolna) koliko_djeljivih++;
			if (x3 != 0 && x3 % 2 == Kontrolna) koliko_djeljivih++;
			
			if (koliko_djeljivih + koliko_nula == 3) Vracam.pb(vect.at(i));
		}
	
	
	for (int i = 0; i < Vracam.size(); i++)
		for (int j = i + 1; j < Vracam.size(); j++)
			if (i != j && Vracam.at(i) == Vracam.at(j))
				Vracam.erase(Vracam.begin() + j), j--;
	
	if (!Kontrolna) {
		for (int i = 0; i < Vracam.size(); i++)
			if (Vracam.at(i) == 0) {
				Vracam.erase(Vracam.begin() + i);
				i--;
			}
	}
 	return Vracam;
}
int main2() {
std::vector<int> v = {
	0, 2147483647, -2147483648,0, 12, 1212, 123, 10102, 10012, 1000, 608, 2613, -608, 333,
	333, 333, 333, 333, 333, 1000, -15, 60, 61, 15, 151, 16, 715, 7222,
};
auto opaki = IzdvojiGadne(v, true), odvratni = IzdvojiGadne(v, false);
std::cout << "Opaki: ";
for (const auto &x : opaki) std::cout << x << " ";
std::cout << std::endl << "Odvratni: ";
for (const auto &x : odvratni) std::cout << x << " ";
//Opaki: 608 -608 60 
//Odvratni: 123 333 -15 15 715
return 0;
}
int main()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int tmp; 
	std::vector<int> vect, x1, x2;
	while (1) {
		std::cin >> tmp;
		if (tmp == 0) break;
		vect.pb(tmp);
	}
	std::cout << "Opaki: ";
	x1 = IzdvojiGadne(vect, 1);
	x2 = IzdvojiGadne(vect, 0);
	for (int x : x1) std::cout << x << " ";
	std::cout << "\n";
	std::cout << "Odvratni: ";
	for (int x : x2) std::cout << x << " ";
	std::cout << "\n";
	return 0;
}