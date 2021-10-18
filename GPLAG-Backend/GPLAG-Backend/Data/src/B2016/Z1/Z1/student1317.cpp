//B 2016/2017, Zadaća 1, Zadatak 1

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::endl;

vector<int> IzdvojiGadne(vector<int> v, bool opaki)
{
	vector<int> vektor;
	
	for(int i=0; i<v.size(); i++)
	{
		int broj(v[i]);
		int brojac0(0), brojac1(0), brojac2(0);
		// Odredjivanje broja pojavljivanja cifara ternarnog brojnog sistema
		do
		{
			int zad_cifra=broj%3;
			broj/=3;
			if(zad_cifra<0) zad_cifra*=(-1);
			
			if(zad_cifra==0) brojac0++;
			if(zad_cifra==1) brojac1++;
			if(zad_cifra==2) brojac2++;
		} while(broj!=0);
		
		if(brojac0%2==0 && brojac1%2==0 && brojac2%2==0 && opaki) vektor.push_back(v[i]);
		if((brojac0==0 || (brojac0>0 && brojac0%2!=0)) && (brojac1==0 || (brojac1>0 && brojac1%2!=0)) && (brojac2==0 || (brojac2>0 && brojac2%2!=0)) && opaki==false) vektor.push_back(v[i]);
	}
	// Izostavljanje suvisnih pojavljivanja istog elementa
	for(int i=0; i<vektor.size(); i++)
	{
		for(int j=i+1; j<vektor.size(); j++)
		{
			if(vektor[i]==vektor[j]) 
			{
				vektor.erase(vektor.begin()+j);
				j--;
			}
		}
	} 
	
	return vektor;
}

int main ()
{
	cout << "Unesite brojeve (0 za prekid unosa): ";
	vector<int> v;
	int broj;
	do
	{
		cin >> broj;
		if(broj==0) break;
		v.push_back(broj);
	} while(broj!=0);
	
	vector<int> a(IzdvojiGadne(v, true));
	vector<int> b(IzdvojiGadne(v, false));
	
	if(a.size()>0)
	{
		cout << "Opaki: ";
		for(int x: a)
			cout << x << " ";
		cout << endl;
	}
	else cout << endl;
	
	if(b.size()>0)
	{
		cout << "Odvratni: ";
		for(int x: b)
			cout << x << " ";
	}
	else cout << endl;
	
	return 0;
}
