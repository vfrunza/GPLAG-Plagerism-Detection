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

bool opak(int broj) {
	int cifre[3] = {0,0,0};
	while(broj!=0) {
		cifre[abs(broj%3)]++;
		broj/=3;
	}
	if( cifre[0]%2 != 0 || cifre[1]%2 != 0 || cifre[2]%2 != 0)
		return false;
	else return true;
}

bool odvratan(int broj) {
	int cifre[3] = {0,0,0};
	while(broj!=0) {
		cifre[abs(broj%3)]++;
		broj/=3;
	}
	if( (cifre[0] != 0 && cifre[0]%2 == 0) || (cifre[1] != 0 && cifre[1]%2 == 0) || (cifre[2] != 0 && cifre[2]%2 == 0) )
		return false;
	else return true;
}

std::vector<int> izbaciPonavljanja(std::vector<int> vektor) {
	std::vector<int> povratni;
	int velicina = vektor.size();
	bool ponovljen = false;
	for(int i(0);i<velicina;i++) {
		ponovljen = false;
		for(int j(0);j<i;j++)
			if(vektor[i]==vektor[j]) {
				ponovljen = true;
				break;
			}
		if(!ponovljen)
			povratni.push_back(vektor[i]);
	}
	return povratni;
}

std::vector<int> IzdvojiGadne(std::vector<int> brojevi, bool c) {
	std::vector<int> povratni;
	if(c) {
		for(int i(0);i<brojevi.size();i++)
			if(opak(brojevi[i]))
				povratni.push_back(brojevi[i]);
	} 
	else {
		for(int i(0);i<brojevi.size();i++)
			if(odvratan(brojevi[i]))
				povratni.push_back(brojevi[i]);
	}
	povratni = izbaciPonavljanja(povratni);
	return povratni;
}


int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> a;
	int x;
	while(1) {
		std::cin>>x;
		if(x==0) break;
		a.push_back(x);
	}
	std::cout<<"Opaki: ";
	auto opaki = IzdvojiGadne(a, true);
	for(int i(0);i<opaki.size();i++)
		std::cout<< opaki[i] <<" ";
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	auto odvratni = IzdvojiGadne(a, false);
	for(int i(0);i<odvratni.size();i++)
		std::cout<< odvratni[i] <<" ";
	return 0;
}