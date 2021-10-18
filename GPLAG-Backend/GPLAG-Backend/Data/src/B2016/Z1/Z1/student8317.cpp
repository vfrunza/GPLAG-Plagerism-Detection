/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int Tenarni(int broj)
{
	int ostatak;
	double tenarnibr(0);
	int i(0);
	while(broj!=0)
	{
		ostatak=broj%3;
		broj=broj/3;
		tenarnibr=tenarnibr+(ostatak*pow(10,i));
		i++;
	}
	return tenarnibr;
}

bool Opak(int broj)
{
	vector<int> br;
	while(broj!=0)
	{
		br.push_back(broj%10);
		broj=broj/10;
	}
	
	vector<int>opakbr;
	for(int i=0;i<br.size();i++)
	{
		int brojac(0);
		for(int j=0;j<opakbr.size();j++)
		{
			if(br[i]==opakbr[j])
			brojac++;
		}
		
		if(brojac==0)
		{
			opakbr.push_back(br[i]);
		}
	}
		
			for(int i=0;i<opakbr.size();i++)
	{
		int brojac(0);
		for(int j=0;j<br.size();j++)
		{
			if(opakbr[i]==br[j])
			brojac++;
		}
		
		if(brojac%2!=0)
		return false;
	}
	
	return true;
}

bool Odvratan(int broj)
{
	vector<int>br;
	while(broj!=0)
	{
		br.push_back(broj%10);
		broj=broj/10;
	}
	 vector<int>odvratanbr;
	 for(int i=0;i<br.size();i++)
	 {
	 	int brojac(0);
	 	for(int j=0;j<odvratanbr.size();j++)
	 	{
	 		if(br[i]==odvratanbr[j])
	 		brojac++;
	 	}
	 	if(brojac==0)
	 	odvratanbr.push_back(br[i]);
	 }
	 	 for(int i=0;i<odvratanbr.size();i++)
	 {
	 	int brojac(0);
	 	for(int j=0;j<br.size();j++)
	 	{
	 		if(odvratanbr[i]==br[j])
	 		brojac++;
	 	}
	 	if(brojac%2==0)
	 	return false;
	 	
	 }
	 
	 return true;
}
	 
vector<int> IzdvojiGadne (vector<int> brojevi, bool vratiopake)
{
	vector<int>br;
	for(int i=0;i<brojevi.size();i++)
	{
	int t=Tenarni(brojevi[i]);
	if(vratiopake)
	{
	if(Opak(t))
	br.push_back(brojevi[i]);
	}
	else
	if(Odvratan(t))
	br.push_back(brojevi[i]);
	}
	
	
	vector<int> novi;
	
	for(int i=0;i<br.size();i++)
	{
		int brojac(0);
		for(int j=0;j<novi.size();j++)
		{
			
			if(br[i]==novi[j])
			brojac++;
		}
		if( brojac==0)
		novi.push_back(br[i]);
		
	}
	
	return novi;
}
	 
int main ()
{
	int broj;
	vector<int>c;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	do
	{
		cin>>broj;
		if(broj!=0)
		c.push_back(broj);
		
	} 
	while(broj!=0);
	

	
	
	cout<<"Opaki: ";
	vector<int> Opaki=IzdvojiGadne(c,true);
	vector<int> Odvratni=IzdvojiGadne(c,false);
	for(int i=0;i<Opaki.size();i++)
	cout<<Opaki[i]<<" ";
	cout<<endl;
	cout<<"Odvratni: ";
	for(int i=0;i<Odvratni.size();i++)
	cout<<Odvratni[i]<<" ";
	
	return 0;
}