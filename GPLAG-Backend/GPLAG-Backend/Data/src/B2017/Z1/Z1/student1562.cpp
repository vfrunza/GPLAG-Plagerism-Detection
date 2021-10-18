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

using namespace std;
long long int PretvoriDecimalniUTernarni(long long int broj)
{
	long long int ternarniBroj = 0;
	long long int privremena;
	long long int i=1;
	do {
		privremena = broj%3;
		broj/=3;
		ternarniBroj = ternarniBroj + (privremena*i);
		i=i*10;
	} while(broj!=0);

	return ternarniBroj;
}

bool ProvjeriJeLiProstiliSlozen(int p)
{
	if(p<0) p=p*(-1);
	if(p<1)
		return false;
	for(int i=2; i<=std::sqrt(p); i++) {
		if(p%i==0) return false;
	}
	return true;
}
bool ProstIliSlozen(int p, bool a)
{
	if(a==true)
		return ProvjeriJeLiProstiliSlozen(p);
	else
		return !ProvjeriJeLiProstiliSlozen(p);
}
bool ProvjeraDaLiJeSimetrican(long long int broj)
{
	if(broj==1) return false;
	long long int privremena;
	long long int n = 0;
	long long int p = broj;
	do {
		privremena = broj%10;
		n = (n*10) + privremena;
		broj = broj/10;
	} while(broj!=0);

	if(p==n)
		return true;
	else
		return false;
}

bool ProvjeraDaLiJeBrojJedinstven(vector<int> nizBrojeva, int broj)
{
	for(auto x : nizBrojeva) {
		if(broj == x) {
			return false;
		}
	}
	return true;
}

/*std::vector<int> IzdvojiProsteSimetricneTernarne(std::vector<int> nizBrojeva)
{
	std::vector<int>trazeniNiz;

	for(auto broj : nizBrojeva) {
		long long int brojuTernarnomObliku = PretvoriDecimalniUTernarni(broj);
		if(ProvjeriJeLiProstiliSlozen(broj) && ProvjeraDaLiJeSimetrican(brojuTernarnomObliku) && ProvjeraDaLiJeBrojJedinstven(trazeniNiz, broj)) {
			trazeniNiz.push_back(broj);
		}
	}
	if(trazeniNiz.size()==0)
		std::cout<<"Nema prostih simetricnih brojeva u vektoru";
	else
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	return trazeniNiz;
}*/

/*std::vector<int> IzdvojiSlozeneSimetricneTernarne(std::vector<int> nizBrojeva)
{
	std::vector<int>trazeniNiz;

	for(auto broj : nizBrojeva) {
		long long int brojuTernarnomObliku=PretvoriDecimalniUTernarni(broj);
		if(!ProvjeriJeLiProstiliSlozen(broj) && ProvjeraDaLiJeSimetrican(brojuTernarnomObliku) && ProvjeraDaLiJeBrojJedinstven(trazeniNiz, broj)) {
			trazeniNiz.push_back(broj);
		}
	}
	if(trazeniNiz.size()==0)
		std::cout << "Nema slozenih simetricnih brojeva u vektoru";
	else
		std::cout<<"Slozeni simetricni brojevi iz vektora su: " ;

	return trazeniNiz;
}
*/

vector<int> IzdvojiSimetricneTernarne(vector<int> nizBrojeva, bool pn)
{
	vector<int> trazeniNiz;
	for(auto broj : nizBrojeva) {
		if(broj==1 || broj==-1)
			continue;
		long long int brojuTernarnomObliku = PretvoriDecimalniUTernarni(broj);
		if(ProstIliSlozen(broj, pn) && ProvjeraDaLiJeSimetrican(brojuTernarnomObliku) && ProvjeraDaLiJeBrojJedinstven(trazeniNiz, broj)) {
			trazeniNiz.push_back(broj);
		}
	}
	return trazeniNiz;

}

void IspisiBrojeve(vector<int> nizBrojeva)
{
	for(int i=0; i<nizBrojeva.size(); i++) {
		cout<<nizBrojeva.at(i);
		if(i<nizBrojeva.size()-1)
			cout<<", ";
	}
	cout<<"."<<endl;
}
int main ()
{

	int prostslozen;
	string str;
	vector<int> nizBrojeva;
	bool tn = false;
	do {
		int broj;
		cout<< "Unesite elemente vektora (-1 za kraj): ";

		for(;;) {
			cin >> broj;
			if(broj==-1) break;
			nizBrojeva.push_back(broj);
		}

		cout<< "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
		cin>>prostslozen;

		while(true) {
			if(prostslozen == 1) {
				tn = true;
				break;
			} else if(prostslozen == 0) {
				tn = false;
				break;
			} else {
				cout<<"Neispravan unos! Unesite ponovo: ";
				cin>>prostslozen;
			}
		}
		getline(cin, str);

	} while(str.size()>0);

	vector<int> trazeniNiz = IzdvojiSimetricneTernarne(nizBrojeva, tn);
	if(trazeniNiz.size()==0 && tn == true)
		cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else if(trazeniNiz.size()==0 && tn == false)
		cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else if(tn == true) {
		cout<<"Prosti simetricni brojevi iz vektora su: " ;
		IspisiBrojeve(trazeniNiz);
	} else if(tn == false) {
		cout<<"Slozeni simetricni brojevi iz vektora su: ";
		IspisiBrojeve(trazeniNiz);
	}
	return 0;
}