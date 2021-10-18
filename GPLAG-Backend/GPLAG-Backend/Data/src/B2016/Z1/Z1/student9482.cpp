/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

int main ()
{
	std::vector<int> Vektor;
	int broj;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;)
	{
		std::cin>>broj;
		if(broj==0)
		{
			break;
		}
		Vektor.push_back(broj);
	}
	std::vector<int> IzdvojiGadne(std::vector<int> a,bool b);
	std::vector<int> Opaki;
	std::vector<int> Odvratni;
	Opaki=IzdvojiGadne(Vektor,true);
	Odvratni=IzdvojiGadne(Vektor,false);
	std::cout<<"Opaki: ";
	for(int i=0;i<Opaki.size();i++)
	{
		std::cout<<Opaki[i]<<" ";
	}
	std::cout<<std::endl<<"Odvratni: ";
	for(int i=0;i<Odvratni.size();i++)
	{
		std::cout<<Odvratni[i]<<" ";
	}
	return 0;
}
std::vector<int> IzdvojiGadne(std::vector<int> a,bool b)
{
	int broj,test,premjesti;
	std::vector<int> Test;
	std::vector<int> Opaki;
	std::vector<int> Odvratni;
	for(int i=0;i<a.size();i++)
	{
		int br_ponavljanja=0;
		Test.resize(0);
		broj=a[i];
		premjesti=a[i];
		for(int j=0;j<Opaki.size();j++)
		{
			if(broj==Opaki[j])
			{
				br_ponavljanja++;
				break;
			}
		}
		for(int j=0;j<Odvratni.size();j++)
		{
			if(broj==Odvratni[j])
			{
				br_ponavljanja++;
				break;
			}
		}
		if(br_ponavljanja==0)
		{
			broj=abs(broj);
			while(broj!=0)
			{
				test=broj%3;
				Test.push_back(test);
				broj=broj/3;
			}
			int brojac0=0;
			for(int i=0;i<Test.size();i++)
			{
				if(Test[i]==0)
				{
					brojac0++;
				}
			}
			int brojac1=0;
			for(int i=0;i<Test.size();i++)
			{
				if(Test[i]==1)
				{
					brojac1++;
				}
			}
			int brojac2=0;
			for(int i=0;i<Test.size();i++)
			{
				if(Test[i]==2)
				{
					brojac2++;
				}
			}
			if((brojac0!=0 && brojac1==0 && brojac2==0 && brojac0%2==0)||(brojac0==0 && brojac1!=0 && brojac2==0 && brojac1%2==0)||(brojac0==0 && brojac1==0 && brojac2!=0 && brojac2%2==0))
			{
				Opaki.push_back(premjesti);
				continue;
			}
			if((brojac0!=0 && brojac1==0 && brojac2==0 && brojac0%2==1)||(brojac0==0 && brojac1!=0 && brojac2==0 && brojac1%2==1)||(brojac0==0 && brojac1==0 && brojac2!=0 && brojac2%2==1))
			{
				Odvratni.push_back(premjesti);
				continue;
			}
			int ostatak0,ostatak1,ostatak2;
			ostatak0=brojac0%2;
			ostatak1=brojac1%2;
			ostatak2=brojac2%2;
			
			if(ostatak0==0 && ostatak1==0 && ostatak2==0)
			{
				Opaki.push_back(premjesti);
			}
			if(ostatak0==1 && ostatak1==1 && ostatak2==1)
			{
				Odvratni.push_back(premjesti);
			}
			if((ostatak0==1 && ostatak1==1 && brojac2==0)||(brojac0==0 && ostatak1==1 && ostatak2==1) || (ostatak0==1 && brojac1==0 && ostatak2==1))
			{
				Odvratni.push_back(premjesti);
			}
		}
	}
	if(b)
	{
		return Opaki;
	}
	return Odvratni;
}