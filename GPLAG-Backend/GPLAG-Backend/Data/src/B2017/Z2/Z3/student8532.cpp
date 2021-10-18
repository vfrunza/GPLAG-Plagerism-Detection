/*B 2017/2018, Zadaća 2, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include<stdexcept>
#include<vector>
#include<new>

//typedef <typename tip>

bool DaLiJePeriodicno(std::vector<int>a)
{
	bool periodican(false);

	
		for(int j=1;j<a.size();j++)
		{
			if(a[j]==a[0])
			{
				int k=j;
				while(a[k]==a[k-j] && k!=a.size()-1)
				k++;
				if(k==a.size()-1)
				periodican=true;
			}
			
		}
	return periodican;
}
int OsnovniPeriod(std::vector<int> b)
{
	int j;
	for(j=1;;j++)
	{
		if(b[j]==b[0])
		break;
	}
	return j;
}

/*auto AlocirajFragmentirano(const std::vector<tip> &vektor, &int koliko_puta)
{
	
}*/
int main ()
{
/*	try
	{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int>vektor(n);
	for(int i=0;i<vektor.size();i++)
	{
		int element;
		std::cin>>element;
	}
	std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int broj;
	enum opcija{nula,jedan};
	if(broj==nula)
	{
		
	}
	else if(broj==jedan
	{
		
	})*/
	bool ime=DaLiJePeriodicno({1,2,3,1,2,4,1,2,5,1});
	if(ime)
	std::cout<<"Da";
	else
	std::cout<<"ne";
	int p=OsnovniPeriod({5,9,7,2,5,9,7,2,5,9,7});
	std::cout<<p;
	return 0;

}