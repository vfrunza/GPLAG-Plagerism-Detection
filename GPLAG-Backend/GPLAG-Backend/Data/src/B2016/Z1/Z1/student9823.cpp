#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

bool ImaLiuVektoru(const std::vector <int> v, int broj)
{
	bool Ima(true);
	for(unsigned int i = 0; i< v.size(); i++) {
		if(v.at(i) == broj) {
			Ima = false;
			break;
		}
	}
	return Ima;
}

int NajveciSaBazom3()  
{
	int maxINT = std::numeric_limits<int>::max();
	int n = int(log(double(maxINT))/log(3));
	return n;
}

std::vector <int> IzdvojiGadne(const std::vector <int> v, bool Vrijednost)
{

	int MaxStepen = NajveciSaBazom3();
	std::vector <int> Novi;

	for(long long i=0; i < v.size(); i++) {

		if(ImaLiuVektoru(Novi, v.at(i))) {

			bool DesiloSe(false);
			if(!Vrijednost && v.at(i)==0) {
				Novi.push_back(v.at(i)); continue;
			} else if(Vrijednost && v.at(i)==0) continue;

			long long int glavniBroj;
			glavniBroj = v.at(i);

			if(glavniBroj <0) { glavniBroj *= -1; }
			
			int broj = 1;
			int najveciStepen = 0;

			while(broj <= glavniBroj) {
				if(najveciStepen == MaxStepen) { DesiloSe=true; break; }
				najveciStepen++;
				broj *=3;
			}

			if(!DesiloSe) najveciStepen -=1;
			int BrojPuta0(0) , BrojPuta1(0), BrojPuta2(0);
			int pomocniBroj=0;

			while(najveciStepen >=0) {
				pomocniBroj = (glavniBroj / int(std::pow(3., najveciStepen)));
				glavniBroj -= (pomocniBroj * int(std::pow(3., najveciStepen)));
				switch(pomocniBroj) {
				case 0:
					BrojPuta0++;
					break;
				case 1:
					BrojPuta1++;
					break;
				case 2:
					BrojPuta2++;
					break;
				default:
					break;
				}
				najveciStepen--;
			}

			if(BrojPuta0%2==0 && BrojPuta1%2==0 && BrojPuta2%2==0 && Vrijednost) Novi.push_back(v.at(i));

			if(!Vrijednost) {
				if(BrojPuta0==0) BrojPuta0++;
				if(BrojPuta1==0) BrojPuta1++;
				if(BrojPuta2==0) BrojPuta2++;
			}
			if(BrojPuta0%2!=0 && BrojPuta1%2!=0 && BrojPuta2%2!=0 && !Vrijednost) Novi.push_back(v.at(i));

		}

	}
	return Novi;
}







int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector <int> pomocni;
	int element;
	for(;;) {
		std::cin >> element;
		if(element==0) break;
		pomocni.push_back(element);
	}

	std::vector <int> a;
	std::vector <int> b;

	a = IzdvojiGadne(pomocni, true);
	b = IzdvojiGadne(pomocni, false);

	std::cout << "Opaki: ";
	for(unsigned int i=0; i< a.size(); i++) std::cout << a.at(i) << " ";
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	for(unsigned int i=0; i< b.size(); i++) std::cout << b.at(i) << " ";

	return 0;
}