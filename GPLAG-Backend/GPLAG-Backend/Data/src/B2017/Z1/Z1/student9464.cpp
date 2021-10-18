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
#include <deque>
#include <cmath>
#include <limits>
int Prost (int x)
{
	if (x == 1 || x == -1) return 2;
	for (int i = 2; i <= std::abs(x / i); ++i)
		if (x % i == 0)
			return 0;
	return 1;
}

bool TernarnoSimetrican (int i)
{
	std::deque<int> a, b;
	do 
	{
		int cif = std::abs(i % 3);
		i /= 3;
		a.emplace_back (cif);
		b.emplace_front (cif);
	}
	while (i);
	return a == b;
	
}
std::vector<int> IzdvojiSimetricneTernarne (const std::vector<int> &v, bool prosti)
{
	std::vector<int> r;
	for (const auto &x : v) 
		if (TernarnoSimetrican (x) && int(prosti) == Prost(x))
			{
				bool ima = false;
				for (const auto &y: r)
					if (x == y)
						{
							ima = true;
							break;
						}
				if (!ima)
					r.emplace_back (x);
				
			}
	return r;
	
}

int main ()
{
 	

//AT16 (neaktivni): vektor koji sadrzi INT_MIN
//RATIONALE: posto funkcija treba da uzme u obzir i negativne brojeve
//           to znaci da se moze napraviti greska kod: n = abs (n).
//           Znamo da su predznacni brojevi vecinom asimetricni, tj.
//           smatra se 0 kao pozitivna. Pa imamo npr tipove sa opsegom
//           [-128, 127]. Ako je maksimalan pozitivan broj koji moze stati
//           u taj tip npr 127, onda NE SMIJEMO raditi n = abs (n) za n < 0
//           jer bismo dobili: n = abs (-128) sto bi bilo +128, ali to
//           NE MOZE stati u taj tip jer mu je maksimum 127. Isto je i sa int
//ISPRAVNO RJESNJE: uopste NE TREBA negirati broj, nego samo brojeve koji 
//          predstavljaju njegove cifre (koji mogu biti negativni).
//          Znamo da je c negativan u izrazu c = a % b kad je a < 0 ^ b > 0, npr:
//                 -16 % 3 = -1
//          pa je onda potrebno negirati (uzeti apsolutni vrijednost) SAMO
//          te jedne cifre, npr:
//          do 
//              {
//                 int cifra = std::abs (n % 3); //<---- OVDJE
//                 ...
//                 n /= 3;
//              }
//          while (n != 0);

    int mini = std::numeric_limits<int>::min();
    std::vector<int> v = {mini, mini, mini, mini, 0, 1, 2, 3, 4, 5, 6, -7, -8, mini};
    auto v1 = IzdvojiSimetricneTernarne(v, true), v2 = IzdvojiSimetricneTernarne(v, false);
    for (const auto &x : v1) 
        std::cout << x << " ";
    for (const auto &x : v2)
        std::cout << x << " ";
}