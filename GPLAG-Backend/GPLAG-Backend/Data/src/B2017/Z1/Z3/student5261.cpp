/*B 2017/2018, Zadaća 1, Zadatak 3
	
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

enum Smjer {Opadajuci = 2, Rastuci = 1};

bool Stependvice(int n)
{
	bool stepen(false);
	if(n < 1) return stepen;
	int mnozac = 1;
	while(mnozac <= n)
	{
		if(mnozac == n) stepen = true;
		mnozac = mnozac * 2;
	}
	return stepen;
}

std::deque<std::vector<int>> RastuciKojiSuStepenDvice(std::vector<int> v)
{
	std::deque<std::vector<int>> raste;
	if(v.size() == 0 || v.size() == 1)
		return raste;
	for(int i=0; i<v.size()-1; i++)													
	{
		std::vector<int> pomocni;
		while(v.at(i+1) > v.at(i) && Stependvice(v.at(i)) && i<v.size()-1)
		{
			pomocni.push_back(v.at(i));
			i++;
			if(i == v.size()-1) break;
		}
		if(i>0 && v.at(i-1) < v.at(i) && Stependvice(v.at(i)))
			pomocni.push_back(v.at(i));
		if(pomocni.size() > 1)
			raste.push_back(pomocni);
	}
	return raste;
}

std::deque<std::vector<int>> OpadajuciKojiSuStepenDvice(std::vector<int> v)
{
	std::deque<std::vector<int>> opada;
	if(v.size() == 0) return opada;
	for(int i=1; i<v.size(); i++)
	{
		std::vector<int> pomocni;
		while(i < v.size()-1 && v.at(i+1) < v.at(i) && Stependvice(v.at(i)))
		{
			pomocni.push_back(v.at(i));
			i++;
			if(i == v.size()-1) break;
		}
		if(i>0 && v.at(i) < v.at(i-1) && Stependvice(v.at(i)))
			pomocni.push_back(v.at(i));
		if(pomocni.size() > 1)
			opada.push_back(pomocni);
	}
	return opada;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer smjer)
{
	std::deque<std::vector<int>> raste_ili_opada;
	if(smjer == 1)
	{
		raste_ili_opada = RastuciKojiSuStepenDvice(v);
	}
	else
	{
		raste_ili_opada = OpadajuciKojiSuStepenDvice(v); 
	}
	return raste_ili_opada;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<int> v;
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++)
	{	
		int k; 
		std::cin >> k;
		v.push_back(k);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int s;
	std::cin >> s;
	Smjer smjer;
	if(s == 1) smjer = Rastuci;
	if(s == 2) smjer = Opadajuci;
	std::deque<std::vector<int>> podnizovi;
	if(smjer == Rastuci)
	{
		podnizovi = MaksimalniPodnizoviStepenaDvojke(v, smjer);
		std::cout << "Maksimalni rastuci podnizovi: "<<std::endl;
		for(int i=0; i<podnizovi.size(); i++)
		{
			for(int j=0; j<podnizovi.at(i).size(); j++)
			{
				std::cout << podnizovi.at(i).at(j) << " ";
			}
			std::cout<<std::endl;
		}
	}
	if(smjer == Opadajuci)
	{
		podnizovi = MaksimalniPodnizoviStepenaDvojke(v, smjer);
		std::cout << "Maksimalni opadajuci podnizovi: "<<std::endl;
		for(int i=0; i<podnizovi.size(); i++)
		{
			for(int j=0; j<podnizovi.at(i).size(); j++)
			{
				std::cout << podnizovi.at(i).at(j) << " ";
			}
			std::cout<<std::endl;
		}
	}
	return 0;
}
/*
int main()
{
std::vector<int> brojevi {0, 1, 2, 3, -4, -5, -6, -7, -8, -9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::deque<std::vector<int>> rastuci {MaksimalniPodnizoviStepenaDvojke(brojevi, Smjer(Rastuci))}, 
                                    opadajuci {MaksimalniPodnizoviStepenaDvojke(brojevi, Smjer(Opadajuci))};

	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
    for (const auto& niz : rastuci)
    {
        for (const int& broj : niz)
            std::cout << broj << " ";
        std::cout << std::endl;
    }

	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
    for (const auto& niz : opadajuci)
    {
        for (const int& broj : niz)
            std::cout << broj << " ";
        std::cout << std::endl;
    }
return 0;
}*/