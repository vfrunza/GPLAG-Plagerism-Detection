/*B 2017/2018, Zadaća 2, Zadatak 3

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
#include <stdexcept>
#include <algorithm>
#include <iomanip>

template <typename tipint>
void periodican(const std::vector<tipint> &veca, int &broj_clanova_podniza, int &broj_podnizova)
{
	try
	{
		for(int i=1; i<veca.size(); i++)
		{
			broj_podnizova=0;
			for(int j=0; j+i<veca.size(); j++)
			{
				if(veca.at(0)==veca.at(j))broj_podnizova++;
				if(veca.at(i+j)!=veca.at(j))break;
				if(j+i==veca.size()-1)
				{
					broj_clanova_podniza=i;
					broj_podnizova++;
					throw std::string("Periodican je");
				}
			}
		}
	}
	catch(...)
	{
		//	std::cout<<"\nBroj podnizova: "<<broj_podnizova<<"\nbroj clanova: "<<broj_clanova_podniza;
		return;
	}
	broj_clanova_podniza=veca.size();
	broj_podnizova=2;

	return;
}



template <typename tipint>
int** AlocirajFragmentirano(const std::vector<tipint> &veca, int &koliko_puta)
{
	if(veca.size()==0)throw std::string("Prazan vektor");
	for(int i=0; i<veca.size(); i++)
		if( veca.at(i)<1)throw std::domain_error("Neispravan vektor");

	int** niz(nullptr);
	int br_clanova(0),br_niz(0);
	periodican(veca,br_clanova,br_niz);
	try
	{
		niz = new int*[br_clanova*br_niz] {};
		try
		{
			for(int i=0; i<br_clanova*br_niz; i++)
			{
				niz[i]=new int[veca.at(i%br_clanova)] {};
			}
		}
		catch(...)
		{
			delete[] niz;
			throw std::domain_error("Neispravan vektor");
		}
		tipint najveci(static_cast<int>(*max_element(veca.begin(),veca.end())));
		for(int i=0; i<br_clanova*br_niz; i++)
		{
			for(int j = 0; j < veca.at(i%br_clanova); j++)
			{
				niz[i][j]=static_cast<int>(najveci-veca.at(i%br_clanova)+1+j);
			}
		}
		return niz;
	}
	catch(...)
	{
		throw std::domain_error("Neispravan vektor");
	}

	return nullptr;
}

template <typename tipint>
int** AlocirajKontinualno(const std::vector<tipint> &veca, int &koliko_puta)
{
	if(veca.size()==0)throw std::string("Prazan vektor");
	for(int i=0; i<veca.size(); i++)
		if( veca.at(i)<1)throw std::domain_error("Neispravan vektor");

	int** niz(nullptr);
	int br_clanova(0),br_niz(0);
	periodican(veca,br_clanova,br_niz);
	try
	{
		niz = new int* [br_niz*br_clanova] {};
		try
		{
			int suma(0);
			for(int i=0; i<veca.size(); i++)suma+=veca.at(i);
			niz[0]= new int[br_niz*br_clanova*suma];
			int najveci=static_cast<int>(*std::max_element(veca.begin(),veca.end()));
			for(int i=0; i<veca.at(0); i++)
				niz[0][i]=static_cast<int>(najveci-i-(najveci-veca.at(0)));
			for(int i=1; i<br_niz*br_clanova; i++)
			{
				niz[i]=niz[(i-1)%br_clanova]+veca.at((i-1)%br_clanova);
				for(int j=0; j<veca.at(i%br_clanova); j++)
					niz[i][j]=static_cast<int>(najveci-j-(najveci-veca.at(i%br_clanova)));
			}
			return niz;
		}
		catch(...)
		{
			throw std::domain_error("Neispravan vektor");
		}
	}
	catch(...)
	{
		throw std::domain_error("Neispravan vektor");
	}
	return nullptr;
}


void pocisti_fragmentiranu(int** pokazivac, int br_pok)
{
	for(int i=0; i<br_pok; i++)delete[] pokazivac[i];
	delete[] pokazivac;
}

void pocisti_kontinualnu(int** pokazivac, int br_pok)
{
	delete[] pokazivac[0];
	delete[] pokazivac;
}

int main ()
{
	typedef void (*pok_na_fun)(int**,int);
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";

	std::vector<int> veca(n);
	for(int i=0; i<n; i++)
	{
		std::cin>>veca.at(i);
	}
	std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int x;
	std::cin>>x;
	typedef int** (*pok_na_aloc)(const std::vector<int>&, int&);
	pok_na_aloc desni_bek[2] {AlocirajKontinualno,AlocirajFragmentirano};
	try
	{
		int koliko_puta,koliko_clanova;
		periodican(veca,koliko_clanova,koliko_puta);
		int** niz(desni_bek[x](veca,koliko_puta));
		std::cout<<"Dinamicki alocirana matrica:\n";
		for(int i=0; i<koliko_puta*koliko_clanova; i++)
		{
			for(int j=0; j<veca.at(i%koliko_clanova); j++)
			{
				std::cout<<std::setw(3)<<std::left<<niz[i][j];
			}
			std::cout<<std::endl;
		}
		pok_na_fun cistac[2] {pocisti_kontinualnu,pocisti_fragmentiranu};
		cistac[x](niz,koliko_puta*koliko_clanova);
	}
	catch(std::domain_error izuzetak)
	{
		std::cout<<"Izuzetak: "<<izuzetak.what()<<"!";
	}
	catch(std::string izuzetak)
	{
		std::cout<<"Izuzetak: "<<izuzetak<<"!";
	}
	return 0;
}