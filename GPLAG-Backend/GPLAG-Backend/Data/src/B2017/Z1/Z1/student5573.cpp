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
std::vector<int> Simetricni(std::vector<int> vektor)
{
	std::vector<int> vrati;
	for(int i=0;i<vektor.size();i++)
	{
		int broj(abs(vektor.at(i))),broj2(0),broj3(0),k(0);
		while(broj!=0)
		{
			broj/=10;
			k++;
		}
		broj=abs(vektor.at(i));
		k--;
		while(broj!=0)
		{
			broj2=broj%10;
			broj3+=broj2*pow(10,k);
			k--;
			broj/=10;
		}
		if(broj3==abs(vektor.at(i)))	vrati.push_back(vektor.at(i));
	}
	return vrati;
}
bool Prosti_Slozeni(int broj)
{
	for(int i=2;i<broj;i++)
	{
		if(broj%i==0) return false;
	}
	return true;
}
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> vektor, bool stanje)
{
	std::vector<int> vrati,ternarni,vrati2;
	for(int i=0;i<vektor.size();i++)
	{
		if(Prosti_Slozeni(vektor.at(i))==stanje)
		{
			vrati.push_back(vektor.at(i));
		}
	}
	for(int i=0;i<vrati.size();i++)
	{
		int k(0),broj1(0),broj2(0),broj3(0);
		broj1=abs(vrati.at(i));
		while(broj1!=0)
		{
			broj2=broj1/3;
			broj3+=(broj1-(broj2*3))*pow(10,k);
			k++;
			broj1=broj2;
		}
		if(vrati.at(i)>0)	ternarni.push_back(broj3);
		else	ternarni.push_back((-1)*broj3);
	}
	ternarni=Simetricni(ternarni);
	for(int i=0;i<ternarni.size();i++)
	{
		int k(0),broj(abs(ternarni.at(i))),broj2(0),broj3(0);
		while(broj!=0)
		{
			broj2=broj%10;
			broj3+=broj2*pow(3,k);
			k++;
			broj/=10;
		}
		vrati2.push_back(broj3);
	}
	return vrati2;
}
int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int broj;
	std::vector<int> vektor;
	do
	{
		std::cin>>broj;
		if(broj!=-1)	vektor.push_back(broj);
	}while(broj!=-1);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int stanje,l(0);
	do
	{
		if(l>0)
		{
			std::cout<<"Neispravan unos! Unesite ponovo: ";
		}
		l++;
		std::cin>>stanje;
	}while(stanje<0 || stanje>1);
	vektor=IzdvojiSimetricneTernarne(vektor,stanje);
	if(vektor.size()!=0)
	{
		if(stanje==1)	std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0;i<vektor.size();i++)
		{
			if(i!=vektor.size()-1)	std::cout<<vektor.at(i)<<", ";
			else std::cout<<vektor.at(i)<<".";
		}
	}
	else
	{
		if(stanje==1)	std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else	std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	}
	return 0;
}