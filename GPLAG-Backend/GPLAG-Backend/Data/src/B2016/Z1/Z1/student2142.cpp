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
using std::endl;
using std::vector;

bool Opak(int n)
{
	vector<int> cifre (10, 0);
	while(n)
	{
		cifre[abs(n%3)]++; //pomjerio zagradu
		n/=3;
	}
	for(int i=0; i<=9; i++)
	{
		if(cifre[i]%2!=0)
			return false;
	}
	return true;
}

bool Odvratan(int n)
{
	vector<int> cifre (10, 0);
	while(n)
	{
		cifre[abs(n%3)]++; //isto
		n/=3;
	}
	for(int i=0; i<=9; i++)
	{
		if(cifre[i]%2==0 && cifre[i]!=0)
			return false;
	}
	return true;
}

vector<int> IzdvojiGadne(vector<int> v, bool opaki_odvratni)
{
	vector<int> gadni;
	if(opaki_odvratni)
	{
		for(int i=0; i<v.size(); i++)
		{
			int isti(0);
			for(int j=0; j<i; j++)
			{
				if(v[j]==v[i])
				{
					isti++;
					break;
				}
			}
			if(isti==0)
				if(Opak(v[i]))
					gadni.push_back(v[i]);
		}
	}
	else
		for(int i=0; i<v.size(); i++)
		{
			int isti(0);
			for(int j=0; j<i; j++)
			{
				if(v[j]==v[i])
				{
					isti++;
					break;
				}
			}
			if(isti==0)
				if(Odvratan(v[i]))
					gadni.push_back(v[i]);
		}
		
	return gadni;
}

int main ()
{
	vector<int> v;
	int broj;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	while(cin>>broj, broj!=0)
		v.push_back(broj);
	vector<int> opaki(IzdvojiGadne(v, true));
	vector<int> odvratni(IzdvojiGadne(v, false));
	cout<<"Opaki: ";
	for(int i=0; i<opaki.size(); i++)
		cout<<opaki[i]<<" ";
	cout<<endl;
	cout<<"Odvratni: ";
	for(int i=0; i<odvratni.size(); i++)
		cout<<odvratni[i]<<" ";
	
		
	return 0;
}