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
#include <stdexcept>
#include <vector>
#include <cmath>
#include <algorithm>
#include <type_traits>
using std::cin;
using std::cout;
typedef std::vector<int> Vektor;

/*template<typename PokTip1, typename PokTip2, typename PokTip3>
void SortirajPodrucjeVrijednosti(PokTip1 pokNaPocetak, PokTip1 pokNaKraj, PokTip2 pokNaPocDrugog, PokTip3 pokNaPocTreceg, typename std::iterator_traits<PokTip1>::value_type Funkcija1(typename std::iterator_traits<PokTip1>::value_type, typename std::iterator_traits<PokTip2>::value_type), bool Funkcija2(typename std::iterator_traits<PokTip1>::value_type, typename std::iterator_traits<PokTip2>::value_type)) {*/
template <typename PokTip1, typename PokTip2, typename PokTip3, typename FunkcijskiTip1, typename FunkcijskiTip2>
void SortirajPodrucjeVrijednosti(PokTip1 pokNaPocetak, PokTip1 pokNaKraj, PokTip2 pokNaPocDrugog, PokTip3 pokNaPocTreceg, FunkcijskiTip1 Funkcija1, FunkcijskiTip2 Funkcija2) {	
	std::sort(pokNaPocetak, pokNaKraj, Funkcija2);
	std::sort(pokNaPocDrugog, pokNaPocDrugog+(pokNaKraj-pokNaPocetak), Funkcija2);
	
	PokTip1 pomocniPok(pokNaPocetak);
	PokTip2 pomocniPok2(pokNaPocDrugog);
	int brojac(0);
	while (pomocniPok!=pokNaKraj) {
		PokTip3 pomocniPok3=std::find(pokNaPocTreceg, pokNaPocTreceg+(pokNaKraj-pokNaPocetak), Funkcija1(*pomocniPok, *pomocniPok2));
		if (pomocniPok3==pokNaPocTreceg+(pokNaKraj-pokNaPocetak)) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		else {
			int b(pomocniPok3-pokNaPocTreceg);
			if (b!=brojac) {
				auto temp (pokNaPocTreceg[b]);
				pokNaPocTreceg[b]=pokNaPocTreceg[brojac];
				pokNaPocTreceg[brojac]=temp;
			}
		}
		brojac++; pomocniPok++; pomocniPok2++;
	}
}
bool DaLiJeProst (int n) {
	if (n<=1) return false;
	for (int i=2;i<=std::sqrt(n);i++) {
		if (n%i==0)
			return false;
	}
	return true;
}
int BrojProstihFaktora(int n) {
	if (DaLiJeProst(n)) return 1;
	int brojac(0);
	for (int i=2;n>1;i++) {
		if ((n%i==0) && (DaLiJeProst(i))) {
			while (n%i==0) {
				n/=i;
				brojac++;
			}
		}
	}
	return brojac;
}
int Test(int x, int y) { return -2*x+y; }
bool Test2(int x, int y) {
	if (BrojProstihFaktora(x)>BrojProstihFaktora(y)) return true;
	if (BrojProstihFaktora(x)==BrojProstihFaktora(y)) {
		if (x>y) return true;
	}
	return false;
}

int main ()
{
	cout<<"Unesite broj elemenata: ";
	int n;
	cin>>n;
	Vektor v1, v2, v3;
	cout<<"Unesite elemente prvog vektora: ";
	for (int i=0;i<n;i++) {
		int m;
		cin>>m;
		if (std::find(v1.begin(), v1.end(), m)==v1.end()) v1.push_back(m);
		else i--;
	}
	cout<<"Unesite elemente drugog vektora: ";
	for (int i=0;i<n;i++) {
		int m;
		cin>>m;
		if (std::find(v2.begin(), v2.end(), m)==v2.end()) v2.push_back(m);
		else i--;
	}
	cout<<"Unesite elemente treceg vektora: ";
	for (int i=0;i<n;i++) {
		int m;
		cin>>m;
		if (std::find(v3.begin(), v3.end(), m)==v3.end()) v3.push_back(m);
		else i--;
	}
	cout<<std::endl;
	try {
		SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), Test, Test2);
	}
	catch (std::logic_error err) {
		cout<<"Izuzetak: "<<err.what();
		return 0;
	}
	
	cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<std::endl;
	for (int i=0;i<n;i++) {
		cout<<"f("<<v1[i]<<", "<<v2[i]<<") = "<<v3[i]<<std::endl;
	}
	return 0;
}