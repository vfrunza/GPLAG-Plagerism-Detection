/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <cmath>

bool Rastavi (int n)
{
   std::vector<int> cifre;
   cifre.resize(3);
   for (int i=0; i<3; i++)
   {
   	cifre.at(i) = 0;
   }
   while (n != 0)
   {
   	int broj(std::abs(n%3));
   	cifre.at(broj)++;
   	n = n / 3;
   }
   
   
   for (int i=0; i<3; i++)
   {
   	if (cifre.at(i) % 2 != 0) return false;
   	
   }
   return true;
   for (int i=0; i<3; i++)
   {
   	if (cifre.at(i) % 2 == 1 && cifre.at(i) == 0) return true;
   	
   }
   return false;
}
std::vector<int> IzdvojiGadne (std::vector<int> v, bool t)
{
	std::vector<int> opaki;
	std::vector<int> odvratni;
	bool proba(true);
	
	for (int x : v)
	   {
	   	proba = true;
	   	if(Rastavi(x) && t == true)
	   	{
	   		for (int i=0; i<opaki.size(); i++)
	   		{
	   			if (opaki.at(i) == x) 
	   			{
	   				proba = false; 
	   				break;
	   			}
	   		}
	   		if (proba) opaki.push_back(x);
	   	}
	   }

	for (int x : v)
		{
			
			if(!Rastavi(x) && t==false) 
			{
				for (int i=0; i<odvratni.size(); i++)
				{
					if(odvratni.at(i) == x) 
					{
						proba = false; 
						break;
					}
				}
				if (proba) odvratni.push_back(x);
			}
		}

	if (t) return opaki;
	else return odvratni;
}

int main ()
{
	std::vector<int> vektorcic;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int a;
	do
	{
		std::cin >> a;
		if (a==0) break;
		vektorcic.push_back(a);
		
	}while (a != 0);
	
	std::vector<int> Opaki(IzdvojiGadne(vektorcic, true));
	std::vector<int> Odvratni(IzdvojiGadne(vektorcic, false));
	
	std::cout << "Opaki: ";
	if (Opaki.size() == 0) std::cout << std::endl;
	else for (int y : Opaki) std::cout << y << " ";
	std::cout << std::endl;
	
	std::cout << "Odvratni: ";
	if (Odvratni.size() == 0) std::cout << std::endl;
	else for (int z : Odvratni) std::cout << z << " ";
	std::cout << std::endl;
	
	return 0;
}