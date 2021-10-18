//B 2016/2017, Zadaća 1, Zadatak 1
#include <iostream>
#include <vector>
#include <cmath>

long int DajTernarni (int decimal)
{
	long int Ternarni(0);
	std::vector<int> temp;
	while (decimal != 0) {
		temp.push_back(decimal%3);
		decimal /= 3;
	}
	for (int i=temp.size()-1; i>=0; --i) {
		Ternarni = 10*Ternarni + temp[i];
	}	return Ternarni;
}

std::vector<int> IzdvojiGadne (std::vector<int> vektor, bool parametar)
{
	std::vector<int> output_vektor;
	for (int x : vektor)
	{
		bool parnost(true);
		bool neparnost(true);
		
		for (int i=0; i<=2; ++i)
		{
			int brojac(0);
			long int broj(DajTernarni(x));
			broj = std::fabs(broj);
			
			// Test za nulu posebno ..
			if (broj == 0) {
				parnost = false;
				neparnost = true;
				break;
			}
			
			while (broj != 0) {
				if (broj%10 == i)
					brojac++;
				
				broj /= 10;
			}
			
			if (brojac != 0) {
				if (not(brojac % 2 == 0))
					parnost = false;
				if (brojac % 2 == 0)
					neparnost = false;
			}
		}
		
		bool nema_broja(true);
		for (int y : output_vektor)
			if (x == y) {
				nema_broja = false;
				break;
			}
			
		if (parnost and parametar and nema_broja)
				output_vektor.push_back(x);
		else if (neparnost and not(parametar) and nema_broja) 
			output_vektor.push_back(x);
	}
	return output_vektor;
}

int main ()
{
	int broj;
	std::vector<int> Vektor;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	do {
		std::cin >> broj;
		if (broj != 0)	Vektor.push_back(broj);
	}	while (broj != 0);
	
	std::cout << "Opaki: ";
	for (int x : IzdvojiGadne(Vektor, true))
		std::cout << x << " ";
	
	std::cout << std::endl << "Odvratni: ";
	for (int x : IzdvojiGadne(Vektor, false))
		std::cout << x << " ";
		
	return 0;
}