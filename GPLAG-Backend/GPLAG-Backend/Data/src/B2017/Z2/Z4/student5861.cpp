/*B 2017/2018, Zadaća 2, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <math>

typedef std::vector<int> intv;

template <typename NekiTip>
void SortirajPodrucjeVrijednosti(NekiTip *pocetak, NekiTip *izakraja, NekiTip *pocetakdrugog, bool Kriterij(NekiTip, NekiTip))
{
	int i=0;
	while(pocetak+i+1 != izakraja) {
		//Logika sortiranja po izboru koja poredi elemente
		if(Kriterij(*(pocetak+i), *(pocetak+i+1))) {
			NekiTip pomocna;
			pomocna = *(pocetak+i);
			*(pocetak+i) = *(pocetak+i+1);
			*(pocetak+i+1) = pomocna;
		}
		//if (Kriterij(*pocetakdrugog...)
		i++;
	}
}

bool DaLiJeProst(int a)
{
	if(a<0) a=a*(-1);
	if(a<1) return false;
	for(int i=2; i<=std::sqrt(a); i++) {
		if(a%i==0) return false;
	}
}

bool ProstIliSlozen(int p, bool a)
{
	if(a==true)
		return DaLiJeProst(p);
	else
		return !DaLiJeProst(p);
}
int BrojProstihFaktora (int a)
{
	//logika za nalazanje prostih faktora
	int brojfaktora(0);
	int prostifaktor(2);
	//uslov da se prolazi kroz proste faktore
	if(a%prostifaktor == 0)
		brojfaktora++;
	a=a/prostifaktor;
}
//funkcija kriterija
bool Kriterij (int a, int b)
{
	if (BrojProstihFaktora(a) > BrojProstihFaktora(b))
		return true;
	else if (BrojProstihFaktora(a) == BrojProstihFaktora(b))
		return a>b;
	return false;
}
template <typename NekiTip, typename NekiTip2>
void SortirajTreciNiz(NekiTip *pocetakprvog, NekiTip *izakraja, NekiTip *pocetakdrugog, NekiTip2 *pocetaktreceg, NekiTip2 Funkcija(NekiTip, NekiTip))
{
	int i=0;
	while(pocetakprvog+i+1 != izakraja) {
		NekiTip2 rezultat = Funkcija(pocetakprvog+i,pocetakdrugog+i);
		//Dio koda koji provjeri da li postoji rezultat unutar treceg niza

	}
}

std::vector<int> UnesiBrojeve(){
	int n;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	
	std::vector<int> brojevi(n);
	
	int broj;
	int el(0);
	intv vektor1(el);
	std::cout<<"Unesite elemente prvog vektora: ";
	for(int i=0; i<n; i++){
		std::cin>>broj;
		brojevi.push_back(broj);
		vektor1.at(i) = n;
	}
	intv vektor2(el);
	std::cout<<"Unesite elemente drugog vektora: ";
	for(int i=0; i<n; i++){
		std::cin>>broj;
		brojevi.push_back(broj);
		vektor2.at(i) = n;
	}
	intv vektor3(el);
	std::cout<<"Unesite elemente treceg vektora: ";
	for(int i=0; i<n; i++){
		std::cin>>broj;
		brojevi.push_back(broj);
		vektor3.at(i) = n;
	}
	return brojevi;
}


int main ()
{
	std::vector<int> nizBrojeva = UnesiBrojeve();
	
	return 0;
}