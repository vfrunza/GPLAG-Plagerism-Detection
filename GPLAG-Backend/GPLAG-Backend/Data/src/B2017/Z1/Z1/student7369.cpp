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

std::vector<int> IzbaciDuple ( std::vector<int> v ) {
	for(int i = 0; i < v.size(); i++ ) {
		for(int j = i+1; j < v.size(); j++ ) {
			if ( v.at(i) == v.at(j) ) {v.erase(v.begin() + j ); j--;}
		}
	}
	return v;
} // <-------- IZBACI DUPLE ELEMENTE VEKTORA

int ObrniBroj ( int a ) {
	int a2{abs(a)}, br{0};
	while ( a2 > 0 ) {
		a2 /= 10;
		br++;
	} br--;
	
	int obrnut{0}; a2 = abs(a);
	while ( a2 > 0 ) {
		obrnut += (( a2 % 10 ) * pow( 10, br ));
		br--;
		a2 /= 10;
	}
	if ( a < 0 ) return obrnut*(-1);
	return obrnut;
} // <-------- OBRNUT BROJ

bool JeLiProst ( int a ) {
	bool prost{true};
	for ( int i = 2; i < a; i++ ) {
		if ( (abs(a) % i) == 0 ){
			prost = false;
			break;
		}
	}
	return prost;
} // <--- PROVJERAVANJE PROSTOĆE BROJA

int uTernar ( int a ) {
	int i{0}, ternar{0}, a2{abs(a)};
	
	while( a2 > 0 ) {
		ternar += ((a2%3) * pow(10, i));
		i++;
		a2/=3;
	}
	if ( a < 0 ) return ternar*(-1);
	return ternar;
} // <--- U TERNAR

std::vector<int> vrati_proste ( std::vector<int> v ) {
	for ( int i = 0; i < v.size(); i++ ) {
		if ((JeLiProst(v.at(i)) == 0 )) {
			v.erase(v.begin() + i) ;
			i--;
		}
	}
	return v;
}

std::vector<int> vrati_slozene ( std::vector<int> v ) {
	for ( int i = 0; i < v.size(); i++) {
		if (( JeLiProst(v.at(i)) == 1)) {
			v.erase(v.begin() + i );
			i--;
		}
	}
	return v;
}

std::vector<int> IzdvojiSimetricneTernarne ( std::vector<int> v, bool t ) {
	v = IzbaciDuple(v);
	if ( t ) {
		v = vrati_proste(v);
		for ( int i = 0; i < v.size(); i++ ) {
			if ( uTernar(v.at(i)) != ( ObrniBroj( uTernar(v.at(i))))){
				v.erase(v.begin() + i );
				--i;
			} 
		}
	}
	else {
		v = vrati_slozene(v);
		for ( int i = 0; i < v.size(); i++ ) {
			if (uTernar(v.at(i)) != ( ObrniBroj(uTernar(v.at(i))))) {
				v.erase(v.begin() + i );
				i--;
			}
		}
	}
	return v;
}

int main ()
{
	std::vector<int> v;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	for(;;) {
		int a;
		std::cin >> a;
		if ( a == -1 ){
			break;}
		v.push_back(a);
	}
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int t;
	while (!(std::cin >> t) || (std::cin.peek()!= '\n') || ((t != 0)&&(t != 1))) {
		std::cin.clear();
		std::cout << "Neispravan unos! Unesite ponovo: ";
	}
	
	v = IzdvojiSimetricneTernarne(v, t);
	
	if (t){
	if (v.size()== 0){ std::cout << "Nema prostih simetricnih brojeva u vektoru."; return 0;}
		std::cout << "Prosti simetricni brojevi iz vektora su:";
		for ( int i = 0 ; i < v.size(); i++ ) {
			std::cout << " " << v.at(i);
			if ( i != v.size() -1 ) std::cout << ",";
			else std::cout << ".";
		}
	}
	else {
	if (v.size() == 0) { std::cout << "Nema slozenih simetricnih brojeva u vektoru."; return 0;}
		std::cout << "Slozeni simetricni brojevi iz vektora su:";
		for( int i = 0 ; i < v.size(); i++ ) {
			std::cout << " " << v.at(i);
			if (i != v.size() - 1 ) std::cout << ",";
			else std::cout << ".";
		}
	}
	
	return 0;
}