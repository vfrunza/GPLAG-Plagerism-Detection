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


bool DaLiJeProst (int broj)
{
	bool prost(true);
	
	if (broj < 2) prost = false;
	int x = std::sqrt(broj);
	
	for (int i = 2; i <= x; i++)
	{
		if (broj%i == 0) prost = false;
	}
	
	return prost;
}

bool DaLiJeSimetrican (int broj)
{
    bool simetrican(true);
    std::vector<int> v;
    
    int cifra;
    if (broj < 0) broj = broj*(-1);
    
    while (broj != 0)
    {
    	cifra = broj%3;
    	v.push_back(cifra);
    	broj = broj/3;
    }
    
    for (int i = 0, j = v.size()-1; i <= (v.size()/2), j >= (v.size()/2); i++, j--)
    {
    
    	if (v.at(i) != v.at(j))
        {
    		simetrican = false;
    		break;
    	}
    }
    
    return simetrican;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool x)
{
	std::vector<int> vrati_vektor;

	
	for (int i = 0; i < v.size(); i++)
	{
		if (DaLiJeProst(v.at(i)) && x == true)
		{
			if (DaLiJeSimetrican(v.at(i))) vrati_vektor.push_back(v.at(i));
		}
		
		if (!DaLiJeProst(v.at(i)) && x == false)
		{
			if (DaLiJeSimetrican(v.at(i))) vrati_vektor.push_back(v.at(i));
		}
	}
	
	return vrati_vektor;

}

int main ()
{
	int broj;
	std::vector<int> v;
	std::vector<int> vrati_v;
	
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin >> broj;
		if (broj != -1) v.push_back(broj);
	}
	while (broj != -1);
	
	int prosti_slozeni;
	
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
	    std::cin >> prosti_slozeni;
	    if (prosti_slozeni != 1 && prosti_slozeni != 0) std::cout << "Neispravan unos! Unesite ponovo: ";
	}
	
	while (prosti_slozeni != 1 && prosti_slozeni != 0);
	
	vrati_v = IzdvojiSimetricneTernarne(v,prosti_slozeni);
	
	if(prosti_slozeni) 
	{
		if (vrati_v.size() > 0)
		{
		    std::cout << "Prosti simetricni brojevi iz vektora su: ";
		    for (int i = 0; i < vrati_v.size(); i++)
		    {
		    	if (i == vrati_v.size()-1) std::cout << vrati_v.at(i) << ".";
		    	else std::cout << vrati_v.at(i) << ", ";
		    }
		}
		else std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	}
	
	if (!prosti_slozeni)
	{
		if (vrati_v.size() > 0)
		{
		    std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		    for (int i = 0; i < vrati_v.size(); i++)
		    {
		    	if (i == vrati_v.size() - 1) std::cout << vrati_v.at(i) << ".";
		    	else std::cout << vrati_v.at(i) << ", ";
		    }
		}
		
		else std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	}
	return 0;
}