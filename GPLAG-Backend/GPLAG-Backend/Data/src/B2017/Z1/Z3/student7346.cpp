#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <climits>
using std::cin;
using std::endl;
using std::cout;
typedef std::vector<int> vektor;
typedef std::deque<vektor> dekvek;
enum Smjer {Rastuci, Opadajuci};

bool StepenBrojaDva (int a)
{

	if (a<1)
		return false;
	while (a!=1) {
		if(a%2!=0)
			return false ;
		a/=2;
	}
	return true;
}

int VelicinaPodniza (int lokacija, vektor brojevi, Smjer smjer)
{
	if (!StepenBrojaDva(brojevi.at(lokacija)))
		return 0;
	int vel(0);
	if (smjer == Opadajuci) {
		for (int i=lokacija+1; i<brojevi.size(); i++) {
			if(brojevi.at(i-1)>=brojevi.at(i) && StepenBrojaDva(brojevi.at(i)))
				vel++;
			else
				break;
		}
	} else {
		for(int i=lokacija+1; i<brojevi.size(); i++) {
			if(brojevi.at(i)>=brojevi.at(i-1) && StepenBrojaDva(brojevi.at(i)))
				vel++;
			else
				break;
		}
	}
	return vel;
}

dekvek MaksimalniPodnizoviStepenaDvojke (vektor brojevi, Smjer smjer)
{
	dekvek krajnji; //Trazeni dek vektora s monotono rastucim/opadajucim podnizovima
	int brvek(0);
	for (int i(0); i<brojevi.size(); i++) {
		int brel(VelicinaPodniza(i, brojevi, smjer));
		if (brel>=1) {
			brvek++;
			krajnji.resize(brvek);
			for (int j=i; j<=brel+i; j++) {
				krajnji.at(brvek-1).push_back(brojevi.at(j));
			}
			i=i+brel;
		}
	}
	return krajnji;
}

void IspisiMaksimalnePodnizove (dekvek rezultat, Smjer smjer)
{
	if (smjer==Rastuci)
		cout << "Maksimalni rastuci podnizovi: " << endl;
	else
		cout << "Maksimalni opadajuci podnizovi: " << endl;
	for (auto x : rezultat) {
		for (auto y : x)
			cout << y << " ";
		cout << endl;
	}
}

int main ()
{
	vektor elementi;
	int brel;
	cout << "Unesite broj elemenata vektora: ";
	cin >> brel;
	cout << "Unesite elemente vektora: ";
	for (int i(0); i<brel; i++) {
		int element;
		cin >> element;
		elementi.push_back(element);
		if(i==INT_MAX) break;
	}
	double smjer;
	cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	cin >> smjer;
	if(smjer!=1 && smjer!=2)
		do {
			cout << "Neispravan smjer, unesite novi: ";
			int smjer;
			cin >> smjer;
		} while (smjer!=1 && smjer!=2) ;

	if(smjer==1) {
		auto rezultat = MaksimalniPodnizoviStepenaDvojke(elementi, Rastuci);
		IspisiMaksimalnePodnizove(rezultat, Rastuci);
	} else {
		auto rezultat = MaksimalniPodnizoviStepenaDvojke(elementi, Opadajuci);
		IspisiMaksimalnePodnizove(rezultat, Opadajuci);
	}
	return 0;
}