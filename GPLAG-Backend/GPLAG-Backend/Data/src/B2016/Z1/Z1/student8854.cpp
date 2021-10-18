/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>








std::vector<int> IzdvojiGadne(std::vector<int>ulaz,bool logika)
{
	
	
	std::vector<int>izlaz;
	if(logika)
	{
		for(int i=0;i<ulaz.size();i++)
	{
		std::vector<int>helper;
		int a{ulaz[i]};
		int ostatak(0);
		if(a==0)
		helper.push_back(0);
		else
		{
		while(a!=0)
		{
			ostatak=a%3;
			helper.push_back(ostatak);
			a=a/3;
		}
		}
		
		
		
		
		
		
		bool JelOpak(false);
	for(int j=0;j<helper.size();j++)
	{
		if(helper[j]==3)
		continue;
		int brojac(0);
		for(int k=j+1;k<helper.size();k++)
		{
			if(helper[j]==helper[k])
			{brojac++;
			helper[k]=3;
				
			}
		}
		if(brojac%2==0)
		{
			JelOpak=false;
			break;
		}
		else
		JelOpak=true;
	}
	if(JelOpak)
	{
		bool a(false);
		if(i!=0)
		{
		for(int l=0;l<i;l++)
		{
			if(ulaz[l]==ulaz[i])
			{
				a=false;
			    break;
			}
			else
			a=true;
		}	
		}
		else
		a=true;
	if(a)
	izlaz.push_back(ulaz[i]);
	
	
	}
	}
	
	
	
	
	
}
else
{
	for(int i=0;i<ulaz.size();i++)
	{
		std::vector<int>helper;
		int a(ulaz[i]);
		int ostatak(0);
		if(a==0)
		{
			helper.push_back(0);
			
		}
		else
		{
		while(a!=0)
		{
			ostatak=a%3;
			helper.push_back(ostatak);
			a=a/3;
		}
		}
		bool JelOdvratan(false);
	for(int j=0;j<helper.size();j++)
	{
		if(helper[j]==3)
		continue;
		int brojac(0);
		for(int k=j+1;k<helper.size();k++)
		{
			if(helper[j]==helper[k])
			{brojac++;
			helper[k]=3;}
		}
		if(brojac%2==1)
		{
			JelOdvratan=false;
			break;
		}
		else
		JelOdvratan=true;
	}
	if(JelOdvratan)
	{
		
			bool a(false);
			if(i!=0)
		{
		for(int l=0;l<i;l++)
		{
			if(ulaz[l]==ulaz[i])
			{
				a=false;
			    break;
			}
			else
			a=true;
		}	
		}
		else
		a=true;
	if(a)
	izlaz.push_back(ulaz[i]);
	
	
	}
	
	
	
	
	
	
	}

}
return izlaz;

}


int main()
{


	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int v;
	std::vector<int>ulaz;
	
	while(std::cin>>v && v!=0)
	{
		ulaz.push_back(v);
	}
	
	std::cout<<"Opaki: ";
	std::vector<int>a(IzdvojiGadne(ulaz,true)),b(IzdvojiGadne(ulaz,false));
	for(int i:a)
	std::cout<<i<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	for(int i:b)
	std::cout<<i<<" ";




	
	return 0;
}