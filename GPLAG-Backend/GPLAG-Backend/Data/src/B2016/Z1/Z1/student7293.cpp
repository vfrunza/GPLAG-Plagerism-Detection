#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> Pretvori (int broj) //TERNARNI ZAPIS
{
	std::vector<int> v2(0);
	int cifra{0};
	
	do {
		cifra = abs(broj%3);
		broj /= 3;
		v2.push_back(cifra);
	} while (broj != 0);

	return v2;
}

std::vector<int> IzdvojiGadne (std::vector<int> v, bool x)
{
	for (int i=0; i<v.size(); i++)
	{
		for (int j=i+1; j<v.size(); j++)
		{
			if (v[i] == v[j])
			{
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	
	std::vector<int> Opaki(0);
	for (int i=0; i<v.size(); i++)
	{
		std::vector<int> p = Pretvori(v[i]);
		int b0{0}, b1{0}, b2{0};
	
		for (int j=0; j<p.size(); j++)
		{
			if (p[j] == 0)	b0 ++;
			if (p[j] == 1)	b1 ++;
			if (p[j] == 2)	b2 ++;
		}
	
		if (b0%2==0 && b1%2==0 && b2%2==0)
		{
			Opaki.push_back(v[i]);
		}
	}

	
	std::vector<int> Odvratni(0);
	for (int i=0; i<v.size(); i++)
	{
		std::vector<int> p = Pretvori(v[i]);
		int b0{0}, b1{0}, b2{0};
		
		for (int j=0; j<p.size(); j++)
		{
			if (p[j] == 0)	b0 ++;
			if (p[j] == 1)	b1 ++;
			if (p[j] == 2)	b2 ++;
		}
		
		if (b0==0)	b0 = 1;
		if (b1==0)	b1 = 1;
		if (b2==0)	b2 = 1;
		
		if (b0%2!=0 && b1%2!=0 && b2%2!=0)
		{
			Odvratni.push_back(v[i]);
		}
	}
	
	if ( x== true)
	{
		return Opaki;
	}
	else return Odvratni;
}

int main ()
{
	int broj;
	std::vector<int> v;
	
	std::cout << "Unesite brojeve (0 za prekid unosa): "; //UNOS VEKTORA
	do {
		std::cin >> broj;
		if (broj!=0)
		{
			v.push_back(broj);
		}
	} while (broj!=0);
	
	std::vector<int> opaki = IzdvojiGadne (v, true); //ISPIS OPAKIH
	std::cout << "Opaki: ";
	for (int i=0; i<opaki.size(); i++)
	{
		std::cout << opaki[i] << " ";
	}
	
	std::cout << std::endl;
	
	std::vector<int> odvratni = IzdvojiGadne (v, false); //ISPIS ODVRATNIH
	std::cout << "Odvratni: ";
	for (int i=0; i<odvratni.size(); i++)
	{
		std::cout << odvratni[i] << " ";
	}
	
	return 0;
}