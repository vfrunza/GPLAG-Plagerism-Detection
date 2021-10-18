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

using std::cout;
using std::cin;
using std::vector;


vector<int>IzdvojiGadne(vector<int>vektor,bool provjera){
		
		vector<int>vracaj_vektor;
		for(int x:vektor)
		{
			vector<int>pomocni;
			int broj(x);
			int cifra(broj%3);
			if (cifra<0)
				cifra=abs(cifra);
			pomocni.push_back(cifra);
			broj/=3;
			if (broj<0)
				broj=abs(broj);
			while (broj!=0)
			{
				int cifra;
				cifra=broj%3;
				pomocni.push_back(cifra);
				broj/=3;
			}
			
			int nule(0),jedinice(0),dvice(0);
			
			for(int i=0;i<pomocni.size();i++)
			{
				if (pomocni[i]==0) nule++;
				else if (pomocni[i]==1) jedinice++;
				else if (pomocni[i]==2) dvice++;
			}
		
			bool a=true;
			
			for(int i=0;i<vracaj_vektor.size();i++)
			{
				if (vracaj_vektor[i]==x)
				{
					a=false;
					break;
				}
			}
			if (a==false) continue;
			
			if (nule%2==0 && jedinice%2==0 && dvice%2==0 && provjera==true)
					vracaj_vektor.push_back(x);
			else if (((nule%2)!=0 || nule==0) && ((jedinice%2)!=0 || jedinice==0) && ((dvice%2)!=0 || dvice==0) && provjera==false)
					vracaj_vektor.push_back(x);
			
			
		}
		
		return vracaj_vektor;
	}

int main ()
{
	int broj;
	vector<int>vektor;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	do
	{
		cin>>broj;
		if (broj==0) break;
		vektor.push_back(broj);
	}while(broj!=0);
	vector<int>opaki;
	vector<int>odvratan;
	opaki=IzdvojiGadne(vektor,true);
	odvratan=IzdvojiGadne(vektor,false);
	
	cout<<"Opaki: ";
	for (int x:opaki)
	{
		cout<<""<<x<<" ";
	}	
	cout<<"\n";
	cout<<"Odvratni: ";
	for (int x:odvratan)
	{
		cout<<""<<x<<" ";
	}
	
	return 0;
}