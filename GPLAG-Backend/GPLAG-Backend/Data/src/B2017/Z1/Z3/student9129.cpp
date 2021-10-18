/*B 2017/2018, ===TITLE===
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: student9129@etf.unsa.ba.	
*/

#include <iostream>
#include <iomanip>
#include <vector>

enum Smjer {Rastuci = 1, Opadajuci = 2};
bool DaLiJeStepenDvojke (int n)
{
    return (!(n == 0) && !(n & (n - 1)));
}

std::vector<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer s)
{
    std::vector<std::vector<int>> podvek;
	for (int i{0}; (i+1 < v.size()); i++)
    {
        std::vector<int> temp;
        if (s == 1)
        	while (i+1 < v.size() && v.at(i) <= v.at(i+1) && DaLiJeStepenDvojke(v.at(i)))
            	temp.push_back(v.at(i++));
        else
        	while (i+1 < v.size() && v.at(i) >= v.at(i+1) && DaLiJeStepenDvojke(v.at(i)))
            	temp.push_back(v.at(i++));
        	
        if (DaLiJeStepenDvojke(v.at(i)))
        	temp.push_back(v.at(i));		
        if (temp.size() > 1)
            podvek.push_back(temp);
    }
    return podvek;
}

int _main ()
{
    int brojElmenata, broj;
    std::vector<int> brojevi;
    
    std::cout << "Unesite broj elemenata vektora: ";
    std::cin >> brojElmenata;
	std::cout << "Unesite elemente vektora: ";
	while (brojElmenata--)
	{
        std::cin >> broj;
        brojevi.push_back(broj);
	}
	
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> broj;
    std::vector<std::vector<int>> podnizovi{MaksimalniPodnizoviStepenaDvojke(brojevi, Smjer(broj))};
    
	std::cout << "Maksimalni " << ((broj == 1) ? "rastuci" : "opadajuci") <<" podnizovi: " << std::endl;
    for (std::vector<int> niz : podnizovi)
    {
        for (int broj : niz)
            std::cout << broj << " ";
        std::cout << std::endl;
    }
    return 0;
}
