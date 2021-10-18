/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProst(int broj)
{
    if(broj<0) broj*=(-1);
    else if(broj<=1) return false;
    for(int i=2; i<=sqrt(broj); i++)
    {
        if(broj%i==0) return false;
    }
    return true;
}

bool Simetrican(int broj)
{
    std::vector<int> v1;
    std::vector<int> v2;
    while(broj!=0)
    {
        int cifra(broj%10);
        v1.push_back(cifra);
        broj/=10;
    }
    for(int i=v1.size()-1; i>=0; i--) v2.push_back(v1.at(i));
    if(v1==v2) return true;
    else return false;
}

int Stepen(int stepen)
{
    int broj(1);
    for(int i=0; i<stepen; i++)
    {
        broj*=10;
    }
    return broj;
}

int VratiTernarni(int broj)
{
    if(broj<0) broj*=(-1);
    std::vector<int> cifre;
    int stepen(-1);
    while(broj!=0)
    {
        int cifra(broj%3);
        cifre.push_back(cifra);
        broj/=3;
        stepen++;
    }
    broj=0;
    for(int i=cifre.size()-1; i>=0; i--)
    {
        //std::cout << cifre[i] << " " << stepen;
        broj+=cifre.at(i)*Stepen(stepen);
        stepen--;
        //if(stepen==0) broj++;
    }
    return broj;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> nizbr, bool test)
{
    bool testing(true);
    std::vector<int> rez;
    for(int i=0; i<nizbr.size(); i++)
    {
        int ternarni;
        if(DaLiJeProst(nizbr.at(i))==test)
        {
            ternarni=VratiTernarni(nizbr.at(i));
            if(Simetrican(ternarni))
            {
                for(int j=0; i<rez.size(); i++)
                {
                    if(nizbr.at(i)==nizbr.at(j))
                    {
                        testing=false;
                        break;
                    }
                }
                if(testing) rez.push_back(nizbr.at(i));
            }
        }
    }
    return rez;
}

int main()
{
    std::cout << "Unesite elemente vektora (-1 za kraj): ";
    std::vector<int> v;
    for(;;)
    {
    	int broj;
    	std::cin >> broj;
    	if(broj==-1) break;
    	else v.push_back(broj);
    }
    std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    int n;
    bool test;
	do
	{
    	std::cin >> n;
    	if(n==1) test=true;
    	else if(n==0) test=false;
    	else std::cout << "Neispravan unos! Unesite ponovo: ";
	}while(n!=1 && n!=0);
    std::vector<int> vKonacan(IzdvojiSimetricneTernarne(v, test));
    if(vKonacan.size()==0) 
    {
    	if(test) std::cout << "Nema prostih ";
    	else std::cout << "Nema slozenih ";
    	std::cout << "simetricnih brojeva u vektoru.";
    }
    else
    {
    	if(test) std::cout << "Prosti ";
    	else std::cout << "Slozeni ";
    	std::cout << "simetricni brojevi iz vektora su: ";
    	for(int i=0; i<vKonacan.size(); i++) 
    	{
    		std::cout << vKonacan.at(i);
    		if(i<vKonacan.size()-1) std::cout << ", ";
    		else std::cout << ".";
    	}
    }
    return 0;
}