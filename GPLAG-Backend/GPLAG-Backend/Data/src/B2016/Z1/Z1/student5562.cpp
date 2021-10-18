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

bool DaLiSePonavlja(std::vector<int> v, int x)
{
	bool ponavlja_se(false);
	for(int n:v)
		if (n == x)
		{
			ponavlja_se = true;
			break;
		}
	return ponavlja_se;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool opaki)
{
	std::vector<int> gadni;
	for (int x:v)
	{
		int n(x);
		bool opak(false), odvratan(false);
		
		if (n == 0)
			odvratan = true;
		
		while(n != 0)
		{
			int cifra_n(n%3), m(x), brojac(0);
			
			while (m != 0)
			{
				int cifra_m(m%3);
				if (cifra_m == cifra_n)
					brojac++;
				m = (m - cifra_m)/3;
			}
			if (brojac%2 == 0)
				opak = true;
			else
				odvratan = true;
			
			if (opak && odvratan)
			{
				opak = false;
				odvratan = false;
				break;
			}
			
			n = (n - cifra_n)/3;
		}
		if (((opak && opaki) || (odvratan && !opaki)) && !DaLiSePonavlja(gadni, x))
			gadni.push_back(x);
	}
	return gadni;
}

int main ()
{
	std::vector <int>v;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	
	for(;;)
	{
		int broj;
		std::cin >> broj;
		if (broj == 0)
			break;
		else
			v.push_back(broj);
	}
	std::cout << "Opaki: ";
	std::vector<int> opaki(IzdvojiGadne(v,true));
	for (int x:opaki)
		std::cout << x << " ";
		
	std::cout << "\nOdvratni: ";
	std::vector<int> odvratni(IzdvojiGadne(v,false));
	for (int x:odvratni)
		std::cout << x << " ";
		
	return 0;
}