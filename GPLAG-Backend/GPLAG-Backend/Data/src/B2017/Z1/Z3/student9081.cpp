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

enum Smjer {Rastuci,Opadajuci};

bool DaLiJeStepenDvojke (int x)
{
	//Funkcija 2^x nije definirana za cijele brojeve manje od 1
	if (x<1)
		return false;
	while (x!=1)
	{
		if (x%2!=0)
		return false;
		x/=2;
	}
	return true;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer x)
{
	std::deque<std::vector<int>> vrati;
	if (x==Rastuci)
	{
		int broj_redova(0);
		for (int i=1;i<v.size();)
		{
			//Pronalazimo najmanje jedan par da zadovoljava uslove
			if (v.at(i-1)<=v.at(i) && DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i-1)))
			{
				vrati.resize(broj_redova+1);
				vrati.at(broj_redova).push_back(v.at(i-1));
				while (i<v.size() && v.at(i-1)<=v.at(i) && DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i-1)))
				{
					//Sve dok je uslov zadovoljen ubacujemo elemente u prvi vektor deka
					vrati.at(broj_redova).push_back(v.at(i));
					i++;
				}
				broj_redova++;
			}
			else
				i++;
			//Ako nismo pronasli par ispitujemo sljedeci par elemenata	
		}
	}
	else if (x==Opadajuci)
	{
		//else naredba radi na isti nacin kao i u if bloku
		//ispituju se ovaj put opadajuci elementi u vektoru
		int broj_redova(0);
		for (int i=1;i<v.size();)
		{
			if (v.at(i-1)>=v.at(i) && DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i-1)))
			{
				vrati.resize(broj_redova+1);
				vrati.at(broj_redova).push_back(v.at(i-1));
				while (i<v.size() && v.at(i-1)>=v.at(i) && DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i-1)))
				{
					vrati.at(broj_redova).push_back(v.at(i));
					i++;
				}
				broj_redova++;
			}
			else
			i++;
		}
	}
	return vrati;
}


int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora: ";
	for (int i=0;i<n;i++)
	{
		int unos;
		std::cin>>unos;
		v.push_back(unos);
	}
	int smjer;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>smjer;
	std::deque<std::vector<int>> ve ;
	if (smjer==1)
		{
		std::cout<<"Maksimalni rastuci podnizovi: ";
		ve=MaksimalniPodnizoviStepenaDvojke(v,Rastuci);
		}
	else 
		{std::cout<<"Maksimalni opadajuci podnizovi: ";
		ve=MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
		}
	std::cout<<"\n";
	for (std::vector<int> x : ve)
	{
		for (int y: x)
		std::cout<<y<<" ";
		std::cout<<"\n";
	}
	
	return 0;
}