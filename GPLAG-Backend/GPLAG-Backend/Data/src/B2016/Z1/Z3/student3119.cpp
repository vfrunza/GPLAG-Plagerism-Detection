/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <iomanip>
#include <vector>

bool DaLiJeStepenDvojke (int n)
{
    return !(n == 0) && !(n & (n - 1));
}
std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> v)
{
    std::vector<std::vector<double>> podvek;
    std::vector<double> temp;

    int i{0};
    while (i+1 < v.size())
    {
        temp.resize(0);
        while (i+1 < v.size() && v.at(i) <= v.at(i+1) && DaLiJeStepenDvojke(v.at(i)))
            temp.push_back(v.at(i++));
        temp.push_back(v.at(i));

        if (temp.size() > 1)
            podvek.push_back(temp);
        i++;
    }
    return podvek;
}

std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> v)
{
    std::vector<std::vector<double>> podvek;
    std::vector<double> temp;

    int i{0};
    while (i+1 < v.size())
    {
        temp.resize(0);

        while (i+1 < v.size() && v.at(i) >= v.at(i+1) && DaLiJeStepenDvojke(v.at(i)))
            temp.push_back(v.at(i++));
        temp.push_back(v.at(i));

        if (temp.size() > 1)
            podvek.push_back(temp);
        i++;
    }
    return podvek;
}

int main ()
{
    
    int brojElmenata, broj;
    std::vector<double> brojevi;
    std::cout << "Unesite broj elemenata vektora: "; //Unos zavrsava kada se unese nesto sto nije realni broj
    std::cin >> brojElmenata;

	std::cout << "Unesite elemente vektora: ";
	while (brojElmenata--)
	{
        std::cin >> broj;
        brojevi.push_back(broj);
    }

    std::vector<std::vector<double>> podnizovi1{RastuciPodnizovi(brojevi)};
    std::vector<std::vector<double>> podnizovi2{OpadajuciPodnizovi(brojevi)};

	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
    for (auto niz : podnizovi1)
    {
        for (auto broj : niz)
            std::cout << broj << " ";
        std::cout << std::endl;
    }

	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
    for (auto niz : podnizovi2)
    {
        for (auto broj : niz)
            std::cout << broj << " ";
        std::cout << std::endl;
    }


    return 0;
}
