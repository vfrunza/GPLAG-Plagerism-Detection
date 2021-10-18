/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
std::vector<int> IzdvojiGadne (std::vector<int> v, bool opaki)
    {
        std::vector<int> r;
        for (const auto &x : v)
            {
                int brojevi[] = {0, 0, 0}, br = x, cif = br % 3, ukupno = 0, duplikat = 0;
                do 
                	brojevi[cif < 0 ? -cif : cif]++, br /= 3;
                while (cif = br % 3, br);
                for (int i = 0; i < 3; ++i) ukupno += brojevi[i] % 2 != opaki || !brojevi[i];
                if (ukupno != 3) continue;
                for (const auto &y : r) if (y == x) duplikat++;
                if (!duplikat) r.push_back (x);
            }
        return r;
    }
   #include <limits>
int main()
{
	    std::vector<int> v;
    int broj;
    std::cout << "Unesite brojeve (0 za prekid unosa): ";
    do {
        
            std::cin >> broj;
            if (broj) 
                v.push_back(broj);
    } while (broj);
    
    std::cout << "Opaki: ";
    for (const auto &a : IzdvojiGadne({v}, true))
        std::cout << a << " ";
    
    std::cout << std::endl << "Odvratni: ";
    for (const auto &a : IzdvojiGadne({v}, false))
        std::cout << a << " ";
}
int ATmain()
{
{//AT13 (skriveni): vektor koji sadrzi INT_MIN
 //RATUONALE: posto funkcija treba da uzme u obzir i negativne brojeve
 //			  to znaci da se moze napraviti greska kod: n = abs (n).
 //			  Znamo da su predznacni brojevi vecinom asimetricni, tj.
 //			  smatra se 0 kao pozitivna. Pa imamo npr tipove sa opsegom
 //			  [-128, 127]. Ako je maksimalan pozitivan broj koji moze stati
 // 		  u taj tip npr 127, onda NE SMIJEMO raditi n = abs (n) za n < 0
 //           jer bismo dobili: n = abs (-128) sto bi bilo +128, ali to
 //           NE MOZE stati u taj tip jer mu je maksimum 127. Isto je i sa int
 
 //ISPRAVNO RJESNJE: uopste NE TREBA negirati broj, nego samo brojeve koji 
 //			 predstavljaju njegove njegove cifre (koji mogu biti negativni).
 //          Znamo da je c negativan u izrazu c = a % b kad je a < 0 ^ b > 0, npr:
 //			 -16 % 3 = -1
 //          pa je onda potrebno negirati (uzeti apsolutni vrijednost) SAMO
 //          te jedne cifre, npr:
 //          
 //          do 
 //				{
 //					int cifra = std::abs (n % 3); //<---- OVDJE
 //					...
 //					n /= 3;
 //				}
 //			while (n != 0);
 
 int mini = std::numeric_limits<int>::min();
 std::vector<int> v = {mini, mini, mini, mini, 0, 1, 2, 3, 4, 5, 6, -7, -8, mini};
 auto v1 = IzdvojiGadne(v, true);
 auto v2 = IzdvojiGadne(v, false);
 std::cout << "Opaki: ";
 for (const auto &x : v1) 
 	std::cout << x << " ";
 std::cout << std::endl << "Odvratni: ";
 for (const auto &x : v2)
 	std::cout << x << " ";
 //Opaki: 4 -8 
 //Odvratni: 0 1 2 3 5 6 -7
}
	return 13;
{//AT12 (skriveni): vektori sa po jednim elementom
	std::cout << IzdvojiGadne({8}, true).at(0) << " " 
			  << IzdvojiGadne({-4}, true).at(0) << std::endl
			  << IzdvojiGadne({5}, false).at(0) << " "
			  << IzdvojiGadne({-7}, false).at(0);
	//8 -4
	//5 -7
}
	return 12;
{//AT11 (skriveni): prazan vektor nema niti opakih niti odvratnih
	std::cout << IzdvojiGadne({}, true).size() << " ";
	std::cout << IzdvojiGadne({}, false).size();
}
//0 0
	return 11;
{//AT10 (skriveni): nula je odvratan broj, isto i svi jednocifreni {-2, -1, 1, 2}.

std::vector<int> v = {0, 0, 0, 1, 5, -2, -3, -1, 0, 1, 3, 68, 2, 15, 61, -56};
auto opaki = IzdvojiGadne(v, true), odvratni = IzdvojiGadne(v, false);
std::cout << "Opaki: ";
for (const auto &x : opaki) std::cout << x << " ";
std::cout << std::endl << "Odvratni: ";
for (const auto &x : odvratni) std::cout << x << " ";
//Opaki: 68 -56 
//Odvratni: 0 1 5 -2 -3 -1 3 2 15 
}
	return 10;
{
//AT9 (skriveni): testiramo brojeve vece od 52487 (2122222222 ternarno)
//jer 2122222222 je najveci broj koji moze stati u int. Ispravno rjesenje
//bi konvertovalo cifre u vektor ili cak i ne vrsilo konverziju dec -> ter
//jer to nije ni potrebno, potrebno je samo brojati cifre.

//ovaj autotest ce testirati dodatno i jos vece brojeve koji ne mogu stati
//u long long int

std::vector<int> v = {
	136, 52487, 52489, 121212, 472396, 101012, 10000, 608, 2613, -608, 333,
	-1549681956, 333, 13837153, -2146422391, -15, 1549681956, 1000, -15,
	std::numeric_limits<int>::max(), -std::numeric_limits<int>::max(), 17
};
auto opaki = IzdvojiGadne(v, true), odvratni = IzdvojiGadne(v, false);
std::cout << "Opaki: ";
for (const auto &x : opaki) std::cout << x << " ";
std::cout << std::endl << "Odvratni: ";
for (const auto &x : odvratni) std::cout << x << " ";
//Opaki: 472396 608 -608 -1549681956 1549681956 
//Odvratni: 52487 333 13837153 -15 
}
	return 9;
{
//AT8 (c9): mijesano sve (negativni + opaki + odvratni + niti jedni)
//OSTALI (javni) autotestovi su na Zamgeru! Posaljite zadacu, sacekajte
//da se pokrenu autotestovi (ujutro oko 5-6h) pa provjerite rezultat (kroz zamger).
//Ako autotest pada onda SAMI testirajte program tako sto cete kopirati kod
//autotesta u svoj main (mozete svoj main preimenovati u main1, a kreirati
//novi main pa u njega staviti kod autotesta) i onda popravljajte program!

std::vector<int> v = {
	136, 123, 12, 1212, 10102, 10012, 1000, 608, 2613, -608, 333,
	333, 333, 333, 333, 333, 1000, -15, 60, 61, 15, 151, 16, 715, 7222,
};
auto opaki = IzdvojiGadne(v, true), odvratni = IzdvojiGadne(v, false);
std::cout << "Opaki: ";
for (const auto &x : opaki) std::cout << x << " ";
std::cout << std::endl << "Odvratni: ";
for (const auto &x : odvratni) std::cout << x << " ";
//Opaki: 608 -608 60 
//Odvratni: 123 333 -15 15 715
}
	
	return 8;
//AT7 (zamger): cijeli vektor su opaki, trazimo odvratne
std::cout << "Odvratnih: " << IzdvojiGadne({2460, 608, 426, 6560, 364}, false).size();
//Odvratnih: 0
	return 7;
//AT6 (zamger): cijeli vektor su odvratni, trazimo opake
std::cout << "Opakih: " << IzdvojiGadne({121, 15451, 15, 179, 777}, true).size();
//Opakih: 0
	return 6;
//AT5 (zamger): cijeli vektor su odvratni
for (const auto &a : IzdvojiGadne({121, 15451, 15, 179, 777}, false))
std::cout << a << " ";
//121 15451 15 179 777
	return 5;
//AT4 (zamger): cijel vektor su opaki:
for (const auto &a : IzdvojiGadne({2460, 608, 426, 6560, 364}, true))
std::cout << a << " ";
//2460 608 426 6560 364 
    return 4;
//AT3 (c9): odvratni brojevi + negativni + duplikati
for (const auto &a : IzdvojiGadne({56, 656, 20, 61, 552, -6384, 223, 8979, 5904, 56, 656, 20, 61, 552, 6384, 223}, false))
std::cout << a << " ";
//223 8979     
	return 3;
//AT2 (c9): opaki brojevi + negativni + duplikati
for (const auto &a : IzdvojiGadne({56, 656, 20, 61, 552, -6384, 223, 8979, 5904,56, 656, 20, 61, 552, 6384, 223}, true))
	std::cout << a << " ";
//56 656 552 -6384 5904 6384     
	return 2;
    std::vector<int> v = {56, 656, 20, 61, 552, -6384, 223, 8979, 80812, 26937, 240801, 15, 3608, 5904, 0};
    auto opaki = IzdvojiGadne(v, true);
    auto omrznuti = IzdvojiGadne(v, false);
    std::cout << "Opaki: ";
    for (const auto &a : opaki)
        std::cout << a << " ";
    std::cout << std::endl << "Omrznuti: ";
    for (const auto &a : omrznuti)
        std::cout << a << " ";
}
