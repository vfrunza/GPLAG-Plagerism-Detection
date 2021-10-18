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

using std::cout;
using std::cin;
using std::vector;

bool Da_li_je_broj_prost(int a) {
	if (a < 0) a *= -1;
	
	for(unsigned int i(2); i <= sqrt(a); i++) 
		if(a % i == 0) return false;
		
	return true;
}

int Pretvori_u_ternarni(int a) {
	int b(a);
	if(a < 0) a *= -1;
	
	int broj(0), br(0);
	
	while(b / 3 != 0) {
		broj = broj + (b % 3) * pow(10, br);
		b /= 3;
		br++;
	}
	
	broj = broj + (b % 3) * pow(10, br);
	
	if(a > 0) return broj;
	
	return broj *= -1;
}

bool Da_li_je_broj_simetrican (int a) {
	
	if(a < 0) a *= -1;
	
	int broj_cifara(0), pom(a);
	
	while(a / 10 != 0) {
		broj_cifara++;
		a /= 10;
	}
	
	broj_cifara++;
	
	for(int i(broj_cifara); i >= 2; i -= 2) {
		
		if((pom % 10) != (pom / (int(pow(10, i - 1)))) % 10) return false;
		pom /= 10;
		
	}
	
	return true;
	
}


typedef vector<int> vektor;

vektor IzdvojiSimetricneTernarne(vektor v, bool a) {
	
	if(a) {
		vektor prosti;

		for(int i(0); i < v.size(); i++) {
			
			if(v.at(i) == 1) continue;
			
			if(Da_li_je_broj_prost(v.at(i))) {
				
				int a(Pretvori_u_ternarni(v.at(i)));
				if(Da_li_je_broj_simetrican(a))  {
					
					int br(0);
					
					for(int j(0); j < prosti.size(); j++) 
						if(prosti.at(j) == v.at(i)) br++;
					
					if(br == 0)	prosti.push_back(v.at(i));
				}
				
			}
		
		}
			
		return prosti;
		
	}
	
	vektor slozeni;
	for(int i(0); i < v.size(); i++) {
		
		if(v.at(i) == 1) continue;
		
		if(!Da_li_je_broj_prost(v.at(i))) {
			int a(Pretvori_u_ternarni(v.at(i)));
			
			if(Da_li_je_broj_simetrican(a)) {
				
				int br(0);
				
				for(int j(0); j < slozeni.size(); j++) 
					if(slozeni.at(j) == v.at(i)) br++;
				
				if(br == 0) slozeni.push_back(v.at(i));
			}
			
		}
		
	}
	
	return slozeni;
	
	
}

void Ispisi(vektor v) {
	
	for(int i(0); i < v.size(); i++) {
		
		if(i != v.size() - 1 ) cout << v.at(i) << ", ";
		else cout << v.at(i) << ".";
		
	}
	
}

int main ()
{
	vektor v, v1;
	int a;
	
	cout << "Unesite elemente vektora (-1 za kraj): ";
	while(cin >> a, a != -1) {
		v.push_back(a);
	}
	
	int b;
	cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	
	while(cin >> b, (b != 0 && b != 1)) {
		cout << "Neispravan unos! Unesite ponovo: ";
	}
	
	v1 = IzdvojiSimetricneTernarne(v, b);
	
	if(b) {
		
		if(v1.size() == 0) cout << "Nema prostih simetricnih brojeva u vektoru.";
		else {
			cout << "Prosti simetricni brojevi iz vektora su: "; 
			Ispisi(v1);
		}
		
	}
	
	else {
		
		if(v1.size() == 0) cout << "Nema slozenih simetricnih brojeva u vektoru.";
		else {
			
			cout << "Slozeni simetricni brojevi iz vektora su: ";
			Ispisi(v1);
		}
		
	}
	
	return 0;
}