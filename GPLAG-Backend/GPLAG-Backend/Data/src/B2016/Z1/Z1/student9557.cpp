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

std::vector<int> Cifre(int n)
{
	
	std::vector<int> v;

	n=fabs(n);
	while (n!=0)
	{
		v.push_back(n%3);
		n/=3;
	}
	return v;
}


std::vector<int> IzdvojiGadne(std::vector<int> v, bool t)
{
	std::vector<int> b;
	std::vector<std::vector<int>> novi;
	std::vector<bool> predznaci(v.size());
	for (int i=0;i<v.size();i++) predznaci[i]=false;
	for (int i=0;i<v.size();i++)
	{
		if (v[i]<0) predznaci[i]=true;
	}
		for (int i=0;i<v.size();i++)
	{
		if (v[i]<0) v[i]=-v[i];
	}
	
	
	for (int i=0;i<v.size();i++)
	{
		novi.push_back(Cifre(v[i]));
	}
	
	
	
	
	std::vector<int> d(3);
	
	for (int q=0;q<novi.size();q++)
	{
		for (int k=0;k<novi[q].size();k++)
		{
			d[novi[q][k]]++;
			
		}
		bool staviti(true);
		for (int i=0;i<d.size();i++)
		{
			if (t==true)
			{
				if (d[i]%2==1)
				{
					staviti=false;
					break;
				}
			}
			else
			{
				if (d[i]%2==0 && d[i]!=0)
				{
					staviti=false;
					break;
				}
			}
		}
		if (staviti) 
		{
			int broj(v[q]);
			if (predznaci[q]==true)
			{
				broj=-broj;	
			}
			b.push_back(broj);
		}
		
		
		for (int i=0;i<d.size();i++) d[i]=0;
	}
	
	int velicina(b.size());
	for (int i=0;i<velicina-1;i++)
	{
		for (int j=i+1;j<velicina;j++)
		{
			if (b[i]==b[j]) b[j]=0;
		}
	}
	velicina=b.size();
	for (int i=0;i<velicina;i++)
	{
		
		if (b[i]==0) 
		{
			
			b.erase(b.begin()+i);
			velicina--;
			i--;
		}
	}
	
	return b;
	
}



int main()
{
	int broj;
	std::vector<int> b;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	for(;;)
	{
		std::cin>> broj;
		if (broj==0) break;
		b.push_back(broj);
	}

	std::cout << "Opaki: ";
	std::vector<int> opaki(IzdvojiGadne(b,true));
	for (int i=0;i<opaki.size();i++) std::cout<< opaki[i] << " ";
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	std::vector<int> odvratni(IzdvojiGadne(b,false));
	for (int i=0;i<odvratni.size();i++) std::cout<< odvratni[i] << " ";

	return 0;
}