/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <deque> 
using std::sqrt;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::deque;
using std::move;
bool Prost (int broj)
{
	if (broj<0)
	broj=broj*(-1);
	if (broj==0)
	return false;
	for (int i = 2; i<=sqrt(broj); i++)
	{
		if (broj%i==0)
		return false;
	}
	return true;
}

bool PretvoriUTernarni (int broj)
{
	vector <int> v;
	
	while (broj!=0)
	{
		int var;
		var=broj%3;
		broj=broj/3;
		v.push_back(var);
	}
    vector<int> v2;
    
    for (int i=v.size()-1; i>=0; i--)
	{
		v2.push_back(v.at(i));
	}
	
	if (v==v2)
	return true;
	else 
	return false;
}

vector<int> IzdvojiSimetricneTernarne (vector<int> v, bool l)
{
	vector<int> a;
	for (int i=0; i<v.size(); i++)
	{
		for (int j=i+1; j<v.size(); j++)
		{
			if (v.at(i)==v.at(j))
			{
			v.erase (v.begin()+j);
			j--;
			}
		}
	}
	for (int i=0; i<v.size(); i++)
	{
	if (l==true && Prost(v.at(i))==true && PretvoriUTernarni(v.at(i))==true)
	{
		a.push_back(v.at(i));
	}
    else if (l==false && Prost(v.at(i))==false && PretvoriUTernarni(v.at(i))==true)
	{
		a.push_back(v.at(i));
	}
	}
	return a;
}

int main ()
{
    
	
	vector<int> v;
	int broj;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	do
	{
		cin>>broj;
		if (broj!=-1)
		v.push_back(broj);
	}
	while (broj!=-1);
	
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int vrijednost;
	do 
	{
	cin>>vrijednost;
	if (vrijednost!=0 && vrijednost!=1)
	cout<<"Neispravan unos! Unesite ponovo: ";
	}
	while (vrijednost!=0 && vrijednost!=1);
	
	vector <int> b;
	b=IzdvojiSimetricneTernarne(v,vrijednost);
	if (b.size()!=0)
	{
		if (vrijednost==1)
		{
			cout<<"Prosti simetricni brojevi iz vektora su: ";

	
			for (int i=0; i<b.size(); i++)
			{
			if (i<b.size()-1)
			cout<<b.at(i)<<", ";
			else if(i==b.size()-1)
			cout<<b.at(i)<<".";
			}
		}
	   else if (vrijednost==0)
	    {
			cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for (int i=0; i<b.size(); i++)
			{
				if (i<b.size()-1)
			    cout<<b.at(i)<<", ";
			    else if (i==b.size()-1)
			    cout<<b.at(i)<<".";
			}
		}
	}
	else
	{
		if (vrijednost==1)
		cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else
		cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	}
	return 0;
	
}