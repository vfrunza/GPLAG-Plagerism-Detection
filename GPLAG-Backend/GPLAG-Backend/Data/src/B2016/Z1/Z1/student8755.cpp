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

std::vector<int> IzdvojiGadne(std::vector<int> v, bool gadni_broj)
{
	std::vector<int> final;
	for(int i=0; i<v.size(); i++)
	{
		int nula(0), jedan(0), dva(0), temp(v[i]);
		while(v[i]!=0)
		{
			if(v[i]%3==0)		nula++;
			else if(v[i]%3==1 || v[i]%3==-1)	jedan++;
			else				dva++;			
			
			v[i]/=3;
		}
		if(temp==0)	nula++;
		if((nula%2==0 && jedan%2==0 && dva%2==0 && gadni_broj) || ((nula%2==1 || nula==0) && (jedan%2==1 || jedan==0) && (dva%2==1 || dva==0) && !(gadni_broj)))
			final.push_back(temp);
	}
	for(int i=0; i<final.size()-1 && final.size()!=0; i++)
			for(int j=i+1; j<final.size(); j++)
				if(final[i]==final[j])	final.erase(final.begin()+j--);
	return final;
}

int main ()
{
	std::vector<int> v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;)
	{
		int x;
		std::cin>>x;
		if(x==0)	break;
		v.push_back(x);
	}
	
	std::cout<<"Opaki: ";
	for(int x : IzdvojiGadne(v,1))	std::cout<<x<<" ";
	std::cout<<std::endl;
	
	std::cout<<"Odvratni: ";
	for(int x : IzdvojiGadne(v,0))	std::cout<<x<<" ";
	std::cout<<std::endl;
	
	return 0;
}