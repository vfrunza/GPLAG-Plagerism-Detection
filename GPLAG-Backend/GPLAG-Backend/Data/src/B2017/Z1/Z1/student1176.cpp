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

bool DaLiJeSimetrican(int broj)
{
	int broj1(0), broj2(0);
	
	if(broj < 0)
	{
		broj = std::abs(broj);
		//predznak = predznak * (-1);
	}
	
	broj1 = broj;
	
	while(broj > 0)
	{
		broj2 = broj2*10 + (broj%10);
		broj = broj / 10;
	}
	
	if(broj1 == broj2) return true;
	else return false;
}

std::vector<int> IzbaciDuple(std::vector<int> v)
{
	for(int i=0; i<v.size()-1; i++)
	{
		for(int j=i+1; j<v.size(); j++)
		{
			if(v.at(i) == v.at(j))
			{
				v.erase(v.begin() + j);
				j--;
			}
		}
	}
	return v;
	
}

bool DaLiJeProst(int n)
{
	if(n<1) return false;
	if(n==1) return false;
	
	for(int i=2; i<n; i++)
	{
		if(n%i == 0) return false;
	}
	return true;
}

std::vector<int> PretvoriUTernarni(std::vector<int> v)
{
	std::vector<int> v1;
	
	for(int i=0; i<v.size(); i++)
	{
		int broj(v.at(i));
		int pomocni(0), pomocni1(0), predznak(1);
		
		if(broj < 0)
		{
			broj = std::abs(broj);
			predznak = predznak * (-1);
		}
		
		while(broj > 0)
		{
			pomocni = pomocni*10 + (broj%3);
		//	std::cout << pomocni << std::endl;
			broj = broj / 3;
		//	std::cout << broj << std::endl;
		}
		
		while(pomocni > 0)
		{
			pomocni1 = pomocni1*10 + (pomocni%10);
			pomocni = pomocni / 10;
		}
		
		pomocni1 = pomocni1 * predznak;
		
		v1.push_back(pomocni1);
	}
	return v1;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, int t)
{
	std::vector<int>v1, v2, v3, v4;
	v1 = IzbaciDuple(v);
	
	
	// ako je t=1 onda tazim proste brojeve
	if(t==1)
	{
		for(int i=0; i<v1.size(); i++)
		{
			int a(v1.at(i));
		
			a  = DaLiJeProst(a);
		
			if(a == true) v2.push_back(v.at(i));
		}
	}
	if(t == 0)
	{
		for(int i=0; i<v1.size(); i++)
		{
			int a(v1.at(i));
		
			a  = DaLiJeProst(a);
		
			if(a == false) v2.push_back(v.at(i));
		}
	}
	
	v3 = PretvoriUTernarni(v2);
	
	for(int i=0; i<v3.size(); i++)
	{
		int a(v3.at(i));
		
		a = DaLiJeSimetrican(a);
		
		if(a == true) v4.push_back(v3.at(i));
	}
	
	return v4;
}

int PretvoriUObicni(int broj)
{
	int predznak(1), kont(0), obicni(0);

	if(broj < 0)
	{
		broj = std::abs(broj);
		predznak = predznak * (-1);
	}
	
	while(broj > 0)
	{
		obicni = obicni + broj%10 * std::pow(3, kont);
	//	std::cout << obicni
		kont++;
		broj = broj / 10;
	}
	
	obicni = obicni * predznak;
	return obicni;
}

int main ()
{
	
	
	std::vector<int> vektor, VEKTOR;
	int cifra, brzaslozenost, test, a;

	std::cout << "Unesite elemente vektora (-1 za kraj): "	;
	
	for(;;)
	{
		std::cin >> cifra;
		if(cifra == -1) break;
		vektor.push_back(cifra);
	}
	
	
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	
	for(;;)
	{
		std::cin >> brzaslozenost;
		if(brzaslozenost == 0 || brzaslozenost == 1) break;
		else
		{
			std::cout << "Neispravan unos! Unesite ponovo: ";
		}
	}
	
	
	VEKTOR = IzdvojiSimetricneTernarne(vektor, brzaslozenost);
	
	test = VEKTOR.size();
	
	if(test == 0 && brzaslozenost == 1) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	else if(test == 0 && brzaslozenost == 0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	else if(test != 0 && brzaslozenost == 1)
	{
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<VEKTOR.size()-1; i++)
		{
			a = PretvoriUObicni(VEKTOR.at(i));
			std::cout << a << ", ";
		}
		
		std::cout << PretvoriUObicni(VEKTOR.at(VEKTOR.size()-1)) << ".";
	}
	else if(test != 0 && brzaslozenost == 0)
	{
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<VEKTOR.size()-1; i++)
		{
			a = PretvoriUObicni(VEKTOR.at(i));
			std::cout << a << ", ";
		}
		
		std::cout << PretvoriUObicni(VEKTOR.at(VEKTOR.size()-1)) << ".";
	}
	
	
	
	//int a(2), b(-13);
	
	//std::cout << DaLiJeProst(a) << " " << DaLiJeProst(b);
	
//	int cifra;
//	std::vector<int> v;
	
	//std::cout << DaLiJeSimetrican(a) << " " << DaLiJeSimetrican(b);
	
/*	
	std::cout << "Unesite elemente vektora (-1 za kraj): "	;
	
	for(;;)
	{
		std::cin >> cifra;
		if(cifra == -1) break;
		v.push_back(cifra);
	}
	
	v = PretvoriUTernarni(v);
	
	for(int i=0; i<v.size(); i++)
	{
		std::cout << v.at(i) << " ";
	}
	
	*/
	
	return 0;
}