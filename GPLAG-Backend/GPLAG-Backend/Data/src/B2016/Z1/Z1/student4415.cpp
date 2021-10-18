/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>

bool find1 (std::vector<int> v1, long long int broj)
{
	for (auto &i : v1) {
		if (i == broj) return true;
	}
	return false;
}


unsigned int  Br_2 (long long int a)
{

	unsigned int brojac(0);

	while (a != 0) {
		if (abs(a%10) == 2) brojac++;
		a /= 10;
	}
	return brojac;
}

unsigned int Br_1 (long long int a)
{
	unsigned int brojac(0);

	while (a != 0) {
		if (abs(a%10) == 1) brojac++;
		a /= 10;
	}
	return brojac;
}

unsigned int Br_0 (long long int a)
{
	if (a == 0) return 1;
	unsigned int brojac(0);

	while (a != 0) {
		if (abs(a%10) == 0) brojac++;
		a /= 10;
	}
	return brojac;
}

bool Opaki (long long int a)
{
	if (a == 0) return false;
	long long int t(0);
	bool opak(true);
	int b(0);
	int i(0);
	while (a != 0) {
		b = abs(a%3);
		t = t + b*pow(10,i);
		a /= 3;
		i++;
	}
	unsigned br_0(Br_0(t));
	unsigned br_1(Br_1(t));
	unsigned br_2(Br_2(t));

	if ((br_0 != 0 and br_0%2 != 0) or (br_1 != 0 and br_1%2 != 0) or (br_2 != 0 and br_2%2 != 0)) opak = false;
	return opak;
}


bool Odvratni (long long int a)
{
	if (a == 0) return true;
	long long int t(0);
	bool odvratan(true);
	int b(0);
	int i(0);
	
	while (a != 0) {
		b = abs(a%3);
		t = t + b*pow(10,i);
		a /= 3;
		i++;
	}
	unsigned int br_0(Br_0(t));
	unsigned int br_1(Br_1(t));
	unsigned int br_2(Br_2(t));

	if ((br_0 != 0 and br_0%2 != 1) or (br_1 != 0 and br_1%2 != 1) or (br_2 != 0 and br_2%2 != 1)) odvratan = false;
	return odvratan;
}

std::vector<int> IzdvojiGadne (std::vector<int> v1,bool t)
{
	std::vector<int> v2;
	if (t == true) {
		for (auto &i : v1) {
			if(Opaki(i)) {
				if (find1(v2,i) == false)
					v2.push_back(i);
			}
		}
	} else {
		for (auto &i : v1) {
			if(Odvratni(i)) {
				if (find1(v2,i) == false)
					v2.push_back(i);
			}
		}
	}
	return v2;
}

int main ()
{

	std::vector<int> v1;

	int a(0);

	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	do {
		std::cin >> a;
		if (a == 0) break;
		v1.push_back(a);
	} while (a != 0);

	std::vector<int> v2 = IzdvojiGadne(v1,true);
	std::vector<int> v3 = IzdvojiGadne(v1,false);

	std::cout << "Opaki: ";
	for (auto i : v2) {
		std::cout << i << " ";
	}
	std::cout  << std::endl;
	std::cout << "Odvratni: ";
	for (auto i : v3) {
		std::cout << i << " ";
	}

	return 0;
}
