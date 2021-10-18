/*B 2017/2018, Zadaća 2, Zadatak 2

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
#include <deque>
#include<stdexcept>
#include<type_traits>
using namespace std;

enum class SmjerKretanja
{
    NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo
};

template<typename T>
auto PjecaniSat(T kont,SmjerKretanja smjer)-> typename remove_reference<decltype(kont[0][0][0])>::type {
	for(int i=0; i<kont.size(); i++) {
		if(kont[i].size()!=kont[0].size()) throw domain_error("Plohe nemaju isti broj redova");
	}
	if(kont.size()<0 || kont.size()%2==0) {
		throw length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	}
	typedef typename remove_reference<decltype(kont[0][0])>::type drugad;
	return 0;
}

int main ()
{
	int n;
	cout<<"Unesite dimenziju (x/y/z): ";
	cin>>n;
	while(n<0) {
		cout<<"Dimenzija nije ispravna, unesite opet: ";
		cin>>n;
	}
	vector<deque<deque<int>>>Kont(n,deque<deque<int>>(n,deque<int>(n)));
	cout<<"Unesite elemente kontejnera: ";
	for(int i=0; i<Kont.size(); i++) {
		for(int j=0; j<Kont[i].size(); j++) {
			for(int k=0; k<Kont[i][j].size(); k++) {
				cin>>Kont[i][j][k];
			}
		}
	}
	int kretanje;
	cout<<"Unesite smjer kretanja [0 - 5]: ";
	cin>>kretanje;
	while(kretanje<0 || kretanje>5) {
		cout<<"Smjer nije ispravan, unesite opet: "<<endl;
		cin>>kretanje;
	}
	try {
		auto sat=PjecaniSat(Kont,SmjerKretanja(kretanje));
		cout<<"\nPjecani sat unesene matrice je: ";
	} catch(domain_error x) {
		cout<<endl<<"Izuzetak: "<<x.what();
	} catch(length_error l) {
		cout<<endl<<"Izuzetak: "<<l.what();
	}
	return 0;
}