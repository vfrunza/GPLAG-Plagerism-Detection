#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <type_traits>

/*
int Funkcija2(int x, int y)
{
	return x+(2*y);
}

bool Poredak2(int x, int y)
{
	int SumaX(0), SumaY(0);
	bool ManjiX(true);
	if (y<x)
		ManjiX=false;
	do {
		SumaX+=abs(x%10);
		x=x/10;
	} while(x!=0);
	do {
		SumaY+=abs(y%10);
		y=y/10;
	} while(y!=0);
	if (SumaX<SumaY || (SumaX==SumaY && ManjiX))
		return true;
	return false;
}
*/

int Funkcija(int x, int y)
{
	return -2*x + y;
}

bool Poredak(int x, int y)
{
	int br1(1), br2(1);
	bool VeciX(true);
	if (y>x)
		VeciX=false;
	if (x<0) x*=-1;
	if (y<0) y*=-1;
	for (int i = 2; x>1 && i!=x; i++) {
		if (x%i==0 && i!=x) {
			br1++;
			x/=i;
			i=1;
		}
	}

	for (int i = 2; y>1 && i!=y; i++) {
		if (y%i==0 && i!=y) {
			br2++;
			y/=i;
			i=1;
		}
	}

	if (br1>br2 || (br1==br2 && VeciX))
		return true;
	return false;

}

template <typename PokaziliIter1, typename PokaziliIter2, typename PokaziliIter3>
void SortirajPodrucjeVrijednosti(PokaziliIter1 poc1, PokaziliIter1 kraj1, PokaziliIter2 poc2, PokaziliIter3 poc3, typename std::remove_reference<decltype(*poc3)>::type funkcija(typename std::remove_reference<decltype(*poc1)>::type, typename std::remove_reference<decltype(*poc2)>::type), bool UvjetSortiranja(typename std::remove_reference<decltype(*poc1)>::type, typename std::remove_reference<decltype(*poc2)>::type))
{
	std::sort(poc1, kraj1, UvjetSortiranja);
	int vel(kraj1-poc1);
	std::sort(poc2, poc2+vel, UvjetSortiranja);

	for (int i = 0; i < vel; i++) {
		PokaziliIter3 Pozicija (std::find(poc3, poc3+vel,funkcija(*(poc1+i), *(poc2+i))));
		/*
			if (!std::binary_search(poc3, poc3+vel,funkcija(*(poc1+i), *(poc2+i)), UvjetSortiranja))
				throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
			PokaziliIter3 Pozicija (std::lower_bound(poc3, poc3+vel,funkcija(*(poc1+i), *(poc2+i)),UvjetSortiranja));
		*/
		if (Pozicija==poc3+vel)
			throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		typename std::remove_reference<decltype(*poc3)>::type temp(*(poc3+i));
		*(poc3+i)=*Pozicija;
		*Pozicija=temp;
	}
}

void Unos(std::vector<int> &v, int const &vel)
{
	for (int i = 0; i < vel; i++) {
		int broj;
		std::cin >> broj;
		int j(i-1);
		for (; j >=0; j--)
			if (v.at(j)==broj)
				break;
		if (j==-1)
			v.at(i)=broj;
		else
			i--;
	}
}

int main ()
{
	// (S1 = 35 12 8 111 20 4) (S2 = 61 39 5 313 42 13) (S3 = 195 46 634 22 113 126)
	int vel;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> vel;
	std::vector<int> v1(vel), v2(vel), v3(vel);
	std::cout << "Unesite elemente prvog vektora: " ;
	Unos(v1, vel);
	std::cout << "Unesite elemente drugog vektora: " ;
	Unos(v2, vel);
	std::cout << "Unesite elemente treceg vektora: " ;
	Unos(v3, vel);
	
	try {
		SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), Funkcija, Poredak);
		std::cout << "\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke:" << std::endl;
		for (int i = 0; i < vel; i++) {
			if (i==vel-1)
				std::cout << "f(" << v1.at(i) << ", " << v2.at(i) << ") = " << v3.at(i);
			else
				std::cout << "f(" << v1.at(i) << ", " << v2.at(i) << ") = " << v3.at(i) << std::endl;
		}
	} catch (std::logic_error greska) {
		std::cout << "\nIzuzetak: " << greska.what();
		return 1;
	}

	return 0;
}