/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9...
	
*/

#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool b) // true = opaki
{
	try
	{
		std::vector<int> niz(0);
		for(int i=0; i<v.size(); i++)
		{
			std::vector<int> cifre(0);
			int br = abs(v.at(i));
			while(br != 0)
			{
				cifre.push_back(br%3);
				br =  br/3;
			}
			std::vector<int> stanje(3,0);
			for(int j=0; j<cifre.size(); j++)
			{
				stanje.at(cifre.at(j)) ++;
			}
			int ima = 1;
			for(int j=0; j<3; j++)
			{
				if(b)
				{
					if(stanje.at(j) % 2 == 1)
					{
						ima=0;
					}
				}
				else
				{
					if(stanje.at(j) % 2 == 0 && stanje.at(j) != 0)
					{
						ima = 0;
					}
				}
			}
			if(ima)
			{
				int ima = 0;
				for(int j=0; j<niz.size(); j++)
				{
					if(v.at(i) == niz.at(j))
					{
						ima = 1;
					}
				}
				if(ima == 0)
				{
					niz.push_back(v.at(i));
				}
			}
		}
		return niz;
	}
	catch(...)
	{
		std::cout << "Greska pri izvrsavanju programa";
		return std::vector<int> (0);
	}
	return std::vector<int> (0);
}

int main ()
{
	std::vector<int> v(0);
	int n;
	try
	{
		std::cout <<  "Unesite brojeve (0 za prekid unosa): ";
		for(;;)
		{
			std::cin >> n;
			if(n == 0) break;
			else
			{
				v.push_back(n);
			}
		}
	}
	catch(...)
	{
		std::cout << "Greska pri unosu podataka";
		return 0;
	}
	std::vector<int> opaki = IzdvojiGadne(v,true);
	std::vector<int> odvratni = IzdvojiGadne(v,false);
	std::cout << "Opaki: ";
	for(int i=0; i<opaki.size(); i++)
	{
		std::cout << opaki.at(i) << " ";
	}
	std::cout << std::endl << "Odvratni: ";
	for(int i=0; i<odvratni.size(); i++)
	{
		std::cout << odvratni.at(i) << " ";
	}
	return 0;
}