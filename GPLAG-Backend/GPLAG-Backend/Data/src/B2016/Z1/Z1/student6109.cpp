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

std::vector<int> IzdvojiGadne (std::vector<int> v, bool tacno)
{
	std::vector<int> v1, v2;
	
	for(int i=0;i<v.size();i++)
	{
		int temp=v[i], temp2=abs(v[i]), rez;
		int brojaci[10];
		bool paran=true, neparan=true;
		for(int j=0;j<10;j++)
			brojaci[j]=0;
			
		while(temp2!=0)
		{
			rez=temp2%3;
			brojaci[rez]++;
			temp2=temp2/3;
		}
		
		for(int j=0;j<10;j++)
		{
			if(brojaci[j]%2!=0)
			{
				paran=false;
				break;
			}
		}
		if(paran) v1.push_back(temp);
		
		for(int j=0;j<10;j++)
		{
			if(brojaci[j]%2!=1 && brojaci[j]!=0)
			{
				neparan=false;
				break;
			}
		}
		if(neparan) v2.push_back(temp);
	}
	
	for(int i=0;i<v1.size();i++)
	{
		for(int j=i+1;j<v1.size();j++)
		{
			if(v1[i]==v1[j]) 
			{
				for(int k=j;k<v1.size()-1;k++)
				{
					v1[k]=v1[k+1];
				}
				v1.resize(v1.size()-1);
				if(i>0) i--;
			}
		}
	}
	
	for(int i=0;i<v2.size();i++)
	{
		for(int j=i+1;j<v2.size();j++)
		{
			if(v2[i]==v2[j])
			{
				for(int k=j;k<v2.size()-1;k++)
				{
					v2[k]=v2[k+1];
				}
				v2.resize(v2.size()-1);
				i--;
			}
		}
	}
	
	if(tacno) return v1;
	else return v2;
}

int main ()
{
	std::vector<int> v;
	int n;
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";

	do
	{
		std::cin>>n;
		if(n!=0) v.push_back(n);
	}while(n!=0);
	
	std::cout<<"Opaki: ";
	std::vector<int> v1=IzdvojiGadne(v,true);
	for(int i=0;i<v1.size();i++) std::cout<<v1[i]<<" ";
	
	std::cout<<std::endl;
	
	std::cout<<"Odvratni: ";
	std::vector<int> v2=IzdvojiGadne(v,false);
	for(int i=0;i<v2.size();i++) std::cout<<v2[i]<<" ";
	return 0;
}