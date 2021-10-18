//B 2016/2017, Zadaća 1, Zadatak 1

#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::cin;
typedef std::vector<int> Vektor;

Vektor PrebaciUTernarni (int n)
{
	Vektor broj;

	do {
		int c (n%3);
		broj.push_back (abs(c));
		n /= 3;

	} while(n != 0);

	return broj;
}
//funkcija broji koliko puta se u broju ponavljaju cifre 0, 1 i 2
Vektor Prebroji (int n)
{
	Vektor broj = PrebaciUTernarni(n);

	Vektor histogram(3,0);                 //u histogram upisujemo broj ponavljanja cifara 0, 1 i 2

	for(int i = 0; i < broj.size(); i++) {
		histogram [(broj.at(i))]++;
	}

	return histogram;
}

Vektor IzdvojiGadne (Vektor v, bool parno_neparno)
{
	Vektor gadni;
	bool opaki(false), odvratni(false);

	for(int i = 0; i < v.size(); i++) {

		Vektor brojac = Prebroji(v.at(i));

		// Provjera da li je broj opak ili odvratan
		for(int j = 0; j < brojac.size(); j++) {

			if(brojac[j] == 0) continue;
			else if(brojac.at(j)%2 == 0) {
				opaki = true;
			} else if(brojac.at(j)%2 != 0) {
				odvratni = true;
			}
		}

		bool ponavljanje(false);

		if(parno_neparno) {
			if(opaki == true && odvratni == false) {
				if(i == 0)	gadni.push_back(v.at(i));
				else {
					//provjeram da li se isti broj vec nalazi u vektoru
					for(int k = 0; k < gadni.size(); k++) {
						if(v.at(i) == gadni.at(k)) {
							ponavljanje = true;
							break;
						} else ponavljanje = false;
					}

					if(ponavljanje == false)
						gadni.push_back(v.at(i));
				}
			}
		} else {
			if(odvratni == true && opaki == false) {
				if(i == 0)	gadni.push_back(v.at(i));
				else {
					for(int k = 0; k < gadni.size(); k++) {
						if(v.at(i) == gadni.at(k)) {
							ponavljanje = true;
							break;
						} else ponavljanje = false;
					}

					if(ponavljanje == false)
						gadni.push_back(v.at(i));
				}
			}
		}
		//vracam vrijednosti na false radi testiranja ostalih elemenata vektora
		opaki = false;
		odvratni = false;
	}

	return gadni;
}

int main ()
{
	Vektor v;
	cout << "Unesite brojeve (0 za prekid unosa): ";
	int x;

	for(;;) {

		cin >> x;
		if(!cin) {
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if(x != 0) v.push_back(x);
		if(x == 0) break;
	}

	Vektor opaki = std::move(IzdvojiGadne(v, true));
	Vektor odvratni = std::move(IzdvojiGadne(v, false));

	cout << "Opaki: ";
	for(int i = 0; i < opaki.size(); i++)
		cout << opaki.at(i) << " ";

	cout << std::endl;

	cout << "Odvratni: ";
	for(int i = 0; i < odvratni.size(); i++)
		cout << odvratni.at(i) << " ";

	return 0;
}