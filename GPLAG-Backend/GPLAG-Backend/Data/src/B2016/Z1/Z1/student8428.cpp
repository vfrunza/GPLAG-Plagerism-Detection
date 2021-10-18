#include <iostream>
#include <vector> 

unsigned long long int UTernarni(long long int broj)
{
	bool negativni = false;
	if(broj < 0)
	{
		broj *= -1;
		negativni = true;
	}
	std::vector<int> vektor;
	do
	{
		vektor.push_back(broj%3);
		broj /= 3;
	}
	while (broj);
	unsigned long long int povratni = 0;
	unsigned long long int puta = 1;

	for(int i(0); i <= vektor.size()-1; i++)
	{
		povratni += vektor[i] * puta;
		puta *= 10;
	}
	return povratni;
	
}

bool DaLiPostojiUVektoru(std::vector<int> v, int broj)
{
	for(int i(0); i < v.size(); i++)
	{
		if(v[i] == broj)
			return false;
	}
	return true;
}

bool DaLiJeOpak(unsigned long long int broj)
{
	std::vector<int> cifre(3);
	do
	{
		cifre[broj%10]++;
		broj /= 10;
	}
	while (broj);
	for(auto elem : cifre)
		if( elem != 0 && elem % 2 != 0)
			return false;
	return true;
}

bool DaLiJeOdvratan(unsigned long long int broj)
{
	
	std::vector<int> cifre(3);
	do
	{
		cifre[broj%10]++;
		broj /= 10;
	}
	while (broj);
	for(auto elem : cifre)
		if( elem != 0 && elem % 2 == 0)
			return false;
	return true;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool uslov)
{
	std::vector<int> povratni;
	for(int i(0); i < v.size(); i++)
	{
		auto broj = UTernarni(v[i]);
		if(uslov == true)
		{
			if( DaLiJeOpak(broj))
				if(DaLiPostojiUVektoru(povratni, v[i]))
					povratni.push_back(v[i]);
		}
		else
		{
			if( DaLiJeOdvratan(broj))
				if(DaLiPostojiUVektoru(povratni, v[i]))
					povratni.push_back(v[i]);
		}
	}
	return povratni;
}

int main ()
{
	std::vector<int> v;
	int broj;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	while( true )
	{
		std::cin >> broj;
		if( broj == 0)
			break;
		v.push_back(broj);
	}
	std::vector<int> Opaki, Odvratni;
	Opaki = IzdvojiGadne(v, true);
	Odvratni = IzdvojiGadne(v, false);
	std::cout << "Opaki: ";
	for(int i(0); i < Opaki.size(); i++)
		std::cout << Opaki[i] << " ";
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	for(int i(0); i < Odvratni.size(); i++)
		std::cout << Odvratni[i] << " ";

	return 0;
}