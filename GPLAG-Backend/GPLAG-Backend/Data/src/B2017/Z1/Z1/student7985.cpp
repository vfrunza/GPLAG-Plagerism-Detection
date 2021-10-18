/*B 2017/2018, Zadaća 1, Zadatak 1*/
#include <iostream>
#include <vector>
#include <cmath> //*abs je overload. u cmath

enum class Kakav{Slozen, Prost, Ostalo}; 
typedef std::vector<int> Vektor;

using std::cout; 
using std::cin;
using std::abs;

enum Kakav KakavJeN(int n){ 
	if(n <= 1) return Kakav::Ostalo; 
	for(int i=2; i<=std::sqrt(n); i++) 
		if(n % i == 0) return Kakav::Slozen;
	return Kakav::Prost;
}

bool SimetricanTernarni(int n){
	Vektor v;
	do{
		v.push_back(abs(n%3));	//!! važno za INT_MIN
		n /= 3;
	}while(n != 0);
	for(int i=0; i<v.size()/2; i++)
		if(v.at(i) != v.at(v.size()-1-i)) return false;
	return true;
}

Vektor IzdvojiSimetricneTernarne(Vektor v, bool prost){
	Vektor novi_v;
	for(int x : v) {
		bool preskoci(false);
		for(int y : novi_v)	
			if(x == y) {
				preskoci = true;
				break;
			}
		if(preskoci) continue;
		
		if(!SimetricanTernarni(abs(x))) continue;
		
		if(prost && KakavJeN(abs(x)) == Kakav::Prost) novi_v.push_back(x);
		else if(!prost && KakavJeN(abs(x)) == Kakav::Slozen) novi_v.push_back(x);
	}
	return novi_v;
}


int main (){
	cout << "Unesite elemente vektora (-1 za kraj): ";
	Vektor z;
	do{
		int x(0);
		cin >> x;
		if(x == -1) break;
		z.push_back(x);
	}while(1);
	cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	bool prost;
	do{
		cin >> prost;
		if(!cin || cin.peek() != '\n'){
			cin.clear();
			cin.ignore(10000, ' '); //heh ' '
			cout << "Neispravan unos! Unesite ponovo: ";
		}
		else break;
	}while(1);
	
	z=IzdvojiSimetricneTernarne(z, prost);
	if(z.size()==0){
		std::string s("prost");
		if(!prost) s = "slozen";
		cout << "Nema " << s << "ih simetricnih brojeva u vektoru.";
		return 0;
	}
	if(prost) cout << "Prosti simetricni brojevi iz vektora su: ";
	else cout << "Slozeni simetricni brojevi iz vektora su: ";
	for(int i=0; ; i++){
		cout << z.at(i);
		if(i == z.size()-1) {
			cout << ".";
			break;
		}
		cout << ", ";
	} 
	
	return 0;
}