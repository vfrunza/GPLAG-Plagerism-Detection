/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: student9129@etf.unsa.ba.	
*/

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cmath>

bool Prost (int n)
{
	for (int i{2}; i <= abs(sqrt(n)); i++)
		if (!(n%i))
			return false;
	return ((n < 2 && n > -2) ? false : true);
}

bool DaLiPostoji (std::vector<int> v, int x)
{
    for (int i : v)
        if (i == x)
            return true;
    return false;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool a) 
{   
    std::vector<int> rezultat;
    std::deque<int> naprijed, nazad;
    for(int x : v) 
    {   
        int broj{x}, ostatak{0};
        naprijed.resize(0), nazad.resize(0);
        while(broj) 
        {                              
            ostatak = abs(broj % 3);
            nazad.push_back(ostatak), naprijed.push_front(ostatak);
            broj /= 3;
        }
        if (nazad == naprijed && Prost(x) == a && !DaLiPostoji(rezultat, x) == rezultat.end() && x != 1 && x != -1)
        	rezultat.push_back(x);
    } 	
    return rezultat;
}

int main ()
{
    std::vector<int> ZadaniVektor;
    int broj, x;
    
    std::cout<< "Unesite elemente vektora (-1 za kraj): ";
    while(std::cin >> broj, broj != -1) 
        ZadaniVektor.push_back(broj);
    std::cout<< "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    while(std::cin >> x, (x < 0 || x > 1))
    	std::cout << "Neispravan unos! Unesite ponovo: ";
        
    std::vector<int> RezultujuciVektor = IzdvojiSimetricneTernarne(ZadaniVektor, x);
    if (RezultujuciVektor.empty())
    	std::cout << "Nema " << ((x) ? "prostih" : "slozenih") << " simetricnih brojeva u vektoru.";
    else 
    {
    	std::cout << ((x) ? "Prosti " : "Slozeni ") << "simetricni brojevi iz vektora su: ";
    	for (int i{0}; i < RezultujuciVektor.size(); i++)
    		std::cout << RezultujuciVektor.at(i) << ((RezultujuciVektor.size() != i + 1) ? ", " : ".");
    }
	return 0;
}

