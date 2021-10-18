#include <iostream>
#include <cmath>
#include <vector>

int ObrniBroj(int broj)
{
	if(broj < 0) broj*=-1;
	int suma(0);
	while(broj != 0)
	{
		suma = suma*10 + broj%10;
		broj = broj / 10;
	}
	return suma;
}

bool DaLiJeProSt(int n)
{
	if(n < 0) n *=-1;
	bool prost(true);
	if(n <= 1) return false;
	for(int i=2; i<=sqrt(n); i++)
	{
		if(n%i == 0)
		{
			prost = false;
			break;
		}
	}
	return prost;
}

int PretvoriUTernarni(int n)
{
	if(n < 0) n *=-1;
	int c, suma(0);
	while(n != 0)
	{
		c = n%3;
		suma = suma*10 + c;
		n /= 3;
	}
	suma = ObrniBroj(suma);
	
	return suma;
}

bool DaLiSePonavlja(std::vector<int> v, int n)
{
	bool ponavlja_se(false);
	for(int i=0; i<v.size(); i++)
	{
		if(v.at(i) == n) 
		{
			ponavlja_se = true;
			break;
		}
	}
	return ponavlja_se;
}

bool DaLiJeSimetrican(int n)
{
	//std::cout << "n = " << n << std::endl;
	if(n < 0) n*=-1;
	int pretvoreni = PretvoriUTernarni(n);
	//std::cout <<"pretvoreni = "<<pretvoreni<<std::endl;
	int obrnuti_pretvoreni = ObrniBroj(pretvoreni);
	//std::cout <<"obrnuti_pretvoreni = "<<obrnuti_pretvoreni<<std::endl;
	bool simetrican(true);
	if(pretvoreni == obrnuti_pretvoreni) simetrican = true;
	else simetrican = false;
	return simetrican;
	
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool vrijednost)
{
	std::vector<int> prosti_ili_slozeni;
	for(int i=0; i<v.size(); i++)
	{
		if(vrijednost == 1)
		{
			if(v.at(i) == 1 || v.at(i) == 0 || !DaLiJeProSt(v.at(i)))
				continue;
			if(DaLiJeSimetrican(v.at(i)) && DaLiSePonavlja(prosti_ili_slozeni, v.at(i)) == false)
				prosti_ili_slozeni.push_back(v.at(i));	
		}
		if(vrijednost == 0)
		{
			if(v.at(i) == 1 || v.at(i) == 0 || DaLiJeProSt(v.at(i)))
				continue;
			if(DaLiJeSimetrican(v.at(i)) && DaLiSePonavlja(prosti_ili_slozeni, v.at(i)) == false)
				prosti_ili_slozeni.push_back(v.at(i));
		}
	}
	return prosti_ili_slozeni;
}


int main ()
{
	std::cout<< "Unesite elemente vektora (-1 za kraj): ";
	int n(0);
	std::vector<int> v, vec;
	do{
		std::cin >> n;
		if(n == -1) break;
		v.push_back(n);
	}while(n != -1);
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int vrijednost;
	std::cin >> vrijednost;
	while(vrijednost != 0 && vrijednost != 1)
	{
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> vrijednost;
	}
	vec = IzdvojiSimetricneTernarne(v, vrijednost);
	if(vrijednost == true)
	{
		if(vec.size() == 0)
		{
			std::cout << "Nema prostih simetricnih brojeva u vektoru."<<std::endl;
			return 0;
		}
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<vec.size(); i++)
		{
			if(i < vec.size()-1)
			{
				std::cout << vec.at(i) << ", ";
			}
			else std::cout << vec.at(i) << ".";
		}
	}
	if(vrijednost == 0)
	{
		if(vec.size() == 0)
		{
			std::cout << "Nema slozenih simetricnih brojeva u vektoru."<<std::endl;
			return 0;
		}
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<vec.size(); i++)
		{
			if(i < vec.size()-1)
			{
				std::cout << vec.at(i) << ", ";
			}
			else std::cout << vec.at(i) << ".";
		}
	}
	
	return 0;
}