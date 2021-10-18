/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector> 
#include <limits>
#include <cmath>
std::vector<int > pretvori_u_ternarni(int n)
{

	std::vector<int>vrati;
	int ostatak;
	while (n!=0) {
		ostatak=fabs(n%3);
		vrati.push_back(ostatak);
		n=n/3;
	}
	return vrati;
}

std::vector<int> broj_ponavljanja(int n)
{
	int suma=0;
	int ponavlja;
	std::vector<int>vrati ;
	auto ternarni(pretvori_u_ternarni(n));
	for(int i=0;i<ternarni.size();i++)
	{
		ponavlja=0;
		for(int j=0;j<i;j++)
		if(ternarni[i]==ternarni[j])
		ponavlja=1;
		if(ponavlja==0)
		{	suma=0;
			for(int j=i;j<ternarni.size();j++)
			if(ternarni[i]==ternarni[j])
			suma++;
			vrati.push_back(suma);
		}
		
	}
	
	return vrati;
}


bool opaki(int n)
{

	auto vrati=broj_ponavljanja(n);
	for(int i=0;i<vrati.size();i++)
	if(vrati[i]%2!=0)
	return false;
	return true;
	
}

bool odvratni(int n)
{
	auto vrati=broj_ponavljanja(n);
	for(int i=0;i<vrati.size();i++)
	if(vrati[i]%2==0)
	return false;
	return true;
	
}


std::vector<int> IzdvojiGadne (std::vector<int>v ,bool gadni)
{
	std::vector<int >vrati;
	int ponavlja=1;
	
	if(gadni==true)
	{
		for(int i=0;i<v.size();i++)
		{
			if(opaki(v[i])==true)
			{
				ponavlja=0;
				for(int j=0;j<i;j++)
				{
					if(v[j]==v[i])
			        {
			        	ponavlja=1;
			        }
				}
				
				if(ponavlja==0)
				{
					vrati.push_back(v[i]);
			
				}
				
			}
			
		}
		
	}
	ponavlja=0;
	if(gadni==false)
	{
		for(int i=0;i<v.size();i++)
		{
			if(odvratni(v[i])==true)
			{
				ponavlja=0;
				for(int j=0;j<i;j++)
		     	{
		     		if(v[i]==v[j])
					{
						ponavlja=1;
					}
		     	}
				if(ponavlja==0)
				{
					vrati.push_back(v[i]);
				}
			}
		}
	}
	
	
	return vrati;
}
int main ()
{
	int broj;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::cin>>broj;
	std::vector<int>v ;
	while (broj!=0) {
		v.push_back(broj);
		std::cin>>broj;
	}	
	std::vector<int>ispis ;
	 ispis=IzdvojiGadne(v,1);
	 std::cout<<"Opaki: ";
	for(int i=0;i<ispis.size();i++)
	std::cout<<ispis[i]<<" ";
	 ispis=IzdvojiGadne(v,0);
	std::cout<<"\n";
	std::cout<<"Odvratni: ";
	for(int i=0;i<ispis.size();i++)
	std::cout<<ispis[i]<<" ";
	return 0;
}