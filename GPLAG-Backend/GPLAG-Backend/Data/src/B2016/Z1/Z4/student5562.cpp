/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

typedef std::vector<std::string> VektorStringova;

bool TestirajSpisak(VektorStringova rijeci)
{
	for (std::string s:rijeci)
		for (char x:s)
			if (x < 'A' || x > 'z' || (x > 'Z' && x < 'a'))
				return false;
	return true;
}

std::string ObrniFraze(std::string recenica, VektorStringova rijeci)
{
	for (int i = 0; i < rijeci.size(); i++) 
	{
		if (recenica.size() >= rijeci.at(i).size())
		for (int j = 0; j <= int(recenica.size()) - rijeci.at(i).size(); j++)
		{
			if (recenica.substr(j, rijeci.at(i).size()) == rijeci.at(i))
			{
				for (int k = 0; k < rijeci.at(i).size(); k++)
				{
					recenica.at(j + k) = rijeci.at(i).at(int(rijeci.at(i).size()) - 1 - k);
				}
			}
		}
	}
	return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, VektorStringova rijeci)
{
	if (!TestirajSpisak(rijeci))
		throw std::domain_error("Nekorektan izbor rijeci");
	int i(0);
	do
	{
		bool space(true);
		for (int j = 0; j < recenica.size(); j++)
		{
			if (recenica.at(j) < 'A' || recenica.at(j) > 'z' || (recenica.at(j) > 'Z' && recenica.at(j) < 'a'))
			{
				space = true;
			}
			else if (space)
			{
				space = false;
				int p(j);
				while (p < recenica.size() && ((recenica.at(p) >= 'A' && recenica.at(p) <= 'Z') || (recenica.at(p) >= 'a' && recenica.at(p) <= 'z')))
					p++;
				std::string rijec(recenica.substr(j, p - j));
				
				bool mijenjaj(false);
				if ((rijeci.size() > 0 && rijec == rijeci.at(i)) || rijeci.size() == 0)
					mijenjaj = true;
				if (mijenjaj)
				{
					//Konverzija u pig latin
					if (rijec.size() > 1)
						rijec = rijec.substr(1, int(rijec.size() - 1)) + rijec.at(0) + std::string("ay");
					else if (rijec.size() == 1)
						rijec = rijec.at(0) + std::string("ay");
					recenica = recenica.substr(0, j) + rijec + recenica.substr(j + int(rijec.size()) - 2, int(recenica.size()) - (j + int(rijec.size()) - 2));
				}
				
			}
		}
		i++;
	} while (i < rijeci.size());
	return recenica;
}

int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	VektorStringova rijeci;
	std::string rijec;
	do{
		std::getline(std::cin, rijec);
		if (rijec.size() > 0)
			rijeci.push_back(rijec);
	} while (rijec.size() > 0);
	
	try
	{
		std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica, rijeci);
	}
	catch (std::domain_error izuzetak)
	{
		std::cout << "Izuzetak: " << izuzetak.what();
	}
	std::cout << "\nRecenica nakon obrtanja fraza: " << ObrniFraze(recenica, rijeci);
	
	return 0;
}