#include <iostream>
#include <vector>
/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
bool DaLiJeOpak(std::vector<int> vektor)
{	
	bool provjera=true;
	for(int i=0; i<vektor.size(); i++)
	{
		if(vektor[i]%2!=0) provjera=false;
	}
	return provjera;
}
bool DaLiJeOdvratan(std::vector<int> vektor)
{	
	bool provjera=true;
	
	for(int i=0; i<vektor.size(); i++)
	{
		if(vektor[i]!=0 && vektor[i]%2==0) provjera=false;
	}
	
	return provjera;
}

std::vector<int> IzdvojiGadne(std::vector<int> primljeni, bool vrsta)
{
	int provjera=0;
	std::vector<int>vracani;
	std::vector<int> vektor;
	std::vector<int>brojpojavljivanja(3);
	
	for(int i=0; i<primljeni.size(); i++)
	{
		

	int broj=primljeni[i];
		if(broj<0) broj=(-1)*primljeni[i];
	
	while(broj!=0)
	{
	vektor.push_back(broj%3);
	broj=broj/3;
	}

	for(int k=0; k<vektor.size(); k++)
	{
		brojpojavljivanja[vektor[k]]++;
	}

		for(int j=0; j<i; j++)
		{
			
			if(primljeni[i]==primljeni[j]) provjera=1;
			
		}
		
	if(vrsta==true)
	{
		if(provjera==0)
	{
		if(DaLiJeOpak(brojpojavljivanja)==1  ) vracani.push_back(primljeni[i]);
	}
	}
	
	else
	{
			if(provjera==0)
				{
						if(DaLiJeOdvratan(brojpojavljivanja)==1) vracani.push_back(primljeni[i]);
						
				}
	}
	for(int k=0;k<3 ; k++) brojpojavljivanja[k]=0;
	
	vektor.resize(0);
	provjera=0;
	}

	return vracani;
}

int main ()
{
	int n;
	std::vector<int>v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;)
	{
		std::cin>>n;
		if(n==0) break;
		v.push_back(n);
	}
		std::vector<int>prima;
		
		prima=IzdvojiGadne(v,true);
		std::cout<<"Opaki: ";
		for(int i=0; i<prima.size(); i++) std::cout<<prima[i]<<" ";
		std::cout<<std::endl;
			prima=IzdvojiGadne(v,false);
		std::cout<<"Odvratni: ";
		for(int i=0; i<prima.size(); i++) std::cout<<prima[i]<<" ";
	return 0;
}