/*  E'UZU BILLAHI MINESHEJ-TANIRRADZIM
	BISMILLA-HIRRAHMA-NIRRAHIM
	ALLAHU LA-ILAHE ILLA-HU, EL-HAJJUL-KAJUM.
	LA TE'HUZUHU SINETUN VE-LA NEVM.
	LEHU MA FISSEMAVATI VE MA FIL-ERD.
	MEN ZELLEZI JESHFE-U INDEHU ILLA BI IZNIH.
	J'ALEMU MA BEJNE EJDIHIM VE MA HELFEHUM.
	VE LA JUHITUNE BI SEJ-IN MIN ILMIHI ILLA BI-MA SAE.
	VESIA KURSIJJU-HUSSEMAVATI VE-ERDA,
	VE-LA JE-UDUHU HIF-ZUHUMA,
	VE HUVEL-ALIJJUL-AZIM.
*/


#include <iostream>
#include <vector>
#include <cmath>


std::vector<int> izdvojiSimetricneTernarne(std::vector<int> v, int prostiBr);
bool prostBroj(int broj);
bool simetricanBroj(int broj);
int duzinaBroja(int broj);
int decimalniUTernare(int broj);
bool ponavljanje(std::vector<int> v, int broj);


int main ()
{
	std::vector<int> v;
	int element;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	while (1)
	{
		std::cin >> element;
		
		if (element == -1)
			break;
			
			
		v.push_back(element);	
	}
	
	int izbor;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> izbor;
	
	while(izbor != 1 && izbor != 0)
	{
		std::cout << "Neispravan unos! Unesite ponovo: ";
		
		std::cin >> izbor;
		
	}
	
	std::vector<int> t = izdvojiSimetricneTernarne(v, izbor);
	
	if (izbor)
	
	{
		if(t.size() == 0)
		
		{
			
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			
			return 0;
		}
		
		std::cout <<"Prosti simetricni brojevi iz vektora su: ";
	}	
		
	else
	
	{
		if(t.size() == 0)
		
		{
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
			
			return 0;
		}
		
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	}
		

	for (unsigned int i = 0; i < t.size(); i++)
	
	{
		if(i < t.size() - 1) std::cout << t.at(i) << ", ";
		
		else std::cout << t.at(i) << ".";
		
	}	
		
	

	return 0;
}

std::vector<int> izdvojiSimetricneTernarne(std::vector<int> v, int prostiBr)

{
	std::vector<int> t;
	
	for (unsigned int i = 0; i < v.size(); i++)
	
	{
		if (!ponavljanje(t, v.at(i)) && simetricanBroj(decimalniUTernare(v.at(i))))
		
		{
			if (prostiBr && prostBroj(v.at(i)))
			
				t.push_back(v.at(i));
				
			else if (!prostiBr && !prostBroj(v.at(i)))
				t.push_back(v.at(i));
		}
	}
	
	return t;
	
}

bool simetricanBroj(int broj)
{
	
	int d = duzinaBroja(broj) - 1;
	
	int x1;
	
	
	if (broj < 0)
	
		broj = -broj;
		
	while (d != 0 && broj)
	
	{
		x1 = static_cast<int>(pow(10, d));
		
		if (broj / x1 != broj % 10)
		
			return false;
			
		broj %=x1;
		
		broj /=10;
		
		d -= 2;
		
	}
	
	return true;
	
}

bool ponavljanje(std::vector<int> v, int broj)
{
	for (unsigned int i = 0; i < v.size(); i++)
	
		if (v.at(i) == broj)
		
		return true;
		
		
	return false;	
		
}

bool prostBroj(int broj)

{
	if (broj < 0)
		broj = -broj;
		
	for (int i = 2; i < broj; i++)
		if (broj % i == 0)
			return false;
			
			
	return true;		
	
	
}

int decimalniUTernare(int broj)
{
	
	int suma(0);
	
	while (broj)
	
	{
		suma = broj % 3 + suma * 10;
		
		broj /= 3;
	}
	
	return suma;
	
	
}

int duzinaBroja (int broj)

{
	int brojac(0);
	
	while (broj)
	
	{
		broj /= 10;
		brojac++;
	}
	
	return brojac;
	
}



