#include <iostream>
#include <vector>
#include <cmath>
using std::endl;
using std::cout;
using std::cin;
typedef std::vector<int> vektor;

long long BrojRikverc (long long broj)
{
	long long rikvercovan(0);
	do {
		int ostatak = broj%10;
		rikvercovan = ostatak + rikvercovan*10;
		broj/=10;
	} while (broj);
	return rikvercovan;
} 

long long Konvertuj (int decimalni)
{
	long long ternarni(0);
	long long koeficijent(1);
	do {
		int ostatak = decimalni % 3;
		decimalni = decimalni / 3;
		ternarni = ternarni + (ostatak*koeficijent);
		koeficijent = koeficijent * 10;
	} while (decimalni != 0);

	return ternarni;
}

bool ProstIliSlozen (int nekibroj)
{
	long long broj(nekibroj);
	if(broj<0)
		broj*=-1;
	if(broj<2)
		return false;
	for (int i=2; i<=std::sqrt(broj); i++) {
		if(broj%i==0) {
			return false;
		}
	}
	return true;
} 

bool ProvjeraSimetricnosti (long long n)
{
	return (n == BrojRikverc(n));
}

vektor IzdvojiSimetricneTernarne (vektor brojevi, bool vrsta)
{
	vektor rezultat;
	if (vrsta) {
		for (int i=0; i<brojevi.size(); i++) {
			if(ProstIliSlozen(brojevi.at(i))) {
				if(ProvjeraSimetricnosti(Konvertuj(brojevi.at(i))))
					rezultat.push_back(brojevi.at(i));
			}
		}
	}
	if (!vrsta) {
		for (int i=0; i<brojevi.size(); i++) {
			if(!ProstIliSlozen(brojevi.at(i))) {
				if(ProvjeraSimetricnosti(Konvertuj(brojevi.at(i))))
					rezultat.push_back(brojevi.at(i));
			}
		}
	}
	
	for (int i(0); i<rezultat.size(); i++) {
		for (int j(i+1); j<rezultat.size(); j++) {
			if (rezultat.at(i)==rezultat.at(j)) {
				rezultat.erase(rezultat.begin()+j);
				j--;
			}
		}
	}
	
	return rezultat;
}
int main ()
{
	int broj;
	vektor brojevi;
	cout << "Unesite elemente vektora (-1 za kraj): " ;
	do {
		cin >> broj;
		if (broj!=-1)
			brojevi.push_back(broj);
	} while (broj!=-1) ;
	int vrsta;
	cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		cin >> vrsta;
		if(vrsta!=1 && vrsta!=0)
			cout << "Neispravan unos! Unesite ponovo: ";
	} while (vrsta!=1 && vrsta!=0);
	if (vrsta) {
		brojevi = IzdvojiSimetricneTernarne(brojevi, true);
		if (brojevi.size()==0)
			cout << "Nema prostih simetricnih brojeva u vektoru.";
		else {
			cout << "Prosti simetricni brojevi iz vektora su: ";
			for (int i(0); i<brojevi.size(); i++) {
				if (i<brojevi.size()-1)
					cout << brojevi.at(i) << ", " ;
				else
					cout << brojevi.at(i) << ".";
			}
		}
	} else {
		brojevi = IzdvojiSimetricneTernarne(brojevi, false);
		if(brojevi.size()==0)
			cout << "Nema slozenih simetricnih brojeva u vektoru.";
		else {
			cout << "Slozeni simetricni brojevi iz vektora su: ";
			for (int i(0); i<brojevi.size(); i++) {
				if (i<brojevi.size()-1)
					cout << brojevi.at(i) << ", " ;
				else
					cout << brojevi.at(i) << ".";
			}
		}
	}
	return 0;
}