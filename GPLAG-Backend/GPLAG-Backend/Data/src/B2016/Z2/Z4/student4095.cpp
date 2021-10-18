/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <vector>
#include <string>
#include <new>
#include <stdexcept>
#include <cstring>

int PotencijalniKrivci (char **&prvi, std::vector<std::string> v)
{
	int brojac(0);
	char** niz_pok(nullptr);
	prvi=nullptr;
	try
	{
		niz_pok=new char *[int(v.size())];
		for (int i=0; i<v.size(); i++)
			niz_pok[i]=nullptr;
		try
		{
			for (int i=0; i<v.size(); i++)
			{
				niz_pok[i]=new char [int(v[i].size())+1];
				std::strcpy(niz_pok[i], v[i].c_str());
				brojac++;
			}
			prvi=niz_pok;
			
		}
		catch (std::bad_alloc)
		{
			for (int i=0; i<v.size(); i++)
				delete[] niz_pok[i];
			delete[] niz_pok;
			throw;
		}
	}
	catch (std::bad_alloc)
	{
		throw; 
	}
	return brojac;
}

char** OdbaciOptuzbu (char** &prvi, int vel, std::string ime)
{
	int i;
	int brojac(0);
	for (i=0; i<vel; i++)
	{
		char* pomocni=prvi[i];
		int j(0);
		bool nisu_jednaki(false);
		while (*pomocni!='\0')
		{
			if(*pomocni!=ime[j])
			{
				nisu_jednaki=true;
				break;
			}	
			pomocni++;
			j++;
		}
		if (!nisu_jednaki)
			prvi[i]=nullptr;
	}
	return prvi;
}

int main ()
{
	std::vector<std::string> recenice{
		"asdf",
		"odustajem",
		"asdf",
	};
	char** pok_na_pok(nullptr);
	try
	{

		auto br_alociranih=PotencijalniKrivci(pok_na_pok, recenice);
		for (int i=0; i<recenice.size(); i++)
		{
			for(int j=0; j<recenice[i].size(); j++)
				std::cout<<pok_na_pok[i][j];
			std::cout<<std::endl;
		}
		for (int i=0; i<recenice.size(); i++)
			delete[] pok_na_pok[i];
		delete[] pok_na_pok;
	}
	catch(std::bad_alloc)
	{
		std::cout<<"Greska pri alokaciji"<<std::endl;
	}
	return 0;
}