/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProst (int nekibroj) {
	int i;
	bool t(true);
	
	for (i=2; i<=sqrt(nekibroj); i++) {
		if(nekibroj%i==0) t = false;
	}
	return t;
}

bool SimetricniTernarni (int clanvektora) {
	
	bool simetricnost(false);
	int ternarni(0), stepen(1);
	
	if(clanvektora < 0) {
		clanvektora *= -1;
	}
	
	while(clanvektora != 0) {
		ternarni += (clanvektora%3) * stepen;
		stepen *= 10;
		clanvektora /= 3;
	}
	
    int k(0), pomocni=fabs(ternarni);
    
		while(ternarni != 0) {
			int l = ternarni % 10;
			int a = k*10 + l;
		    k = a;
		    ternarni /= 10;
		}
	if(pomocni == k)  simetricnost = true;
	
	return simetricnost;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v1, bool p) {
	
	std::vector<int> v2;
	
		for(int i(0); i<v1.size(); i++) {
			if(DaLiJeProst(v1.at(i))) {
				int pomocni = v1.at(i);
				if(SimetricniTernarni(pomocni)==true && p==true) v2.push_back(v1.at(i));
			}

			else  {
				if(SimetricniTernarni(v1.at(i))==true && p==false) v2.push_back(v1.at(i));
		}
}
return v2;
}

int main ()
{
	std::vector<int> a;
	
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	int elementi;
	
	do {
		std::cin >> elementi;
		if(elementi != -1) a.push_back(elementi);
	}
	while(elementi != -1);
	
	int m;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> m;
	while(m!=1 && m!=0) {
		std::cin.clear();
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> m;
	}
	
	if(m == 1) {
	
	a = IzdvojiSimetricneTernarne(a, true);
	if(a.size()==0) {
		std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	}
	else {
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
    for (int i(0); i<a.size(); i++) {
    	if(i==a.size()-1) std::cout << a.at(i) << ".";
    else    std::cout << a.at(i) << ", ";
    }
	}
	}
    
    if(m==0) {
    	
   a = IzdvojiSimetricneTernarne(a, false);
   if(a.size()==0) {
		std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	}
	else {
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
    for (int i(0); i<a.size(); i++) {
    	if(i==a.size()-1) std::cout << a.at(i) << ".";
    else    std::cout << a.at(i) << ", ";
    }
	}
	}
	
    
	return 0;
}