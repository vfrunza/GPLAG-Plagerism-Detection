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
std::vector<int> IzdvojiGadne(std::vector<int> vek, bool t)
{

	std::vector<int> b;
	int ostatak;
	for(int i =0;i<vek.size(); i++)
	{
		bool sadrzan(false);
		int br = abs(vek[i]);
		int br0(0), br1(0), br2(0);
		for(int j=0; j<b.size();j++)
		{
			if(vek[i] == b[j])
			{
				sadrzan = true;
				break;
			}
		}
		if(sadrzan) continue;
		while(br != 0)
		{
			ostatak = br % 3;
			if(ostatak == 0) br0++;
			if(ostatak == 1) br1++;
			if(ostatak == 2) br2++;
			br/=3;
		}
		if(t)
		{
			if(br0 % 2==0 && br1 % 2 == 0 && br2 % 2 == 0) b.push_back(vek[i]);
		}
		else
		{
			if((br0 % 2!=0 && br1 % 2 != 0 && br2 % 2 != 0) || (br0 == 0 && br1 % 2 != 0 && br2 % 2 != 0) || (br0 % 2!=0 && br1 == 0 && br2 % 2 != 0) || (br0 % 2!=0 && br1 % 2 != 0 && br2 == 0)) b.push_back(vek[i]);

		}
	}
	return b;
}

int main ()
{
	std::vector<int> vek;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int n;
	for(;;)
	{
		std::cin>> n;
		if(n!=0) vek.push_back(n);
		else break;
	}
	std::vector<int> b, c;
	b=IzdvojiGadne(vek, 1);
	c=IzdvojiGadne(vek, 0);
	std::cout<<"Opaki: ";
	for(int i=0;i<b.size(); i++)
	{
		std::cout<<b[i]<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i=0;i<c.size(); i++)
	{
		std::cout<<c[i]<<" ";
	}
	return 0;
}