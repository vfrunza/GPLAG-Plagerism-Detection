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
using namespace std;

bool JeLiProst (int broj)
{
	int brojac = 0;
	for (int i = 1; i <= broj/2; i++)
		{
			if (broj % i == 0) brojac++; 
		}
	if (brojac > 1) return true;
	else return false;
}

vector<int> IzdvojiSimetricneTernarne (vector<int> v, bool znak)
{
	vector<int> noviT;
	vector<int> noviF;
	for (int i = 0; i < v.size(); i++)
		{
			if (JeLiProst(v.at(i))) noviT.push_back(v.at(i));
			else noviF.push_back(v.at(i));
		}
	if (!znak) return noviT;
	else return noviF;
}
int main ()
{
	vector<int> brojevi, novo;
	cout << "Unesite brojeve (0 za kraj): ";
	int broj;
	do {
		cin >> broj;
		if (broj != 0) brojevi.push_back(broj);
	}while (broj != 0);
	
	novo = IzdvojiSimetricneTernarne(brojevi, true);
	
	vector<int> neki;
	
	for (int i = 0; i < novo.size(); i++)
	{
		while (novo.at(i) != 0)
			
	}
	
	for (int i = 0; i < novo.size(); i++)
		cout << novo.at(i) << " ";
	
	return 0;
}