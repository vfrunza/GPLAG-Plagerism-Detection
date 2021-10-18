/*B 2017/2018, Zadaća 2, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <stdexcept>

enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje,
    DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename ktip>
auto PjescaniSat( ktip kont, SmjerKretanja kuda ) -> decltype(kont)
{
	
	ktip result=kont;
	if(kont.size()==0)
	{
		result.resize(0);
		return result;
	}
	
	size_t vel=kont.size();
	for(int i=0;i<kont.size();i++)
	{
		if(vel!= kont.at(i).size())throw std::domain_error("3D matrica nema oblik kocke");
		for(int j=0;j<kont.at(i).size();j++)
		{
			if(vel!=kont.at(i).at(j).size())throw std::domain_error("3D matrica nema oblik kocke");
			result.at(i).at(j).resize(0);
		}
	}
	
	if(vel%2==0)throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	for(int i=0; i<kont.size(); i++)
	{
			for(int j=0; j<kont.at(i).size(); j++)
			{
				result.at(i).at(j).resize(0);
				int vektori{i},vektorj{j},vektork{0};
			
				if(kuda == SmjerKretanja::NaprijedNazad)
				{
					vektori=j;
					vektorj=i;
				}
				if(kuda == SmjerKretanja::NazadNaprijed)
				{
					vektori=kont.size()-j-1;
					vektorj=i;
				}
				if(kuda == SmjerKretanja::GoreDolje)
				{
					vektori=i;
					vektorj=j;
				}
				if(kuda == SmjerKretanja::DoljeGore)
				{
					vektori=i;
					vektorj=kont.size()-1-j;
				}
				if(kuda == SmjerKretanja::LijevoDesno)
				{
					vektori=i;
					vektork=j;
				}
				if(kuda == SmjerKretanja::DesnoLijevo)
				{
					vektori=i;
					vektork=kont.size()-1-j;
				}
				for(int k=0+j; k<kont.at(i).at(j).size()-j; k++)
				{
					if(kuda == SmjerKretanja::LijevoDesno)
						vektorj=k;
					else if(kuda == SmjerKretanja::DesnoLijevo)
						vektorj=k;
					else vektork=k;
					result.at(i).at(j).push_back(kont.at(vektori).at(vektorj).at(vektork));
				}
				if(j>=kont.at(i).at(j).size()/2)result.at(i).at(j).resize(0);
				for(int k=kont.at(i).at(j).size()-j-1; k>=0 && k<j+1; k++)
				{
					if(kuda == SmjerKretanja::LijevoDesno) vektorj=k;
					else if (kuda == SmjerKretanja::DesnoLijevo) vektorj=k;
					else vektork=k;
					result.at(i).at(j).push_back(kont.at(vektori).at(vektorj).at(vektork));
				}

			}
	}
	return result;
}

template <typename ktip>
void ispisi(ktip kont)
{
	std::cout<<"\nPjescani sat unesene matrice je:\n";
	for(int i=0; i<kont.size(); i++)
	{
		for(int j=0; j<kont.at(i).size(); j++)
		{
			for(int a=0; a<(kont.size()-kont.at(i).at(j).size())/2; a++)
			{
				std::cout<<"    ";
			}
			for(int k=0; k<kont.at(i).at(j).size(); k++)
			{
			
				std::cout<<std::setw(4)<<std::right<<kont.at(i).at(j).at(k);
			}
			std::cout<<"\n";
		}
		std::cout<<std::endl;
	}
}

int main ()
{

	std::cout<<"Unesite dimenziju (x/y/z): ";
	int n;
	for(;;)
	{
		std::cin>>n;
		if(n>=0)break;
		std::cout<<"Dimenzija nije ispravna, unesite opet: ";
	}
	std::cout<<"Unesite elemente kontejnera: ";
	std::vector<std::deque<std::deque<int>>> kanta;
	std::deque<std::deque<int>> manjakanta;

	std::deque<int>kantica;
	int temp;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<n; k++)
			{
				std::cin>>temp;
				kantica.push_back(temp);
			}
			manjakanta.push_back(kantica);
			kantica.resize(0);
		}
		kanta.push_back(manjakanta);
		manjakanta.resize(0);
	}
	std::cout<<"Unesite smjer kretanja [0 - 5]:";
	SmjerKretanja kuda;
	int smjer;
	for(;;)
	{
		std::cin>>smjer;
		if(smjer>=0 && smjer<=5)break;
		std::cout<<" Smjer nije ispravan, unesite opet: ";
	}
	kuda=SmjerKretanja(smjer);
	try
	{
		auto result=PjescaniSat(kanta,kuda);
		ispisi(result);
	}
	catch(std::length_error izuzetak)
	{
		std::cout<<"\nIzuzetak: "<<izuzetak.what();
	}
	catch(std::domain_error izuzetak)
	{
		std::cout<<"\nIzuzetak: "<<izuzetak.what();
	}
	return 0;
}