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


/*POKUŠAJ*/
int Obrni (int n)
{
	int obrnut=0,temp;
	while (n!=0)
	{
		temp=n%10;
		obrnut=obrnut*10+temp;
		n/=10;
	}
	return obrnut;
}

bool DaLiJeSimetrican (int n)
{
	int obrnut(Obrni(n));
	int cifra_od_n, cifra_od_obrnutog;
	while (n!=0)
	{
		cifra_od_n=n%10;
		cifra_od_obrnutog=obrnut%10;
		
		if (cifra_od_obrnutog!=cifra_od_n) return false;
		
		
		obrnut/=10;
		n/=10;
	}
	return true;
}
/***********/

bool DaLiJeProst (int n) {
	
	int korijen(int(std::sqrt(n)));
	
	for(int i(2); i<=korijen; i++){
		if(n%i==0)
		return 0;
	}
	if(n<2)
	return 0;
	
	return 1;
}

int PretvoriUTernarne (int broj) {
	int pomocna(broj);
	int pomoc_broj(0);
	int x;
	int i(0);
	
	while(pomocna!=0) {
		x=pomocna%3;
		pomoc_broj=pow(10,i)*x+pomoc_broj;
		pomocna=pomocna/3;
		i++;
	}
	return pomoc_broj;
}



std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool a) {
	std::vector<int> ternarni;
	
	if(v.size()==0)
		return ternarni;
	
		for(int i(0); i<v.size(); i++){
			if(a){
				if(DaLiJeProst(std::abs(v.at(i))))
				ternarni.push_back(v.at(i));
			}
			else {
				if(!DaLiJeProst(std::abs(v.at(i))))
				ternarni.push_back(v.at(i));
			}
		}
		
		std::vector<int> vrati_iz_funkcije;
		
			for(int i(0); i<ternarni.size(); i++){
			if(DaLiJeSimetrican(PretvoriUTernarne(ternarni.at(i))))
			vrati_iz_funkcije.push_back(ternarni.at(i));
		}
		
		for(int i(0);i<vrati_iz_funkcije.size();i++){
			for(int j(i+1);j<vrati_iz_funkcije.size();j++){
				if(vrati_iz_funkcije.at(i)==vrati_iz_funkcije.at(j)){
					vrati_iz_funkcije.erase(vrati_iz_funkcije.begin()+j);
					j--;
				}
			}
		}
		
	return vrati_iz_funkcije;
}

int main ()
{
	std::vector<int> v;
	cout<< "Unesite elemente vektora (-1 za kraj): ";
	int broj(0);
	do{
		cin >> broj;
		if(broj==-1) break;
		v.push_back(broj);
	} while(broj!=-1);
	int x;
	cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do
	{
		cin >> x;
		if(x!=1 && x!=0)
			cout<<"Neispravan unos! Unesite ponovo: ";
	}
	while(x!=1 && x!=0);
	
	std::vector<int> ISPIS = IzdvojiSimetricneTernarne(v, x);
	
	if(x==1){
		if(ISPIS.size()==0)
		cout << "Nema prostih simetricnih brojeva u vektoru.";
		else
		{
			cout << "Prosti simetricni brojevi iz vektora su: ";
			for(int i(0);i<ISPIS.size();i++) {
				cout << ISPIS.at(i);
				if(i==ISPIS.size()-1)
					cout << ".";
				else
					cout <<", ";
			}
		}
	}
	else
	{
		if(ISPIS.size()==0)
		cout << "Nema slozenih simetricnih brojeva u vektoru.";
		else
		{
			cout << "Slozeni simetricni brojevi iz vektora su: ";
			for(int i(0);i<ISPIS.size();i++){
				cout << ISPIS.at(i);
				if(i==ISPIS.size()-1)
					cout << ".";
				else
					cout << ", ";
			}
		}
	}
	
	return 0;
}