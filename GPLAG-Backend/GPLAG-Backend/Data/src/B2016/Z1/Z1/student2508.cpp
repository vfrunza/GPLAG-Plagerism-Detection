/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include<iostream>
#include<vector>
#include<limits>
//Funkcije za provjeravanje opakosti/odvratnosi broja

bool DaLiJeOpak(int n)
{
	std::vector<int> broj;
	long int m{abs(n)};
	while(1)
	{
		broj.push_back(m%3);
		m/=3;
		if(m==0)
			break;
	}
	
	for(int i(0);i<3;i++)
	{
		int brojac(0);
		for(int j(0);j<broj.size();j++)
		{
			if(i==broj.at(j))
				brojac++;
		}
		
		if(brojac%2!=0 && brojac!=0)
		{
			return false;
		}
	}
	
	return true;
}

bool DaLiJeOdvratan(int n)
{
	std::vector<int> broj;
	long int m{abs(n)};
	while(1)
	{
		broj.push_back(m%3);
		m/=3;
		if(m==0)
			break;
	}
	
	for(int i(0);i<3;i++)
	{
		int brojac(0);
		for(int j(0);j<broj.size();j++)
		{
			if(i==broj.at(j))
				brojac++;
		}
		
		if(brojac%2==0 && brojac!=0)
		{
			return false;
		}
	}
	
	return true;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool opaki)
{
	
	std::vector<int> gadni;
	if(opaki)
	{
		for(int i(0);i<v.size();i++)
		{
			if(DaLiJeOpak(v.at(i)))
			{
				gadni.push_back(v[i]);
				for(int j(i+1);j<v.size();j++)
				{
					if(v[i]==v[j])
					{
						v.erase(v.begin()+j);		//Izbacivanje clanova koji su viska
						j--;
					}
				}
			}
		}
	}
	else
	{
		for(int i(0);i<v.size();i++)
		{
			if(DaLiJeOdvratan(v.at(i)))
			{
				gadni.push_back(v[i]);
				for(int j(i+1);j<v.size();j++)
				{
					if(v[i]==v[j])
					{
						v.erase(v.begin()+j);
						j--;
					}
				}
			}
		}
	}
	
	return gadni;
}

int main ()
{

	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	for(;;)
	{
		int x;
		std::cin>>x;
		if(x!=0)
			v.push_back(x);
		else
			break;
	}
	std::vector<int> b,c;
	b=IzdvojiGadne(v,true);
	c=IzdvojiGadne(v,false);
	std::cout<<"Opaki: ";
	for(int i(0);i<b.size();i++) std::cout<<b.at(i)<<" ";
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i(0);i<c.size();i++) std::cout<<c.at(i)<<" ";
	return 0;
}